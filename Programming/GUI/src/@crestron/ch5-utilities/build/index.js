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
Object.defineProperty(exports, "__esModule", { value: true });
const utils_1 = require("./utils");
const archiver_1 = require("./archiver");
const distributor_1 = require("./distributor");
const metadata_1 = require("./metadata");
var enums_1 = require("./enums");
exports.DeviceType = enums_1.DeviceTypeEnum;
var enums_2 = require("./enums");
exports.OutputLevel = enums_2.OutputLevelEnum;
exports.archiver = (options) => __awaiter(this, void 0, void 0, function* () {
    const logger = new utils_1.ConsoleLogger();
    const utils = new utils_1.Utils(logger);
    const metadataGenerator = new metadata_1.MetadataGenerator(utils);
    const ch5Archiver = new archiver_1.Ch5Archiver(utils, metadataGenerator);
    yield ch5Archiver.createArchive(options);
});
exports.distributor = (filename, options) => __awaiter(this, void 0, void 0, function* () {
    const logger = new utils_1.ConsoleLogger();
    const utils = new utils_1.Utils(logger);
    const dist = new distributor_1.Ch5Distributor(utils, logger);
    yield dist.initializeTransferWithCredentialsCheck(filename, options);
});
