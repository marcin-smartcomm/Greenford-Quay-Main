namespace Crestron.DeviceDrivers.SDK.Transports.Cip;
        // class declarations
         class CipClientTransport;
         class CipClientTransportFactory;
     class CipClientTransportFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

namespace Crestron.DeviceDrivers.SDK.Transports.Cip.ActiveCNX;
        // class declarations
         class ActiveCNXEventArgs;
         class ActiveCNXErrorEventArgs;
         class ActiveCNXConnectionEventArgs;
         class ActiveCNXCertificateEventArgs;
         class ActiveCNXIncomingConnectEventArgs;
         class ActiveCNXIdentificationEventArgs;
         class ActiveCNX;
         class BackgroundTaskQueue;
     class ActiveCNXIncomingConnectEventArgs 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING ConnectionInfo[];
        SIGNED_LONG_INTEGER IPID;
    };

     class ActiveCNXIdentificationEventArgs 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING MACAddress[];
        STRING ProgramInstanceId[];
        STRING DeviceHostName[];
        STRING Slots[];
    };

     class ActiveCNX 
    {
        // class delegates

        // class events
        EventHandler onCertVerification ( ActiveCNX sender, ActiveCNXCertificateEventArgs e );
        EventHandler onDigital ( ActiveCNX sender, ActiveCNXEventArgs e );
        EventHandler onAnalog ( ActiveCNX sender, ActiveCNXEventArgs e );
        EventHandler onSerial ( ActiveCNX sender, ActiveCNXEventArgs e );
        EventHandler onError ( ActiveCNX sender, ActiveCNXErrorEventArgs e );
        EventHandler onConnect ( ActiveCNX sender, ActiveCNXConnectionEventArgs e );
        EventHandler onDisconnect ( ActiveCNX sender, ActiveCNXConnectionEventArgs e );
        EventHandler onIncomingConnect ( ActiveCNX sender, ActiveCNXIncomingConnectEventArgs e );
        EventHandler onCIPIdentification ( ActiveCNX sender, ActiveCNXIdentificationEventArgs e );

        // class functions
        FUNCTION CreateDisconnectResponsePacket ();
        static STRING_FUNCTION StackTraceToString ();
        FUNCTION Connect ();
        FUNCTION InitiateReceive ();
        FUNCTION Disconnect ();
        FUNCTION UpdateRequest ();
        FUNCTION SendProgramReady ();
        FUNCTION Deactivate ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        SIGNED_LONG_INTEGER NumberOfAnalogSignalsReceived;
        SIGNED_LONG_INTEGER NumberOfDigitalSignalsReceived;
        SIGNED_LONG_INTEGER NumberOfSerialSignalsReceived;
        STRING m_strAuthenticated[];
        STRING m_strMutuallyAuthenticated[];
        STRING m_strStreamEncrypted[];
        STRING m_strStreamSigned[];
        SIGNED_LONG_INTEGER LocalPort;
        SIGNED_LONG_INTEGER m_iRemotePort;
        STRING m_MACAddress[];
        STRING m_ProgramInstanceId[];
        STRING m_MftID[];
        STRING m_ModelID[];
        STRING m_DeviceHostName[];
        STRING m_Slots[];

        // class properties
        STRING IPAddress[];
        SIGNED_LONG_INTEGER MaxLength;
    };

     class BackgroundTaskQueue 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION RemoveData ( STRING key );
        STRING_FUNCTION ToString ();
        FUNCTION Dispose ();
        FUNCTION Cancel ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Name[];
    };

namespace Crestron.DeviceDrivers.SDK.Responses;
        // class declarations
         class CipInterlockJoinProcessorInfo;
         class CipJoinProcessorType;
         class CipJoinResponseProcessingNode;
         class CipJoinSelectProcessor;
         class CipJoinSelectProcessorInfo;
         class CipInterlockJoinProcessorInfoTypeFactory;
         class CipDigitalJoinProcessorFactory;
         class CipAnalogJoinProcessorFactory;
         class CipSerialJoinProcessorFactory;
         class CipInterlockJoinProcessorFactory;
         class CipJoinProcessorFactory;
         class CipJoinSelectProcessorInfoTypeFactory;
     class CipInterlockJoinProcessorInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

    static class CipJoinProcessorType // enum
    {
        static SIGNED_LONG_INTEGER Digital;
        static SIGNED_LONG_INTEGER Analog;
        static SIGNED_LONG_INTEGER Serial;
        static SIGNED_LONG_INTEGER Interlock;
    };

     class CipJoinSelectProcessor 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING ResponseTypeName[];

        // class properties
        STRING Name[];
    };

     class CipJoinSelectProcessorInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipInterlockJoinProcessorInfoTypeFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipDigitalJoinProcessorFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipAnalogJoinProcessorFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipSerialJoinProcessorFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipInterlockJoinProcessorFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipJoinProcessorFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CipJoinSelectProcessorInfoTypeFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

