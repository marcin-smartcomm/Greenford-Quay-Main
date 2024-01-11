import { ICh5Archiver, IConfigOptions, IMetadataGenerator } from "../interfaces";
import { IUtils } from "../interfaces/IUtils";
export declare class Ch5Archiver implements ICh5Archiver {
    private readonly _utils;
    private readonly _metadataGenerator;
    constructor(utils: IUtils, metadataGenerator: IMetadataGenerator);
    createArchive(options: IConfigOptions): Promise<string>;
    private validateDirectoryContents;
    /**
     * Method addContractFileToConfig create config dir if not exist and
     * read the cse2j file and write file in config folder
     * @param {IConfigOptions} options
     */
    private addContractFileToConfig;
    private archive;
    private registerOutputEvents;
    private registerArchiveEvents;
}
