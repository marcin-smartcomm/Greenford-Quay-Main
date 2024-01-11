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
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const fs_1 = __importDefault(require("fs"));
const ioConstants_1 = __importDefault(require("../ioConstants"));
const path = __importStar(require("path"));
const sha256File = require('sha256-file');
class MetadataGenerator {
    constructor(utils) {
        this._utils = utils;
    }
    generateMetadataFile(options, extension) {
        return new Promise((resolve, reject) => {
            const archiveFilePath = `${options.outputDirectory}/${options.projectName}.${extension}`;
            const archiveFile = fs_1.default.lstatSync(archiveFilePath);
            try {
                options.additionalProjectManifestParameters = options.additionalProjectManifestParameters || {};
                const metadata = Object.assign({ projectname: `${options.projectName}.${extension}`, modifiedtime: archiveFile.mtime.toISOString(), "sha-256": sha256File(archiveFilePath) }, options.additionalProjectManifestParameters);
                fs_1.default.writeFileSync(ioConstants_1.default.getMetadataFilePath(options.projectName, options.outputDirectory), JSON.stringify(metadata));
                resolve();
            }
            catch (error) {
                reject(error);
            }
        });
    }
    generateAppUiManifest(options) {
        const appUiPath = path.resolve(options.directoryName, 'appui');
        this._utils.checkExistingDirectory(appUiPath, options.outputLevel);
        const manifestFilePath = path.resolve(appUiPath, 'manifest');
        this._utils.writeToFile(manifestFilePath, ioConstants_1.default.AppUiManifestContent);
    }
    addAppUiMetadata(options, appUiManifestPath) {
        return new Promise((resolve, reject) => {
            try {
                this._utils.validateFileExists(appUiManifestPath);
                if (!options.additionalAppuiManifestParameters) {
                    resolve();
                }
                const params = options.additionalAppuiManifestParameters;
                let stream = fs_1.default.createWriteStream(appUiManifestPath, { flags: 'a' });
                Object.keys(options.additionalAppuiManifestParameters).forEach((key) => {
                    stream.write(`\r\n${key}:${params[key]}`);
                });
                stream.end();
                resolve();
            }
            catch (e) {
                reject(e);
            }
        });
    }
}
exports.MetadataGenerator = MetadataGenerator;
