import { Ch5Platform, Ch5SignalFactory } from "../ch5-core";
export declare enum Ch5TouchActivitySignals {
    CsigTime = "Csig.Time",
    CsigResetActivityTimer = "Csig.Reset_Activity_Timer",
    CsigTouchActivity = "Csig.Touch_Activity",
}
export declare class Ch5TouchActivity {
    private static _instance;
    private readonly _ch5SignalFactory;
    private _ch5TimeSignal;
    private _ch5ResetActivityTimerSignal;
    private _ch5Platform;
    private _supportsTouchActivity;
    private _touchInactivityPeriod;
    private _touchActivityTimeoutId;
    private constructor();
    static getInstance(ch5SignalFactory?: Ch5SignalFactory, ch5Platform?: Ch5Platform): Ch5TouchActivity;
    init(): void;
    private setSupportsTouchActivity(ch5PlatformInfo);
    private subscribeToTimeSignal();
    private subscribeToResetActivityTimerSignal();
    private _onTouchStart(event);
    private _onTouchMove(event);
    private _onTouchEnd(event);
    private _onTouchCancel(event);
    private publishTouchActivity();
    private setTouchInactivityTimeout();
    private clearTouchInactivityTimeout();
    private publishTouchActivityEvent(touchActivityFlag);
}
