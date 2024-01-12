"use strict";
// Copyright (C) 2018 to the present, Crestron Electronics, Inc.
// All rights reserved.
// No part of this software may be reproduced in any form, machine
// or natural, without the express written consent of Crestron Electronics.
// Use of this source code is subject to the terms of the Crestron Software License Agreement
// under which you licensed this source code.
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const path_1 = __importDefault(require("path"));
const ioConstants_1 = __importDefault(require("../ioConstants"));
const enums_1 = require("../enums");
const ssh2_sftp_client_1 = __importDefault(require("ssh2-sftp-client"));
class Ch5Distributor {
    constructor(utils, logger) {
        this._utils = utils;
        this._logger = logger;
    }
    /**
     * Method will validate the existence of archive to be deployed
     * if this file exists it will be deployed to provided target from config
     * also this method provides solution for prompting credentials inline inputs.
     * @param filename
     * @param distributorOptions
     */
    initializeTransferWithCredentialsCheck(filename, distributorOptions) {
        return __awaiter(this, void 0, void 0, function* () {
            const existsArchive = this._utils.validateFileExists(filename);
            if (!existsArchive) {
                throw new Error(ioConstants_1.default.noArchiveFile(filename));
            }
            distributorOptions.sftpDirectory = Ch5Distributor.getSftpDirectory(distributorOptions);
            distributorOptions.sftpUser = Ch5Distributor.getSftpUser(distributorOptions);
            distributorOptions.sftpPassword = Ch5Distributor.getSftpPassword(distributorOptions);
            distributorOptions.privateKey = Ch5Distributor.getPrivateKey(distributorOptions);
            distributorOptions.passphrase = Ch5Distributor.getPassphrase(distributorOptions);
            if (distributorOptions.deviceType === enums_1.DeviceTypeEnum.TouchScreen && distributorOptions.slowMode) {
                this._logger.info(`Sending ${ioConstants_1.default.touchScreenUpdateCommand} command to device...`);
                yield this._utils.runSshCommand(distributorOptions, ioConstants_1.default.touchScreenUpdateCommand);
            }
            yield this.transferFiles(distributorOptions, filename);
            yield this.reloadDevice(distributorOptions, filename);
        });
    }
    reloadDevice(distributorOptions, filename) {
        return __awaiter(this, void 0, void 0, function* () {
            let command = '';
            switch (distributorOptions.deviceType) {
                case enums_1.DeviceTypeEnum.TouchScreen:
                    command = ioConstants_1.default.touchScreenReloadCommand;
                    break;
                case enums_1.DeviceTypeEnum.ControlSystem:
                    command = ioConstants_1.default.controlSystemReloadCommand + ' -U:CH5 -P:' + `${path_1.default.basename(filename)}`;
                    break;
                case enums_1.DeviceTypeEnum.Mobile:
                    command = ioConstants_1.default.controlSystemReloadCommand + ' -T:MobileApp -U:CH5 -P:' + `${path_1.default.basename(filename)}`;
                    break;
                case enums_1.DeviceTypeEnum.Web:
                    command = ioConstants_1.default.controlSystemReloadCommand + ' -T:WebXPanel -U:CH5 -P:' + `${path_1.default.basename(filename)}`;
                    break;
                default:
                    throw new Error('Unknown device type');
            }
            this._logger.info(ioConstants_1.default.sendReloadCommandToDevice(distributorOptions.deviceType) + ':' + command);
            yield this._utils.runSshCommand(distributorOptions, command);
        });
    }
    transferFiles(distributorOptions, filename) {
        return __awaiter(this, void 0, void 0, function* () {
            const sftp = new ssh2_sftp_client_1.default();
            try {
                yield sftp.connect(this._utils.getConnectOptions(distributorOptions));
                let { sftpDirectory } = distributorOptions;
                this._logger.info(ioConstants_1.default.connectedToDeviceAndUploading);
                if (distributorOptions.deviceType === enums_1.DeviceTypeEnum.Web) {
                    // find if output directory is HTML or html
                    const matchingDirs = yield sftp.list('/', `${sftpDirectory.toUpperCase()}|${sftpDirectory.toLowerCase()}`);
                    sftpDirectory = `/${matchingDirs[0].name}/${distributorOptions.projectName}`;
                }
                const targetPath = `${sftpDirectory}/${path_1.default.basename(filename)}`;
                const pathExists = yield sftp.exists(sftpDirectory);
                // checking if path is a directory. Creating it otherwise
                if (pathExists !== 'd') {
                    this._logger.debug(`Creating directory ${sftpDirectory}.`);
                    yield sftp.mkdir(`${sftpDirectory}`, true);
                    this._logger.debug(`Created directory ${sftpDirectory}. Now uploading`);
                }
                this._logger.debug(`Trying to upload file to ${targetPath}.`);
                yield sftp.put(filename, targetPath, { autoClose: false });
                this._logger.debug(`Uploaded file.`);
            }
            catch (err) {
                throw new Error(ioConstants_1.default.errorOnConnectingToHostWithError(distributorOptions.controlSystemHost, err.message));
            }
            finally {
                yield sftp.end();
                this._logger.debug('Closing sftp connection.');
            }
        });
    }
    static getSftpDirectory(distributorOptions) {
        if (distributorOptions.sftpDirectory) {
            return distributorOptions.sftpDirectory;
        }
        switch (distributorOptions.deviceType) {
            case enums_1.DeviceTypeEnum.TouchScreen:
                return ioConstants_1.default.touchScreenSftpDirectory;
            case enums_1.DeviceTypeEnum.ControlSystem:
            case enums_1.DeviceTypeEnum.Mobile:
            case enums_1.DeviceTypeEnum.Web:
                return ioConstants_1.default.controlSystemSftpDirectory;
            default:
                throw new Error('SFTP directory is not set.');
        }
    }
    static getSftpUser(distributorOptions) {
        return distributorOptions.sftpUser || ioConstants_1.default.defaultUser;
    }
    static getSftpPassword(distributorOptions) {
        return distributorOptions.sftpPassword || ioConstants_1.default.defaultPassword;
    }
    static getPrivateKey(distributorOptions) {
        return distributorOptions.privateKey || undefined;
    }
    static getPassphrase(distributorOptions) {
        return distributorOptions.passphrase || undefined;
    }
}
exports.Ch5Distributor = Ch5Distributor;
