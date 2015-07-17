class CertificateManager {
    private let certificateManager = DVTSigningCertificateManager.defaultCertificateManager() as! DVTSigningCertificateManager

    func certificates() -> Set<DVTSigningCertificate> {
        return self.certificateManager.signingCertificates as! Set<DVTSigningCertificate>
    }

    func certificateForCommonName(commonName : String) -> DVTSigningCertificate? {
        for certificate in self.certificates() {
            if certificate.commonName == commonName {
                return certificate
            }
        }
        return nil
    }
}