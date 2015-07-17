// This class wraps Xcode's DVTDeviceManager to manage iOS device.
class DeviceManager {
    private lazy var deviceManager = DVTDeviceManager.defaultDeviceManager()

    func allDevices() -> Set<DVTDevice> {
        return DVTDeviceManager.defaultDeviceManager().availableDevices
    }

    func deviceForName(name : String) -> DVTDevice? {
        for device in allDevices() {
            if device.name == name {
                return device
            }
        }
        return nil
    }
}