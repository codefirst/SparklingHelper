class RequestProvisioning {
    private let portalSource = IDECodesignIssueResolutionPortalSource.defaultPortalSource()

    private let account : DVTDeveloperAccount
    private let certificate : DVTSigningCertificate
    private let device: DVTDevice

    // obtain from Xcode analysis result. Why watchos?
    private let platformIdentifier = "com.apple.platform.watchos"

    // Could not specify any app id feature at free provisioning account
    private let requiredFeatures = DVTAppIDFeatures()

    private let logAspect = DVTLogAspect.logAspectWithName("sparkling")

    init(account : DVTDeveloperAccount, certificate : DVTSigningCertificate, device: DVTDevice) {
        self.account = account
        self.certificate = certificate
        self.device = device
    }

    func call(bundleIdentifier: String) {
        // FIXME: Add some error handling, or wait for result.
        portalSource.requestDevelopmentProvisioningProfileForAccount(
            self.account,
            signingCertificate: self.certificate,
            platformIdentifier: self.platformIdentifier,
            bundleIdentifiers: NSSet(object: bundleIdentifier),
            requiredCodesignableDevices: NSSet(object: self.snapshotDevice()),
            requiredFeatures: self.requiredFeatures,
            logAspect: logAspect)
    }

    private func snapshotDevice() -> DVTCodesignableDeviceSnapshot{
        return DVTCodesignableDeviceSnapshot.snapshotFromCodesignableDevice(self.device) as! DVTCodesignableDeviceSnapshot
    }
}