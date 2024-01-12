import { IConfigOptions } from './interfaces';
export { IConfigOptions as ConfigOptions } from './interfaces';
export { DeviceTypeEnum as DeviceType } from "./enums";
export { OutputLevelEnum as OutputLevel } from "./enums";
export declare const archiver: (options: IConfigOptions) => Promise<void>;
export declare const distributor: (filename: string, options: IConfigOptions) => Promise<void>;
