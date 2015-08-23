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
        portalSource.requestDevelopmentProvisioningProfileForAccount(
            self.account,
            signingCertificate: self.certificate,
            platformIdentifier: self.platformIdentifier,
            appIDRequirements: NSSet(object: appIDRequirement(bundleIdentifier)),
            requiredCodesignableDevices: self.snapshotDevices(),
            logAspect: logAspect)
        .waitUntilFinished()
    }

    private func snapshotDevices() -> NSSet {
        var devices = device.proxiedDevices?.map { snapshot($0) }
        devices?.append(snapshot(self.device))
        return NSSet(array: devices ?? [])
    }

    private func appIDRequirement(bundleIdentifier : String) -> IDECodesignIssueResolverAppIDRequirements {
        return IDECodesignIssueResolverAppIDRequirements(
            bundleIdentifier: bundleIdentifier,
            entitlements: [
                "application-identifier":
                    "$(AppIdentifierPrefix)\(bundleIdentifier)",
                "keychain-access-groups" :
                    ["$(AppIdentifierPrefix)\(bundleIdentifier)"]
            ],
            features: requiredFeatures)
    }

    private func snapshot(device : AnyObject) ->  DVTCodesignableDeviceSnapshot {
        return DVTCodesignableDeviceSnapshot.snapshotFromCodesignableDevice(device) as! DVTCodesignableDeviceSnapshot
    }
}