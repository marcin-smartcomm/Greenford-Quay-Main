namespace SSH_Interface_v1._7;
        // class declarations
         class SSH_Interface;
     class SSH_Interface 
    {
        // class delegates
        delegate FUNCTION StringToSimplPlus ( SIMPLSHARPSTRING Data );

        // class events

        // class functions
        FUNCTION Command_In ( STRING Data );
        FUNCTION Accept_Any_Key ( SIGNED_LONG_INTEGER AcceptAnyKey );
        FUNCTION Accept_New_Key ();
        FUNCTION Decline_New_Key ();
        FUNCTION Unique_ID ( SIGNED_LONG_INTEGER Id );
        FUNCTION SaveSettings ();
        FUNCTION LoadSettings ();
        FUNCTION Reconnect ( STRING Host , SIGNED_LONG_INTEGER Port , STRING Username , STRING Password );
        FUNCTION Connect ( STRING Host , SIGNED_LONG_INTEGER Port , STRING Username , STRING Password );
        FUNCTION Disconnect ();
        FUNCTION Debug ( SIGNED_LONG_INTEGER D );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        DelegateProperty StringToSimplPlus SendFromDevice;
        DelegateProperty StringToSimplPlus SendConnectionStatus;
        DelegateProperty StringToSimplPlus SendFingerprint;
    };

