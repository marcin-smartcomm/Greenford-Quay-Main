import { ILogger } from "../interfaces";
export declare class ConsoleLogger implements ILogger {
    debug(msg: string): void;
    error(msg: string, err: Error): void;
    info(msg: string): void;
    warn(msg: string, err?: Error): void;
}
