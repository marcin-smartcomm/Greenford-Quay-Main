using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Linq;
using Crestron;
using Crestron.Logos.SplusLibrary;
using Crestron.Logos.SplusObjects;
using Crestron.SimplSharp;

namespace UserModule_BGM_COMMS
{
    public class UserModuleClass_BGM_COMMS : SplusObject
    {
        static CCriticalSection g_criticalSection = new CCriticalSection();
        
        
        
        
        StringParameter ROOMIDENTIFIER;
        StringParameter MODE;
        Crestron.Logos.SplusObjects.AnalogInput ZONE1_VOL_FB__POUND__;
        Crestron.Logos.SplusObjects.AnalogInput ZONE2_VOL_FB__POUND__;
        Crestron.Logos.SplusObjects.AnalogInput ZONE3_VOL_FB__POUND__;
        Crestron.Logos.SplusObjects.AnalogInput ZONE4_VOL_FB__POUND__;
        Crestron.Logos.SplusObjects.StringInput RX__DOLLAR__;
        Crestron.Logos.SplusObjects.AnalogOutput ZONE1_VOLUME__POUND__;
        Crestron.Logos.SplusObjects.AnalogOutput ZONE2_VOLUME__POUND__;
        Crestron.Logos.SplusObjects.AnalogOutput ZONE3_VOLUME__POUND__;
        Crestron.Logos.SplusObjects.AnalogOutput ZONE4_VOLUME__POUND__;
        Crestron.Logos.SplusObjects.StringOutput TX__DOLLAR__;
        object RX__DOLLAR___OnChange_0 ( Object __EventInfo__ )
        
            { 
            Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
            try
            {
                SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
                
                __context__.SourceCodeLine = 23;
                if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Left( RX__DOLLAR__ , (int)( 3 ) ) == "BGM"))  ) ) 
                    { 
                    __context__.SourceCodeLine = 25;
                    if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( Functions.Find( ROOMIDENTIFIER  , RX__DOLLAR__ ) > 0 ))  ) ) 
                        { 
                        __context__.SourceCodeLine = 27;
                        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Mid( RX__DOLLAR__ , (int)( 12 ) , (int)( 6 ) ) == "Volume"))  ) ) 
                            { 
                            __context__.SourceCodeLine = 29;
                            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (MODE  == "multi"))  ) ) 
                                { 
                                __context__.SourceCodeLine = 31;
                                ZONE1_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 19 ) , (int)( 3 ) ) ) ) ; 
                                __context__.SourceCodeLine = 32;
                                Functions.Delay (  (int) ( 10 ) ) ; 
                                __context__.SourceCodeLine = 33;
                                ZONE2_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 19 ) , (int)( 3 ) ) ) ) ; 
                                __context__.SourceCodeLine = 34;
                                Functions.Delay (  (int) ( 10 ) ) ; 
                                __context__.SourceCodeLine = 35;
                                ZONE3_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 19 ) , (int)( 3 ) ) ) ) ; 
                                __context__.SourceCodeLine = 36;
                                Functions.Delay (  (int) ( 10 ) ) ; 
                                __context__.SourceCodeLine = 37;
                                ZONE4_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 19 ) , (int)( 3 ) ) ) ) ; 
                                } 
                            
                            __context__.SourceCodeLine = 39;
                            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (MODE  == "solo"))  ) ) 
                                { 
                                __context__.SourceCodeLine = 41;
                                ZONE1_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 19 ) , (int)( 3 ) ) ) ) ; 
                                } 
                            
                            } 
                        
                        __context__.SourceCodeLine = 44;
                        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Mid( RX__DOLLAR__ , (int)( 12 ) , (int)( 8 ) ) == "Zone1Vol"))  ) ) 
                            { 
                            __context__.SourceCodeLine = 46;
                            ZONE1_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 21 ) , (int)( 3 ) ) ) ) ; 
                            } 
                        
                        __context__.SourceCodeLine = 48;
                        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Mid( RX__DOLLAR__ , (int)( 12 ) , (int)( 8 ) ) == "Zone2Vol"))  ) ) 
                            { 
                            __context__.SourceCodeLine = 50;
                            ZONE2_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 21 ) , (int)( 3 ) ) ) ) ; 
                            } 
                        
                        __context__.SourceCodeLine = 53;
                        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Mid( RX__DOLLAR__ , (int)( 12 ) , (int)( 8 ) ) == "Zone3Vol"))  ) ) 
                            { 
                            __context__.SourceCodeLine = 55;
                            ZONE3_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 21 ) , (int)( 3 ) ) ) ) ; 
                            } 
                        
                        __context__.SourceCodeLine = 58;
                        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Mid( RX__DOLLAR__ , (int)( 12 ) , (int)( 8 ) ) == "Zone4Vol"))  ) ) 
                            { 
                            __context__.SourceCodeLine = 60;
                            ZONE4_VOLUME__POUND__  .Value = (ushort) ( Functions.Atoi( Functions.Mid( RX__DOLLAR__ , (int)( 21 ) , (int)( 3 ) ) ) ) ; 
                            } 
                        
                        } 
                    
                    } 
                
                
                
            }
            catch(Exception e) { ObjectCatchHandler(e); }
            finally { ObjectFinallyHandler( __SignalEventArg__ ); }
            return this;
            
        }
        
    object ZONE1_VOL_FB__POUND___OnChange_1 ( Object __EventInfo__ )
    
        { 
        Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
        try
        {
            SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
            
            __context__.SourceCodeLine = 68;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (MODE  == "multi"))  ) ) 
                {
                __context__.SourceCodeLine = 69;
                TX__DOLLAR__  .UpdateValue ( "BGM:" + ROOMIDENTIFIER + ":Zone1Volume:" + Functions.ItoA (  (int) ( ZONE1_VOL_FB__POUND__  .UshortValue ) )  ) ; 
                }
            
            __context__.SourceCodeLine = 71;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (MODE  == "solo"))  ) ) 
                {
                __context__.SourceCodeLine = 72;
                TX__DOLLAR__  .UpdateValue ( "BGM:" + ROOMIDENTIFIER + ":Volume:" + Functions.ItoA (  (int) ( ZONE1_VOL_FB__POUND__  .UshortValue ) )  ) ; 
                }
            
            
            
        }
        catch(Exception e) { ObjectCatchHandler(e); }
        finally { ObjectFinallyHandler( __SignalEventArg__ ); }
        return this;
        
    }
    
