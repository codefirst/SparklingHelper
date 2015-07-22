@interface DVTFuture : NSObject
{
}

+ (id)futureWithOperation:(id)arg1;
+ (id)cancelledFuture;
+ (id)futureWithResult:(id)arg1;
+ (id)futureWithError:(id)arg1;
+ (id)runOperation:(id)arg1;
+ (id)trackOperation:(id)arg1;
- (void)trackFuture:(id)arg1;
- (void)trackFuture:(id)arg1 progress:(float)arg2 cancel:(BOOL)arg3 result:(BOOL)arg4 error:(BOOL)arg5;
- (void)updateProgressFromReporters;
- (void)failWithError:(id)arg1 afterTimeout:(double)arg2;
- (void)succeedWithResult:(id)arg1 afterTimeout:(double)arg2;
- (void)cancelAfterTimeout:(double)arg1;
- (void)_setState:(long long)arg1 result:(id)arg2 error:(id)arg3 afterTimeout:(double)arg4;
- (void)succeedWithResult:(id)arg1;
- (void)failWithError:(id)arg1;
- (void)cancel;
- (void)setState:(long long)arg1 result:(id)arg2 error:(id)arg3;
- (id)future;
- (void)setProgress:(long long)arg1;
@property(readonly, copy) NSString *description;
- (id)_description;
- (void)observeFinishWithDispatchGroup:(id)arg1;
@property(readonly, getter=isCancelled) BOOL cancelled;
- (long long)waitUntilFinished;
- (id)result;
- (id)error;
- (void)_signalFinished;
- (void)_waitUntilFinished;
- (void)dealloc;
- (id)initWithResult:(id)arg1;
- (id)initWithError:(id)arg1;
- (id)init;

@end


@interface DVTPlatform : NSObject
{
}

+ (id)_preferredArchitectureForPlatformWithIdentifier:(id)arg1;
+ (id)extraPlatformFolders;
+ (id)defaultPlatform;
+ (BOOL)loadAllPlatformsReturningError:(id *)arg1;
+ (void)_loadPlatformAtPath:(id)arg1;
+ (id)_propertyDictionaryForPlatformAtPath:(id)arg1;
+ (id)allPlatforms;
+ (void)registerPlatform:(id)arg1;
+ (id)platformForPath:(id)arg1;
+ (void)_mapPlatformPath:(id)arg1 toPlatform:(id)arg2;
+ (id)_allPlatformsByIdentifierValues;
+ (id)platformForIdentifier:(id)arg1;
+ (void)_mapPlatformIdentifier:(id)arg1 toPlatform:(id)arg2;
+ (id)platformForUserDescription:(id)arg1;
+ (id)platformForName:(id)arg1;
+ (void)_mapPlatformName:(id)arg1 toPlatform:(id)arg2 isAlias:(BOOL)arg3;
+ (void)initialize;
@property(readonly, copy) NSString *platformVersion; // @synthesize platformVersion=_platformVersion;
@property(readonly, copy) NSDictionary *deviceProperties; // @synthesize deviceProperties=_deviceProperties;
@property(readonly) BOOL isDeploymentPlatform; // @synthesize isDeploymentPlatform=_isDeploymentPlatform;
@property(readonly, copy) NSString *userDescription; // @synthesize userDescription=_userDescription;
@property(readonly, copy) NSString *platformDirectoryName; // @synthesize platformDirectoryName=_platformDirectoryName;
@property(readonly, copy) NSString *name; // @synthesize name=_name;
@property(readonly, copy) NSArray *alternateNames; // @synthesize alternateNames=_alternateNames;
@property(readonly, copy) NSString *identifier; // @synthesize identifier=_identifier;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)description;
@property(readonly, copy) NSSet *SDKs;
- (void)addSDK:(id)arg1;
- (id)internalPropertyListDictionary;
- (id)propertyListDictionary;
- (id)initWithPath:(id)arg1;
- (id)initWithPropertyListDictionary:(id)arg1 path:(id)arg2;

@end



@interface DVTDevice : NSObject
{
}

