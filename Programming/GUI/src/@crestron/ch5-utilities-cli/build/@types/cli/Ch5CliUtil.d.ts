import { DeviceType, OutputLevel } from "@crestron/ch5-utilities";
export declare class Ch5CliUtil {
    writeError(error: Error): void;
    getOutputLevel(options: any): OutputLevel;
    getDeviceType(deviceTypeInput: string): DeviceType;
}
