namespace Crestron.DeviceDrivers.SDK;
        // class declarations
         class CommandBuilderArgs;
         class ControlCommandRuleExecution;
         class ControlCommand;
         class FeedbackRuleExecution;
         class StateChangeRuleExecution;
         class WillSendRuleExecution;
         class DidSendRuleExecution;
         class CommandComponentArgs;
         class ComponentArgs;
         class CommandData;
         class CommandDefinition;
         class ImplementationInfo;
         class CommandIdDefinition;
         class CommandRequest;
         class CommandTransportInfoTypeResolver;
         class CommandWithValues;
         class CustomCommandBuilder;
         class DeviceTargetStateLookupOverride;
         class CommandIdRolloverBehavior;
         class CommandResponseExpectation;
         class IntegerCommandId;
         class IntegerCommandIdFactory;
         class TransportInfoCommand;
         class ConditionComponentArgs;
         class ConditionDefinition;
         class CommandRepeatTiming;
         class ControllerAdditionalState;
         class ControllerCommandSet;
         class ControllerComponentArgs;
         class ControllerDefinition;
         class ControllerProperty;
         class StateCommand;
         class PollingConfiguration;
         class NumericControllerScales;
         class StateCommandRepeatTiming;
         class AResponseProcessingNode;
         class CommandDecodeResponseProcessor;
         class CommandDecodeResponseProcessorFactory;
         class CommandResponse;
         class ProcessingBehavior;
         class SelectType;
         class ConditionType;
         class ResponseProcessingNodeResult;
         class ResponseProcessingStepStatus;
         class ResponseComponentArgs;
         class ResponseProcessingContext;
         class ResponseProcessingDefinition;
         class ResponseProcessingNode;
         class ResponseProcessingNodeInfo;
         class ResponseProcessorData;
         class ResponseStreamReader;
         class ResponseReaderWrapper;
         class RuleComponentArgs;
         class RuleConditionChecker;
         class RuleDefinition;
         class RuleTriggerTypes;
         class TransformationCall;
         class TransformationComponentArgs;
         class TransformationException;
         class TransformCallDefinition;
         class TransformDefinition;
         class CommandIdValueLookup;
         class EmptyResponseData;
         class EmptyTransportInfoBuilder;
         class TransportType;
         class GenericStreamTransport;
         class TransportBase;
         class PacketTransportCoordinator;
         class TransportCoordinator;
         class StandaloneCommandCoordinator;
         class StreamTransportCoordinator;
         class TransportComponentArgs;
         class TransportCoordinatorArgs;
         class TransportDefinition;
         class TransportInfo;
         class TransportInfoComponentArgs;
         class TransportWatchDog;
         class InputUserAttributeInfo;
         class InputUserAttributeInfoInfoTypeFactory;
         class ConnectionRequirement;
         class InputDataType;
         class UserAttributeDefinition;
         class ConnectionController;
         class CoordinatorProviderArgs;
         class CoordinatorInitialData;
         class CoordinatorBaseData;
         class CoordinatorTransportData;
         class CoordinatorTransformationData;
         class CoordinatorConditionData;
         class CoordinatorCommandData;
         class CoordinatorProviderData;
         class DriverCoordinator;
         class DriverCoordinatorProvider;
         class DriverCoordinatorException;
         class StateVariables;
         class SupportedFeatureDefinition;
         class BasicTemplateString;
         class NoTemplateString;
         class StringFormatterLookup;
         class TemplateParameter;
         class TemplateString;
         class ComponentLogger;
         class DriverLogger;
         class LoggingConstants;
         class ConfigurationDefinition;
         class DeveloperInformationDefinition;
         class DriverDefinition;
         class BaseDefinitionType;
         class ParameterVisibility;
         class StringType;
         class ParameterUnit;
         class ProcessorPlatform;
         class DeviceType;
         class GeneralInformationDefinition;
         class InputOutputDefinition;
         class NamedDefinition;
         class TypedDefinition;
         class Serialization;
           class StateChangedEventArgs;
           class BooleanEventArgs;
           class TransportRxEventArgs;
           class FeedbackEventArgs;
           class StateChangeSetEventArgs;
           class LogEventArgs;
           class LogEntryLevelChangedArgs;
     class ControlCommandRuleExecution 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION AddCommand ( ControlCommand command );
        FUNCTION Block ();
        FUNCTION RemoveOriginalCommandWithoutBlocking ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        ControlCommand OriginalCommand;
    };

     class FeedbackRuleExecution 
    {
        // class delegates
        delegate STRING_FUNCTION ValueLookup ( STRING parameterId , STRING format );

        // class events

        // class functions
        STRING_FUNCTION GetFeedbackValue ( STRING name );
        STRING_FUNCTION GetOriginalFeedbackValue ( STRING name );
        FUNCTION ModifyValue ( STRING name , STRING value );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        DelegateProperty ValueLookup PresentStateAfterFeedback;
    };

     class StateChangeRuleExecution 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION SetFeedbackValue ( STRING name , STRING value );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        StateChangedEventArgs ChangeEvent;
    };

     class WillSendRuleExecution 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Block ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class DidSendRuleExecution 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION AddControlCommand ( ControlCommand command );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING OriginalCommandName[];
    };

     class ComponentArgs 
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

     class CommandDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Transport[];
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class ImplementationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class CommandIdDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        CommandIdRolloverBehavior Rollover;
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class CommandTransportInfoTypeResolver 
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

    static class CommandIdRolloverBehavior // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER Reconnect;
    };

    static class CommandResponseExpectation // enum
    {
        static SIGNED_LONG_INTEGER Unknown;
        static SIGNED_LONG_INTEGER HasResponse;
        static SIGNED_LONG_INTEGER HasNoResponse;
    };

     class IntegerCommandIdFactory 
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

     class ConditionDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class CommandRepeatTiming 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        LONG_INTEGER RepeatDelay;
        LONG_INTEGER RepeatHoldOff;
    };

     class ControllerDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        LONG_INTEGER CommandRetryCount;
        LONG_INTEGER DeviceProcessingTime;
        LONG_INTEGER PollingHoldoffTime;
        LONG_INTEGER FeedbackHoldoffTime;
        LONG_INTEGER PollingInterval;
        PollingConfiguration PollingConfiguration;
        STRING InvalidationFeedback[];
        STRING ValuesWithoutFeedback[];
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

    static class StateCommand // enum
    {
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER Set;
        static SIGNED_LONG_INTEGER Toggle;
        static SIGNED_LONG_INTEGER Increment;
        static SIGNED_LONG_INTEGER Decrement;
        static SIGNED_LONG_INTEGER PressAndHold;
        static SIGNED_LONG_INTEGER HoldIncrement;
        static SIGNED_LONG_INTEGER HoldDecrement;
        static SIGNED_LONG_INTEGER CycleUp;
        static SIGNED_LONG_INTEGER CycleDown;
        static SIGNED_LONG_INTEGER HoldCycleUp;
        static SIGNED_LONG_INTEGER HoldCycleDown;
        static SIGNED_LONG_INTEGER Release;
        static SIGNED_LONG_INTEGER SetToDefault;
        static SIGNED_LONG_INTEGER SetTimeout;
        static SIGNED_LONG_INTEGER PresetCycleUp;
        static SIGNED_LONG_INTEGER PresetCycleDown;
        static SIGNED_LONG_INTEGER PresetHoldCycleUp;
        static SIGNED_LONG_INTEGER PresetHoldCycleDown;
        static SIGNED_LONG_INTEGER PresetStore;
        static SIGNED_LONG_INTEGER PresetRecall;
        static SIGNED_LONG_INTEGER SendCommand;
        static SIGNED_LONG_INTEGER SendCustomCommand;
        static SIGNED_LONG_INTEGER Connect;
        static SIGNED_LONG_INTEGER Disconnect;
        static SIGNED_LONG_INTEGER ProvideGenericStreamTransport;
        static SIGNED_LONG_INTEGER SetBand;
        static SIGNED_LONG_INTEGER ProvideCustomTransport;
        static SIGNED_LONG_INTEGER Push;
        static SIGNED_LONG_INTEGER CycleOffOn;
        static SIGNED_LONG_INTEGER Get;
        static SIGNED_LONG_INTEGER Begin;
        static SIGNED_LONG_INTEGER End;
        static SIGNED_LONG_INTEGER CustomCommandBase;
    };

    static class PollingConfiguration // enum
    {
        static SIGNED_LONG_INTEGER Always;
        static SIGNED_LONG_INTEGER Never;
        static SIGNED_LONG_INTEGER IfUnknown;
    };

    static class NumericControllerScales // enum
    {
        static SIGNED_LONG_INTEGER Level;
        static SIGNED_LONG_INTEGER Decibels;
        static SIGNED_LONG_INTEGER Percent;
        static SIGNED_LONG_INTEGER UShortScale;
        static SIGNED_LONG_INTEGER Other;
    };

     class StateCommandRepeatTiming 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        StateCommand Command;
        LONG_INTEGER RepeatDelay;
        LONG_INTEGER RepeatHoldOff;
    };

     class AResponseProcessingNode 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Initialize ( ResponseComponentArgs args );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Name[];
    };

     class CommandDecodeResponseProcessorFactory 
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

    static class ProcessingBehavior // enum
    {
        static SIGNED_LONG_INTEGER UntilMatch;
        static SIGNED_LONG_INTEGER Continue;
        static SIGNED_LONG_INTEGER Stop;
    };

    static class SelectType // enum
    {
        static SIGNED_LONG_INTEGER All;
        static SIGNED_LONG_INTEGER Any;
        static SIGNED_LONG_INTEGER IfPresent;
    };

    static class ConditionType // enum
    {
        static SIGNED_LONG_INTEGER Match;
        static SIGNED_LONG_INTEGER Ack;
    };

    static class ResponseProcessingNodeResult // enum
    {
        static SIGNED_LONG_INTEGER Incomplete;
        static SIGNED_LONG_INTEGER Match;
        static SIGNED_LONG_INTEGER ContinueMatch;
        static SIGNED_LONG_INTEGER NoMatch;
        static SIGNED_LONG_INTEGER StopNoMatch;
    };

    static class ResponseProcessingStepStatus // enum
    {
        static SIGNED_LONG_INTEGER Incomplete;
        static SIGNED_LONG_INTEGER Match;
        static SIGNED_LONG_INTEGER NoMatch;
    };

     class ResponseProcessingDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Condition[];
        ConditionType ConditionType;
        STRING Match[];
        STRING Output[];
        ProcessingBehavior Processing;
        SelectType SelectType;
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class ResponseProcessingNodeInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        ResponseProcessorData ProcessorData;
        ProcessingBehavior Processing;
        STRING MatchOutput[];
        SelectType SelectType;
        ConditionType ConditionType;
    };

     class RuleDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING AppliesTo[];
        STRING Condition[];
        STRING Except[];
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

    static class RuleTriggerTypes // enum
    {
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER ControlCommand;
        static SIGNED_LONG_INTEGER Feedback;
        static SIGNED_LONG_INTEGER StateChange;
        static SIGNED_LONG_INTEGER WillSend;
        static SIGNED_LONG_INTEGER DidSend;
    };

     class TransformCallDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Input[];
        STRING Output[];
        STRING Transformation[];
    };

     class TransformDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class EmptyResponseData 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static Crestron.DeviceDrivers.SDK.EmptyResponseData Instance;

        // class properties
    };

     class EmptyTransportInfoBuilder 
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

    static class TransportType // enum
    {
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER CecDevice;
        static SIGNED_LONG_INTEGER CrestronConnected;
        static SIGNED_LONG_INTEGER Http;
        static SIGNED_LONG_INTEGER Ir;
        static SIGNED_LONG_INTEGER SerialComport;
        static SIGNED_LONG_INTEGER Simpl;
        static SIGNED_LONG_INTEGER Tcp;
        static SIGNED_LONG_INTEGER Telnet;
        static SIGNED_LONG_INTEGER Udp;
    };

     class TransportBase 
    {
        // class delegates

        // class events
        EventHandler OnDeviceConnectionChanged ( TransportBase sender, BooleanEventArgs e );
        EventHandler OnUserConnectionChanged ( TransportBase sender, BooleanEventArgs e );
        EventHandler OnDataReceived ( TransportBase sender, TransportRxEventArgs e );
        EventHandler OnReadyToSend ( TransportBase sender, EventArgs e );
        EventHandler OnWatchDogHeartbeat ( TransportBase sender, EventArgs e );

        // class functions
        FUNCTION Dispose ();
        FUNCTION Disconnect ();
        FUNCTION Reinitialize ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Name[];
        LONG_INTEGER WaitForResponseTimeout;
        LONG_INTEGER WatchDogTimerInterval;
    };

     class TransportCoordinator 
    {
        // class delegates

        // class events
        EventHandler OnReadyToSend ( TransportCoordinator sender, EventArgs e );
        EventHandler OnFeedbackReceived ( TransportCoordinator sender, FeedbackEventArgs e );
        EventHandler OnDataReceived ( TransportCoordinator sender, EventArgs e );

        // class functions
        FUNCTION Dispose ();
        FUNCTION Disconnect ();
        FUNCTION ProcessCommand ( ControlCommand command );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static LONG_INTEGER DefaultWatchDogTimerInterval;

        // class properties
        STRING Name[];
        SIGNED_LONG_INTEGER MaxCommandHistory;
    };

     class TransportDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        LONG_INTEGER TimeBetweenCommands;
        STRING ResponseProcessor[];
        LONG_INTEGER WaitForResponseTimeout;
        STRING Coordinator[];
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

    static class TransportInfo 
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

     class InputUserAttributeInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING UserAttributeTypeOnScreen[];
        static STRING UserAttributeTypeDeviceId[];
        static STRING UserAttributeTypeCustom[];

        // class properties
        InputDataType DataType;
        STRING DefaultValue[];
        STRING DefaultValueLabel[];
        ConnectionRequirement RequiredForConnection;
    };

     class InputUserAttributeInfoInfoTypeFactory 
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

    static class ConnectionRequirement // enum
    {
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER Before;
        static SIGNED_LONG_INTEGER After;
    };

    static class InputDataType // enum
    {
        static SIGNED_LONG_INTEGER String;
        static SIGNED_LONG_INTEGER Number;
        static SIGNED_LONG_INTEGER Boolean;
        static SIGNED_LONG_INTEGER Hex;
    };

     class UserAttributeDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Description[];
        STRING Label[];
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class CoordinatorInitialData 
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

     class CoordinatorBaseData 
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

     class CoordinatorTransportData 
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

     class CoordinatorTransformationData 
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

     class CoordinatorConditionData 
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

     class CoordinatorCommandData 
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

     class CoordinatorProviderData 
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

     class DriverCoordinator 
    {
        // class delegates

        // class events
        EventHandler OnStateChanged ( DriverCoordinator sender, StateChangeSetEventArgs e );

        // class functions
        FUNCTION Dispose ();
        FUNCTION ProcessingLoop ();
        FUNCTION EnqueueControlCommand ( ControlCommand command );
        FUNCTION ProcessOne ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING ComponentName[];

        // class properties
    };

     class DriverCoordinatorProvider 
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

    static class StateVariables 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING True[];
        static STRING False[];
        static STRING Ack[];
        static STRING CommandName[];
        static STRING CommandId[];
        static STRING Connection[];
        static STRING UserConnection[];
        static STRING Username[];
        static STRING Password[];
        static STRING Host[];
        static STRING Port[];

        // class properties
    };

     class SupportedFeatureDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

    static class LoggingConstants 
    {
        // class delegates

        // class events

        // class functions
        static STRING_FUNCTION GenerateReceiveTag ( STRING transportName );
        static STRING_FUNCTION GenerateSendTag ( STRING transportName );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING Receive[];
        static STRING Send[];
        static STRING SendReceiveLoggingFormatString[];
        static STRING ComponentTypeSeparator[];
        static STRING ComponentTypeOther[];
        static STRING ComponentTypeTransformation[];
        static STRING ComponentTypeCondition[];
        static STRING ComponentTypeRule[];
        static STRING ComponentTypeResponse[];
        static STRING ComponentTypeCommand[];
        static STRING ComponentTypeTransport[];
        static STRING ComponentTypeController[];
        static STRING ComponentTypeCoordinator[];
        static STRING ComponentTypeCapability[];

        // class properties
    };

     class ConfigurationDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING DriverInstanceIdentifier[];
        LONG_INTEGER MinTimeBetweenCommands;
    };

     class DeveloperInformationDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Company[];
        STRING Contact[];
        STRING Email[];
        STRING Website[];
        STRING PhoneNumber[];
    };

     class DriverDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CurrentSchemaVersion[];

        // class properties
        GeneralInformationDefinition GeneralInformation;
        STRING SchemaVersion[];
        ConfigurationDefinition Configuration;
        STRING Comment[];
    };

     class BaseDefinitionType 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Comment[];
    };

    static class ParameterVisibility // enum
    {
        static SIGNED_LONG_INTEGER Default;
        static SIGNED_LONG_INTEGER Advanced;
        static SIGNED_LONG_INTEGER Hidden;
    };

    static class StringType // enum
    {
        static SIGNED_LONG_INTEGER Text;
        static SIGNED_LONG_INTEGER LongText;
        static SIGNED_LONG_INTEGER TemplateString;
        static SIGNED_LONG_INTEGER LongTemplateString;
        static SIGNED_LONG_INTEGER ExistingParameter;
        static SIGNED_LONG_INTEGER NewParameter;
        static SIGNED_LONG_INTEGER NewOrExistingParameter;
    };

    static class ParameterUnit 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING Milliseconds[];

        // class properties
    };

    static class ProcessorPlatform 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING Series3[];
        static STRING Series4[];

        // class properties
    };

    static class DeviceType 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING AvReceiver[];
        static STRING FlatPanelDisplay[];
        static STRING Projector[];
        static STRING Speaker[];
        static STRING NetworkSwitch[];
        static STRING CableBox[];
        static STRING VideoServer[];

        // class properties
    };

     class GeneralInformationDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING BaseModel[];
        STRING Description[];
        STRING DriverVersion[];
        STRING Manufacturer[];
        STRING MinCresDbVersion[];
        STRING MinSdkVersion[];
        STRING MinToolboxVersion[];
        STRING DeviceType[];
        DeveloperInformationDefinition Developer;
        STRING DependencyGroup[];
    };

     class InputOutputDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING FriendlyName[];
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

     class NamedDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Name[];
        STRING Comment[];
    };

     class TypedDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

    static class Serialization 
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

