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
exports.Ch5CliUtil = void 0;
var chalk_1 = __importDefault(require("chalk"));
var ch5_utilities_1 = require("@crestron/ch5-utilities");
var Ch5CliUtil = /** @class */ (function () {
    function Ch5CliUtil() {
    }
    Ch5CliUtil.prototype.writeError = function (error) {
        console.log(chalk_1.default.red(error.name + ": " + error.message));
    };
    Ch5CliUtil.prototype.getOutputLevel = function (options) {
        if (options.quiet) {
            return ch5_utilities_1.OutputLevel.Quiet;
        }
        if (options.verbose) {
            return ch5_utilities_1.OutputLevel.Verbose;
        }
        return ch5_utilities_1.OutputLevel.Normal;
    };
    Ch5CliUtil.prototype.getDeviceType = function (deviceTypeInput) {
        switch (deviceTypeInput) {
            case 'touchscreen':
                return ch5_utilities_1.DeviceType.TouchScreen;
            case 'controlsystem':
                return ch5_utilities_1.DeviceType.ControlSystem;
            case 'web':
                return ch5_utilities_1.DeviceType.Web;
            case 'mobile':
                return ch5_utilities_1.DeviceType.Mobile;
            default:
                throw new Error("Unknown device type " + deviceTypeInput);
        }
    };
    return Ch5CliUtil;
}());
exports.Ch5CliUtil = Ch5CliUtil;
