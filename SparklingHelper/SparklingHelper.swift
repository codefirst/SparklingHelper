//
//  SparklingHelper.swift
//
//  Created by mzp on 7/15/15.
//  Copyright © 2015 mzp. All rights reserved.
//

import AppKit

var sharedPlugin: SparklingHelper?

class SparklingHelper: NSObject {
    let pluginName = "SparklingHelper"

    var bundle: NSBundle

    init(bundle: NSBundle) {
        self.bundle = bundle

        super.init()
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "createMenuItems", name: NSMenuDidChangeItemNotification, object: nil)
        createMenuItems()
    }

    deinit {
        NSNotificationCenter.defaultCenter().removeObserver(self)
    }

    func createMenuItems() {
        if menuInstalled() { return }

        if let item = NSApp.mainMenu?.itemWithTitle("Help") {
            let actionMenuItem = NSMenuItem(title:pluginName, action:"doMenuAction", keyEquivalent:"")
            actionMenuItem.target = self
            item.submenu!.addItem(NSMenuItem.separatorItem())
            item.submenu!.addItem(actionMenuItem)
        }
    }

    func menuInstalled() -> Bool {
        let menuItem = NSApp.mainMenu?.itemWithTitle("Help")
        let submenu = menuItem?.submenu?.itemWithTitle(pluginName)

        return submenu != nil
    }

    func doMenuAction() {
        // do nothing
    }
}

