import { OutputLevelEnum, DeviceTypeEnum } from '../enums/';
export interface IConfigOptions {
    projectName: string;
    directoryName: string;
    outputDirectory: string;
    outputLevel: OutputLevelEnum;
    additionalAppuiManifestParameters: IAdditionalParameters;
    additionalProjectManifestParameters: IAdditionalParameters;
    controlSystemHost: string;
    sftpUser: string;
    sftpPassword: string;
    promptForCredential: boolean;
    sftpDirectory: string;
    deviceType: DeviceTypeEnum;
    contractFile: string | undefined;
    privateKey: string | undefined;
    passphrase: string | undefined;
    slowMode: boolean;
}
export interface IAdditionalParameters {
    [index: string]: string;
}
