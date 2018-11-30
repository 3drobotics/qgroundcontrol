//
//  YuneecSDKManager_Communication.h
//  YuneecSDK
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import "YuneecSDKManager.h"

/**
 * For custom camera communication configure
 * If you want to use custom communication, you need set the communication method before call any camera method.
 */
@interface YuneecSDKManager ()

#pragma mark - custom camera media communication

/**
 * Weather use custom media communication
 */
@property (nonatomic, assign) BOOL          useCustomMediaCommunication;

/**
 * The custom media ip address
 */
@property (nonatomic, copy) NSString        *customMediaIpAddress;

/**
 * The custom media udp port of fetching media
 */
@property (nonatomic, assign) NSUInteger    customMediaPort;

/**
 * the custom transfer packet size in bytes, the recommend size for MFi mode is 3900 bytes
 */
@property (nonatomic, assign) NSUInteger    customMediaTransferPacketSize;


#pragma mark - tcp configure in Wifi mode
/**
 camera tcp media download port in Wifi Mode, default is 9800
 */
@property (nonatomic, assign) NSInteger cameraMediaDownloadPort;

/**
 camera Ip address in Wifi Mode, default is @"192.168.42.1"
 */
@property (nonatomic, copy) NSString *cameraIpAddress;


#pragma mark - Http configure
/**
 CGO3 root server address, default is @"http://192.168.42.1/"
 */
@property (nonatomic, copy) NSString *CGO3RootServerAddress;

/**
 CGO3 server media path, default is @"http://192.168.42.1/100MEDIA/"
 */
@property (nonatomic, copy) NSString *CGO3ServerMediaPath;

/**
 breeze server media address, default is @"http://192.168.42.1/DCIM/100MEDIA/"
 */
@property (nonatomic, copy) NSString *breezeServerMediaAddress;


@end