+ (id)modelNameFromModelUTI:(id)arg1;
+ (id)modelUTIFromModelCode:(id)arg1;
+ (id)keyPathsForValuesAffectingActiveProxiedDevice;
+ (id)_knownDeviceLocators;
+ (void)initialize;
@property(retain) DVTPlatform *platform; // @synthesize platform=_platform;
@property(copy) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy) NSString *operatingSystemBuild; // @synthesize operatingSystemBuild=_operatingSystemBuild;
@property(copy) NSString *operatingSystemVersion; // @synthesize operatingSystemVersion=_operatingSystemVersion;
@property(getter=isAvailable) BOOL available; // @synthesize available=_available;
@property(copy, nonatomic) NSString *modelCode; // @synthesize modelCode=_modelCode;
@property(copy) NSString *name; // @synthesize name=_name;
@property BOOL canSelectArchitectureToExecute; // @synthesize canSelectArchitectureToExecute=_canSelectArchitectureToExecute;
@property(copy) NSOrderedSet *supportedArchitectures; // @synthesize supportedArchitectures=_supportedArchitectures;
@property(nonatomic, getter=isUsedForDevelopment) BOOL usedForDevelopment; // @synthesize usedForDevelopment=_usedForDevelopment;
@property(getter=isIgnored) BOOL ignored; // @synthesize ignored=_ignored;
@property(copy, nonatomic) NSString *modelName; // @synthesize modelName=_modelName;
@property(copy, nonatomic) NSString *modelUTI; // @synthesize modelUTI=_modelUTI;
@property(copy, nonatomic) NSString *operatingSystemVersionWithBuildNumber; // @synthesize operatingSystemVersionWithBuildNumber=_operatingSystemVersionWithBuildNumber;
@property(readonly, copy) NSURL *deviceLocation; // @synthesize deviceLocation=_deviceLocation;
- (id)launchApplicationWithBundleIdentifier:(id)arg1 withArguments:(id)arg2 environment:(id)arg3 options:(id)arg4;
- (id)applicationIsInstalledWithBundleIdentifier:(id)arg1;
- (id)uninstallApplicationWithBundleIdentifier:(id)arg1 andOptions:(id)arg2;
- (id)installApplicationAtPath:(id)arg1 withOptions:(id)arg2;
@property(readonly) BOOL canInstallApplication;
@property(readonly) BOOL canRunExecutables;
- (id)shutDownDevice;
- (id)startUpDevice;
@property(readonly) unsigned long long startupState;
@property(readonly) BOOL canStartUpAndShutDown;
@property(readonly) _Bool canTakeScreenshot;
- (void)unpair;
@property(readonly) _Bool isPaired;
@property(readonly) _Bool usesPairingRecord;
@property(readonly) _Bool canEnableWireless;
- (void)disableWireless;
- (id)enableWireless;
@property(readonly) _Bool isWirelessEnabled;
@property(readonly, copy) NSArray *addresses;
@property(readonly, copy) NSString *hostname;
@property(readonly) _Bool hasWiredConnection;
@property(readonly) _Bool hasWirelessConnection;
@property(readonly) _Bool isWireless;
- (void)terminateWatchAppForCompanionIdentifier:(id)arg1 options:(id)arg2;
- (id)listenForInstallOfAppExtensionIdentifiers:(id)arg1 timeout:(double)arg2;
- (id)_applicationListingChannel;
@property(readonly) unsigned long long supportedLaunchOptions;
- (id)proxiedPrimaryInstrumentsServer;
- (id)primaryInstrumentsServer;
- (id)makeTransportForTestManagerService:(id *)arg1;
@property(readonly) BOOL requiresTestDaemonMediationForTestHostConnection;
@property(readonly) BOOL supportsTestManagerDaemon;
- (void)renameDevice:(id)arg1;
@property(readonly) BOOL canRename;
@property(readonly) BOOL canBeWatchCompanion;
- (void)disableDeviceForDevelopment;
- (void)enableDeviceForDevelopment;
- (id)installApplicationsSync:(id)arg1 options:(id)arg2;
- (id)installApplicationSync:(id)arg1 options:(id)arg2;
- (void)stopDebuggingXPCServices:(id)arg1;
- (void)debugXPCServices:(id)arg1;
- (void)debugXPCServices:(id)arg1 onPairedDevice:(BOOL)arg2;
- (BOOL)validateDeviceSpecifierOptions:(id)arg1 allowMultipleMatches:(BOOL)arg2 error:(id *)arg3;
@property(readonly, copy) NSString *nameForDeveloperPortal;
@property(readonly, copy) NSString *platformIdentifier;
@property(readonly) BOOL isRunningSupportedOS;
@property(readonly) BOOL isSupportedHardware;
@property(readonly) BOOL canIgnore;
- (void)uninstallProvisioningProfile:(id)arg1;
- (BOOL)installProvisioningProfileAtURL:(id)arg1 error:(id *)arg2;
- (void)installProvisioningProfile:(id)arg1;
@property(readonly) NSSet *provisioningProfiles;
@property(readonly) BOOL supportsProvisioning;
@property(readonly) BOOL supportsArchiving;
- (BOOL)canPerformUbiquityFetchEvent;
- (void)performUbiquityFetchEvent;
- (void)performFetchEventForPID:(int)arg1;
@property(readonly) unsigned long long supportsFetchEvents;
- (BOOL)addressSanitizerRequiresDyldInsertLibrary;
- (id)optimizationProfilesPathFromBundleIdentifier:(id)arg1;
- (BOOL)supportsPGOReturningError:(id *)arg1;
@property(readonly) BOOL supportsDebuggingForAskOnLaunch;
@property(readonly) BOOL supportsUnhostedXPCServiceDebugging;
@property(readonly) BOOL supportsXPCServiceDebugging;
@property(readonly) BOOL canRunMultipleInstancesPerApp;
@property(readonly) BOOL runsRemoteFromHostLauncher;
@property(readonly) BOOL supportsDebugAsDifferentUser;
@property(readonly) BOOL supportsDebuggingDocumentVersioning;
@property(readonly) BOOL supportsResumeAndTurningItOnOrOff;
@property(readonly) BOOL supportsCustomWorkingDirectory;
@property(readonly) BOOL supportsDisplayScaleOption;
@property(readonly) BOOL supportsRoutingCoverageFile;
@property(readonly) BOOL supportsLocalizationOptions;
@property(readonly) BOOL supportsLocationSimulation;
@property(readonly) BOOL supportsBuildingThinnedResources;
@property(readonly) NSString *deviceIdentifierForGPUTracing;
@property(readonly) BOOL supportsApplicationDataUploading;
@property(readonly) BOOL supportsAttachByPIDOrName;
@property(readonly, copy) NSString *processorDescription;
@property(readonly) NSString *executionDisplayName;
@property(readonly, copy) NSString *recordedFramesBacktraceRecordingDylibPath;
@property(readonly, copy) NSString *recordedFramesLibdispatchIntrospectionDylibPath;
@property(readonly, copy) NSString *recordedFramesMinimumVersionString;
@property(readonly) BOOL supportsRecordedFrames;
@property(readonly) BOOL alwaysAttachesForDebugging;
@property(readonly, getter=isConcreteDevice) BOOL concreteDevice;
@property(readonly, getter=isGenericDevice) BOOL genericDevice;
@property(readonly) NSString *displayOrder;
@property(copy) NSString *nativeArchitecture; // @synthesize nativeArchitecture=_nativeArchitecture;
@property(readonly) _Bool deviceIsBusy;
@property(readonly) NSError *unavailabilityError;
@property(readonly) BOOL isProxiedDevice;
@property(readonly, copy) NSSet *proxiedDevices;
- (id)servicesMatchingCapability:(id)arg1;
- (id)_instantiateServicesForCapability:(id)arg1;
- (BOOL)isEqual:(id)arg1;
@property(readonly) unsigned long long hash;
- (id)initWithDeviceLocation:(id)arg1 extension:(id)arg2;
@property(readonly, copy) NSString *description;

