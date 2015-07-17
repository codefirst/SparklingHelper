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
    private let xcode = XcodeGateway()

    func run() {
        webServer.addDefaultHandlerForMethod("GET", requestClass: GCDWebServerRequest.self, processBlock: {request in
            switch request.path {
            case "/devices":
                let devices = self.xcode.deviceManager.allDevices().map {
                    [ "name": $0.name, "identifier": $0.identifier, "platform": $0.platform.name ]
                }
                return GCDWebServerDataResponse(JSONObject: devices)
            case "/accounts":
                let accounts = self.xcode.accountManager.accounts().map {
                    [ "username" : $0.username ]
                }
                return GCDWebServerDataResponse(JSONObject: accounts)
            case "/certificates":
                let certificates = self.xcode.certificateManager.certificates().map {
                    [
                        "commonName" : $0.commonName,
                        "portalTeamID" : $0.portalTeamID,
                        "portalMemberID" : $0.portalMemberID,
                        "trimmedName" : $0.trimmedName
                    ]
                }
                return GCDWebServerDataResponse(JSONObject: certificates)
            case "/request_provisioning":
                // FIXME: check method type
                let req = RequestProvisioningHandler(xcode: self.xcode, query: request.query as! [String:String])
                let json = req.call()
                return GCDWebServerDataResponse(JSONObject: json)
            default:
                let title = "⚡️SparklingHelper"
                let html = ["accounts", "devices", "certificates"].reduce("<h1>\(title)</h1><ul>") {
                    $0 + "<li><a href='\($1)'>\($1)</a></li>"
                } + "</ul>"
                return GCDWebServerDataResponse(HTML: "<html><head><title>\(title)</title></head><body>\(html)</body></html")
            }
        })

        // run webs server at some free port.
        // User can access this server via bonjour finding.
        webServer.startWithPort(0, bonjourName: "SparklingHelper")

        print("Visit \(webServer.serverURL) in your web browser")
    }
}