//
//  NSError+YuneecCameraSDK.h
//  YuneecCameraSDK
//
//  Created by kimiz on 2017/10/12.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nonnull const YuneecCameraSDKErrorDomain;

/**
 * Yuneec Camera Error code
 * The system errorcode is > 0
 */
typedef NS_ENUM(NSInteger, YuneecCameraErrorCode) {
    /**
     * No error
     */
    YuneecCameraErrorNoError                        = 0x0000,
    /**
     * The camera is not connected
     */
    YuneecCameraErrorIsDisconnected                 = -70001,
    /**
     * The camera is not initialized
     */
    YuneecCameraErrorIsNotInitialized               = -70002,
    /**
     * the camera is in progress
     */
    YuneecCameraErrorIsInProgress                   = -70003,
    /**
     *  The camera is not support this method
     */
    YuneecCameraErrorIsNotSupport                   = -70004,
    /**
     * The camera command execute failed
     */
    YuneecCameraErrorFailed                         = -70005,
    /**
     * The camera command is timeout
     */
    YuneecCameraErrorTimeout                        = -70006,
    /**
     * the paramter is invalid
     */
    YuneecCameraInvalidParameter                    = -70007,
    /**
     * The camera return error param id
     */
    YuneecCameraErrorWrongParamId                   = -70008,
    /**
     * The camera return error param value
     */
    YuneecCameraErrorWrongParamValue                = -70009,
    /**
     * The camera return data is invalid
     */
    YuneecCameraErrorReturnDataInvalid              = -70010,
    /**
     * The camera is not video mode
     * When in photo mode call start/stop recording video method will return this error.
     */
    YuneecCameraErrorIsNotVideoMode                 = -70011,
    /**
     * The camera is not photo mode
     * When in video mode call take photo method will return this error.
     */
    YuneecCameraErrorIsNotPhotoMode                 = -70012,
    /**
     * The camera is recording video
     * When the camera is recording video, call start recording video method will return this error.
     */
    YuneecCameraErrorIsRecordingVideo               = -70013,
    /**
     * The camera is not recording video
     * When the camera is not recording video, call stop recording video method will return this error.
     */
    YuneecCameraErrorIsNotRecordingVideo            = -70014,
    /**
     * Transfer file to camera failed with invalid file name ack
     */
    YuneecCameraFileTransferInvalidFileNameAck      = -70015,
    /**
     * Transfer file to camera timeout
     */
    YuneecCameraFileTransferTimeout                 = -10002,
    /**
     * Transfer file return wrong data
     */
    YuneecCameraFileTransferReceiveWrongData        = -10003,
    /**
     * Transfer file return too many connection
     */
    YuneecCameraFileTransferTooManyConnection       = -10004,
    /**
     * Transfer file return CRC error
     */
    YuneecCameraFileTransferCRCError                = -10005,
    /**
     * Connected to server failed
     */
    YuneecCameraFileTransferConnectionFailed        = -10006,
    /**
     * File name too long
     */
    YuneecCameraFileTransferFileNameTooLong         = -10007,
    /**
     * system call error
     */
    YuneecCameraFileTransferSysCallError            = -10008,
};

@interface NSError (YuneecCameraSDK)

+ (instancetype _Nullable)buildCameraErrorForCode:(NSInteger)errorCode;

@end

NS_ASSUME_NONNULL_END
