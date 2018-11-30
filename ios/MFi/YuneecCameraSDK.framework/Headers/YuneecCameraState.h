//
//  YuneecCameraState.h
//  YuneecSDK
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YuneecCameraSDK/YuneecCameraDefine.h>
#import <YuneecCameraSDK/YuneecRational.h>

/**
 * Current camera panorama state
 */
typedef NS_ENUM (NSUInteger, YuneecCameraPanoramaState) {
    /**
     * Not in panorama mode
     */
    YuneecCameraPanoramaStateNone,
    /**
     * panorama taking photo
     */
    YuneecCameraPanoramaStateTakingPhoto,
    /**
     * panorama take photo complate
     */
    YuneecCameraPanoramaStateTakenDone,
    /**
     * panorma stoped with unexcepted gimbal unexcepted error
     */
    YuneecCameraPanoramaStateGimbalUnexceptedStop,
    /**
     * panorma stoped with unexcepted camera unexcepted error
     */
    YuneecCameraPanoramaStateCameraUnexceptedStop,
    /**
     * panorama init failed
     */
    YuneecCameraPanoramaStateInitFailed,
};

/**
 * Yuneec Camera state
 */
@interface YuneecCameraState : NSObject

/**
 * The camera total storeage in KB
 */
@property (nonatomic, readonly) NSUInteger                  totalStorageInKB;

/**
 * The camera free storage in KB
 */
@property (nonatomic, readonly) NSUInteger                  freeStorageInKB;

/**
 * Current camera mode
 */
@property (nonatomic, readonly) YuneecCameraMode            cameraMode;

/**
 * Whether the camera is recording video
 */
@property (nonatomic, readonly) BOOL                        isRecordingVideo;

/**
 * Current video record time in seconds
 */
@property (nonatomic, readonly) NSUInteger                  videoRecordTimeInSeconds;

/**
 *  Weather the camera is capturing photo
 */
@property (nonatomic, readonly) BOOL                        isCapturingPhoto;

/**
 * Weather the camera is capturing photo timelapse
 */
@property (nonatomic, readonly) BOOL                        isCapturingPhotoTimelapse;

/**
 * Remain photo count
 */
@property (nonatomic, readonly) NSUInteger                  remainingPhotoCount;

/**
 * Remain record time in second
 */
@property (nonatomic, readonly) NSUInteger                  remainingRecordTime;

#pragma mark - camera extra parameter

/**
 * Current record video resolution
 */
@property (nonatomic, readonly) YuneecCameraVideoResolution     videoResolution;

/**
 * Current record video framerate
 */
@property (nonatomic, readonly) YuneecCameraVideoFrameRate      videoFrameRate;

/**
 * Current video file format
 */
@property (nonatomic, readonly) YuneecCameraVideoFileFormat     videoFileFormat;

/**
 * Current photo resolution
 */
@property (nonatomic, readonly) YuneecCameraPhotoResolution     photoResolution;

/**
 * Current photo aspect ratio
 */
@property (nonatomic, readonly) YuneecCameraPhotoAspectRatio    photoAspectRatio;

/**
 * Current photo format
 */
@property (nonatomic, readonly) YuneecCameraPhotoFormat         photoFormat;

/**
 * Current photo quality
 */
@property (nonatomic, readonly) YuneecCameraPhotoQuality        photoQuality;

/**
 * Current photo mode
 */
@property (nonatomic, readonly) YuneecCameraPhotoMode           photoMode;

/**
 * Current photo mode amount
 */
@property (nonatomic, readonly) NSUInteger                      photoModeAmount;

/**
 * Current photo mode millisecond
 */
@property (nonatomic, readonly) NSUInteger                      photoModeMillisecond;

/**
 * Current photo mode EV step
 */
@property (nonatomic, readonly) YuneecRational                  *photoModeEvStep;

/**
 * Current white balance mode
 */
@property (nonatomic, readonly) YuneecCameraWhiteBalanceMode    whiteBalanceMode;

/**
 * Current AE Mode
 */
@property (nonatomic, readonly) YuneecCameraAEMode              aeMode;
/**
 * Current exposure value
 */
@property (nonatomic, readonly) YuneecRational *                exposureValue;

/**
 * Current shutter time value
 */
@property (nonatomic, readonly) YuneecRational *                shutterTime;

/**
 * Current ISO value
 */
@property (nonatomic, readonly) NSInteger                       isoValue;

/**
 * Current flicker mode
 */
@property (nonatomic, readonly) YuneecCameraFlickerMode         flickerMode;

/**
 * Current image quality(scene mode)
 */
@property (nonatomic, readonly) YuneecCameraImageQualityMode    imageQualityMode;

/**
 * Current meter mode
 */
@property (nonatomic, readonly) YuneecCameraMeterMode           meterMode;

/**
 * Current board temperature
 */
@property (nonatomic, readonly) NSUInteger                      boardTemperature;

/**
 * Current panorama state
 */
@property (nonatomic, readonly) YuneecCameraPanoramaState       panoramaState;

/**
 * Panorama need taken total picture
 */
@property (nonatomic, readonly) NSUInteger                      panoramaTotalPicture;

/**
 * Panorama already taken picture
 */
@property (nonatomic, readonly) NSUInteger                      panoramaTakenPicture;

@end
