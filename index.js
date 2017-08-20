const addon = require("bindings")("addon");

/**
 * @typedef {number} Effect
 */

/**
 * @enum {Effect}
 */
const effects = {
    FULL_ON: 0,
    BREATH: 1,
    BREATH_CYCLE: 2,
    SINGLE: 3,
    WAVE: 4,
    RIPPLE: 5, 
    CROSS: 6,
    RAIN: 7,
    STAR: 8,
    SNAKE: 9,
    REC: 10,
    SPECTRUM: 11,
    RAPID_FIRE: 12,
    INDICATOR: 13,
    MULTI_1: 0xE0,
    MULTI_2: 0xE1,
    MULTI_3: 0xE2,
    MULTI_4: 0xE3, 	                      
    OFF: 0xFE
}

/**
 * @typedef {number} Device
 */

/**
 * @enum {Device}
 */
const devices = {
    MASTERKEYS_PRO_L: 0,
    MASTERKEYS_PRO_S: 1,
    MASTERKEYS_PRO_L_White: 2,
    MASTERKEYS_PRO_M_White: 3,
    MASTERMOUSE_L: 4,
    MASTERMOUSE_S: 5,
    MASTERKEYS_PRO_M: 6,
    MASTERKEYS_PRO_S_WHITE: 7

}

/**
 * @typedef {number} Layout
 */

/**
 * @enum {Layout}
 */
const layouts = {
    UNINIT: 0,
    US: 1,
    EU: 2
}

/**
 * Gets the current CPU usgae
 * @return {number} usgae
 */
function getCPUUsage() {
    return addon.GetCPUUsage();
}

/**
 * Gets the current RAM usgae
 * @return {number} usgae
 */
function getRAMUsage() {
    return addon.GetRAMUsage();
}

/**
 * Gets the current volume
 * @return {number} volume
 */
function getVolume() {
    return addon.GetVolume();
}

/**
 * Sets the device to control
 * @param {Device} device
 */
function setDevice(device) {
    addon.SetDevice(device);
}

/**
 * Verifies that the device is plugged in 
 * @return {boolean} plugged
 */
function isDevicePluggedIn() {
    return addon.IsDevicePluggedIn();
}

/**
 * Gets the keyboard layout
 * @return {Layout} layout
 */
function getLayout() {
    return addon.GetFormat();
}

/**
 * Enables/disables LED control
 * @param {boolean} enabled
 * @return {boolean} success
 */
function enableLEDControl(enabled) {
    return addon.EnableLEDControl(enabled);
}

/**
 * Sets the current keyboard effect
 * @param {Effect} effect
 * @return {boolean} success
 */
function setEffect(effect) {
    return addon.SwitchLEDEffect(effect);
}

/**
 * Changes the color of every key
 * @param {number} r
 * @param {number} g
 * @param {number} b
 * @return {boolean} success
 */
function setFullLEDColor(r, g, b) {
    return addon.SetFullLEDColor(r, g, b);
}

/**
 * Changes the color of a specific key
 * @param {number} row
 * @param {number} column
 * @param {number} r
 * @param {number} g
 * @param {number} b
 * @return {boolean} success
 */
function setLEDColor(row, column, r, g, b) {
    return addon.SetLEDColor(row, column, r, g, b);
}

module.exports = {
    effects,
    devices,
    layouts,
    getCPUUsage,
    getRAMUsage,
    getVolume,
    setDevice,
    isDevicePluggedIn,
    getLayout,
    enableLEDControl,
    setEffect,
    setFullLEDColor,
    setLEDColor
}