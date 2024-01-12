/// <reference types="node" />
import { OutputLevelEnum } from '../enums';
import { IConfigOptions, ILogger } from '../interfaces';
import { IUtils } from "../interfaces/IUtils";
export declare class Utils implements IUtils {
    private readonly _logger;
    constructor(logger: ILogger);
    checkExistingDirectory(directoryName: string, loggingLevel: OutputLevelEnum): boolean;
    deleteDirectory(directoryName: string): void;
    /**
     * Method for checking input contract file must have cse2j extension
     *
     * @param fileName
     */
    validateFileExists(fileName: string): boolean;
    writeToFile(filePath: string, content: string): void;
    /**
     * Method readFromFile read content of file and return content as string.
     * @param {string} filePath
     * @param {string} [encodingFormat='utf8']
     */
    readFromFile(filePath: string, encodingFormat?: string): string;
    /**
     * Method for checking contract editor config file extension.
     *
     * @param fileName
     */
    validateContractFile(fileName: string): boolean;
    /**
     * Method for running restart/reload command on device
     *
     * @param distributorOptions
     * @param command
     */
    runSshCommand(distributorOptions: IConfigOptions, command: string): Promise<string>;
    getConnectOptions(distributorOptions: IConfigOptions): {
        host: string;
        username: string;
        password?: string | undefined;
        passphrase?: string | undefined;
        privateKey?: Buffer | undefined;
    };
}
