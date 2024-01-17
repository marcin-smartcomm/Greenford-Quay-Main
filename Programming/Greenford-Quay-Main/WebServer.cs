using System.Net;
using System.Text;
using System;
using System.Threading.Tasks;
using System.IO;
using Newtonsoft.Json;
using Crestron.SimplSharpPro.AudioDistribution;
using System.Collections.Generic;

namespace Greenford_Quay_Main
{
    class WebServer
    {
        SSE_Server _eventServer;

        public WebServer(SSE_Server eventServer)
        {
            try
            {
                _eventServer = eventServer;
                ListenAsync();
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("Problem in WebServer Constructor: " + ex.Message);
            }
        }

        public async void ListenAsync()
        {
            HttpListener listener = new HttpListener();
            listener.Prefixes.Add("http://*:50000/api/");
            listener.Start();

            ConsoleLogger.WriteLine("Server Started...");

            while (true)
            {
                try
                {
                    //Await Client Request
                    HttpListenerContext context = await listener.GetContextAsync();
                    await Task.Run(() => ProcessRequestAsync(context));
                }
                catch (HttpListenerException) { break; }
                catch (InvalidOperationException) { break; }
            }

            listener.Stop();
        }

        async void ProcessRequestAsync(HttpListenerContext context)
        {
            try
            {
                //Respond to Request
                string response = "";
                string incomingRequest = context.Request.RawUrl;
                ConsoleLogger.WriteLine("Request Coming on " + context.Request.RawUrl + " || from: " + context.Request.RemoteEndPoint.Address.ToString());

                if (incomingRequest.Contains("/RoomData"))
                {
                    string clientIP = context.Request.RemoteEndPoint.Address.ToString();
                    string roomID = incomingRequest.Split('?')[1];

                    if (roomID.Contains("999"))
                        response = FileOperations.loadRoomJson(GetRoomAssigned(clientIP), "Core");
                    else
                        response = FileOperations.loadRoomJson(Int32.Parse(roomID), "Core");
                }

                if (incomingRequest.Contains("/RoomsList"))
                {
                    List<string> roomData = new List<string>();
                    foreach(string directory in FileOperations.GetRoomDirectories())
                    {
                        string roomRaw = directory.Split('/')[1];
                        int roomID = int.Parse(roomRaw.Replace("Room", ""));

                        RoomCoreData rcd = JsonConvert.DeserializeObject<RoomCoreData>(FileOperations.loadRoomJson(roomID, "Core"));
                        roomData.Add($"{rcd.roomName}:{rcd.roomID}");
                    }

                    response = JsonConvert.SerializeObject(roomData);
                }

                if(incomingRequest.Contains("ChangeZone"))
                {
                    string clientIP = context.Request.RemoteEndPoint.Address.ToString();
                    string newRoomID = incomingRequest.Split('?')[1];

                    IPtoRoom ipToRoom = JsonConvert.DeserializeObject<IPtoRoom>(FileOperations.loadCoreInfo("IPtoRoom"));
                    int indexOfClient = Array.IndexOf(ipToRoom.IPAddress, clientIP);
                    ipToRoom.RoomID[indexOfClient] = int.Parse(newRoomID);

                    FileOperations.saveCoreJson("IPtoRoom", JsonConvert.SerializeObject(ipToRoom));

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                #region SourceSelection

                else if (incomingRequest.Contains("ChangeSouceSelected"))
                {
                    string roomID = incomingRequest.Split('?')[1].Split(':')[0];
                    string srcID = incomingRequest.Split('?')[1].Split(':')[1];

                    RoomCoreData rcd = JsonConvert.DeserializeObject<RoomCoreData>(FileOperations.loadRoomJson(Int32.Parse(roomID), "Core"));
                    rcd.sourceSelected = rcd.menuItems[int.Parse(srcID)].menuItemName;

                    FileOperations.saveRoomJson(roomID, "Core", JsonConvert.SerializeObject(rcd));

                    ControlSystem.SendMessageToSIMPL($"BGM:Room{roomID}:Source:{srcID}");

                    RoomMenuItem selectedItem = rcd.menuItems[int.Parse(srcID)];
                    if (selectedItem.tvRequired)
                    {
                        ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1PON");
                        ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1HDMI{selectedItem.tvHDMIRequired}");
                    }
                    else ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1POFF");

                    response = "{ \"currentSource\": \""+rcd.sourceSelected+"\" }";
                }

                #endregion

                #region VolumeControls

                else if (incomingRequest.Contains("ChangeVolumeLevel"))
                {
                    string roomID = incomingRequest.Split('?')[1].Split(':')[0];
                    string newLevel = incomingRequest.Split('?')[1].Split(':')[1];

                    ControlSystem.SendMessageToSIMPL($"BGM:Room0{roomID}:Volume:{newLevel}");

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("MuteVolume"))
                {
                    string roomID = incomingRequest.Split('?')[1];

                    RoomCoreData rcd = JsonConvert.DeserializeObject<RoomCoreData>(FileOperations.loadRoomJson(int.Parse(roomID), "Core"));

                    RoomMenuItem currentSource = new RoomMenuItem();
                    foreach(RoomMenuItem rmi in rcd.menuItems) 
                        if (rmi.menuItemName == rcd.sourceSelected)
                            currentSource = rmi;

                    if (currentSource.volControlType == "Btns") ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1KP:MuteToggle");
                    if (currentSource.volControlType == "Slider") ControlSystem.SendMessageToSIMPL($"BGM:Room{roomID}:MuteToggle");

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("GetSliderLevel"))
                {
                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("GetMuteState"))
                {
                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("VolUpBtnPress"))
                {
                    string roomID = incomingRequest.Split('?')[1];
                    ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1Vol+");

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("VolDownBtnPress"))
                {
                    string roomID = incomingRequest.Split('?')[1];
                    ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1Vol-");

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("TVOnBtnPress"))
                {
                    string roomID = incomingRequest.Split('?')[1];
                    ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1PON");

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                else if (incomingRequest.Contains("TVOffBtnPress"))
                {
                    string roomID = incomingRequest.Split('?')[1];
                    ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1POFF");

                    response = "{ \"CommandProcessed\": \"true\" }";
                }

                #endregion

                #region Freeview Control

                else if (incomingRequest.Contains("/FreeviewCtrl"))
                {
                    string roomID = incomingRequest.Split('?')[1].Split(':')[0];
                    string btnPressed = incomingRequest.Split('?')[1].Split(':')[1];

                    ControlSystem.FreeviewBtnPress(roomID, int.Parse(btnPressed));
                }

                #endregion

                else if (incomingRequest.Contains("/FireAlarmState"))
                {

                }

                else if (incomingRequest.Contains("/Disconnect"))
                {
                    string IP = context.Request.RemoteEndPoint.Address.ToString();
                    _eventServer.DisconnectFromStream(IP);
                    response = $"\"response\": \"Ok\"";
                }

                else if (incomingRequest.Contains("/RoomShutdown"))
                {
                    string roomID = incomingRequest.Split('?')[1];

                    RoomCoreData rcd = JsonConvert.DeserializeObject<RoomCoreData>(FileOperations.loadRoomJson(int.Parse(roomID), "Core"));
                    rcd.sourceSelected = "Off";
                    FileOperations.saveRoomJson(roomID, "Core", JsonConvert.SerializeObject(rcd));

                    ControlSystem.SendMessageToSIMPL($"Room{roomID}TV1POFF");
                    ControlSystem.SendMessageToSIMPL($"BGM:Room{roomID}:MuteOn");

                    response = "{ \"currentSource\": \"" + rcd.sourceSelected + "\" }";
                }

                context.Response.ContentLength64 = Encoding.UTF8.GetByteCount(response);
                context.Response.AddHeader("Access-Control-Allow-Origin", "*");
                context.Response.AddHeader("Access-Control-Allow-Methods", "*");
                context.Response.AddHeader("Access-Control-Allow-Headers", "*");
                context.Response.ContentType = "application/json";
                context.Response.StatusCode = (int)HttpStatusCode.OK;

                using (Stream s = context.Response.OutputStream)
                using (StreamWriter writer = new StreamWriter(s))
                    await writer.WriteAsync(response);
            }
            catch (Exception ex) { ConsoleLogger.WriteLine("Bad Request: " + ex.Message); }
        }

        int GetRoomAssigned(string TP_IPAddress)
        {
            IPtoRoom ipToRoomData = JsonConvert.DeserializeObject<IPtoRoom>(FileOperations.loadCoreInfo("IPtoRoom"));

            for (int i = 0; i < ipToRoomData.IPAddress.Length; i++)
                if (ipToRoomData.IPAddress[i] == TP_IPAddress)
                    return ipToRoomData.RoomID[i];

            return 2;
        }
    }
}