// Remaining properties
@property(readonly, copy) NSSet *capabilities; // @dynamic capabilities;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSMutableSet *mutableCapabilities; // @dynamic mutableCapabilities;
@property(readonly) Class superclass;

@end


@interface DVTDeveloperAccount : NSObject
{
/*    DVTDispatchLock *_lock;
    BOOL _alwaysLogInUsingQA;
    BOOL _enabled;
    DVTDeveloperAccountSession *_session;
    DVTDeveloperAccountCredentials *_accountCredentials;
    NSString *_userDescription;*/
}

+ (id)keyPathsForValuesAffectingUserDescriptionOrBestGuess;
+ (id)keyPathsForValuesAffectingHasPassword;
+ (id)keyPathsForValuesAffectingPassword;
+ (id)accountWithPropertyListRepresentation:(id)arg1 keychain:(struct OpaqueSecKeychainRef *)arg2 error:(id *)arg3;
+ (id)accountWithIdentity:(struct OpaqueSecIdentityRef *)arg1;
+ (id)accountWithCredentials:(id)arg1;
@property BOOL enabled; // @synthesize enabled=_enabled;
@property BOOL alwaysLogInUsingQA; // @synthesize alwaysLogInUsingQA=_alwaysLogInUsingQA;
@property(copy, nonatomic) NSString *userDescription; // @synthesize userDescription=_userDescription;
//@property(copy) DVTDeveloperAccountCredentials *accountCredentials; // @synthesize accountCredentials=_accountCredentials;
@property(readonly) NSDictionary *propertyListRepresentation;
@property(readonly) NSString *userDescriptionOrBestGuess;
@property(readonly) BOOL hasPassword;
@property(copy) NSString *password;
@property(readonly) _Bool isCertBased;
- (BOOL)isEqual:(id)arg1;
- (unsigned long long)hash;
@property(readonly, copy) NSString *username;
- (void)revokeSession:(id)arg1;
- (id)sessionIfAvailable;
- (id)sessionByLoggingInIfNeeded:(id *)arg1;
- (id)_sessionByLoggingIn:(id *)arg1;
- (id)init;
@end