namespace Crestron.DeviceDrivers.SDK.Util;
        // class declarations
         class AllowedException;
         class ByteMath;
         class ObjectPool;
         class DefaultEncoding;
         class ImplementationMissingException;
         class HasImplementationProviderAttribute;
         class ImplementationProviderAttribute;
         class NamedImplementationProvider;
         class LoggingCast;
         class HistoricalAllocStringBuilder;
         class HistoricalLengthStringBuilder;
         class UnoptimizedStringBuilder;
         class ReflectionFunc;
         class ConsoleWrapper;
         class CriticalSection;
         class DelegateWrapperBase;
         class DriverDataStore;
         class EventWrapper;
         class FileSystem;
         class PersistentValue;
         class Resources;
         class ResourcesFromTypeAssembly;
         class ThreadEventWrapper;
         class ThreadWrapper;
         class BufferedStream;
         class BufferedStreamReader;
         class EmptyBufferedStreamReader;
         class ValueLookupFactory;
    static class ByteMath 
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

    static class ObjectPool 
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

    static class DefaultEncoding 
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

     class ImplementationMissingException 
    {
        // class delegates

        // class events

        // class functions
        STRING_FUNCTION ToString ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Message[];
        STRING StackTrace[];
        STRING HelpLink[];
        STRING Source[];
        SIGNED_LONG_INTEGER HResult;
    };

     class HasImplementationProviderAttribute 
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

     class NamedImplementationProvider 
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

    static class LoggingCast 
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

     class HistoricalAllocStringBuilder 
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

     class HistoricalLengthStringBuilder 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        SIGNED_LONG_INTEGER MaxLength;
    };

     class UnoptimizedStringBuilder 
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

    static class ReflectionFunc 
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

    static class ConsoleWrapper 
    {
        // class delegates

        // class events

        // class functions
        static FUNCTION WriteLine ( STRING message );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class CriticalSection 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION DisposeLock ();
        FUNCTION Leave ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class DelegateWrapperBase 
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

     class EventWrapper 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Dispose ();
        FUNCTION ClearSubscribers ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

    static class FileSystem 
    {
        // class delegates

        // class events

        // class functions
        static STRING_FUNCTION CombinePath ( STRING part1 , STRING part2 );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING DriverSdkPath[];
    };

    static class Resources 
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

    static class ResourcesFromTypeAssembly 
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

     class BufferedStream 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Dispose ();
        FUNCTION Clear ();
        FUNCTION Consume ( SIGNED_LONG_INTEGER numBytes );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

    static class ValueLookupFactory 
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

namespace Crestron.DeviceDrivers.SDK.Util.Units;
        // class declarations
         class UnitConversion;
    static class UnitConversion 
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

namespace Crestron.DeviceDrivers.SDK.Util.TestHooks;
        // class declarations
         class TestHarness;
     class TestHarness 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        TestHarness ActiveHooks;
        LONG_INTEGER Millis;
    };

