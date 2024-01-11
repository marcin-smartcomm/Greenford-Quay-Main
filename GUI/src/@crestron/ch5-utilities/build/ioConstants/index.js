"use strict";
// Copyright (C) 2018 to the present, Crestron Electronics, Inc.
// All rights reserved.
// No part of this software may be reproduced in any form, machine
// or natural, without the express written consent of Crestron Electronics.
// Use of this source code is subject to the terms of the Crestron Software License Agreement
// under which you licensed this source code.
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const path_1 = __importDefault(require("path"));
class IoConstants {
    static archiveCreatedWithSize(projectName, extension, size) {
        return `Archive ${projectName}.${extension} has been successfully created. ${size} bytes.`;
    }
    static errorWithMessage(message) {
        return `Error: ${message}.`;
    }
    static directoryCreated(directoryName) {
        return `Directory ${directoryName} is empty. No files to archive.`;
    }
    static directoryDoesNotExist(directoryName) {
        return `Directory ${directoryName} does not exist. No files to archive.`;
    }
    static noArchiveFile(archiveFilePath) {
        return `Archive ${archiveFilePath} does not exist.`;
    }
    static sendReloadCommandToDevice(device) {
        return `Sending reload command to ${device} device`;
    }
    static errorOnConnectingToHostWithError(host, errorMessage) {
        return `Error on connection to ${host}:  ${errorMessage}. No success executing command.`;
    }
    static hashingError(errorMessage) {
        return `Hashing failed: ${errorMessage}`;
    }
    static getMetadataFilePath(projectName, directory) {
        directory = directory || IoConstants.temporaryArchiveDir;
        return path_1.default.resolve(directory, `${projectName}_manifest.json`);
    }
    static getAppUiManifestFilePath(sourceDirectory) {
        return path_1.default.resolve(sourceDirectory, "appui", "manifest");
    }
    static getTempArchiveFilePath(projectName, extension, directory) {
        directory = directory || IoConstants.temporaryArchiveDir;
        extension = extension || IoConstants.tempExtension;
        return `${directory}/${projectName}.${extension}`;
    }
    static checkingDirectoryExists(directoryName) {
        return `Checking for existing folder ${directoryName}.`;
    }
    static createdDirectory(directoryName) {
        return `Created directory ${directoryName}.`;
    }
    static fileDoesNotExist(fileName) {
        return `File ${fileName} has not been found.`;
    }
    static invalidContractFile(fileName) {
        return `Invalid file ${fileName}.Contract editor config file must have .cse2j extension.`;
    }
    static deviceOutput(data) {
        return `Device output: ${data}`;
    }
    static deviceError(data) {
        return `Device error: ${data}`;
    }
}
// default values used in the functionality. do not change these without carefull testing.
IoConstants.touchScreenReloadCommand = 'projectload';
IoConstants.touchScreenUpdateCommand = 'begindisplay';
IoConstants.touchScreenSftpDirectory = 'display';
IoConstants.controlSystemReloadCommand = 'CSProjectLoad';
IoConstants.controlSystemSftpDirectory = 'html';
IoConstants.tempExtension = 'ch5';
IoConstants.defaultExtension = 'ch5z';
IoConstants.temporaryArchiveDir = 'temp';
IoConstants.defaultUser = 'crestron';
IoConstants.defaultPassword = '';
IoConstants.AppUiManifestContent = 'apptype:ch5';
IoConstants.addingExtraParamsToManifest = 'Appending extra parameter from config to manifest file.';
IoConstants.connectedToDeviceAndUploading = 'Connected to device. Uploading archive file.';
IoConstants.connectViaSsh = 'Connected via ssh to device';
IoConstants.connectionClosed = 'Connection closed.';
IoConstants.connectionEnded = 'Connection has ended. Success executing command.';
IoConstants.sftUserConsoleLabel = 'SFTP username: ';
IoConstants.sftPasswordConsoleLabel = 'SFTP password: ';
IoConstants.NOENT = 'NOENT';
IoConstants.ENOENT = 'ENOENT';
// error messages
IoConstants.noIndexFile = 'No index.html file present.';
IoConstants.noManifestAndCreateWithDir = 'No appui and manifest file present. Creating directory and manifest file.';
IoConstants.noManifestAndCreate = 'No manifest file present. Creating manifest file.';
IoConstants.wrongAppType = 'Manifest file contains different type of app type.';
IoConstants.noConfiguration = 'Input configuration missing.';
IoConstants.errorConfiguration = 'Configuration error: ';
IoConstants.errorProjectName = 'Project name cannot be empty.';
IoConstants.errorDirectoryName = 'Directory name cannot be empty.';
IoConstants.errorOutputDirectoryName = 'Output directory name cannot be empty.';
IoConstants.somethingWentWrong = 'Something went wrong.';
IoConstants.helpCommand = 'help';
// success messages
IoConstants.deploymentComplete = 'Deployment complete.';
exports.default = IoConstants;
