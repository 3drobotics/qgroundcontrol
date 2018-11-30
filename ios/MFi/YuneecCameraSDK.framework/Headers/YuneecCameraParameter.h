//
//  YuneecCameraParameter.h
//  YuneecSDK
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YuneecCameraSDK/YuneecCameraDefine.h>
#import <YuneecCameraSDK/YuneecRational.h>

NS_ASSUME_NONNULL_BEGIN

@class YuneecCameraParameter;

#pragma mark - Range Key of the change dictionary.
/**
 *  Video resolution and framerate change key.
 */
extern NSString *const YuneecCameraSupportVideoResolutionAndFrameRateChangeKey;

/**
 * ShutterTime change key
 */
extern NSString *const YuneecCameraSupportShutterTimeChangeKey;

/**
 * When a parameter range is changed. The delelgate method will be called.
 */
@protocol YuneecCameraParameterDelegate <NSObject>

@optional
/**
 * When the parameter is changed. the delegate will be called.
 *
 * @param parameter the Yuneec Camera parameter instance
 * @param changeParameterName the changed parameter name
 */
- (void)cameraParameter:(YuneecCameraParameter *) parameter didChangeParameter:(NSString *) changeParameterName;

@end

/**
 * Yuneec camera support parameter
 */
@interface YuneecCameraParameter : NSObject

@property (nonatomic, weak, nullable) id<YuneecCameraParameterDelegate>   cameraParameterDelegate;

/**
 * Singleton object for Yuneec canera parameter
 *
 * @return Yuneec Camera parameter instance
 */
+ (instancetype)sharedInstance;

/**
 * Set camera type. 
 * Must call this method before get camera parameter
 *
 * @param cameraType camera type input
 */
- (void)setCameraType:(YuneecCameraType) cameraType;

/**
 * You need call this method on CGOPro camera before call get video resolution and framerate
 *
 * @param cameraVideoStandard current camera standard
 */
- (void)setCameraVideoStandard:(YuneecCameraVideoStandard) cameraVideoStandard;

/**
 * You need call this method on CGOPro camera before call get video resolution and framerate
 *
 * @param cameraCompressionFormat current camera compression format
 */
- (void)setCameraVideoCompressionFormat:(YuneecCameraVideoCompressionFormat) cameraCompressionFormat;

/**
 * Yuneec camera support video resolution
 *
 * @return camera support video resolution
 */
- (NSArray<NSNumber *> *)supportVideoResolution;

/**
 * Get support video frame rate
 *
 * @return all support video frame rate for current camera type
 */
- (NSArray<NSNumber *> *)supportVideoFrameRate;

/**
 * Get Video resolution support video framerate
 *
 * @param videoResolution input video resolution
 * @return video framerate by the input video resolution
 */
- (NSArray<NSNumber *> *)supportVideoFrameRateByVideoResolution:(YuneecCameraVideoResolution) videoResolution;

/**
 * Get support video resolution and frame rate
 *
 * @return all support video resolution and frame rate for current camera type
 */
- (NSArray<NSDictionary *> *)supportVideoResolutionAndFrameRate;

/**
 * Get camera support video standard value
 *
 * @return camera support video standard value
 */
- (NSArray<NSNumber *> *)supportVideoStandard;

/**
 * Get camera support video mode
 *
 * @return camera support video mode
 */
- (NSArray<NSNumber *> *)supportVideoMode;

/**
 * Get the camera support photo resolution
 *
 * @return camera support photo resolution
 */
- (NSArray<NSNumber *> *)supportPhotoResolution;

/**
 * Get the camera support photo aspect ratio
 *
 * @return camera support photo aspect ratio
 */
- (NSArray<NSNumber *> *)supportPhotoAspectRatio;

/**
 * Get the camera support photo quality
 *
 * @return camera support photo quality
 */
- (NSArray<NSNumber *> *)supportPhotoQuality;

/**
 * Get the camera support photo format
 *
 * @return camera support photo format
 */
- (NSArray<NSNumber *> *)supportPhotoFormat;

/**
 * Get the camera support photo mode
 *
 * @return camera support photo mode
 */
- (NSArray<NSNumber *> *)supportPhotoMode;

/**
 * Get the camera support photo mode burst amount
 *
 * @return photo mode burst amount
 */
- (NSArray<NSNumber *> *)supportPhotoModeBurstAmount;

/**
 * Get the camera support photo mode timer
 *
 * @return photo mode timer
 */
- (NSArray<NSNumber *> *)supportPhotoModeTimer;

/**
 * Get the camera in timelapse photo mode support millisecond value
 *
 * @return timelapse photo mode support millisecond
 */
- (NSArray<NSNumber *> *)supportPhotoModeTimelapseMillisecond;

/**
 * Get the camera in Aeb photo mode ev step by input burst amount
 *
 * @param burstAmount burst amount
 * @return support ev step in burst amount
 */
- (NSArray<YuneecRational *> *)supportPhotoModeAebEvStepByAmount:(NSInteger) burstAmount;

/**
 * Get the camera support AEMode

 @return camera support AEMode
 */
- (NSArray<NSNumber *> *)supportAEMode;

/**
 * Get the camera support exposure value
 *
 * @return camera support exposure value
 */
- (NSArray<YuneecRational *> *)supportExposureValue;

/**
 * You need call this method on CGOPro camera before call get shutter time value
 *
 * @param cameraMode current camera mode
 */
- (void)setCameraMode:(YuneecCameraMode) cameraMode;

/**
 * Get camera support shutter time value
 *
 * @return camera support shutter time value
 */
- (NSArray<YuneecRational *> *)supportShutterTime;

/**
 * Get Camera support ISO value

 @return camera supoort ISO value
 */
- (NSArray<NSNumber *> *)supportISOValue;

/**
 * Get Camera support meter mode
 *
 * @return camera support meter mode
 */
- (NSArray<NSNumber *> *)supportMeterMode;

/**
 * Get Camera support flicker mode
 *
 * @return camera support flicker mode
 */
- (NSArray<NSNumber *> *)supportFlickerMode;

/**
 * Get Camera support white balance mode
 *
 * @return camera support white balance mode
 */
- (NSArray<NSNumber *> *)supportWhiteBalanceMode;


/**
 * Get Camera support manual white balance value
 *
 * @return camera support manual white balance value
 */
- (NSArray<NSNumber *> *)supportManualWhiteBalanceValue;

/**
 * Get Camera support image quality mode
 *
 @return camera support image quality mode
 */
- (NSArray<NSNumber *> *)supportImageQualityMode;

/**
* Get Camera support video compression format

 @return camera support video compression format
 */
- (NSArray<NSNumber *> *)supportVideoCompressionFormat;
 
/**
 * Get Camera support video file format
 *
 * @return camera support video file format
 */
- (NSArray<NSNumber *> *)supportVideoFileFormat;

/**
 * Get camera stream support encoder style
 *
 * @return camera stream support encoder style
 */
- (NSArray<NSNumber *> *)supportStreamEncoderStyle;

/**
 * Get camera support image flip degree
 *
 * @return camera support image flip degree
 */
- (NSArray<NSNumber *> *)supportImageFlipDegree;

/**
 * Get camera support style
 *
 * @return camera support style
 */
- (NSArray<NSNumber *> *)supportStyle;

/**
 * Get camera support center point
 *
 * @return camera support center point
 */
- (NSArray<NSNumber *> *)supportCenterPoints;

@end

NS_ASSUME_NONNULL_END
