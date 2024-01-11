/// <reference types="node" />
import { OutputLevelEnum } from "../enums";
import { IConfigOptions } from "./IConfigOptions";
export interface IUtils {
    checkExistingDirectory(directoryName: string, loggingLevel: OutputLevelEnum): boolean;
    deleteDirectory(directoryName: string): void;
    /**
     * Method for checking a file on the filesystem
     *
     * @param fileName
     */
    validateFileExists(fileName: string): boolean;
    /**
     * Method for checking contract editor config file extension.
     *
     * @param {string} fileName
     */
    validateContractFile(fileName: string): boolean;
    writeToFile(filePath: string, content: string): void;
    /**
     * Method for read the content of the file.
     *
     * @param {string} filePath
     */
    readFromFile(filePath: string, encodingFormat?: string): string;
    /**
     * Method for running a command on device
     *
     * @param distributorOptions
     * @param command
     */
    runSshCommand(distributorOptions: IConfigOptions, command: string): void;
    /**
     * Method for assembling the options object for connect
     *
     * @param distributorOptions
     */
    getConnectOptions(distributorOptions: IConfigOptions): {
        host: string;
        username: string;
        password?: string;
        passphrase?: string;
        privateKey?: Buffer;
    };
}
