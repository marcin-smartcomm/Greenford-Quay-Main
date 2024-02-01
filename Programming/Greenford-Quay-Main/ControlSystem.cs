using System;
using Crestron.SimplSharp;                          	// For Basic SIMPL# Classes
using Crestron.SimplSharpPro;                       	// For Basic SIMPL#Pro classes
using Crestron.SimplSharpPro.CrestronThread;            // For Threading
using Crestron.SimplSharpPro.EthernetCommunication;
using Crestron.SimplSharpPro.DeviceSupport;
using Crestron.SimplSharpPro.UI;
using Newtonsoft.Json;
using Crestron.SimplSharpPro.GeneralIO;

namespace Greenford_Quay_Main
{
    public class ControlSystem : CrestronControlSystem
    {
        public SSE_Server sse;
        public static ThreeSeriesTcpIpEthernetIntersystemCommunications _SimplWindowsComms;

        CenIoRy104 _doorHoldingRelayInterface;
        CrestronOne iPad;

        bool _fireAlarmState = false;

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

                    string googleApiKey = "AIzaSyBeDkV6Zpr9irQuXS1Ig7dDfdIFGVTiG0U";
                    InitializeCalendars(googleApiKey);

                    _doorHoldingRelayInterface = new CenIoRy104(0xC0, this);
                    _doorHoldingRelayInterface.Register();

                    _doorHoldingRelayInterface.RelayPorts[1].Register();
                    _doorHoldingRelayInterface.RelayPorts[2].Register();
                    _doorHoldingRelayInterface.RelayPorts[3].Register();
                    _doorHoldingRelayInterface.RelayPorts[4].Register();

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

        private void GamesCalendarCheck_inMeeting(bool inMeeting)
        {
            if (_fireAlarmState) return;
            if(this.SupportsRelay) GamesRoomDoorControl(inMeeting);
        }
        private void MediaCalendarCheck_inMeeting(bool inMeeting)
        {
            if (_fireAlarmState) return;
            if (this.SupportsRelay) MediaRoomDoorControl(inMeeting);
        }
        private void DiningCalendarCheck_inMeeting(bool inMeeting)
        {
            if (_fireAlarmState) return;
            if (this.SupportsRelay) DiningDoorControl(inMeeting);
        }
        private void YogaCalendarCheck_inMeeting(bool inMeeting)
        {
            if (_fireAlarmState) return;
            if (this.SupportsRelay) YogaDoorControl(inMeeting);
        }

        void GamesRoomDoorControl(bool occupationState)
        {
            _doorHoldingRelayInterface.RelayPorts[1].State = occupationState;
            this.RelayPorts[5].State = !occupationState;
        }
        void MediaRoomDoorControl(bool occupationState) => this.RelayPorts[6].State = !occupationState;
        void DiningDoorControl(bool occupationState)
        {
            _doorHoldingRelayInterface.RelayPorts[2].State = occupationState;
            _doorHoldingRelayInterface.RelayPorts[3].State = occupationState;
            this.RelayPorts[7].State = !occupationState;
        }
        void YogaDoorControl(bool occupationState) => this.RelayPorts[8].State = !occupationState;

        void InitializeCalendars(string googleApiKey)
        {
            string YogaCalendarID = "gq.block8@gmail.com";
            string PrivateDiningCalendarID = "ca0357ea7ffd7fc53b9f194c6705db437d7deba85ca66c30529ae56f475237b4@group.calendar.google.com";
            string MediaRoomCalendarID = "3f5d207b1e3b5517fefb0a084d9f48594a42f5cd9cf2f862570e3029bc99597d@group.calendar.google.com";
            string GamesRoomCalendarID = "56b0f026f634d28a92ddef07166a7a46c1a644f1e71ada2c8943cd6b2bf7be38@group.calendar.google.com";

            CalendarCheck yogaCalendarCheck = new CalendarCheck(this, YogaCalendarID, googleApiKey, "Yoga");
            CalendarCheck diningCalendarCheck = new CalendarCheck(this, PrivateDiningCalendarID, googleApiKey, "Dining");
            CalendarCheck mediaCalendarCheck = new CalendarCheck(this, MediaRoomCalendarID, googleApiKey, "Media");
            CalendarCheck gamesCalendarCheck = new CalendarCheck(this, GamesRoomCalendarID, googleApiKey, "Games");

            yogaCalendarCheck.inMeeting += YogaCalendarCheck_inMeeting;
            diningCalendarCheck.inMeeting += DiningCalendarCheck_inMeeting;
            mediaCalendarCheck.inMeeting += MediaCalendarCheck_inMeeting;
            gamesCalendarCheck.inMeeting += GamesCalendarCheck_inMeeting;
        }

