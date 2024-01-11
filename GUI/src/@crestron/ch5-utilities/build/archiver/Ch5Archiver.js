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
const fs_1 = __importDefault(require("fs"));
const archiver_1 = __importDefault(require("archiver"));
const enums_1 = require("../enums");
const ioConstants_1 = __importDefault(require("../ioConstants"));
class Ch5Archiver {
    constructor(utils, metadataGenerator) {
        this._utils = utils;
        this._metadataGenerator = metadataGenerator;
    }
    createArchive(options) {
        return __awaiter(this, void 0, void 0, function* () {
            // validate app contents
            this.validateDirectoryContents(options);
            // check for contract editor config file. if exsit then process it.
            if (!!options.contractFile) {
                this.addContractFileToConfig(options);
            }
            // create outputDirectory, else we cannot create temp directory
            this._utils.checkExistingDirectory(options.outputDirectory, options.outputLevel);
            // create app ui manifest file
            this._metadataGenerator.generateAppUiManifest(options);
            // app ui manifest file
            yield this._metadataGenerator.addAppUiMetadata(options, ioConstants_1.default.getAppUiManifestFilePath(options.directoryName));
            // change target directory to outputDirectory/temp
            const tmpOptions = Object.assign({}, options);
            tmpOptions.outputDirectory = tmpOptions.outputDirectory + '/temp';
            // inner archive
            yield this.archive(tmpOptions, enums_1.ArchiveExtensions.CH5_EXTENSION);
            // project manifest file
            yield this._metadataGenerator.generateMetadataFile(tmpOptions, enums_1.ArchiveExtensions.CH5_EXTENSION);
            // change source directory to outputDirectory/temp
            const tmpOptions2 = Object.assign({}, options);
            tmpOptions2.directoryName = tmpOptions.outputDirectory;
            // final archive
            const result = yield this.archive(tmpOptions2, enums_1.ArchiveExtensions.CH5Z_EXTENSION);
            // delete temp directory
            this._utils.deleteDirectory(tmpOptions.outputDirectory);
            return result;
        });
    }
    validateDirectoryContents(options) {
        const indexFilePath = `${options.directoryName}/index.html`;
        this._utils.validateFileExists(indexFilePath);
    }
    /**
     * Method addContractFileToConfig create config dir if not exist and
     * read the cse2j file and write file in config folder
     * @param {IConfigOptions} options
     */
    addContractFileToConfig(options) {
        const contractFile = "" + options.contractFile;
        const dirName = `config`;
        const contractFileName = "contract.cse2j";
        const configDir = `${options.directoryName}/${dirName}`;
        const targetFilePath = `${options.directoryName}/${dirName}/${contractFileName}`;
        this._utils.validateFileExists(contractFile);
        this._utils.validateContractFile(contractFile);
        // create config folder under project dir if not exist.
        this._utils.checkExistingDirectory(configDir, options.outputLevel);
        const fileContent = this._utils.readFromFile(contractFile);
        if (this._utils.checkExistingDirectory(configDir, options.outputLevel)) {
            this._utils.writeToFile(targetFilePath, fileContent);
        }
    }
    archive(options, extension) {
        return new Promise((resolve, reject) => {
            const outputDirectory = options.outputDirectory;
            this._utils.checkExistingDirectory(outputDirectory, options.outputLevel);
            const outputFileName = `${outputDirectory}/${options.projectName}.${extension}`;
            const output = fs_1.default.createWriteStream(outputFileName);
            this.registerOutputEvents(output, outputFileName, resolve, reject);
            const archive = archiver_1.default('zip', {
                zlib: { level: 9 }
            });
            this.registerArchiveEvents(archive, outputFileName, resolve, reject);
            // pipe archive data to the file
            archive.pipe(output);
            // append source directory
            archive.directory(options.directoryName, '');
            // wrap up
            archive.finalize();
        });
    }
    registerOutputEvents(output, outputFileName, resolve, reject) {
        output.on('close', () => {
            resolve(outputFileName);
        });
        output.on('finish', () => {
            resolve(outputFileName);
        });
        output.on('end', () => {
            resolve(outputFileName);
        });
        output.on('error', (error) => {
            reject(error);
        });
    }
    registerArchiveEvents(archive, outputFileName, resolve, reject) {
        archive.on('warning', (err) => {
            if (err.code === 'ENOENT') {
                // log warning
                resolve(outputFileName);
            }
            else {
                reject(err);
            }
        });
        // good practice to catch this error explicitly
        archive.on('error', (error) => {
            reject(error);
        });
    }
}
exports.Ch5Archiver = Ch5Archiver;
