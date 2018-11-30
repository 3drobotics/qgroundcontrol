//
//  YuneecRemoteControllerKey.h
//  YuneecApp
//
//  Created by dj.yue on 2017/5/3.
//  Copyright © 2017 yuneec. All rights reserved.
//

#import "RCResponseInfo.h"

@class YuneecRemoteControllerKey;

@protocol YuneecRemoteControllerKeyDelegate <NSObject>
@optional
/**
 * custom key of remote controller
 *
 * @param eventid event id
 * @param eventValue event value
 */
- (void)reportEventInfoUpdateRCCustomKeyEventid:(int)eventid withEventValue:(int)eventValue;
@end


@interface YuneecRemoteControllerKey : NSObject

@property (nonatomic, weak) id<YuneecRemoteControllerKeyDelegate> delegate;

+ (instancetype)sharedInstance;

- (void)infoWithPayload:(NSData *)payload  withCommand:(RC_CMD_ID)command;
/**
 1~10 for Button1~10
  *1 - Loiter Button (Button to the left of power button)
  *2 - RTL Button (Button to the right of power button)
  *3 - Camera Button
  *4 - Arm Button
  *5 - Video Button
 11~20 for Switch1~10
  *11 - Angle/sport mode
 21~30 for Wheel1~10
  *21 - Right wheel
 41 for Wifi
 42 for Battery
 43 for HDMI
 */
@property (nonatomic, assign) uint8_t eventid;

/**
 For Button:0-release 1-press 2-long press
 For Switch: 0-middle 1-right 2-left
 For Wheel: -1-turn left 1-turn right
 For Wifi: 0-disconnected, 1-connected  2-Auth failed
 For battery: Percentage of battery power (for example, 15 means 15% remaining)
 For HDMI: 0-disconnected, 1-connected
 */
@property (nonatomic, assign) int8_t value;

@end
