# SparklingHelper

Xcode plugin that provides http gateway to access internal API.

## Feature

 * Provide information: developper account(i.e. AppleID), certificates, devices
 * Create development provisionings

## Requirements

 * Xcode 7.0 beta 5 (7A176x)

## Usage

See [homebrew-sparkling](https://github.com/codefirst/homebrew-sparkling).

## Development

### Build
Download the workspace and build it, and then relaunch Xcode.

SparklingHelpr will be installed in ~/Library/Application Support/Developer/Shared/Xcode/Plug-ins automatically.

### Access via Safari

You can find SparklingHelper on Safari's favorite bar via Bonjour.

![](https://raw.githubusercontent.com/codefirst/SparklingHelper/master/doc/bonjour.png)

## Available API

### GET /accounts
Return available account(i.e. AppleID).

### GET /devices
Return available devices(including iOS simulator).

### GET /certificates
Return available certificates.

### GET /request_provisioning
Create development provisioning by request bundle identifier.

E.g.

```
http://mzpbook.local.:53221/request_provisioning?username=mzpppp%2Bfree@gmail.com&certificateName=iPhone%20Developer:%20mzpppp%2Bfree@gmail.com%20(78KR9QS4P3)&deviceName=mzpPhone&bundleIdentifier=jp.mzp.Hello2
```
