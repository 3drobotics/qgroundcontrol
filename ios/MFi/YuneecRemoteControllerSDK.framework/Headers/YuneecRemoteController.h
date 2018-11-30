//
//  YuneecRemoteController.h
//  YuneecRemoteControllerSDK
//
//  Created by tbago on 27/11/2017.
//  Copyright © 2017 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <YuneecRemoteControllerSDK/YuneecRemoteControllerDefine.h>
#import "RemoteCalibrationHeaders.h"

NS_ASSUME_NONNULL_BEGIN

@class YuneecRemoteController;

@protocol YuneecRemoteControllerDelegate <NSObject>

/**
 * To update drone connection status
 *
 * @param remoteController the data remote controller instance
 * @param bConnected connect status
 */
@optional
- (void)remoteController:(YuneecRemoteController *) remoteController
              updateDroneConnectionStatus:(BOOL) bConnected;

@end

@interface YuneecRemoteController : NSObject

@property (nonatomic, weak, nullable) id<YuneecRemoteControllerDelegate>    delegate;

#pragma mark - init & dealloc

- (void)closeRemoteController;

#pragma mark - version & type

- (void)getType:(void(^)(NSError * _Nullable error,
                         NSString * _Nullable type)) block;

- (void)getVersionInfo:(void(^)(NSError * _Nullable error,
                                NSString * _Nullable hardwareVersion,
                                NSString * _Nullable firmwareVersion,
                                NSString * _Nullable mcuVersion)) block;

#pragma mark - drone monitor
/**
 * Start monitoring drone connection status
 *
 * delegate to notify update
 */
- (void)startMonitorDroneConnection;

/**
 * Stop monitoring drone connection status
 *
 * Disable monitor
 */
- (void)stopMonitorDroneConnection;

/**
 * Scan auto pilot
 *
 * @param block A block object to be executed when the command return.
 * When execute success, the autoPilotIds will contain a list aircraft Id's.
 */
- (void)scanAutoPilot:(void(^)(NSError *_Nullable error,
                                NSArray * _Nullable autoPilotIds)) block;

/**
 * Bind autopilot with autoPilot id
 *
 * @param autoPilotId aircraft Id
 * @param block A block object to be executed when the command return.
 */
- (void)bindAutoPilot:(NSString *) autoPilotId
                 block:(void(^)(NSError *_Nullable error)) block;

#pragma mark - camera bind
/**
 * Scan camera wifi info
 *
 * @param block A block object to be executed when the command return.
 * When execute success, the wifiArray will contain all wifi list
 */
- (void)scanCameraWifi:(void(^)(NSError *_Nullable error,
                                NSArray<YuneecRemoteControllerCameraWifiInfo *> * _Nullable wifiArray)) block;

/**
 * Bind camera wifi with SSID and password
 *
 * @param wifiSSID wifi SSID
 * @param password wifi password
 * @param block A block object to be executed when the command return.
 */
- (void)bindCameraWifi:(NSString *) wifiSSID
              password:(NSString *) password
                 block:(void(^)(NSError *_Nullable error)) block;


/**
 * Unbind current camera wifi
 *
 * @param block A block object to be executed when the command return.
 */
- (void)unbindCameraWifi:(void(^)(NSError * _Nullable error)) block;

/**
 * Unbind RC
 *
 * @param block A block object to be executed when the command return.
 */
- (void)unbindRC:(void(^)(NSError * _Nullable error)) block;

/**
 * Exit RC bind
 * This function should be called after bindAutoPilot,
 * to successfully complete the binding process
 *
 * @param block A block object to be executed when the command return.
 */
- (void)exitBind:(void(^)(NSError * _Nullable error)) block;

/**
 * Get camera bind wifi info
 *
 * @param block A block object to be executed when the command return.
 * When bind with camera wifi, the bindWifiInfo will contain bind camera wifi info.
 */
- (void)getCameraWifiBindStatus:(void(^)(NSError * _Nullable error,
                                         YuneecRemoteControllerBindCameraWifiInfo * _Nullable bindWifiInfo)) block;

#pragma mark - get & set

/**
 * Get remote controller SDCard info
 *
 * @param block A block object to be executed when the command return.
 * freeSpace byte unit
 * totalSpace byte unit
 */
- (void)getSDCardInfo:(void(^)(NSError * _Nullable error,
                               BOOL isInserted,
                               NSInteger freeSpace,
                               NSInteger totalSpace)) block;

/**
 * Get remote controller battery info
 *
 * @param block A block object to be executed when the command return.
 * When execute success, the capacity will be 0~100 percent. the temperature is °C.
 */
- (void)getBatteryInfo:(void(^)(NSError *_Nullable error,
                                uint32_t capacity,
                                float temperature,
                                BOOL isChange)) block;

/**
 * Get remote controller gps info
 *
 * @param block A block object to be executed when the command return.
 * When execute success, the gpsInfo will contain remote controller gps info
 */
- (void)getGPSInfo:(void(^)(NSError *_Nullable error,
                            YuneecRemoteControllerGPSInfo * _Nullable gpsInfo)) block;

/**
 * Get hardware info
 *
 * @param block A block object to be executed when the command return.
 * When execute success, the haredInfo ojbect will contain all info about remote controller.
 */
- (void)getHardwareInfo:(void(^)(NSError * _Nullable error,
                                 YuneecRemoteControllerHardwareInfo * _Nullable hardwareInfo)) block;

- (void)getChannelMapValue:(void(^)(NSError * _Nullable error,
                            NSArray<NSNumber *> *mapValueArray)) block;

- (void)setChannelMapValue:(NSArray<NSNumber *> *) mapValueArray
                     block:(void(^)(NSError * _Nullable error)) block;

#pragma mark - firmware upgrade

- (void)startFirmwareUpgrade:(NSString *) hardwareVersion
             firmwareVersion:(NSString *) firmwareVersion
                  mcuVersion:(NSString *) mcuVersion
                firmwareName:(NSString *) firmwareName
                firmwareSize:(NSInteger) firmwareSize
                        type:(NSString *) type
                       block:(void(^)(NSError * _Nullable error)) block;

- (void)transferFirmwareData:(NSData *) firmwareData
                   retryData:(BOOL) retryData
                       block:(void(^)(NSError * _Nullable error)) block;

- (void)cancelFirmwareUpgrade:(void(^)(NSError * _Nullable error)) block;

- (void)sendFirmwareMD5Value:(NSString *) MD5Value

                       block:(void(^)(NSError * _Nullable error)) block;


/**
 * Remote Calibration Settings
 */
/**
 * 遥控器硬件值
 * responseHwInput 遥控器个按钮值;
 */
- (void)getHwInput:(void(^)(NSError * _Nullable error,RCResponseGetHwInputValInfo * _Nullable responseHwInput)) block;

/**
 * 获取遥控器的(Bind/Calibrate)状态
 * responseState 是否绑定状态和是否正在校准状态;
 */
- (void)getState:(void(^)(NSError * _Nullable error,RCResponseGetStateInfo * _Nullable responseState)) block;

/**
 开始遥控器校准
 */
- (void)startRCCalibration:(void(^)(NSError * _Nullable error,RCResponseInfo *responseInfo))block;

/**
 停止遥控器校准
 */
- (void)stopRCCalibration:(void(^)(NSError * _Nullable error,RCResponseInfo *responseInfo))block;

/**
 停止遥控器校准
 */
- (void)cancelRCCalibration:(void(^)(NSError * _Nullable error,RCResponseInfo *responseInfo))block;



@end

NS_ASSUME_NONNULL_END
