//
//  RCResponseGetVersionInfo.h
//  YuneecApp
//
//  Created by dj.yue on 2017/4/26.
//  Copyright © 2017年 dj.yue. All rights reserved.
//

#import "RCResponseInfo.h"


/**
 遥控器版本信息(CMD_GET_VERSION)
 */
@interface RCResponseGetVersionInfo : RCResponseInfo

@property (nonatomic, copy) NSString * hardwareVersion;//硬件
@property (nonatomic, copy) NSString * firmwareVersion;//固件
@property (nonatomic, copy) NSString * mcuVersion;

@end
