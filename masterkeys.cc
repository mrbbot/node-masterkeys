#include <nan.h>
#include <SDKDLL.h>

NAN_METHOD(GetCPUUsage) {
    LONG usage = GetNowCPUUsage();
    int intUsage = (int) usage;
    info.GetReturnValue().Set(intUsage);
}

NAN_METHOD(GetRAMUsage) {
    DWORD usage = GetRamUsage();
    int intUsage = (int) usage;
    info.GetReturnValue().Set(intUsage);
}

NAN_METHOD(GetVolume) {
    float volume = GetNowVolumePeekValue();
    info.GetReturnValue().Set(volume);
};

NAN_METHOD(SetDevice) {
    if(!info[0]->IsNumber()) {
        Nan::ThrowError("Invalid device!");
        return;
    }

    int deviceIndex = (int) info[0]->NumberValue();
    DEVICE_INDEX device = static_cast<DEVICE_INDEX>(deviceIndex);

    SetControlDevice(device);
}

NAN_METHOD(IsDevicePluggedIn) {
    bool devicePluggedIn = IsDevicePlug();
    info.GetReturnValue().Set(devicePluggedIn);
}

NAN_METHOD(GetFormat) {
    int layout = (int) GetDeviceLayout();
    info.GetReturnValue().Set(layout);
}

NAN_METHOD(EnableLEDControl) {
    if(!info[0]->IsBoolean()) {
        Nan::ThrowError("Invalid enable state!");
        return;
    }

    bool enableLED = info[0]->BooleanValue();
    bool result = EnableLedControl(enableLED);
    info.GetReturnValue().Set(result); 
}

NAN_METHOD(SwitchLEDEffect) {
    if(!info[0]->IsNumber()) {
        Nan::ThrowError("Invalid effect!");
        return;
    }

    int effectIndex = (int) info[0]->NumberValue();
    EFF_INDEX effect = static_cast<EFF_INDEX>(effectIndex);
    bool result = SwitchLedEffect(effect);
    info.GetReturnValue().Set(result);
}

NAN_METHOD(RefreshLED) {
    if(!info[0]->IsBoolean()) {
        Nan::ThrowError("Invalid auto-refresh state!");
        return;
    }

    bool autoRefresh = info[0]->BooleanValue();

    bool result = RefreshLed(autoRefresh);
    info.GetReturnValue().Set(result);
}

NAN_METHOD(SetFullLEDColor) {
    if(!info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsNumber()) {
        Nan::ThrowError("Invalid arguments!");
        return;
    }

    BYTE r = (BYTE) info[0]->NumberValue();
    BYTE g = (BYTE) info[1]->NumberValue();
    BYTE b = (BYTE) info[2]->NumberValue();

    bool result = SetFullLedColor(r, g, b);
    info.GetReturnValue().Set(result);
}

NAN_METHOD(SetLEDColor) {
    if(!info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsNumber() || !info[3]->IsNumber() || !info[4]->IsNumber()) {
        Nan::ThrowError("Invalid arguments!");
        return;
    }

    int row = (int) info[0]->NumberValue();
    int column = (int) info[1]->NumberValue();

    BYTE r = (BYTE) info[2]->NumberValue();
    BYTE g = (BYTE) info[3]->NumberValue();
    BYTE b = (BYTE) info[4]->NumberValue();

    bool result = SetLedColor(row, column, r, g, b);
    info.GetReturnValue().Set(result);
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, GetCPUUsage);
    NAN_EXPORT(target, GetRAMUsage);
    NAN_EXPORT(target, GetVolume);
    NAN_EXPORT(target, SetDevice);
    NAN_EXPORT(target, IsDevicePluggedIn);
    NAN_EXPORT(target, GetFormat);
    NAN_EXPORT(target, EnableLEDControl);
    NAN_EXPORT(target, SwitchLEDEffect);
    NAN_EXPORT(target, RefreshLED);
    NAN_EXPORT(target, SetFullLEDColor);
    NAN_EXPORT(target, SetLEDColor);
}

NODE_MODULE(addon, Initialize)