object ZONE2_VOL_FB__POUND___OnChange_2 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        
        __context__.SourceCodeLine = 77;
        TX__DOLLAR__  .UpdateValue ( "BGM:" + ROOMIDENTIFIER + ":Zone2Volume:" + Functions.ItoA (  (int) ( ZONE2_VOL_FB__POUND__  .UshortValue ) )  ) ; 
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object ZONE3_VOL_FB__POUND___OnChange_3 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        
        __context__.SourceCodeLine = 83;
        TX__DOLLAR__  .UpdateValue ( "BGM:" + ROOMIDENTIFIER + ":Zone3Volume:" + Functions.ItoA (  (int) ( ZONE3_VOL_FB__POUND__  .UshortValue ) )  ) ; 
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object ZONE4_VOL_FB__POUND___OnChange_4 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        
        __context__.SourceCodeLine = 89;
        TX__DOLLAR__  .UpdateValue ( "BGM:" + ROOMIDENTIFIER + ":Zone4Volume:" + Functions.ItoA (  (int) ( ZONE4_VOL_FB__POUND__  .UshortValue ) )  ) ; 
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}


public override void LogosSplusInitialize()
{
    SocketInfo __socketinfo__ = new SocketInfo( 1, this );
    InitialParametersClass.ResolveHostName = __socketinfo__.ResolveHostName;
    _SplusNVRAM = new SplusNVRAM( this );
    
    ZONE1_VOL_FB__POUND__ = new Crestron.Logos.SplusObjects.AnalogInput( ZONE1_VOL_FB__POUND____AnalogSerialInput__, this );
    m_AnalogInputList.Add( ZONE1_VOL_FB__POUND____AnalogSerialInput__, ZONE1_VOL_FB__POUND__ );
    
    ZONE2_VOL_FB__POUND__ = new Crestron.Logos.SplusObjects.AnalogInput( ZONE2_VOL_FB__POUND____AnalogSerialInput__, this );
    m_AnalogInputList.Add( ZONE2_VOL_FB__POUND____AnalogSerialInput__, ZONE2_VOL_FB__POUND__ );
    
    ZONE3_VOL_FB__POUND__ = new Crestron.Logos.SplusObjects.AnalogInput( ZONE3_VOL_FB__POUND____AnalogSerialInput__, this );
    m_AnalogInputList.Add( ZONE3_VOL_FB__POUND____AnalogSerialInput__, ZONE3_VOL_FB__POUND__ );
    
    ZONE4_VOL_FB__POUND__ = new Crestron.Logos.SplusObjects.AnalogInput( ZONE4_VOL_FB__POUND____AnalogSerialInput__, this );
    m_AnalogInputList.Add( ZONE4_VOL_FB__POUND____AnalogSerialInput__, ZONE4_VOL_FB__POUND__ );
    
    ZONE1_VOLUME__POUND__ = new Crestron.Logos.SplusObjects.AnalogOutput( ZONE1_VOLUME__POUND____AnalogSerialOutput__, this );
    m_AnalogOutputList.Add( ZONE1_VOLUME__POUND____AnalogSerialOutput__, ZONE1_VOLUME__POUND__ );
    
    ZONE2_VOLUME__POUND__ = new Crestron.Logos.SplusObjects.AnalogOutput( ZONE2_VOLUME__POUND____AnalogSerialOutput__, this );
    m_AnalogOutputList.Add( ZONE2_VOLUME__POUND____AnalogSerialOutput__, ZONE2_VOLUME__POUND__ );
    
    ZONE3_VOLUME__POUND__ = new Crestron.Logos.SplusObjects.AnalogOutput( ZONE3_VOLUME__POUND____AnalogSerialOutput__, this );
    m_AnalogOutputList.Add( ZONE3_VOLUME__POUND____AnalogSerialOutput__, ZONE3_VOLUME__POUND__ );
    
    ZONE4_VOLUME__POUND__ = new Crestron.Logos.SplusObjects.AnalogOutput( ZONE4_VOLUME__POUND____AnalogSerialOutput__, this );
    m_AnalogOutputList.Add( ZONE4_VOLUME__POUND____AnalogSerialOutput__, ZONE4_VOLUME__POUND__ );
    
    RX__DOLLAR__ = new Crestron.Logos.SplusObjects.StringInput( RX__DOLLAR____AnalogSerialInput__, 100, this );
    m_StringInputList.Add( RX__DOLLAR____AnalogSerialInput__, RX__DOLLAR__ );
    
    TX__DOLLAR__ = new Crestron.Logos.SplusObjects.StringOutput( TX__DOLLAR____AnalogSerialOutput__, this );
    m_StringOutputList.Add( TX__DOLLAR____AnalogSerialOutput__, TX__DOLLAR__ );
    
    ROOMIDENTIFIER = new StringParameter( ROOMIDENTIFIER__Parameter__, this );
    m_ParameterList.Add( ROOMIDENTIFIER__Parameter__, ROOMIDENTIFIER );
    
    MODE = new StringParameter( MODE__Parameter__, this );
    m_ParameterList.Add( MODE__Parameter__, MODE );
    
    
    RX__DOLLAR__.OnSerialChange.Add( new InputChangeHandlerWrapper( RX__DOLLAR___OnChange_0, false ) );
    ZONE1_VOL_FB__POUND__.OnAnalogChange.Add( new InputChangeHandlerWrapper( ZONE1_VOL_FB__POUND___OnChange_1, false ) );
    ZONE2_VOL_FB__POUND__.OnAnalogChange.Add( new InputChangeHandlerWrapper( ZONE2_VOL_FB__POUND___OnChange_2, false ) );
    ZONE3_VOL_FB__POUND__.OnAnalogChange.Add( new InputChangeHandlerWrapper( ZONE3_VOL_FB__POUND___OnChange_3, false ) );
    ZONE4_VOL_FB__POUND__.OnAnalogChange.Add( new InputChangeHandlerWrapper( ZONE4_VOL_FB__POUND___OnChange_4, false ) );
    
    _SplusNVRAM.PopulateCustomAttributeList( true );
    
    NVRAM = _SplusNVRAM;
    
}

