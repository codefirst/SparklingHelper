class AccountManager {
    private let accountManager = DVTDeveloperAccountManager.sharedAccountManager() as! DVTDeveloperAccountManager

    func accounts() -> [DVTDeveloperAccount] {
        let set : NSOrderedSet = self.accountManager.accounts
        return set.array as! [DVTDeveloperAccount]
    }
}