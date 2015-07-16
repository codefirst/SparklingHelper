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
            default:
                let title = "SparklingHelper"
                let html = "<h1>⚡️SparklingHelper</h1>" +
                "<ul>" +
                    "<li><a href=\"/devices\">/devices</a></li>" +
                "</ul>"
                return GCDWebServerDataResponse(HTML: "<html><head><title>⚡️\(title)</title></head><body>\(html)</body></html")
            }
        })

        webServer.startWithPort(8081, bonjourName: "sparklingHelper")

        print("Visit \(webServer.serverURL) in your web browser")
    }
}