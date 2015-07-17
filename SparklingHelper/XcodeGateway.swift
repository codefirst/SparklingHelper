// Gateway for Xcode's internal class
class XcodeGateway {
    lazy var deviceManager = DeviceManager()
    lazy var accountManager = AccountManager()
    lazy var certificateManager = CertificateManager()
}