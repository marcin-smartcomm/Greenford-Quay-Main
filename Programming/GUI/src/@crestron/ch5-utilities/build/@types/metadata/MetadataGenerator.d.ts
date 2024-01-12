import { IConfigOptions, IMetadataGenerator, IUtils } from '../interfaces';
export declare class MetadataGenerator implements IMetadataGenerator {
    private readonly _utils;
    constructor(utils: IUtils);
    generateMetadataFile(options: IConfigOptions, extension: string): Promise<void>;
    generateAppUiManifest(options: IConfigOptions): void;
    addAppUiMetadata(options: IConfigOptions, appUiManifestPath: string): Promise<void>;
}