@protocol DVTDeveloperProfileAccountProvider <NSObject>
@property(readonly) NSString *typeIdentifier;
- (BOOL)importAccountsFromKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(NSDictionary *)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
- (BOOL)exportAccountsToKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(id *)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
@end

@interface DVTDeveloperAccountManager : NSObject <DVTDeveloperProfileAccountProvider>
{}

+ (id)sharedAccountManager;
@property(retain, nonatomic) DVTDeveloperAccount *defaultAccount; // @synthesize defaultAccount=_defaultAccount;
@property(readonly) NSString *typeIdentifier;
- (BOOL)importAccountsFromKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(id)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
- (BOOL)exportAccountsToKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(id *)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
- (void)removeAccountsObject:(id)arg1;
- (void)addAccountsObject:(id)arg1;
@property(readonly, nonatomic) NSOrderedSet *accounts;
- (id)_mutableAccounts;
- (void)updateUserDefaults;
- (id)_accountsByCreatingFromDefaults;
- (id)_accountsByCreatingFromKeychain;
- (_Bool)hasAccountWithUsername:(id)arg1;
- (id)accountWithUsername:(id)arg1;
@end

@interface DVTSigningCertificateManager : NSObject
{
/*    DVTDispatchLock *_certificateLock;
    NSMutableSet *_signingCertificates;
    NSMutableSet *_signingIdentityCertificates;
    DVTSigningCertificateSource *_certificateSource;*/
}

+ (id)defaultCertificateManager;
+ (void)initialize;
- (void)_delayedPostCertificatesChangedNotification;
- (void)forceFullSync;
- (void)signingCertificateSourceShouldDoFullResetFromSigningCertificates:(id)arg1;
- (void)signingCertificateSourcePrivateKeyStatusForCertificatesMayHaveChanged:(id)arg1;
- (void)signingCertificateSource:(id)arg1 didRemoveCertificate:(id)arg2;
- (void)signingCertificateSource:(id)arg1 didAddCertificate:(id)arg2;
@property(readonly) NSSet *signingIdentityCertificates;
@property(readonly) NSSet *signingCertificates;
- (id)logAspect;
@property(readonly, copy) NSString *description;
- (void)primitiveInvalidate;
- (id)initWithCertificateSource:(id)arg1;
- (id)init;

