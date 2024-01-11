import { IConfigOptions, ILogger } from "../interfaces";
import { IUtils } from "../interfaces/IUtils";
export declare class Ch5Distributor {
    private readonly _utils;
    private readonly _logger;
    constructor(utils: IUtils, logger: ILogger);
    /**
     * Method will validate the existence of archive to be deployed
     * if this file exists it will be deployed to provided target from config
     * also this method provides solution for prompting credentials inline inputs.
     * @param filename
     * @param distributorOptions
     */
    initializeTransferWithCredentialsCheck(filename: string, distributorOptions: IConfigOptions): Promise<void>;
    private reloadDevice;
    private transferFiles;
    private static getSftpDirectory;
    private static getSftpUser;
    private static getSftpPassword;
    private static getPrivateKey;
    private static getPassphrase;
}
