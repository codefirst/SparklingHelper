// This class wraps Xcode's DVTDeviceManager to manage iOS device.
class DeviceManager {
    private lazy var deviceManager = DVTDeviceManager.defaultDeviceManager()

    func allDevices() -> Set<DVTDevice> {
        return DVTDeviceManager.defaultDeviceManager().availableDevices
    }
}