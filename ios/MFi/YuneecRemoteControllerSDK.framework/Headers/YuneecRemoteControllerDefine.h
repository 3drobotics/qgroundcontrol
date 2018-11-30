//
//  YuneecRemoteControllerDefine.h
//  YuneecRemoteControllerSDK
//
//  Created by tbago on 30/11/2017.
//  Copyright © 2017 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YuneecRemoteControllerCameraWifiInfo : NSObject

@property (copy, nonatomic) NSString        *SSID;
@property (assign, nonatomic) NSInteger     frequency;
@property (assign, nonatomic) NSInteger     signalLevel;

@end

@interface YuneecRemoteControllerBindCameraWifiInfo : YuneecRemoteControllerCameraWifiInfo

@property (copy, nonatomic) NSString        *ipAddress;

@end

@interface YuneecRemoteControllerGPSInfo : NSObject

@property (assign, nonatomic) double        latitude;
@property (assign, nonatomic) double        longitude;
@property (assign, nonatomic) double        altitude;
@property (assign, nonatomic) NSInteger     satellites;
@property (assign, nonatomic) NSInteger     accuracy;

/**
 * 延角度方向速率m/s
 */
@property (nonatomic, assign) double        speed;

/**
 * 从北顺时针偏移,单位度
 */
@property (nonatomic, assign) NSInteger     angle;

@end


/**
 * Remote Controller haredware info
 */
@interface YuneecRemoteControllerHardwareInfo : NSObject

/**
 * remote controller joystick count
 */
@property (assign, nonatomic) NSInteger     joystickCount;

/**
 * remote controller knob count
 */
@property (assign, nonatomic) NSInteger     knobCount;

/**
 * remote controller switch count
 */
@property (assign, nonatomic) NSInteger     switchCount;

/**
 * remote controller button count
 */
@property (assign, nonatomic) NSInteger     buttonCount;

/**
 * current joystick value
 */
@property (strong, nonatomic) NSArray<NSNumber *>   *joystickValueArray;

/**
 * current knob value
 */
@property (strong, nonatomic) NSArray<NSNumber *>   *knobValueArray;

/**
 * current switch value
 */
@property (strong, nonatomic) NSArray<NSNumber *>   *switchValueArray;

/**
 * current button value
 */
@property (strong, nonatomic) NSArray<NSNumber *>   *buttonValueArray;

@end