@end

@interface DVTSigningCertificate : NSObject
{
}

+ (id)keychainSearchList;
@property(readonly) id underlyingType; // @synthesize underlyingType=_underlyingType;
@property(readonly) NSString *portalTeamName; // @synthesize portalTeamName=_portalTeamName;
- (id)_valueInSubjectNameSectionFromCertificate:(struct OpaqueSecCertificateRef *)arg1 forOID:(id)arg2;
- (id)_dateFromCertificate:(struct OpaqueSecCertificateRef *)arg1 forOID:(id)arg2;
- (id)certificateData;
- (id)defaultDesignatedRequirementsForIdentifier:(id)arg1;
@property(readonly) NSString *serialNumber; // @synthesize serialNumber=_serialNumber;
@property(readonly) NSString *sha1Hash; // @synthesize sha1Hash=_sha1Hash;
@property(readonly, getter=isForServer) BOOL forServer;
@property(readonly, getter=isTrusted) BOOL trusted;
@property(readonly, getter=isExpired) BOOL expired;
@property(readonly) NSDate *expirationDate; // @synthesize expirationDate=_expirationDate;
@property(readonly) NSDate *issueDate; // @synthesize issueDate=_issueDate;
@property(readonly, getter=isIdentity) BOOL identity;
@property(readonly) NSString *portalMemberID; // @synthesize portalMemberID=_portalMemberID;
- (id)portalTeamName:(struct OpaqueSecCertificateRef *)arg1;
@property(readonly) NSString *portalTeamID; // @synthesize portalTeamID=_portalTeamID;
- (BOOL)isFromPortal;
@property(readonly) NSString *commonName; // @synthesize commonName=_commonName;
@property(readonly) NSString *trimmedName; // @synthesize trimmedName=_trimmedName;
@property(readonly) NSString *certificateKind; // @synthesize certificateKind=_certificateKind;
- (long long)compare:(id)arg1;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (struct OpaqueSecCertificateRef *)certificateRef;
- (id)description;
- (id)initWithUnderlyingType:(id)arg1 logAspect:(id)arg2;

@end


@interface DVTDeviceManager : NSObject
{
}

+ (id)defaultDeviceManager;
+ (void)initialize;
- (id)deviceLocatorForDeviceType:(id)arg1;
- (id)searchForDevicesWithType:(id)arg1 options:(id)arg2 timeout:(double)arg3 error:(id *)arg4;
- (id)searchForDeviceWithType:(id)arg1 options:(id)arg2 genericOnly:(BOOL)arg3 timeout:(double)arg4 error:(id *)arg5;
- (id)_searchForDevicesWithType:(id)arg1 options:(id)arg2 genericOnly:(BOOL)arg3 allowMultiple:(BOOL)arg4 timeout:(double)arg5 error:(id *)arg6;
- (id)_waitForDeviceUsingLocatorsToOptions:(id)arg1 genericOnly:(BOOL)arg2 allowMultiple:(BOOL)arg3 timeout:(double)arg4 error:(id *)arg5;
- (id)_lookUpAvailableDevicesUsingLocatorsToOptions:(id)arg1 genericOnly:(BOOL)arg2 allowMultiple:(BOOL)arg3 error:(id *)arg4;
- (id)_deviceLocatorForDeviceSpecifierPrefix:(id)arg1 error:(id *)arg2;
- (BOOL)locateOnlyLocalComputerWithError:(id *)arg1;
- (void)locateOnlyLocalComputer;
- (void)stopLocating;
- (BOOL)startLocatingWithError:(id *)arg1;
- (void)startLocating;
- (void)_adjustAvailableDevicesForChangeKind:(unsigned long long)arg1 addedObjects:(id)arg2 removedObjects:(id)arg3;
- (void)_stopObservingDevice:(id)arg1;
- (void)_startObservingDevice:(id)arg1;
- (id)_discoverDeviceLocators;
- (id)deviceAtDeviceLocation:(id)arg1;
- (id)_deviceLocatorForDeviceLocationScheme:(id)arg1;
- (id)devicesMatchingPredicate:(id)arg1;
- (id)init;