        public override void InitializeSystem()
        {

            try
            {
                _SimplWindowsComms = new ThreeSeriesTcpIpEthernetIntersystemCommunications(0xB0, "127.0.0.2", this);
                _SimplWindowsComms.Register();
                _SimplWindowsComms.SigChange += _SimplWindowsComms_SigChange;

                if(this.SupportsRelay)
                {
                    this.RelayPorts[1].Register();
                    this.RelayPorts[2].Register();
                    this.RelayPorts[3].Register();
                    this.RelayPorts[4].Register();
                    this.RelayPorts[5].Register();
                    this.RelayPorts[6].Register();
                    this.RelayPorts[7].Register();
                    this.RelayPorts[8].Register();
                }
                if (this.SupportsVersiport)
                {
                    ConsoleLogger.WriteLine("Configuring versiport 1 as Digital In");
                    this.VersiPorts[1].Register();
                    if (this.VersiPorts[1].SupportsDigitalInput)
                        this.VersiPorts[1].SetVersiportConfiguration(eVersiportConfiguration.DigitalInput);

                    this.VersiPorts[1].VersiportChange += ControlSystem_VersiportChange; ;
                }
            }
            catch (Exception e)
            {
                ErrorLog.Error("Error in InitializeSystem: {0}", e.Message);
            }
        }

        private void ControlSystem_VersiportChange(Versiport port, VersiportEventArgs args)
        {
            ConsoleLogger.WriteLine("Port" + port.DeviceName + "state changed to: " + args.Event + "Digital In State: " + port.DigitalIn);
            SetFireAlarmState(port.DigitalIn);
        }
        public void SetFireAlarmState(bool state)
        {
            try
            {
                if (state)
                {
                    ConsoleLogger.WriteLine("Fire Alarm Cleared");
                    _fireAlarmState = false;
                }
                else
                {
                    ConsoleLogger.WriteLine("Fire Alarm Detected");
                    _fireAlarmState = true;

                    //Release All Door Holds
                    YogaDoorControl(false);
                    DiningDoorControl(false);
                    MediaRoomDoorControl(false);
                    GamesRoomDoorControl(false);
                }
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("Exception While Informing: " + ex);
            }
        }

        private void _SimplWindowsComms_SigChange(BasicTriList currentDevice, SigEventArgs args)
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

        public static void FreeviewBtnPress(string roomID, int btnNum)
        {
            string key = string.Empty;
            byte[] message = new byte[6];
            switch (btnNum)
            {
                //SOURCE
                case 0: key = "InputSelect"; break;
                //POWER
                case 1: key = "PowerToggle"; break;
                //1
                case 2: key = "1"; break;
                //2
                case 3: key = "2"; break;
                //3
                case 4: key = "3"; break;
                //VOL_UP
                case 5: key = "Vol+"; break;
                //4
                case 6: key = "4"; break;
                //5
                case 7: key = "5"; break;
                //6
                case 8: key = "6"; break;
                //VOL_DOWN
                case 9: key = "Vol-"; break;
                //7
                case 10: key = "7"; break;
                //8
                case 11: key = "8"; break;
                //9
                case 12: key = "9"; break;
                //MUTE
                case 13: key = "MuteToggle"; break;
                //CH_DOWN
                case 14: key = "Ch-"; break;
                //0
                case 15: key = "0"; break;
                //CH_UP
                case 16: key = "Ch+"; break;
                //GREEN
                case 17: key = "Green"; break;
                //YELLOW
                case 18: key = "Yellow"; break;
                //CYAN(BLUE)
                case 19: key = "Blue"; break;
                //MENU
                case 20: key = "Menu"; break;
                //DISPLAY
                case 21: key = "Display"; break;
                //DIGIT
                case 22: key = "Digit"; break;
                //PIP_TV_VIDEO
                case 23: key = "PIP"; break;
                //EXIT
                case 24: key = "Exit"; break;
                //REWND
                case 25: key = "Rewind"; break;
                //STOP
                case 26: key = "Stop"; break;
                //PLAY
                case 27: key = "Play"; break;
                //FAST_FORWARD
                case 28: key = "FastForward"; break;
                //PAUSE
                case 29: key = "Pause"; break;
                //TOOLS
                case 30: key = "Tools"; break;
                //RETURN
                case 31: key = "Return"; break;
                //MAGNIFICO_LITE
                case 32: key = "Magnifico"; break;
                //UP
                case 33: key = "Up"; break;
                //DOWN
                case 34: key = "Down"; break;
                //RIGHT
                case 35: key = "Right"; break;
                //LEFT
                case 36: key = "Left"; break;
                //ENTER
                case 37: key = "Enter"; break;
                //RED
                case 38: key = "Red"; break;
                //LOCK
                case 39: key = "Lock"; break;
                //CONTENT
                case 40: key = "Guide"; break;
                //DISCRETE_POWER_OFF
                case 41: key = "POFF"; break;
                //3D
                case 42: key = "3D"; break;
            }
            SendMessageToSIMPL("Room" + roomID + "TV1KP:" + key);
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