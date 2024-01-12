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
const enums_1 = require("./enums");
const index_1 = require("./index");
const config = {
    "projectName": "showcase-app",
    "directoryName": "../../library/showcase-app/dist",
    "outputDirectory": "output-test",
    "outputLevel": enums_1.OutputLevelEnum.Verbose,
    "additionalAppuiManifestParameters": {
        "testing-key": "testing-val",
        "testing-key1": "testing-val1",
        "testing-key2": "testing-val2",
        "testing-key3": "testing-val3"
    },
    "additionalProjectManifestParameters": {
        "testing-metadata": "testing-metadata",
        "testing-metadata1": "testing-metadata2"
    },
    "controlSystemHost": "192.168.2.44",
    "sftpUser": "crestron",
    "sftpPassword": "",
    "promptForCredential": false,
    "sftpDirectory": "display",
    "deviceType": enums_1.DeviceTypeEnum.TouchScreen,
    "contractFile": undefined,
    "privateKey": undefined,
    "passphrase": undefined,
    "slowMode": false
};
let commands = process.argv;
if (commands.includes('archive')) {
    index_1.archiver(config)
        .then(() => console.log('Archiving is done'));
}
else if (commands.includes('distribute')) {
    index_1.distributor(path_1.default.resolve(config.outputDirectory, `${config.projectName}.ch5z`), config)
        .then(() => {
        console.log('Distribution is done');
        process.exit(0);
    })
        .catch(err => {
        console.error(err);
        process.exit(1);
    });
}
else {
    throw new Error('Unknown command');
}