// Remaining properties
@property(copy) NSSet<DVTDevice*> *availableDevices; // @dynamic availableDevices;
@property(readonly, copy) NSMutableSet *mutableAvailableDevices; // @dynamic mutableAvailableDevices;

@end

@interface DVTCodesignableDeviceSnapshot : NSObject
{
    BOOL _supportsProvisioning;
    NSString *_name;
    NSString *_nameForDeveloperPortal;
    NSString *_identifier;
    NSString *_platformIdentifier;
    NSSet *_proxiedDevices;
}

+ (id)snapshotFromCodesignableDevice:(id)arg1;
@property(copy) NSSet *proxiedDevices; // @synthesize proxiedDevices=_proxiedDevices;
@property BOOL supportsProvisioning; // @synthesize supportsProvisioning=_supportsProvisioning;
@property(copy) NSString *platformIdentifier; // @synthesize platformIdentifier=_platformIdentifier;
@property(copy) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy) NSString *nameForDeveloperPortal; // @synthesize nameForDeveloperPortal=_nameForDeveloperPortal;
@property(copy) NSString *name; // @synthesize name=_name;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DVTAppIDFeatures : NSObject <NSCopying>
{
    NSDictionary *_flags;
    NSSet *_cloudContainers;
    NSSet *_applicationGroups;
    NSSet *_omcIdentifiers;
}

+ (id)paymentPassAccessEntitlement;
+ (id)inAppPaymentsEntitlement;
+ (id)userNameForFlag:(id)arg1;
@property(readonly) NSSet *omcIdentifiers; // @synthesize omcIdentifiers=_omcIdentifiers;
@property(readonly) NSSet *applicationGroups; // @synthesize applicationGroups=_applicationGroups;
@property(readonly) NSSet *cloudContainers; // @synthesize cloudContainers=_cloudContainers;
@property(readonly) NSDictionary *flags; // @synthesize flags=_flags;
- (BOOL)allowsFeatures:(id)arg1 missingFeatures:(id *)arg2;
@property(readonly) NSString *userDescription;
- (id)description;
- (id)plistRepresentation;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(readonly) BOOL requiresExplicitAppID;
@property(readonly) DVTAppIDFeatures *enabledFeatures;
- (id)featuresBySettingValue:(id)arg1 forKey:(id)arg2;
- (BOOL)isEqual:(id)arg1;
- (id)initWithFlags:(id)arg1 cloudContainers:(id)arg2 applicationGroups:(id)arg3 omcIdentifiers:(id)arg4;
- (id)init;

@end

@interface DVTLogAspect : NSObject
{
    NSString *_name;
    BOOL _signalInstruments;
    BOOL _takeTimeProfile;
    int _logLevel;
    NSArray *_activeLoggers;
}

+ (id)logAspectWithName:(id)arg1;
+ (id)allAspects;
+ (int)defaultLogLevel;
+ (void)initialize;
@property(copy) NSArray *activeLoggers; // @synthesize activeLoggers=_activeLoggers;
@property BOOL takeTimeProfile; // @synthesize takeTimeProfile=_takeTimeProfile;
@property BOOL signalInstruments; // @synthesize signalInstruments=_signalInstruments;
@property int logLevel; // @synthesize logLevel=_logLevel;
@property(readonly) NSString *name; // @synthesize name=_name;
- (id)description;
- (void)_logAndOutdentAtLogLevel:(int)arg1 withFormat:(id)arg2;
- (void)_logAndIndentAtLogLevel:(int)arg1 withFormat:(id)arg2;
- (void)_logAtLogLevel:(int)arg1 withFormat:(id)arg2;
- (id)initWithName:(id)arg1 logLevel:(int)arg2 signalInstruments:(BOOL)arg3 takeTimeProfile:(BOOL)arg4 activeLoggers:(id)arg5;
- (id)init;

@end



