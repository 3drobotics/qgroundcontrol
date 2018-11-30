//
//  RCRequestCommonInfo.h
//  YuneecApp
//
//  Created by dj.yue on 2017/4/20.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseCommand.h"

/**
 Super class
 */
@interface RCRequestInfo : NSObject
- (NSData *)buildPayload;

@end

/**
 带参数的遥控器指令,
 */
typedef NS_ENUM(uint8_t, RCCalibrateAction) {
    RCCalibrateActionStop,
    RCCalibrateActionStart,
    RCCalibrateActionCancel,
};
@interface RCRequestCalibrateInfo : RCRequestInfo

@property (nonatomic, assign) RCCalibrateAction action;///< start or stop or cancel

@end


