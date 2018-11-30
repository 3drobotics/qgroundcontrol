//
//  RCMessageReportEventInfo.h
//  YuneecApp
//
//  Created by dj.yue on 2017/5/3.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import "RCResponseInfo.h"


/**
 监视器模块
 遥控器按键状态上报信息
 */
extern NSString * const kOBRemoteMSGReportEventNotification;

@interface RCMessageReportEventInfo : RCResponseInfo


/**
 1~10 for Button1~10
 11~20 for Switch1~10
 21~30 for Wheel1~10
 41 for Wifi
 42 for Battery
 */
@property (nonatomic, assign) uint8_t eventid;

/**
 For Button:0-release 1-prees 2-long press
 For Switch: 0-middle 1-right 2-left
 For Whell: 1-turn left -1-turn right
 For Wifi: 0-disconnected, 1-connected
 For battery: 电池电量百分比(例如:15就代表电量还剩15%)
 */
@property (nonatomic, assign) int8_t value;

@end
