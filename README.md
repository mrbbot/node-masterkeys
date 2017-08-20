# node-masterkeys

A node wrapper for the CoolerMaster Custom Lighting SDK for MasterKeys keyboards.

> Note: This module is only designed to work with **Windows** based computers.

## Installation Instructions

1. First install the windows build tools: ```npm install --global --production windows-build-tools```
2. Then install the module: ```npm install --save node-masterkeys```

## Example

```js
const mk = require("node-masterkeys");

mk.setDevice(mk.devices.MASTERKEYS_PRO_S);

mk.enableLEDControl(true);

mk.setFullLEDColor(255, 0, 0);

setTimeout(function() {
    mk.enableLEDControl(false);
}, 3000);
```

Documentation can be found here: [https://mrbbot.github.io/node-masterkeys/global.html](https://mrbbot.github.io/node-masterkeys/global.html)