namespace Crestron.DeviceDrivers.SDK.Util.SimplSharp;
        // class declarations
         class HashCalculation;
     class HashCalculation 
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

namespace Crestron.DeviceDrivers.SDK.Util.WebSocket;
        // class declarations
         class WebSocket;
         class WebSocketFrame;
         class FrameControlBits;
         class WebSocketPacketEventArgs;
         class WebSocketServer;
    static class FrameControlBits // enum
    {
        static SIGNED_LONG_INTEGER OpContinuation;
        static SIGNED_LONG_INTEGER OpText;
        static SIGNED_LONG_INTEGER OpBinary;
        static SIGNED_LONG_INTEGER OpClose;
        static SIGNED_LONG_INTEGER OpPing;
        static SIGNED_LONG_INTEGER OpPong;
        static SIGNED_LONG_INTEGER OpCode;
        static SIGNED_LONG_INTEGER Fin;
    };

namespace Crestron.DeviceDrivers.SDK.Util.Extensions;
        // class declarations
         class ControllerExtensions;
         class CopyExtensions;
         class DebugExtensions;
         class EnumerableExtensions;
         class EnumExtensions;
         class LookupExtensions;
         class ImplementationProviderAttributeExtensions;
         class ImplementationProviderExtensions;
    static class ControllerExtensions 
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

    static class CopyExtensions 
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

    static class DebugExtensions 
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

    static class EnumerableExtensions 
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

    static class EnumExtensions 
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

    static class LookupExtensions 
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

    static class ImplementationProviderAttributeExtensions 
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

    static class ImplementationProviderExtensions 
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

