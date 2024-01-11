using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Greenford_Quay_Main
{
    public class SSE_Server
    {
        public List<Tuple<uint, HttpListenerContext, string>> _eventListeners;

        public SSE_Server()
        {
            try
            {
                _eventListeners = new List<Tuple<uint, HttpListenerContext, string>>();
                EventListenerAsync();
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("Problem in SSE_Server Constructor: " + ex.Message);
            }
        }

        public async void EventListenerAsync()
        {
            try
            {
                HttpListener listener = new HttpListener();
                listener.Prefixes.Add("http://*:50001/api/events/");
                listener.Start();

                ConsoleLogger.WriteLine("Event Server Started...");

                while (true)
                {
                    try
                    {
                        //Await Client Request
                        HttpListenerContext context = await listener.GetContextAsync();
                        await Task.Run(() => ProcessEventRequestAsync(context));
                        ConsoleLogger.WriteLine("New event subscription: " + context.Request.RemoteEndPoint.Address.ToString());
                    }
                    catch (HttpListenerException) { break; }
                    catch (InvalidOperationException) { break; }
                }

                listener.Stop();
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine($"{ex.Message}");
            }
        }

        public void DisconnectFromStream(string IPAddress)
        {
            foreach (Tuple<uint, HttpListenerContext, string> entry in _eventListeners)
            {
                if (entry.Item3 == IPAddress)
                {
                    ConsoleLogger.WriteLine("_eventListener IP: " + entry.Item3 + " || disconnect request IP: " + IPAddress + " --DELETING--");
                    _eventListeners.Remove(entry);
                    DisconnectFromStream(IPAddress);
                    break;
                }
                else
                {
                    ConsoleLogger.WriteLine("_eventListener IP: " + entry.Item3 + " || disconnect request IP: " + IPAddress);
                }
            }
        }

        public void UpdateAllConnected(int roomID, string infoChanged)
        {
            var inactiveListeners = new List<Tuple<uint, HttpListenerContext, string>>();

            foreach (Tuple<uint, HttpListenerContext, string> entry in _eventListeners)
            {
                if (entry.Item1 == roomID)
                {
                    string message = "data: NEWINFO:" + infoChanged + "\n\n";
                    byte[] messageBytes = ASCIIEncoding.ASCII.GetBytes(message);

                    try
                    {
                        entry.Item2.Response.OutputStream.WriteAsync(messageBytes, 0, messageBytes.Length);
                        entry.Item2.Response.OutputStream.FlushAsync();
                    }
                    catch (Exception ex)
                    {
                        ConsoleLogger.WriteLine("Could not send event data to: " + entry.Item2.Request.UserHostAddress + ", Reason: \n" + ex.Message);
                        inactiveListeners.Add(entry);
                    }
                }
            }

            foreach (var inactiveListener in inactiveListeners)
                _eventListeners.Remove(inactiveListener);
        }

        void ProcessEventRequestAsync(HttpListenerContext context)
        {
            string incomingRequest = context.Request.RawUrl;

            try
            {
                uint roomID = uint.Parse(incomingRequest.Split('?')[1]);
                string IP = context.Request.RemoteEndPoint.Address.ToString();

                context.Response.AddHeader("Access-Control-Allow-Origin", "*");
                context.Response.Headers.Add("Content-Type", "text/event-stream");
                context.Response.Headers.Add("Cache-Control", "no-cache");
                context.Response.Headers.Add("Connection", "keep-alive");

                byte[] responseBytes = Encoding.UTF8.GetBytes("\nevent: update\n\n");
                context.Response.OutputStream.WriteAsync(responseBytes, 0, responseBytes.Length);
                context.Response.OutputStream.FlushAsync();

                _eventListeners.Add(new Tuple<uint, HttpListenerContext, string>(roomID, context, IP));

                if (_eventListeners.Count > 1) CheckForDuplicates();

                ConsoleLogger.WriteLine(_eventListeners.Count + " Event Listeners: ");
                foreach (Tuple<uint, HttpListenerContext, string> entry in _eventListeners)
                    ConsoleLogger.WriteLine("IP: " + entry.Item3 + " || Room: " + entry.Item1);

            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("Bad request..." + ex.Message);
            }
        }

        void CheckForDuplicates()
        {
            Tuple<uint, HttpListenerContext, string> itemToCheck = _eventListeners.Last();

            for (int i = 0; i < _eventListeners.Count - 1; i++)
                if (_eventListeners[i].Item3 == itemToCheck.Item3)
                    _eventListeners.RemoveAt(i);
        }
    }
}