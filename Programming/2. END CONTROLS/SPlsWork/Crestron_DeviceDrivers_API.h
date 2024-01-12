namespace Crestron.DeviceDrivers.API;
        // class declarations
         class LogEntryLevel;
    static class LogEntryLevel // enum
    {
        static SIGNED_LONG_INTEGER Off;
        static SIGNED_LONG_INTEGER Error;
        static SIGNED_LONG_INTEGER Warning;
        static SIGNED_LONG_INTEGER Info;
        static SIGNED_LONG_INTEGER Debug;
        static SIGNED_LONG_INTEGER Trace;
    };

namespace Crestron.DeviceDrivers.API.DataStructures.Units;
        // class declarations
         class TemperatureUnit;
         class EnumExtensions;
         class Temperature;
    static class TemperatureUnit // enum
    {
        static SIGNED_LONG_INTEGER Unknown;
        static SIGNED_LONG_INTEGER Fahrenheit;
        static SIGNED_LONG_INTEGER Celsius;
        static SIGNED_LONG_INTEGER Kelvin;
    };

    static class EnumExtensions 
    {
        // class delegates

        // class events

        // class functions
        static STRING_FUNCTION ToUnitsAbbreviation ( TemperatureUnit units );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

namespace Crestron.DeviceDrivers.API.Collections;
        // class declarations
         class ImmutableArray;
         class ImmutableDictionary;
    static class ImmutableArray 
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

    static class ImmutableDictionary 
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

namespace Crestron.DeviceDrivers.API.Capabilities;
        // class declarations
         class DeviceLicense;
         class DeviceLicenseStatus;
         class ValueLimit;
    static class DeviceLicenseStatus // enum
    {
        static SIGNED_LONG_INTEGER Unknown;
        static SIGNED_LONG_INTEGER Active;
        static SIGNED_LONG_INTEGER Inactive;
        static SIGNED_LONG_INTEGER Expired;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.PowerManagement;
        // class declarations
         class PingMonitoringFeatures;
         class PingTargetRebootMode;
         class PowerBankFeatures;
         class PowerBankContainerFeatures;
         class PowerBankControlFeatures;
         class PowerBankControlMode;
         class PowerFaults;
         class PowerFaultFeatures;
         class PowerMeteringFeatures;
         class PoweredDeviceTraits;
         class RebootCapabilityFeatures;
         class RebootStatus;
         class PowerOverEthernetPortFeatures;
         class DeviceAttachmentStatus;
    static class PingMonitoringFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER SetRebootMode;
        static SIGNED_LONG_INTEGER PingTimeout;
        static SIGNED_LONG_INTEGER PingRetries;
        static SIGNED_LONG_INTEGER PingInterval;
        static SIGNED_LONG_INTEGER PingDelay;
        static SIGNED_LONG_INTEGER RebootAttempts;
        static SIGNED_LONG_INTEGER FailedPingAttempts;
    };

    static class PingTargetRebootMode // enum
    {
        static SIGNED_LONG_INTEGER Uninitialized;
        static SIGNED_LONG_INTEGER AnyOffline;
        static SIGNED_LONG_INTEGER AllOffline;
    };

    static class PowerBankFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER GetName;
        static SIGNED_LONG_INTEGER SetName;
    };

    static class PowerBankContainerFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER PowerOnSequence;
    };

    static class PowerBankControlFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER DiscretePower;
        static SIGNED_LONG_INTEGER TogglePower;
        static SIGNED_LONG_INTEGER PowerFeedback;
        static SIGNED_LONG_INTEGER CyclePower;
        static SIGNED_LONG_INTEGER CyclePowerDelay;
        static SIGNED_LONG_INTEGER PowerOnDelay;
        static SIGNED_LONG_INTEGER ControlMode;
    };

    static class PowerBankControlMode // enum
    {
        static SIGNED_LONG_INTEGER FullControl;
        static SIGNED_LONG_INTEGER CycleOnly;
    };

    static class PowerFaults // enum
    {
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER Unspecified;
        static SIGNED_LONG_INTEGER UnderVoltage;
        static SIGNED_LONG_INTEGER OverVoltage;
        static SIGNED_LONG_INTEGER OverCurrent;
        static SIGNED_LONG_INTEGER OverTemperature;
        static SIGNED_LONG_INTEGER OverHumidity;
        static SIGNED_LONG_INTEGER SurgeDetected;
        static SIGNED_LONG_INTEGER SurgeProtectionCompromised;
        static SIGNED_LONG_INTEGER WiringFault;
    };

    static class PowerFaultFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER UnderVoltageFault;
        static SIGNED_LONG_INTEGER UnderVoltageThreshold;
        static SIGNED_LONG_INTEGER OverVoltageFault;
        static SIGNED_LONG_INTEGER OverVoltageThreshold;
        static SIGNED_LONG_INTEGER OverCurrentFault;
        static SIGNED_LONG_INTEGER OverCurrentThreshold;
        static SIGNED_LONG_INTEGER OverTemperatureFault;
        static SIGNED_LONG_INTEGER OverTemperatureThreshold;
        static SIGNED_LONG_INTEGER OverHumidityFault;
        static SIGNED_LONG_INTEGER OverHumidityThreshold;
        static SIGNED_LONG_INTEGER SurgeDetectedFault;
        static SIGNED_LONG_INTEGER SurgeProtectionCompromisedFault;
        static SIGNED_LONG_INTEGER WiringFault;
    };

    static class PowerMeteringFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER Amperage;
        static SIGNED_LONG_INTEGER Voltage;
        static SIGNED_LONG_INTEGER Frequency;
        static SIGNED_LONG_INTEGER Power;
        static SIGNED_LONG_INTEGER EnergyConsumption;
        static SIGNED_LONG_INTEGER ResetEnergyConsumption;
        static SIGNED_LONG_INTEGER Temperature;
        static SIGNED_LONG_INTEGER Humidity;
    };

    static class PoweredDeviceTraits // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER NotPluggable;
    };

    static class RebootCapabilityFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER RebootFeedback;
    };

    static class RebootStatus // enum
    {
        static SIGNED_LONG_INTEGER Unknown;
        static SIGNED_LONG_INTEGER Idle;
        static SIGNED_LONG_INTEGER Rebooting;
    };

    static class PowerOverEthernetPortFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER DeviceAttached;
        static SIGNED_LONG_INTEGER PowerClass;
        static SIGNED_LONG_INTEGER EffectivePowerAllocation;
    };

    static class DeviceAttachmentStatus // enum
    {
        static SIGNED_LONG_INTEGER Uninitialized;
        static SIGNED_LONG_INTEGER NotAttached;
        static SIGNED_LONG_INTEGER Attached;
        static SIGNED_LONG_INTEGER Indeterminate;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.Networking;
        // class declarations
         class EthernetDuplexMode;
         class NetworkAdapterInformationFeatures;
         class NetworkPortControlFeatures;
         class NetworkPortStatusFeatures;
         class EthernetPhysicalProperties;
         class NetworkAdapterInfo;
    static class EthernetDuplexMode // enum
    {
        static SIGNED_LONG_INTEGER Unknown;
        static SIGNED_LONG_INTEGER Half;
        static SIGNED_LONG_INTEGER Full;
    };

    static class NetworkAdapterInformationFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER NetworkAdapters;
    };

    static class NetworkPortControlFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER GetIsPortEnabled;
        static SIGNED_LONG_INTEGER SetIsPortEnabled;
    };

    static class NetworkPortStatusFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER IsLinkUp;
        static SIGNED_LONG_INTEGER PhysicalStatus;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.Events;
        // class declarations
         class CollectionChangedAction;
    static class CollectionChangedAction // enum
    {
        static SIGNED_LONG_INTEGER Added;
        static SIGNED_LONG_INTEGER Removed;
        static SIGNED_LONG_INTEGER Replaced;
        static SIGNED_LONG_INTEGER Reset;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.Errors;
        // class declarations
         class DeviceErrorCode;
         class DeviceErrorCodeSeverity;
    static class DeviceErrorCodeSeverity // enum
    {
        static SIGNED_LONG_INTEGER Unknown;
        static SIGNED_LONG_INTEGER Error;
        static SIGNED_LONG_INTEGER Warning;
        static SIGNED_LONG_INTEGER Info;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.Diagnostics;
        // class declarations
         class ComponentTemperatureStatus;
         class ComputePlatformDiagnosticsFeatures;
         class SystemCoolingFanStatus;
    static class ComputePlatformDiagnosticsFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER CpuUsagePercent;
        static SIGNED_LONG_INTEGER RamUsagePercent;
        static SIGNED_LONG_INTEGER FanStatus;
        static SIGNED_LONG_INTEGER ComponentTemperature;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.Conferencing;
        // class declarations
         class ConferenceCallControlsFeatures;
         class ConferenceCallMicInputFeatures;
         class DeviceCustomUiFeatures;
         class DeviceWithExternalMediaSourcesFeatures;
         class ExternalMediaSourceConnector;
         class ExternalMediaSourceIcon;
         class ExternalSourceInfo;
         class ExternalSourceRoutedEventArgs;
         class WidgetStateChangedEventArgs;
    static class ConferenceCallControlsFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER IsCallActive;
        static SIGNED_LONG_INTEGER IsSharingContent;
        static SIGNED_LONG_INTEGER AvailableContentSources;
        static SIGNED_LONG_INTEGER EndCall;
        static SIGNED_LONG_INTEGER ShareRemoteContent;
    };

    static class ConferenceCallMicInputFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER OnOff;
        static SIGNED_LONG_INTEGER Toggle;
        static SIGNED_LONG_INTEGER Feedback;
    };

    static class DeviceCustomUiFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER GetWidgetStates;
        static SIGNED_LONG_INTEGER SetWidgetStates;
        static SIGNED_LONG_INTEGER UploadUiDefinition;
        static SIGNED_LONG_INTEGER RemoveUiDefinition;
        static SIGNED_LONG_INTEGER Id;
        static SIGNED_LONG_INTEGER SupportedUiDefinitionsFormats;
        static SIGNED_LONG_INTEGER OpenUiPanel;
    };

    static class DeviceWithExternalMediaSourcesFeatures // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER AddRemoveExternalSource;
        static SIGNED_LONG_INTEGER SetStatus;
        static SIGNED_LONG_INTEGER AvailableConnectors;
        static SIGNED_LONG_INTEGER AvailableIcons;
        static SIGNED_LONG_INTEGER RemoveAllExternalSources;
    };

namespace Crestron.DeviceDrivers.API.Capabilities.AudioMixer;
        // class declarations
         class AudioCrosspointId;
         class AudioMixerCrosspointGainChangedEventArgs;
         class CrosspointData;
         class MediaConnector;

namespace Crestron.DeviceDrivers.API.Capabilities.VoiceControl;
        // class declarations

namespace Crestron.DeviceDrivers.API.Capabilities.Communications;
        // class declarations