namespace Crestron.DeviceDrivers.SDK.Time;
        // class declarations
         class ActionSchedule;
         class MillisTickStopwatch;
         class PolledTimeout;
         class RepeatingScheduleAction;
         class ScheduleAction;
         class ScheduledTimeout;
         class Time;
     class MillisTickStopwatch 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Start ();
        FUNCTION Stop ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static LONG_INTEGER Stopped;

        // class properties
        LONG_INTEGER ElapsedMilliseconds;
    };

     class ScheduleAction 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION DoAction ();
        FUNCTION Reschedule ( LONG_INTEGER delay );
        FUNCTION Stop ();
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        LONG_INTEGER ScheduledTimeMillis;
    };

    static class Time 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static LONG_INTEGER Millisecond;
        static LONG_INTEGER MillisecondsInSecond;
        static LONG_INTEGER Second;
        static LONG_INTEGER SecondsInMinute;
        static LONG_INTEGER MinutesInHour;
        static LONG_INTEGER HoursInDay;
        static LONG_INTEGER SecondsInHour;
        static LONG_INTEGER SecondsInDay;
        static LONG_INTEGER MillisecondsInDay;
        static LONG_INTEGER Minute;
        static LONG_INTEGER Hour;
        static LONG_INTEGER Day;
        static LONG_INTEGER DefaultMaxMillisTimeout;

        // class properties
        LONG_INTEGER Millis;
    };

namespace Crestron.DeviceDrivers.SDK.Schema.Attributes;
        // class declarations
         class ProviderTypeAttribute;

namespace Crestron.DeviceDrivers.SDK.Attributes;
        // class declarations
         class DefaultValueAttribute;
         class DriverParameterAttribute;
         class ResolveTypeCallbackAttribute;
     class DriverParameterAttribute 
    {
        // class delegates

        // class events

        // class functions
        static STRING_FUNCTION GetDefaultFriendlyName ( STRING propertyName );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Name[];
        STRING Description[];
        ParameterVisibility Visibility;
        LONG_INTEGER ParameterIndex;
        STRING TableColumnNames[][];
        STRING TableColumnDescriptions[][];
        StringType StringType;
        StringType DictKeyStringType;
        SIGNED_LONG_INTEGER ValueDisplayPrecision;
        STRING Unit[];
    };

namespace Crestron.DeviceDrivers.SDK.Events;
        // class declarations
         class BooleanEventArgs;
         class FeedbackEventArgs;
         class LogEntryLevelChangedArgs;
         class LogEventArgs;
         class StateChangedEventArgs;
         class ValueChange;
         class StateChangedEventArgsFactory;
         class StateChangeSetEventArgs;
         class TransportRxEventArgs;
     class BooleanEventArgs 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        BooleanEventArgs True;
        BooleanEventArgs False;
    };

     class ValueChange 
    {
        // class delegates

        // class events

        // class functions
        STRING_FUNCTION ToString ();
        FUNCTION Update ( ValueChange newChange );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class TransportRxEventArgs 
    {
        // class delegates

        // class events

        // class functions
        static FUNCTION Return ( TransportRxEventArgs instance );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

namespace Crestron.DeviceDrivers.SDK.Extensions;
        // class declarations
         class Extensions;
         class DriverDefinitionExtensions;
    static class Extensions 
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

    static class DriverDefinitionExtensions 
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

namespace Crestron.DeviceDrivers.SDK.SubDevices;
        // class declarations
         class SubDeviceDefinition;
     class SubDeviceDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Type[];
        STRING Name[];
        STRING Comment[];
    };

namespace Crestron.DeviceDrivers.SDK.Transports.WebSocket;
        // class declarations
         class DedicatedThreadWebSocket;
         class WebSocketClientData;
         class WebSocketPacketType;
         class SimplWebSocketTransport;
         class SimplWebSocketTransportFactory;
         class WebSocketCommandTransportInfo;
         class WebSocketCommandTransportInfoDefinition;
         class CommandInfoTypeFactory;
         class WebSocketTransportFrame;
         class WebSocketTransportInfo;
         class WebSocketTransportInfoTypeFactory;
         class WebSocketTransportInfoBuilder;
         class WebSocketTransportInfoBuilderFactory;
     class WebSocketClientData 
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

    static class WebSocketPacketType // enum
    {
        static SIGNED_LONG_INTEGER Continuation;
        static SIGNED_LONG_INTEGER Text;
        static SIGNED_LONG_INTEGER Binary;
        static SIGNED_LONG_INTEGER Close;
        static SIGNED_LONG_INTEGER Ping;
        static SIGNED_LONG_INTEGER Pong;
    };

     class SimplWebSocketTransportFactory 
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

     class WebSocketCommandTransportInfo 
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

     class WebSocketCommandTransportInfoDefinition 
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

     class CommandInfoTypeFactory 
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

     class WebSocketTransportFrame 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        WebSocketCommandTransportInfo Info;
    };

     class WebSocketTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
        STRING Protocol[];
        STRING Url[];
        STRING ProxyHost[];
        LONG_INTEGER ProxyPort;
        STRING ProxyUsername[];
        STRING ProxyPassword[];
        LONG_INTEGER ReconnectInterval;
        LONG_INTEGER PingInterval;
    };

     class WebSocketTransportInfoTypeFactory 
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

     class WebSocketTransportInfoBuilderFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transports.Udp;
        // class declarations
         class UdpCommandTransportInfo;
         class UdpCommandTransportInfoDefinition;
         class CommandInfoTypeFactory;
         class UdpTransport;
         class UdpTransportFactory;
         class UdpTransportInfo;
         class UdpTransportInfoTypeFactory;
     class UdpCommandTransportInfo 
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

     class UdpCommandTransportInfoDefinition 
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

     class CommandInfoTypeFactory 
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

     class UdpTransportFactory 
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

     class UdpTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
        SIGNED_LONG_INTEGER Port;
        SIGNED_LONG_INTEGER ReceiveBufferSize;
    };

     class UdpTransportInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transports.Tcp;
        // class declarations
         class TcpTransport;
         class TcpTransportFactory;
         class TcpTransportInfo;
         class TcpTransportInfoTypeFactory;
         class TcpTransportInfoBuilder;
         class TcpTransportInfoBuilderFactory;
     class TcpTransportFactory 
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

     class TcpTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
        LONG_INTEGER ReconnectInterval;
        STRING Encoding[];
    };

     class TcpTransportInfoTypeFactory 
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

     class TcpTransportInfoBuilder 
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

     class TcpTransportInfoBuilderFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transports.Serial;
        // class declarations
         class SerialTransportFactory;
         class SerialTransportInfo;
         class InfoTypeFactory;
         class SerialTransportInfoBuilder;
         class Factory;
     class SerialTransportFactory 
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

     class SerialTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
    };

     class InfoTypeFactory 
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

     class SerialTransportInfoBuilder 
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

     class Factory 
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

