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

namespace UserModule_PRISM_8X8_VOLUME_MODULE
{
    public class UserModuleClass_PRISM_8X8_VOLUME_MODULE : SplusObject
    {
        static CCriticalSection g_criticalSection = new CCriticalSection();
        
        
        UShortParameter CONTROLLER_ID__POUND__;
        Crestron.Logos.SplusObjects.AnalogInput VOL_IN__POUND__;
        Crestron.Logos.SplusObjects.StringOutput CMD_OUT__DOLLAR__;
        Crestron.Logos.SplusObjects.StringInput DSP_RX__DOLLAR__;
        Crestron.Logos.SplusObjects.AnalogOutput VOL_FB__POUND__;
        object VOL_IN__POUND___OnChange_0 ( Object __EventInfo__ )
        
            { 
            Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
            try
            {
                SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
                
                __context__.SourceCodeLine = 16;
                if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( CONTROLLER_ID__POUND__  .Value < 10 ))  ) ) 
                    {
                    __context__.SourceCodeLine = 17;
                    CMD_OUT__DOLLAR__  .UpdateValue ( "CS 0000" + Functions.ItoA (  (int) ( CONTROLLER_ID__POUND__  .Value ) ) + " " + Functions.ItoA (  (int) ( VOL_IN__POUND__  .UshortValue ) ) + "\u000D"  ) ; 
                    }
                
                else 
                    {
                    __context__.SourceCodeLine = 19;
                    CMD_OUT__DOLLAR__  .UpdateValue ( "CS 000" + Functions.ItoA (  (int) ( CONTROLLER_ID__POUND__  .Value ) ) + " " + Functions.ItoA (  (int) ( VOL_IN__POUND__  .UshortValue ) ) + "\u000D"  ) ; 
                    }
                
                
                
            }
            catch(Exception e) { ObjectCatchHandler(e); }
            finally { ObjectFinallyHandler( __SignalEventArg__ ); }
            return this;
            
        }
        
    object DSP_RX__DOLLAR___OnChange_1 ( Object __EventInfo__ )
    
        { 
        Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
        try
        {
            SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
            ushort NEWVOLPOS = 0;
            ushort NEWVOLINT = 0;
            
            CrestronString NEWVOLSTRING;
            NEWVOLSTRING  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 10, this );
            
            CrestronString MATCHSTRING;
            MATCHSTRING  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 10, this );
            
            
            __context__.SourceCodeLine = 28;
            MATCHSTRING  .UpdateValue ( "#" + Functions.ItoA (  (int) ( CONTROLLER_ID__POUND__  .Value ) )  ) ; 
            __context__.SourceCodeLine = 30;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( Functions.Find( MATCHSTRING , DSP_RX__DOLLAR__ ) > 0 ))  ) ) 
                { 
                __context__.SourceCodeLine = 32;
                NEWVOLPOS = (ushort) ( (Functions.Find( "%" , DSP_RX__DOLLAR__ ) - 8) ) ; 
                __context__.SourceCodeLine = 33;
                NEWVOLSTRING  .UpdateValue ( Functions.Mid ( DSP_RX__DOLLAR__ ,  (int) ( NEWVOLPOS ) ,  (int) ( 3 ) )  ) ; 
                __context__.SourceCodeLine = 34;
                VOL_FB__POUND__  .Value = (ushort) ( Functions.Atoi( NEWVOLSTRING ) ) ; 
                } 
            
            
            
        }
        catch(Exception e) { ObjectCatchHandler(e); }
        finally { ObjectFinallyHandler( __SignalEventArg__ ); }
        return this;
        
    }
    

public override void LogosSplusInitialize()
{
    _SplusNVRAM = new SplusNVRAM( this );
    
    VOL_IN__POUND__ = new Crestron.Logos.SplusObjects.AnalogInput( VOL_IN__POUND____AnalogSerialInput__, this );
    m_AnalogInputList.Add( VOL_IN__POUND____AnalogSerialInput__, VOL_IN__POUND__ );
    
    VOL_FB__POUND__ = new Crestron.Logos.SplusObjects.AnalogOutput( VOL_FB__POUND____AnalogSerialOutput__, this );
    m_AnalogOutputList.Add( VOL_FB__POUND____AnalogSerialOutput__, VOL_FB__POUND__ );
    
    DSP_RX__DOLLAR__ = new Crestron.Logos.SplusObjects.StringInput( DSP_RX__DOLLAR____AnalogSerialInput__, 1000, this );
    m_StringInputList.Add( DSP_RX__DOLLAR____AnalogSerialInput__, DSP_RX__DOLLAR__ );
    
    CMD_OUT__DOLLAR__ = new Crestron.Logos.SplusObjects.StringOutput( CMD_OUT__DOLLAR____AnalogSerialOutput__, this );
    m_StringOutputList.Add( CMD_OUT__DOLLAR____AnalogSerialOutput__, CMD_OUT__DOLLAR__ );
    
    CONTROLLER_ID__POUND__ = new UShortParameter( CONTROLLER_ID__POUND____Parameter__, this );
    m_ParameterList.Add( CONTROLLER_ID__POUND____Parameter__, CONTROLLER_ID__POUND__ );
    
    
    VOL_IN__POUND__.OnAnalogChange.Add( new InputChangeHandlerWrapper( VOL_IN__POUND___OnChange_0, false ) );
    DSP_RX__DOLLAR__.OnSerialChange.Add( new InputChangeHandlerWrapper( DSP_RX__DOLLAR___OnChange_1, false ) );
    
    _SplusNVRAM.PopulateCustomAttributeList( true );
    
    NVRAM = _SplusNVRAM;
    
}

public override void LogosSimplSharpInitialize()
{
    
    
}

public UserModuleClass_PRISM_8X8_VOLUME_MODULE ( string InstanceName, string ReferenceID, Crestron.Logos.SplusObjects.CrestronStringEncoding nEncodingType ) : base( InstanceName, ReferenceID, nEncodingType ) {}




const uint CONTROLLER_ID__POUND____Parameter__ = 10;
const uint VOL_IN__POUND____AnalogSerialInput__ = 0;
const uint CMD_OUT__DOLLAR____AnalogSerialOutput__ = 0;
const uint DSP_RX__DOLLAR____AnalogSerialInput__ = 1;
const uint VOL_FB__POUND____AnalogSerialOutput__ = 1;

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
