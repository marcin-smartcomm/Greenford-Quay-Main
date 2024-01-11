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
const fs_1 = __importDefault(require("fs"));
const rimraf_1 = __importDefault(require("rimraf"));
const enums_1 = require("../enums");
const ssh2_1 = require("ssh2");
const ioConstants_1 = __importDefault(require("../ioConstants"));
class Utils {
    constructor(logger) {
        this._logger = logger;
    }
    checkExistingDirectory(directoryName, loggingLevel) {
        this._logger.debug(ioConstants_1.default.checkingDirectoryExists(directoryName));
        const existsDir = fs_1.default.existsSync(`${directoryName}`) ? fs_1.default.lstatSync(directoryName) : null;
        if (!existsDir || !existsDir.isDirectory) {
            fs_1.default.mkdirSync(directoryName);
            this._logger.debug(ioConstants_1.default.createdDirectory(directoryName));
            return false;
        }
        return true;
    }
    deleteDirectory(directoryName) {
        const existsDir = fs_1.default.existsSync(`${directoryName}`) ? fs_1.default.lstatSync(directoryName) : null;
        if (existsDir && existsDir.isDirectory) {
            rimraf_1.default.sync(directoryName);
        }
    }
    /**
     * Method for checking input contract file must have cse2j extension
     *
     * @param fileName
     */
    validateFileExists(fileName) {
        const existsArchive = fs_1.default.existsSync(fileName) ? fs_1.default.lstatSync(fileName).isFile() : null;
        if (!existsArchive) {
            throw new Error(ioConstants_1.default.fileDoesNotExist(fileName));
        }
        return true;
    }
    writeToFile(filePath, content) {
        fs_1.default.writeFileSync(filePath, content);
    }
    /**
     * Method readFromFile read content of file and return content as string.
     * @param {string} filePath
     * @param {string} [encodingFormat='utf8']
     */
    readFromFile(filePath, encodingFormat = 'utf8') {
        const fileContent = fs_1.default.readFileSync(filePath, encodingFormat);
        return fileContent;
    }
    /**
     * Method for checking contract editor config file extension.
     *
     * @param fileName
     */
    validateContractFile(fileName) {
        const fileExtension = "" + fileName.split('.').pop();
        if (fileExtension.toLocaleLowerCase() !== enums_1.ConfigExtensions.CSE2J_CONFIG_EXTENSION) {
            throw new Error(ioConstants_1.default.invalidContractFile(fileName));
        }
        return true;
    }
    /**
     * Method for running restart/reload command on device
     *
     * @param distributorOptions
     * @param command
     */
    runSshCommand(distributorOptions, command) {
        return new Promise((resolve, reject) => {
            const ssh2 = new ssh2_1.Client();
            ssh2.on('ready', () => {
                this._logger.info(ioConstants_1.default.connectViaSsh);
                ssh2.exec(command, (err, stream) => {
                    if (err)
                        throw err;
                    stream.on('close', () => {
                        this._logger.debug(ioConstants_1.default.connectionClosed);
                        ssh2.end();
                    }).on('data', (data) => {
                        this._logger.debug(ioConstants_1.default.deviceOutput(data));
                    }).stderr.on('data', (data) => {
                        this._logger.debug(ioConstants_1.default.deviceError(data));
                        reject(data);
                    });
                });
            }).on('end', () => {
                this._logger.info(ioConstants_1.default.connectionEnded);
                resolve('done');
            }).connect(this.getConnectOptions(distributorOptions));
        });
    }
    getConnectOptions(distributorOptions) {
        let options = {
            host: distributorOptions.controlSystemHost,
            username: distributorOptions.sftpUser,
        };
        if (distributorOptions.privateKey) {
            options.privateKey = fs_1.default.readFileSync(distributorOptions.privateKey);
            if (distributorOptions.passphrase) {
                options.passphrase = distributorOptions.passphrase;
            }
        }
        else {
            options.password = distributorOptions.sftpPassword;
        }
        return options;
    }
}
exports.Utils = Utils;
