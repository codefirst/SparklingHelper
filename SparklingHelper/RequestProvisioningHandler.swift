class RequestProvisioningHandler {
    private let xcode : XcodeGateway
    private let query : [String:String]

    init(xcode : XcodeGateway, query : [String:String]) {
        self.xcode = xcode
        self.query = query
    }

    func call() -> NSObject {
        if let username = query["username"],
            let certificateName = query["certificateName"],
            let deviceName = query["deviceName"],
            let bundleIdentifier = query["bundleIdentifier"],
            let account = self.xcode.accountManager.accountForUsername(username),
            let certificate = self.xcode.certificateManager.certificateForCommonName(certificateName),
            let device = self.xcode.deviceManager.deviceForName(deviceName)
        {
            RequestProvisioning(account: account, certificate: certificate, device: device).call(bundleIdentifier)
            return ["status": "ok"]
        } else {
            return ["status": "invalid parameter"]
        }
    }
}