//
//  YuneecSDKManager.h
//  YuneecSDK
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Manager Yuneec SDK
 */
@interface YuneecSDKManager : NSObject

/**
 * Singleton instance
 *
 * @return YuneecSDKManager singleton instance
 */
+ (instancetype)sharedInstance;

@end
