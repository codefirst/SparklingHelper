class CertificateManager {
    private let certificateManager = DVTSigningCertificateManager.defaultCertificateManager() as! DVTSigningCertificateManager

    func certificates() -> Set<DVTSigningCertificate> {
        return self.certificateManager.signingCertificates as! Set<DVTSigningCertificate>
    }
}