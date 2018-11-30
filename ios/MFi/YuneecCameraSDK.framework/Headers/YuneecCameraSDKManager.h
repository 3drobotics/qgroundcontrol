//
//  YuneecCameraSDKManager.h
//  YuneecCameraSDK
//
//  Created by tbago on 2017/9/5.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Manager Yuneec Camera SDK
 */
@interface YuneecCameraSDKManager : NSObject

/**
 * Get the YuneecCameraSDK current version.
 *
 * @return YuneecCameraSDK current version.
 */
+ (NSString *)getSDKVersion;

@end
