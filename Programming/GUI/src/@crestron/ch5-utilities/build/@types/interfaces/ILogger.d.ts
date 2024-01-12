export interface ILogger {
    info(msg: string | object): void;
    warn(msg: string | object, err?: Error): void;
    error(msg: string | object, err: Error): void;
    debug(msg: string | object): void;
}
