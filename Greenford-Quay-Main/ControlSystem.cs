using System;
using Crestron.SimplSharp;                          	// For Basic SIMPL# Classes
using Crestron.SimplSharpPro;                       	// For Basic SIMPL#Pro classes
using Crestron.SimplSharpPro.CrestronThread;            // For Threading
using Crestron.SimplSharpPro.EthernetCommunication;
using Crestron.SimplSharpPro.UI;
using Newtonsoft.Json;

namespace Greenford_Quay_Main
{
    public class ControlSystem : CrestronControlSystem
    {
        public SSE_Server sse;
        public static ThreeSeriesTcpIpEthernetIntersystemCommunications _SimplWindowsComms;
        CrestronOne iPad;

        public ControlSystem()
            : base()
        {
            try
            {
                Thread.MaxNumberOfUserThreads = 20;

                //Subscribe to the controller events (System, Program, and Ethernet)
                CrestronEnvironment.SystemEventHandler += new SystemEventHandler(_ControllerSystemEventHandler);
                CrestronEnvironment.ProgramStatusEventHandler += new ProgramStatusEventHandler(_ControllerProgramEventHandler);
                CrestronEnvironment.EthernetEventHandler += new EthernetEventHandler(_ControllerEthernetEventHandler);

                if(this.SupportsEthernet)
                {
                    ConsoleLogger cs = new ConsoleLogger();
                    cs.ConsoleLoggerStart(55555);

                    sse = new SSE_Server();
                    WebServer ws = new WebServer(sse);

                    iPad = new CrestronOne(0x03, this);
                    iPad.ParameterProjectName.Value = "Greenford-Quay-Block8-iPad-GUI";
                    iPad.Register();
                }
            }
            catch (Exception e)
            {
                ErrorLog.Error("Error in the constructor: {0}", e.Message);
            }
        }

        public override void InitializeSystem()
        {

            try
            {
                _SimplWindowsComms = new ThreeSeriesTcpIpEthernetIntersystemCommunications(0xB0, "127.0.0.2", this);
                _SimplWindowsComms.Register();
                _SimplWindowsComms.SigChange += _SimplWindowsComms_SigChange;
            }
            catch (Exception e)
            {
                ErrorLog.Error("Error in InitializeSystem: {0}", e.Message);
            }
        }

        private void _SimplWindowsComms_SigChange(Crestron.SimplSharpPro.DeviceSupport.BasicTriList currentDevice, SigEventArgs args)
        {
            switch (args.Sig.Type)
            {
                case eSigType.String:
                    _SimplWindowsComms_MessageReceived(_SimplWindowsComms.StringOutput[1].StringValue);
                    break;
            }
        }
        private void _SimplWindowsComms_MessageReceived(string newMessage)
        {
            try
            {
                string fromSIMPLWindows = newMessage;
                ConsoleLogger.WriteLine("Message Received from SIMPL Windows: " + fromSIMPLWindows);

                if (fromSIMPLWindows.Contains("BGM"))
                {
                    string roomIDraw = fromSIMPLWindows.Split(':')[1].Replace("Room", "");
                    int roomID = int.Parse(roomIDraw);

                    RoomCoreData rcd = JsonConvert.DeserializeObject<RoomCoreData>(FileOperations.loadRoomJson(roomID, "Core"));
                    ConsoleLogger.WriteLine($"RoomID Extracted: {roomID}");

                    if (fromSIMPLWindows.Contains("Volume"))
                    {
                        rcd.volLevel = int.Parse(fromSIMPLWindows.Split(':')[3]);
                        sse.UpdateAllConnected(roomID, $"Slider:{fromSIMPLWindows.Split(':')[3]}");
                    }
                    else if (fromSIMPLWindows.Contains("UnMuted"))
                    {
                        rcd.volMute = false;
                        sse.UpdateAllConnected(roomID, "Mute:false");
                    }
                    else if (fromSIMPLWindows.Contains("Muted"))
                    {
                        rcd.volMute = true;
                        sse.UpdateAllConnected(roomID, "Mute:true");
                    }

                    FileOperations.saveRoomJson(roomID.ToString(), "Core", JsonConvert.SerializeObject(rcd));
                }
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("Problem in ControlSystem _SimplWindowsComms_MessageReceived: " + ex);
            }
        }

        public static void SendMessageToSIMPL(string message)
        {
            _SimplWindowsComms.StringInput[1].StringValue = message;
        }

        void _ControllerEthernetEventHandler(EthernetEventArgs ethernetEventArgs)
        {
            switch (ethernetEventArgs.EthernetEventType)
            {//Determine the event type Link Up or Link Down
                case (eEthernetEventType.LinkDown):
                    if (ethernetEventArgs.EthernetAdapter == EthernetAdapterType.EthernetLANAdapter)
                    {
                        //
                    }
                    break;
                case (eEthernetEventType.LinkUp):
                    if (ethernetEventArgs.EthernetAdapter == EthernetAdapterType.EthernetLANAdapter)
                    {

                    }
                    break;
            }
        }
        void _ControllerProgramEventHandler(eProgramStatusEventType programStatusEventType)
        {
            switch (programStatusEventType)
            {
                case (eProgramStatusEventType.Paused):
                    break;
                case (eProgramStatusEventType.Resumed):
                    break;
                case (eProgramStatusEventType.Stopping):
                    break;
            }

        }

        void _ControllerSystemEventHandler(eSystemEventType systemEventType)
        {
            switch (systemEventType)
            {
                case (eSystemEventType.DiskInserted):
                    break;
                case (eSystemEventType.DiskRemoved):
                    break;
                case (eSystemEventType.Rebooting):
                    break;
            }

        }
    }
}