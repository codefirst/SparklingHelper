//
//  SparklingHTTPServer.swift
//  SparklingHelper
//
//  Created by mzp on 7/15/15.
//  Copyright © 2015 mzp. All rights reserved.
//

import Foundation


class SparklingHTTPServer {
    let webServer = GCDWebServer()

    func run() {
        webServer.addDefaultHandlerForMethod("GET", requestClass: GCDWebServerRequest.self, processBlock: {request in
            switch request.path {
            case "/devices":
                let devices = DVTDeviceManager.defaultDeviceManager().availableDevices?.map { device in
                    [ "name": device.name, "identifier": device.identifier, "platform": device.platform.name ]
                }

                return GCDWebServerDataResponse(JSONObject: devices)
            default:
                let title = "SparklingHelper"
                let html = "<h1>⚡️SparklingHelper</h1>" +
                "<ul>" +
                    "<li><a href=\"/devices\">/devices</a></li>" +
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