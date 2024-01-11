import { IConfigOptions } from "./IConfigOptions";
export interface IMetadataGenerator {
    generateMetadataFile(options: IConfigOptions, extension: string): Promise<void>;
    generateAppUiManifest(options: IConfigOptions): void;
    addAppUiMetadata(options: IConfigOptions, appUiManifestPath: string): Promise<void>;
}
