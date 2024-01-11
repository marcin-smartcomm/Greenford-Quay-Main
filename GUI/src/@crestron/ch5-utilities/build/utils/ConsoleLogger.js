"use strict";
// Copyright (C) 2018 to the present, Crestron Electronics, Inc.
// All rights reserved.
// No part of this software may be reproduced in any form, machine
// or natural, without the express written consent of Crestron Electronics.
// Use of this source code is subject to the terms of the Crestron Software License Agreement
// under which you licensed this source code.
Object.defineProperty(exports, "__esModule", { value: true });
class ConsoleLogger {
    debug(msg) {
        console.debug(msg);
    }
    error(msg, err) {
        console.error(err, msg);
    }
    info(msg) {
        console.info(msg);
    }
    warn(msg, err) {
        console.warn(msg, err);
    }
}
exports.ConsoleLogger = ConsoleLogger;
