//
//  SparklingHTTPServer.swift
//  SparklingHelper
//
//  Created by mzp on 7/15/15.
//  Copyright © 2015 mzp. All rights reserved.
//

import Foundation


class SparklingHTTPServer {
    private let webServer = GCDWebServer()
    private lazy var deviceManager = DeviceManager()
    private lazy var accountManager = AccountManager()

    func run() {
        webServer.addDefaultHandlerForMethod("GET", requestClass: GCDWebServerRequest.self, processBlock: {request in
            switch request.path {
            case "/devices":
                let devices = self.deviceManager.allDevices().map {
                    [ "name": $0.name, "identifier": $0.identifier, "platform": $0.platform.name ]
                }
                return GCDWebServerDataResponse(JSONObject: devices)
            case "/accounts":
                let accounts = self.accountManager.accounts().map {
                    [ "username" : $0.username ]
                }
                return GCDWebServerDataResponse(JSONObject: accounts)
            default:
                let title = "SparklingHelper"
                let html = "<h1>⚡️SparklingHelper</h1>" +
                "<ul>" +
                    "<li><a href=\"/devices\">/devices</a></li>" +
                    "<li><a href=\"/accounts\">/accounts</a></li>" +
                "</ul>"
                return GCDWebServerDataResponse(HTML: "<html><head><title>⚡️\(title)</title></head><body>\(html)</body></html")
            }
        })

        // run webs server at some free port.
        // User can access this server via bonjour finding.
        webServer.startWithPort(0, bonjourName: "SparklingHelper")

        print("Visit \(webServer.serverURL) in your web browser")
    }
}