namespace Crestron.DeviceDrivers.SDK.Transports.Http;
        // class declarations
         class HttpRequestType;
         class AuthenticationMethod;
         class HttpClientKeepAliveWrapper;
         class HttpCommandTransportInfo;
         class HttpCommandTransportInfoDefinition;
         class CommandInfoTypeFactory;
         class HttpResponseDataBase;
         class HttpsClientKeepAliveWrapper;
         class HttpSendFailureRecoveryStrategy;
         class HttpTransportInfo;
         class HttpTransportInfoTypeFactory;
         class HttpTransportInfoBuilder;
         class HttpTransportInfoBuilderFactory;
         class SimplHttpResponseData;
         class SimplHttpTransport;
         class SimplHttpTransportFactory;
    static class HttpRequestType // enum
    {
        static SIGNED_LONG_INTEGER Get;
        static SIGNED_LONG_INTEGER Put;
        static SIGNED_LONG_INTEGER Post;
        static SIGNED_LONG_INTEGER Delete;
        static SIGNED_LONG_INTEGER Head;
    };

    static class AuthenticationMethod // enum
    {
        static LONG_INTEGER None;
        static LONG_INTEGER Basic;
        static LONG_INTEGER Digest;
        static LONG_INTEGER Negotiate;
        static LONG_INTEGER NTLM;
        static LONG_INTEGER Digest_IE;
        static LONG_INTEGER NTLM_WB;
        static LONG_INTEGER Only;
        static LONG_INTEGER Anysafe;
        static LONG_INTEGER Any;
    };

     class HttpCommandTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING ContentType[];
        STRING Encoding[];
        STRING Password[];
        HttpRequestType RequestType;
        SIGNED_LONG_INTEGER Timeout;
        STRING Url[];
        STRING UserName[];
        AuthenticationMethod AuthenticationMethod;
    };

     class HttpCommandTransportInfoDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING ContentType[];
        STRING Encoding[];
        STRING Endpoint[];
        STRING Password[];
        STRING Url[];
        STRING UserName[];
    };

     class CommandInfoTypeFactory 
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

     class HttpResponseDataBase 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING HttpStatusCode[];

        // class properties
    };

     class HttpTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
        LONG_INTEGER RetryDelayMilliseconds;
        STRING ContentType[];
        STRING Encoding[];
        STRING Password[];
        HttpRequestType RequestType;
        SIGNED_LONG_INTEGER Timeout;
        STRING Url[];
        STRING UserName[];
        AuthenticationMethod AuthenticationMethod;
    };

     class HttpTransportInfoTypeFactory 
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

     class HttpTransportInfoBuilderFactory 
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

     class SimplHttpTransportFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transports.Cip;
        // class declarations
         class CipCommand;
         class CipCommandBuilder;
         class CipDigitalCommandBuilderFactory;
         class CipAnalogCommandBuilderFactory;
         class CipSerialCommandBuilderFactory;
         class CipCommandInfo;
         class CipCommandInfoDefinition;
         class CipCommandInfoDefinitionTypeFactory;
         class CipInterlockCommandInfoDefinition;
         class CipDeInterlockCommandInfoTypeFactory;
         class CipInterlockCommand;
         class CipInterlockCommandBuilder;
         class CipInterlockCommandBuilderFactory;
         class CipJoinType;
         class CipResponseData;
         class CipTransportInfo;
         class TcpTransportInfoTypeFactory;
         class CipTransportInfoBuilder;
         class TcpTransportInfoBuilderFactory;
     class CipDigitalCommandBuilderFactory 
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

     class CipAnalogCommandBuilderFactory 
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

     class CipSerialCommandBuilderFactory 
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

     class CipCommandInfoDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING DigitalCommandDefinitionType[];
        static STRING AnalogCommandDefinitionType[];
        static STRING SerialCommandDefinitionType[];

        // class properties
        SIGNED_LONG_INTEGER Join;
        SIGNED_LONG_INTEGER MethodName;
        STRING Value[];
    };

     class CipCommandInfoDefinitionTypeFactory 
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

     class CipInterlockCommandInfoDefinition 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandDefinitionType[];

        // class properties
        STRING Value[];
    };

     class CipDeInterlockCommandInfoTypeFactory 
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

     class CipInterlockCommandBuilderFactory 
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

    static class CipJoinType // enum
    {
        static SIGNED_LONG_INTEGER Digital;
        static SIGNED_LONG_INTEGER Analog;
        static SIGNED_LONG_INTEGER Serial;
    };

     class CipTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
        LONG_INTEGER ReconnectInterval;
    };

     class TcpTransportInfoTypeFactory 
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

     class CipTransportInfoBuilder 
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

     class TcpTransportInfoBuilderFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transports.Cec;
        // class declarations
         class CecTransportFactory;
         class CecTransportInfo;
         class InfoTypeFactory;
         class CecTransportInfoBuilder;
         class Factory;
     class CecTransportFactory 
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

     class CecTransportInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransportDefinitionType[];

        // class properties
    };

     class InfoTypeFactory 
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

     class CecTransportInfoBuilder 
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

     class Factory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.Substring;
        // class declarations
         class SubstringTransformation;
         class SubstringTransformationFactory;
         class SubstringTransformationInfo;
         class SubstringTransformationInfoTypeFactory;
     class SubstringTransformationFactory 
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

     class SubstringTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        SIGNED_LONG_INTEGER Length;
        SIGNED_LONG_INTEGER StartIndex;
    };

     class SubstringTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.StringReplace;
        // class declarations
         class StringReplaceTransformation;
         class StringReplaceTransformationFactory;
         class StringReplaceTransformationInfo;
         class StringReplaceTransformationInfoTypeFactory;
     class StringReplaceTransformationFactory 
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

     class StringReplaceTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        STRING Pattern[];
        STRING Replacement[];
    };

     class StringReplaceTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.StringPadding;
        // class declarations
         class StringPaddingTransformation;
         class StringPaddingTransformationFactory;
         class PaddingDirection;
         class PaddingMode;
         class StringPaddingTransformationInfo;
         class StringPaddingTransformationInfoTypeFactory;
     class StringPaddingTransformationFactory 
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

    static class PaddingDirection // enum
    {
        static SIGNED_LONG_INTEGER Left;
        static SIGNED_LONG_INTEGER Right;
    };

    static class PaddingMode // enum
    {
        static SIGNED_LONG_INTEGER SpecifiedCharacter;
        static SIGNED_LONG_INTEGER PKCS7;
    };

     class StringPaddingTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        PaddingDirection PaddingDirection;
        PaddingMode PaddingMode;
        SIGNED_LONG_INTEGER TotalLength;
    };

     class StringPaddingTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.StringFormat;
        // class declarations
         class StringFormatTransformation;
         class StringFormatTransformationFactory;
         class StringFormatTransformationInfo;
         class StringFormatTransformationInfoTypeFactory;
     class StringFormatTransformationFactory 
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

     class StringFormatTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        STRING DataType[];
        STRING FormatString[];
        STRING SplitInput[];
    };

     class StringFormatTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.Slice;
        // class declarations
         class SliceTransformation;
         class SliceTransformationFactory;
         class SliceTransformationInfo;
         class SliceTransformationInfoTypeFactory;
     class SliceTransformationFactory 
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

     class SliceTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        SIGNED_LONG_INTEGER StartIndex;
    };

     class SliceTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.SimplByteConverter;
        // class declarations
         class SimplByteConverterTransformation;
         class SimplByteConverterTransformationFactory;
         class SimplByteConverterTransformationInfo;
         class SimplByteConverterTransformationInfoTypeFactory;
     class SimplByteConverterTransformationFactory 
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

     class SimplByteConverterTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
    };

     class SimplByteConverterTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.RijndaelEncryptor;
        // class declarations
         class RijndaelEncryptorTransformation;
         class RijndaelEncryptorTransformationFactory;
         class RijndaelEncryptorTransformationInfo;
         class RijndaelEncryptorTransformationInfoTypeFactory;
     class RijndaelEncryptorTransformationFactory 
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

     class RijndaelEncryptorTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        STRING Key[];
        STRING IV[];
    };

     class RijndaelEncryptorTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.RijndaelDecryptor;
        // class declarations
         class RijndaelDecryptorTransformation;
         class RijndaelDecryptorTransformationFactory;
         class RijndaelDecryptorTransformationInfo;
         class RijndaelDecryptorTransformationInfoTypeFactory;
     class RijndaelDecryptorTransformationFactory 
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

     class RijndaelDecryptorTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        STRING Key[];
        STRING IV[];
    };

     class RijndaelDecryptorTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.PBKDF2;
        // class declarations
         class PBKDF2SHA256Transformation;
         class PBKDF2SHA256TransformationFactory;
         class HashAlgorithm;
         class PBKDF2TransformationInfo;
         class PBKDF2TransformationInfoTypeFactory;
     class PBKDF2SHA256TransformationFactory 
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

    static class HashAlgorithm // enum
    {
        static SIGNED_LONG_INTEGER SHA256;
    };

     class PBKDF2TransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        STRING Salt[];
        SIGNED_LONG_INTEGER Iterations;
        SIGNED_LONG_INTEGER LengthOfKey;
        HashAlgorithm Algorithm;
    };

     class PBKDF2TransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.Math;
        // class declarations
         class MathTransformation;
         class MathTransformationFactory;
         class MathTransformationInfo;
         class MathTransformationInfoTypeFactory;
         class OperationType;
     class MathTransformationFactory 
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

     class MathTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        OperationType OpType;
    };

     class MathTransformationInfoTypeFactory 
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

    static class OperationType // enum
    {
        static SIGNED_LONG_INTEGER LittleEndianBytesToInt;
        static SIGNED_LONG_INTEGER LittleEndianBytesToUint;
        static SIGNED_LONG_INTEGER IntToLittleEndianBytes;
        static SIGNED_LONG_INTEGER UIntToLittleEndianBytes;
        static SIGNED_LONG_INTEGER BigEndianBytesToInt;
        static SIGNED_LONG_INTEGER BigEndianBytesToUint;
        static SIGNED_LONG_INTEGER IntToBigEndianBytes;
        static SIGNED_LONG_INTEGER UIntToBigEndianBytes;
        static SIGNED_LONG_INTEGER Add;
        static SIGNED_LONG_INTEGER Multiply;
        static SIGNED_LONG_INTEGER Round;
        static SIGNED_LONG_INTEGER Abs;
        static SIGNED_LONG_INTEGER Sign;
        static SIGNED_LONG_INTEGER Floor;
        static SIGNED_LONG_INTEGER Ceiling;
    };