public override void LogosSimplSharpInitialize()
{
    
    
}

public UserModuleClass_BGM_COMMS ( string InstanceName, string ReferenceID, Crestron.Logos.SplusObjects.CrestronStringEncoding nEncodingType ) : base( InstanceName, ReferenceID, nEncodingType ) {}




const uint ROOMIDENTIFIER__Parameter__ = 10;
const uint MODE__Parameter__ = 11;
const uint ZONE1_VOL_FB__POUND____AnalogSerialInput__ = 0;
const uint ZONE2_VOL_FB__POUND____AnalogSerialInput__ = 1;
const uint ZONE3_VOL_FB__POUND____AnalogSerialInput__ = 2;
const uint ZONE4_VOL_FB__POUND____AnalogSerialInput__ = 3;
const uint RX__DOLLAR____AnalogSerialInput__ = 4;
const uint ZONE1_VOLUME__POUND____AnalogSerialOutput__ = 0;
const uint ZONE2_VOLUME__POUND____AnalogSerialOutput__ = 1;
const uint ZONE3_VOLUME__POUND____AnalogSerialOutput__ = 2;
const uint ZONE4_VOLUME__POUND____AnalogSerialOutput__ = 3;
const uint TX__DOLLAR____AnalogSerialOutput__ = 4;

[SplusStructAttribute(-1, true, false)]
public class SplusNVRAM : SplusStructureBase
{

    public SplusNVRAM( SplusObject __caller__ ) : base( __caller__ ) {}
    
    
}

SplusNVRAM _SplusNVRAM = null;

public class __CEvent__ : CEvent
{
    public __CEvent__() {}
    public void Close() { base.Close(); }
    public int Reset() { return base.Reset() ? 1 : 0; }
    public int Set() { return base.Set() ? 1 : 0; }
    public int Wait( int timeOutInMs ) { return base.Wait( timeOutInMs ) ? 1 : 0; }
}
public class __CMutex__ : CMutex
{
    public __CMutex__() {}
    public void Close() { base.Close(); }
    public void ReleaseMutex() { base.ReleaseMutex(); }
    public int WaitForMutex() { return base.WaitForMutex() ? 1 : 0; }
}
 public int IsNull( object obj ){ return (obj == null) ? 1 : 0; }
}


}
