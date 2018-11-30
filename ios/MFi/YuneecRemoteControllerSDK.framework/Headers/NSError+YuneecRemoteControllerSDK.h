//
//  NSError+YuneecRemoteControllerSDK.h
//  YuneecRemoteControllerSDK
//
//  Created by tbago on 27/11/2017.
//  Copyright © 2017 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, YuneecRemoteControllerErrorCode) {
    YuneecRemoteControllerErrorNoError              = 0x00000,
    YuneecRemoteControllerErrorUnsupport            = -0x5000,
    YuneecRemoteControllerErrorInvalidParam         = -0x5001,
    YuneecRemoteControllerErrorInvalidSetting       = -0x5002,
    YuneecRemoteControllerErrorBusy                 = -0x5003,
    YuneecRemoteControllerErrorNotMatch             = -0x5004,
    YuneecRemoteControllerErrorGpsNotFixed          = -0x5005,

    ///< begin query bind state special error code
    YuneecRemoteControllerErrorDisconnected         = -0x5101,
    YuneecRemoteControllerErrorInactive             = -0x5102,
    YuneecRemoteControllerErrorInterfaceDisabled    = -0x5103,
    YuneecRemoteControllerErrorScanning             = -0x5104,
    YuneecRemoteControllerErrorAuthenticating       = -0x5105,
    YuneecRemoteControllerErrorAssociating          = -0x5106,
    YuneecRemoteControllerErrorAssociated           = -0x5107,
    YuneecRemoteControllerError4WayHandShake        = -0x5108,
    YuneecRemoteControllerErrorGroupHandShake       = -0x5109,
    ///< end end query bind state error code

    ///< begin firmware upgrade error
    YuneecRemoteControllerFirmwareNotExit           = -0x5201,
    YuneecRemoteControllerFirmwareRetryMaxCount     = -0x5202,
    ///< end firmware upgrade error

    /**
     * Send command without response
     */
    YuneecRemoteControllerErrorTimeout              = -0x5FFC,
    /**
     * Client is busy and cannot execute command
     */
    YuneecRemoteControllerErrorClientBusy           = -0x5FFD,
    /**
     * 数据长度错误
     */
    YuneecRemoteControllerErrorLength               = -0x5FFE,
    YuneecRemoteControllerErrorUnknown              = -0x5FFF,

};

@interface NSError (YuneecRemoteControllerSDK)

+ (instancetype _Nullable)buildRemoteControllerErrorWithCode:(YuneecRemoteControllerErrorCode) errorCode;

@end
