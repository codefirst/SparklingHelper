//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//
#import "DVTFoundation.h"

#pragma mark Blocks

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

#pragma mark Named Structures
/*
@interface IDECodesignIssueResolver : NSObject
{
    IDECodesignIssueResolutionPortalSource *_portal;
    DVTSigningCertificateManager *_certificateManager;
    DVTProvisioningProfileManager *_provisioningProfileManager;
}

+ (id)defaultProvider;
@property(retain) DVTProvisioningProfileManager *provisioningProfileManager; // @synthesize provisioningProfileManager=_provisioningProfileManager;
@property(retain) DVTSigningCertificateManager *certificateManager; // @synthesize certificateManager=_certificateManager;
@property(retain) IDECodesignIssueResolutionPortalSource *portal; // @synthesize portal=_portal;
- (void).cxx_destruct;
- (id)_resolutionOptionsForMissingProfilesWithAccount:(id)arg1 portalTeamID:(id)arg2 signingCertificate:(id)arg3 platformIdentifier:(id)arg4 bundleIdentifiers:(id)arg5 requiredFeaturesOrNil:(id)arg6 requiredCodesignableDevicesOrNil:(id)arg7 provisioningProfileType:(unsigned long long)arg8 logAspect:(id)arg9;
- (id)_resolutionOptionsForMissingNewestCertWithAccount:(id)arg1 portalTeamID:(id)arg2 certificiateKind:(id)arg3 platformIdentifier:(id)arg4 existingCertificateSerialNumber:(id)arg5 logAspect:(id)arg6;
- (id)_resolutionOptionsForNoCertWithAccount:(id)arg1 portalTeamID:(id)arg2 certificiateKind:(id)arg3 platformIdentifier:(id)arg4 logAspect:(id)arg5;
- (id)determineResolutionOptionsForAccount:(id)arg1 portalTeamID:(id)arg2 certificateKind:(id)arg3 installerCertificateKindOrNil:(id)arg4 platformIdentifier:(id)arg5 bundleIdentifiersOrNil:(id)arg6 requireProvisioningProfiles:(BOOL)arg7 requiredFeaturesOrNil:(id)arg8 requiredEntitlementsOrNil:(id)arg9 requiredCodesignableDevicesOrNil:(id)arg10 alreadyRegisteredCodesignableDevices:(BOOL)arg11 provisioningProfileType:(unsigned long long)arg12 logAspectOrNil:(id)arg13;
- (id)determineResolutionOptionsForInputs:(id)arg1 account:(id)arg2 logAspectOrNil:(id)arg3;
- (id)logAspect;
- (id)initWithPortalInfoSource:(id)arg1 certificateManager:(id)arg2 provisioningProfileManager:(id)arg3;

@end*/

@interface IDECodesignIssueResolverAppIDRequirements : NSObject
{
    NSString *_bundleIdentifier;
    NSDictionary *_requiredEntitlements;
    DVTAppIDFeatures *_requiredFeatures;
}

+ (IDECodesignIssueResolverAppIDRequirements*)appIDRequirementsWithBundleIdentifier:(id)arg1 entitlements:(id)arg2 features:(id)arg3;
@property(retain) DVTAppIDFeatures *requiredFeatures; // @synthesize requiredFeatures=_requiredFeatures;
@property(retain) NSDictionary *requiredEntitlements; // @synthesize requiredEntitlements=_requiredEntitlements;
@property(retain) NSString *bundleIdentifier; // @synthesize bundleIdentifier=_bundleIdentifier;
- (id)description;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
@end


@interface IDECodesignIssueResolutionPortalSource : NSObject
{
}

+ (id)concurrentQueue;
+ (id)defaultPortalSource;
- (id)requestDistributionProvisioningProfileForAccount:(id)arg1 signingCertificate:(id)arg2 platformIdentifier:(id)arg3 bundleIdentifiers:(id)arg4 includeDevices:(BOOL)arg5 logAspect:(id)arg6;
- (id)_requestDistributionProvisioningProfileWithPortalPlatform:(id)arg1 subPlatform:(id)arg2 bundleIdentifier:(id)arg3 includeDevices:(BOOL)arg4 token:(id)arg5 logAspect:(id)arg6;
- (DVTFuture*)requestDevelopmentProvisioningProfileForAccount:(id)arg1 signingCertificate:(id)arg2 platformIdentifier:(id)arg3 appIDRequirements:(id)arg4 requiredCodesignableDevices:(id)arg5 logAspect:(id)arg6;
- (id)_requestDevelopmentProvisioningProfileWithPortalPlatform:(id)arg1 subPlatform:(id)arg2 bundleIdentifier:(id)arg3 requiredFeatures:(id)arg4 token:(id)arg5 logAspect:(id)arg6;
- (id)_registerCodeSignableDevice:(id)arg1 withPortalPlatform:(id)arg2 token:(id)arg3 logAspect:(id)arg4;
- (id)_requestProvisioningProfileWithPortalPlatform:(id)arg1 bundleIdentifier:(id)arg2 token:(id)arg3 profileOp:(id)arg4 logAspect:(id)arg5;
- (id)downloadProvisioningProfileWithProfileId:(id)arg1 platform:(id)arg2 token:(id)arg3 logAspect:(id)arg4;
- (id)revokeCertificateWithSerialNumber:(id)arg1 forAccount:(id)arg2 portalTeamID:(id)arg3 certificiateKind:(id)arg4 platformIdentifier:(id)arg5 logAspect:(id)arg6;
- (id)requestCertificateForAccount:(id)arg1 portalTeamID:(id)arg2 certificiateKind:(id)arg3 platformIdentifier:(id)arg4 logAspect:(id)arg5;
- (id)findSerialNumberOfNewestSigningCertificateForAccount:(id)arg1 portalTeamID:(id)arg2 certificiateKind:(id)arg3 platformIdentifier:(id)arg4 logAspect:(id)arg5;
- (id)_portalSubPlatformForDVTPlatformIdentifier:(id)arg1;
- (id)_portalPlatformForDVTPlatformIdentifier:(id)arg1;
- (id)_generatePortalOperationTokenForAccount:(id)arg1 portalTeamID:(id)arg2 logAspect:(id)arg3;
- (id)teamNameForTeamWithTeamID:(id)arg1;

@end