namespace Crestron.DeviceDrivers.SDK.Transformations.Map;
        // class declarations
         class MapTransformation;
         class MapTransformationFactory;
         class MapTransformationInfo;
         class MapTransformationInfoTypeFactory;
     class MapTransformationFactory 
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

     class MapTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        STRING MapDefault[];
        STRING InversePrefix[];
        STRING InverseDefault[];
    };

     class MapTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.Length;
        // class declarations
         class LengthTransformation;
         class LengthTransformationFactory;
         class LengthTransformationInfo;
         class LengthTransformationInfoTypeFactory;
     class LengthTransformationFactory 
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

     class LengthTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        SIGNED_LONG_INTEGER Offset;
    };

     class LengthTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Transformations.Hash;
        // class declarations
         class HashTransformation;
         class HashTransformationFactory;
         class Sha256Hash;
         class HashTransformationInfo;
         class EncodeTransformationInfoTypeFactory;
         class HashType;
     class HashTransformationFactory 
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

     class Sha256Hash 
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

     class HashTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        HashType Algorithm;
    };

     class EncodeTransformationInfoTypeFactory 
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

    static class HashType // enum
    {
        static SIGNED_LONG_INTEGER Sha256;
        static SIGNED_LONG_INTEGER Md5;
    };

namespace Crestron.DeviceDrivers.SDK.Transformations.Encode;
        // class declarations
         class EncodeTransformation;
         class EncodeTransformationFactory;
         class EncodeTransformationInfo;
         class EncodeTransformationInfoTypeFactory;
         class EncodingType;
     class EncodeTransformationFactory 
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

     class EncodeTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        EncodingType Encoding;
    };

     class EncodeTransformationInfoTypeFactory 
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

    static class EncodingType // enum
    {
        static SIGNED_LONG_INTEGER Base64;
    };

namespace Crestron.DeviceDrivers.SDK.Transformations.Checksum;
        // class declarations
         class ChecksumTransformation;
         class ChecksumTransformationFactory;
         class ChecksumTransformationInfo;
         class ChecksumTransformationInfoTypeFactory;
         class ComplementType;
     class ChecksumTransformationFactory 
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

     class ChecksumTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
        SIGNED_LONG_INTEGER WordSize;
        ComplementType Complement;
    };

     class ChecksumTransformationInfoTypeFactory 
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

    static class ComplementType // enum
    {
        static SIGNED_LONG_INTEGER None;
        static SIGNED_LONG_INTEGER Ones;
        static SIGNED_LONG_INTEGER Twos;
    };

