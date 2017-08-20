const mk = require("./index");

mk.setDevice(mk.devices.MASTERKEYS_PRO_S);

mk.enableLEDControl(true);

mk.setLEDColor(0, 0, 255, 0, 0);

setTimeout(function() {
    mk.enableLEDControl(false);
}, 3000);

console.log(mk.isDevicePluggedIn());