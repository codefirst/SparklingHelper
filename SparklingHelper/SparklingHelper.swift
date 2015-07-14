//
//  SparklingHelper.swift
//
//  Created by mzp on 7/15/15.
//  Copyright © 2015 mzp. All rights reserved.
//

import AppKit

var sharedPlugin: SparklingHelper?

class SparklingHelper: NSObject {
    var bundle: NSBundle

    init(bundle: NSBundle) {
        self.bundle = bundle

        super.init()
        createMenuItems()
    }

    deinit {
        NSNotificationCenter.defaultCenter().removeObserver(self)
    }

    func createMenuItems() {
        if let item = NSApp.mainMenu!.itemWithTitle("Edit") {
            let actionMenuItem = NSMenuItem(title:"Do Action", action:"doMenuAction", keyEquivalent:"")
            actionMenuItem.target = self
            item.submenu!.addItem(NSMenuItem.separatorItem())
            item.submenu!.addItem(actionMenuItem)
        }
    }

    func doMenuAction() {
        let error = NSError(domain: "Hello World!", code:42, userInfo:nil)
        NSAlert(error: error).runModal()
    }
}

