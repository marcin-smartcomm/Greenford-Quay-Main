import { IConfigOptions } from "./IConfigOptions";
export interface ICh5Archiver {
    createArchive(options: IConfigOptions): Promise<string>;
}