namespace Crestron.DeviceDrivers.SDK.Transformations.CharMap;
        // class declarations
         class CharMapTransformation;
         class CharMapTransformationFactory;
         class CharMapTransformationInfo;
         class CharMapTransformationInfoTypeFactory;
     class CharMapTransformationFactory 
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

     class CharMapTransformationInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TransformationType[];

        // class properties
    };

     class CharMapTransformationInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Rules.SetOther;
        // class declarations
         class SetOtherFeedbackRule;
         class SetOtherFeedbackRuleFactory;
         class SetOtherOnSendRule;
         class SetOtherOnSendRuleFactory;
         class SetOtherRuleInfo;
         class SetOtherRuleInfoTypeFactory;
         class SetOtherStateRule;
         class SetOtherStateRuleFactory;
         class SetOtherStateRuleInfo;
         class SetOtherStateRuleInfoTypeFactory;
     class SetOtherFeedbackRuleFactory 
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

     class SetOtherOnSendRuleFactory 
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

     class SetOtherRuleInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeNameFeedback[];
        static STRING TypeNameOnSend[];

        // class properties
    };

     class SetOtherRuleInfoTypeFactory 
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

     class SetOtherStateRuleFactory 
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

     class SetOtherStateRuleInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class SetOtherStateRuleInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Rules.SequencedEntryRule;
        // class declarations
         class SequencedEntryRule;
         class SequencedEntryRuleFactory;
         class SequencedEntryRuleInfo;
         class SequencedEntryRuleInfoTypeFactory;
     class SequencedEntryRuleFactory 
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

     class SequencedEntryRuleInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
        STRING Content[];
    };

     class SequencedEntryRuleInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Rules.CommandSequence;
        // class declarations
         class CommandSequenceRule;
         class CommandSequenceRuleFactory;
         class CommandSequenceRuleInfo;
         class CommandSequenceRuleInfoTypeFactory;
     class CommandSequenceRuleFactory 
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

     class CommandSequenceRuleInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class CommandSequenceRuleInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Rules.Block;
        // class declarations
         class BlockRule;
         class BlockRuleFactory;
         class BlockRuleInfo;
         class BlockRuleInfoTypeFactory;
     class BlockRuleFactory 
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

     class BlockRuleInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class BlockRuleInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Responses;
        // class declarations
         class AlwaysMatchProcessor;
         class AlwaysMatchProcessorFactory;
         class CaptureAllProcessor;
         class CaptureAllProcessorFactory;
         class ForEachResponseMatchBehavior;
         class ForEachResponseProcessor;
         class ForEachResponseProcessorFactory;
         class ForEachResponseProcessorInfo;
         class ForEachResponseInfoTypeFactory;
         class NameMatchProcessor;
         class NameMatchProcessorFactory;
         class RegexResponseProcessor;
         class RegexResponseProcessorFactory;
         class RegexResponseProcessorInfo;
         class RegexResponseInfoTypeFactory;
     class AlwaysMatchProcessorFactory 
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

     class CaptureAllProcessorFactory 
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

    static class ForEachResponseMatchBehavior // enum
    {
        static SIGNED_LONG_INTEGER MatchIfAny;
        static SIGNED_LONG_INTEGER MatchIfAll;
        static SIGNED_LONG_INTEGER StopOnFirstMatch;
    };

     class ForEachResponseProcessor 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Initialize ( ResponseComponentArgs args );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Name[];
    };

     class ForEachResponseProcessorFactory 
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

     class ForEachResponseProcessorInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING ResponseType[];

        // class properties
        STRING Count[];
        STRING Index[];
        STRING Key[];
        ForEachResponseMatchBehavior MatchBehavior;
        STRING ValuePrefix[];
    };

     class ForEachResponseInfoTypeFactory 
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

     class NameMatchProcessorFactory 
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

     class RegexResponseProcessorFactory 
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

     class RegexResponseProcessorInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING ResponseType[];
        static STRING MultiResponseType[];

        // class properties
        ResponseProcessingStepStatus Mismatch;
    };

     class RegexResponseInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Responses.BinaryPacket;
        // class declarations
         class BinaryPacketComponent;
         class BinaryPacketResponseProcessor;
         class BinaryPacketResponseProcessorFactory;
     class BinaryPacketResponseProcessorFactory 
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

namespace Crestron.DeviceDrivers.SDK.Xml;
        // class declarations
         class XmlCommandBuilderFactory;
         class XmlCommandInfo;
         class XmlCommandInfoTypeFactory;
     class XmlCommandBuilderFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandType[];

        // class properties
    };

     class XmlCommandInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandDefinitionType[];

        // class properties
        STRING Content[];
    };

     class XmlCommandInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Text;
        // class declarations
         class TextCommandInfo;
         class TextCommandInfoTypeFactory;
         class TextCommand;
         class TextCommandBuilder;
         class TextCommandBuilderFactory;
     class TextCommandInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandDefinitionType[];

        // class properties
        STRING Content[];
    };

     class TextCommandInfoTypeFactory 
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

     class TextCommandBuilderFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandType[];

        // class properties
    };

namespace Crestron.DeviceDrivers.SDK.Json.Responses;
        // class declarations
         class JsonResponseProcessor;
         class JsonResponseProcessorFactory;
         class JsonResponseProcessorInfo;
         class JsonResponseProcessorInfoTypeFactory;
     class JsonResponseProcessorFactory 
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

     class JsonResponseProcessorInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING ResponseTypeName[];

        // class properties
        STRING Encoding[];
    };

     class JsonResponseProcessorInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Json.Formatters;
        // class declarations
         class JsonEscapeFormatter;
         class JsonEscapeQuotedFormatter;
         class JsonFormatter;
     class JsonEscapeFormatter 
    {
        // class delegates

        // class events

        // class functions
        STRING_FUNCTION Format ( STRING input );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING FormatName[];

        // class properties
        STRING Name[];
    };

     class JsonEscapeQuotedFormatter 
    {
        // class delegates

        // class events

        // class functions
        STRING_FUNCTION Format ( STRING input );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING FormatName[];

        // class properties
        STRING Name[];
    };

    static class JsonFormatter 
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

namespace Crestron.DeviceDrivers.SDK.Formatters;
        // class declarations
         class FloatFormatter;
         class IntFormatter;
     class FloatFormatter 
    {
        // class delegates

        // class events

        // class functions
        STRING_FUNCTION Format ( STRING input );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING FormatName[];

        // class properties
        STRING Name[];
    };

     class IntFormatter 
    {
        // class delegates

        // class events

        // class functions
        STRING_FUNCTION Format ( STRING input );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING FormatName[];

        // class properties
        STRING Name[];
    };

