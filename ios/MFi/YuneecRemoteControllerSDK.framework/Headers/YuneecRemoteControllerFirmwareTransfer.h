//
//  YuneecRemoteControllerUpgrade.h
//  YuneecRemoteControllerSDK
//
//  Created by tbago on 20/03/2018.
//  Copyright © 2018 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YuneecRemoteController;

NS_ASSUME_NONNULL_BEGIN

@interface YuneecRemoteControllerFirmwareTransfer : NSObject


/**
 * Create instance with firmware path
 *
 * @param remoteController remote controller instance for send command
 * @return instance of remote controller upgrade
 */
- (instancetype)initWithRemoteController:(YuneecRemoteController *) remoteController;

/**
 * upgrade firmware
 *
 * @param firmwarePath firmware local store path
 * @param progressBlock progress block
 * @param completionBlock completion block
 */
- (void)transferFirmwareToRemoteController:(NSString *) firmwarePath
                             progressBlock:(void(^)(float progress)) progressBlock
                           completionBlock:(void(^)(NSError *_Nullable error)) completionBlock;


/**
 * Cancel firmware upgradde
 */
- (void)cancelUpgrade;

@end

NS_ASSUME_NONNULL_END