namespace Crestron.DeviceDrivers.SDK.Controllers.TunerController;
        // class declarations
         class TunerController;
         class TunerControllerFactory;
         class TunerControllerState;
           class ValueLookup;
     class TunerControllerFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.TimedStatusController;
        // class declarations
         class TimedStatusControllerInfo;
         class TimedStatusControllerInfoTypeFactory;
         class TimedStatusControllerState;
         class TimedStatusStateController;
         class TimedStatusStateControllerFactory;
     class TimedStatusControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
        LONG_INTEGER MinTimeout;
        LONG_INTEGER Timeout;
    };

     class TimedStatusControllerInfoTypeFactory 
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

     class TimedStatusControllerState 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        LONG_INTEGER Timeout;
    };

     class TimedStatusStateControllerFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.StringController;
        // class declarations
         class StringStateController;
         class StringStateControllerFactory;
         class StringControllerInfo;
         class StringControllerInfoTypeFactory;
     class StringStateControllerFactory 
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

     class StringControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class StringControllerInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.StreamController;
        // class declarations
         class StreamStateController;
         class StreamStateControllerFactory;
         class StreamControllerInfo;
         class StringControllerInfoTypeFactory;
     class StreamStateControllerFactory 
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

     class StreamControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class StringControllerInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.NumericController;
        // class declarations
         class NumericControllerInfo;
         class NumericControllerInfoTypeFactory;
         class NumericControllerScale;
         class NumericControllerState;
         class NumericStateController;
         class NumericStateControllerFactory;
     class NumericControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class NumericControllerInfoTypeFactory 
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

     class NumericStateControllerFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.NumericController.Scaling;
        // class declarations
         class AcceleratingLevelRamper;
         class LevelRamper;
         class IntegerLevel;
         class PercentUshortLevelTranslator;
         class ScalingLevelTranslator;
         class Scale;
         class ScaledValue;
         class ScalingExtensions;
    static class ScalingExtensions 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.MultiValueController;
        // class declarations
         class MultiValueStateController;
         class GenericStateControllerFactory;
         class MultiValueStateControllerInfo;
         class MultiValueStateControllerInfoTypeFactory;
     class GenericStateControllerFactory 
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

     class MultiValueStateControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class MultiValueStateControllerInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.GenericController;
        // class declarations
         class GenericStateController;
         class GenericStateControllerFactory;
         class GenericStateControllerInfo;
         class GenericStateControllerInfoTypeFactory;
     class GenericStateControllerFactory 
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

     class GenericStateControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class GenericStateControllerInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.EnumController;
        // class declarations
         class EnumControllerInfo;
         class EnumControllerInfoTypeFactory;
         class EnumControllerState;
         class EnumStateController;
         class EnumStateControllerFactory;
     class EnumControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
    };

     class EnumControllerInfoTypeFactory 
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

     class EnumControllerState 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING AvailableValues[][];
    };

     class EnumStateControllerFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.DebounceController;
        // class declarations
         class DebounceStateController;
         class DebounceStateControllerFactory;
         class DebounceStateControllerInfo;
         class DebounceStateControllerInfoTypeFactory;
     class DebounceStateControllerFactory 
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

     class DebounceStateControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
        LONG_INTEGER MinimumOffDuration;
        LONG_INTEGER MinimumOnDuration;
        LONG_INTEGER MinimumTriggerOffDuration;
        LONG_INTEGER MinimumTriggerOnDuration;
    };

     class DebounceStateControllerInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.CommandController;
        // class declarations
         class CommandControllerInfo;
         class CommandControllerInfoTypeFactory;
         class CommandController;
         class CommandControllerFactory;
         class CustomCommandRepeatTiming;
     class CommandControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
        STRING AppliesTo[];
        LONG_INTEGER RepeatDelay;
        LONG_INTEGER RepeatHoldOff;
    };

     class CommandControllerInfoTypeFactory 
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

     class CommandControllerFactory 
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

     class CustomCommandRepeatTiming 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
        STRING Command[];
        LONG_INTEGER RepeatDelay;
        LONG_INTEGER RepeatHoldOff;
    };

namespace Crestron.DeviceDrivers.SDK.Controllers.BooleanController;
        // class declarations
         class BooleanStateController;
         class BooleanStateControllerFactory;
     class BooleanStateControllerFactory 
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

namespace Crestron.DeviceDrivers.SDK.Controllers.ArrayController;
        // class declarations
         class ArrayControllerInfo;
         class ArrayControllerInfoTypeFactory;
         class ArrayState;
         class ArrayStateController;
         class ArrayStateControllerFactory;
     class ArrayControllerInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING TypeName[];

        // class properties
        SIGNED_LONG_INTEGER Size;
    };

     class ArrayControllerInfoTypeFactory 
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

     class ArrayStateControllerFactory 
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

namespace Crestron.DeviceDrivers.SDK.Conditions.ExistsCondition;
        // class declarations
         class ExistsCondition;
         class ExistsConditionFactory;
         class ExistsConditionInfo;
         class ExistsConditionInfoTypeFactory;
     class ExistsCondition 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Initialize ( ConditionComponentArgs args );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class ExistsConditionFactory 
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

     class ExistsConditionInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING ConditionType[];

        // class properties
    };

     class ExistsConditionInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Conditions.CompareCondition;
        // class declarations
         class CompareConditionInfo;
         class CompareConditionInfoTypeFactory;
         class IsEqualCondition;
         class IsEqualConditionFactory;
         class IsMatchCondition;
         class IsMatchConditionFactory;
     class CompareConditionInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING EqualCondition[];
        static STRING MatchCondition[];

        // class properties
    };

     class CompareConditionInfoTypeFactory 
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

     class IsEqualCondition 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Initialize ( ConditionComponentArgs args );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class IsEqualConditionFactory 
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

     class IsMatchCondition 
    {
        // class delegates

        // class events

        // class functions
        FUNCTION Initialize ( ConditionComponentArgs args );
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        INTEGER __class_id__;

        // class properties
    };

     class IsMatchConditionFactory 
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

namespace Crestron.DeviceDrivers.SDK.Conditions.CombinationCondition;
        // class declarations
         class CombinationCondition;
         class AndFactory;
         class OrFactory;
         class CombinationType;
         class CombinationConditionInfo;
         class CombinationConditionInfoTypeFactory;
     class AndFactory 
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

     class OrFactory 
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

    static class CombinationType // enum
    {
        static SIGNED_LONG_INTEGER And;
        static SIGNED_LONG_INTEGER Or;
    };

     class CombinationConditionInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING OrCondition[];
        static STRING AndCondition[];

        // class properties
    };

     class CombinationConditionInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Commands.WakeOnLan;
        // class declarations
         class WolCommand;
         class WolCommandBuilder;
         class WolCommandBuilderFactory;
         class WolCommandInfo;
         class WolCommandInfoTypeFactory;
     class WolCommandBuilderFactory 
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

     class WolCommandInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandDefinitionType[];

        // class properties
        STRING MacAddress[];
    };

     class WolCommandInfoTypeFactory 
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

namespace Crestron.DeviceDrivers.SDK.Commands.Template;
        // class declarations
         class TemplateCommandBuilder;
         class TemplateCommandBuilderFactory;
         class TemplateCommandInfo;
         class TemplateCommandInfoTypeFactory;
     class TemplateCommandBuilderFactory 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandType[];

        // class properties
    };

     class TemplateCommandInfo 
    {
        // class delegates

        // class events

        // class functions
        SIGNED_LONG_INTEGER_FUNCTION GetHashCode ();
        STRING_FUNCTION ToString ();

        // class variables
        static STRING CommandDefinitionType[];

        // class properties
        STRING CommandName[];
    };

     class TemplateCommandInfoTypeFactory 
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

