//
//  YuneecCamera.h
//  YuneecCameraSDK
//
//  Created by tbago on 2017/9/5.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <YuneecCameraSDK/YuneecRational.h>
#import <YuneecCameraSDK/YuneecCameraDefine.h>

NS_ASSUME_NONNULL_BEGIN

@class YuneecCamera;
@class YuneecCameraState;
@class YuneecCameraH264VideoFrame;
/**
 * delegate method for camera stream data and camera status
 */
@protocol YuneecCameraDelegate <NSObject>

@optional

/**
 * receive H.264 data from camera
 *
 * @param camera the camera instance
 * @param videoFrame return video data
 */
- (void)camera:(YuneecCamera *) camera didReceiveVideoFrame:(YuneecCameraH264VideoFrame *) videoFrame;

/**
 * recevie camera state change and data
 *
 *@param camera the camera instance
 * @param cameraState return current camera state
 */
- (void)camera:(YuneecCamera *) camera didChangeCameraState:(YuneecCameraState *) cameraState;

/**
 * recevie camera histogram data
 *
 * @param camera the camera instance
 * @param histogramData return histogram data array
 */
- (void)camera:(YuneecCamera *) camera didReceiveHistogramData:(NSArray *) histogramData;

/**
 * recevie camera error via remote controller
 *
 * @param camera the camera instance
 * @param error return remote controller error
 */
- (void)camera:(YuneecCamera *) camera didReceiveErrorViaRemoteController:(NSError *) error;

/**
 * receive camera cature state change

 * @param camera the camera instance
 * @param isCapturingPhoto Return YES while capturing is taking place.
 */
- (void)camera:(YuneecCamera *) camera didChangeCameraCaptureState:(BOOL)isCapturingPhoto;

@end

@protocol YuneecCameraUpgradeStateDelegate <NSObject>

- (void)camera:(YuneecCamera *) camera didReceiveUpgradeType:(YuneecCameraUpgradeType) upgradeType
 upgradeStatus:(YuneecCameraUpgradeStatus) upgradeStatus
upgradePercent:(float) upgradePercent;

@end

@interface YuneecCamera : NSObject

/**
 *  Add delegate to camera.
 *
 *  @param cameraDelegate input delegate
 */
- (void)addDelegate:(id<YuneecCameraDelegate>) cameraDelegate;

/**
 *  Remove camera delegate
 *
 *  @param cameraDelegate input delegate
 */
- (void)removeDelegate:(id<YuneecCameraDelegate>)   cameraDelegate;

/**
 *  Remove all delegates.
 */
- (void)removeAllDelegates;

/**
 *  Ready to update status.
 */
- (void)readyToUpdate;

@property (nonatomic, weak, nullable) id<YuneecCameraUpgradeStateDelegate>   upgradeStateDelegate;

#pragma mark - Camera init method

/**
 * Init Yuneec Camera, Must call this method before other method.
 * If the camera is bind by self. You don't need call this method again.
 *
 *  @param block A block object to be executed when the command return. When execute success the error is nil
 */
- (void)initCamera:(void(^)(NSError *_Nullable error)) block;

/**
 * Close current camera connection.
 * You need call this method when the Wi-Fi is disconnect or first call camera method.
 */
- (void)closeCamera;

#pragma mark - Camera Stream ExtraData Parser

/**
 * parser camera stream extra data
 *
 * @param extraData input extra data
 */
- (void)parserStreamExtraData:(NSData *) extraData;

#pragma mark - Camera basic command

/**
 *  Change current camera mode
 *
 *  @param cameraMode Camera mode to change
 *  @param block      A block object to be executed when the command return.
 */
- (void)setCameraMode:(YuneecCameraMode) cameraMode
                block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get current camera mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getCameraMode:(void(^)(NSError * _Nullable error,
                           YuneecCameraMode cameraMode)) block;


/**
 *  Start recording video
 *
 *  @param block A block object to be executed when the command return.
 */
- (void)startRecordingVideo:(void(^)(NSError * _Nullable error)) block;

/**
 *  Stop recording video
 *
 *  @param block A block object to be executed when the command return.
 */
- (void)stopRecordingVideo:(void(^)(NSError * _Nullable error)) block;

/**
 *  Take photo
 *
 *  @param block A block object to be executed when the command return.
 */
- (void)takePhoto:(void(^)(NSError * _Nullable error)) block;

/**
 * Stop take photo
 *
 * In single photo mode, you don't need call this method after call take photo command
 * In burst photo mode, you can call this method to cancel burst take photo command
 * In timelapse photo mode, you can call this method to cancel take photo after seconds
 * In Aeb photo mode, you can call this method to cancel Aeb take photo command
 * @param block A block object to be executed when the command return.
 */
- (void)stopTakePhoto:(void(^)(NSError * _Nullable error)) block;

/**
 *  Get Camera version info
 *
 *  @param block A block object to be executed when the command return. cameraType will be camera type; cameraName will be camera type name; version will be camera current version;branch will be camera branch like A or F;
 */
- (void)getCameraVersionInfo:(void(^)(NSError * _Nullable error, YuneecCameraType cameraType, NSString * _Nullable cameraName, NSString * _Nullable version, NSString * _Nullable branch)) block;

/**
 *  Get system version info, packaged firmware which includes camra, flying controller, etc.
 *
 *  @param block A block object to be executed when the command return. Version will be current system version; Branch will be system branch like A or F;
 */
- (void)getSystemVersionInfo:(void(^)(NSError * _Nullable error, NSString * _Nullable name, NSString * _Nullable version, NSString * _Nullable buildVersion, NSString * _Nullable branch)) block;

- (void)getGimbalVersionInfo:(void(^)(NSError * _Nullable error, NSString *_Nullable version)) block;

#pragma mark - Camera Settings

/**
 * Set camera AE Mode
 *
 * @param aeMode input AE Mode
 * @param block A block object to be executed when the command return.
 */
- (void)setAEMode:(YuneecCameraAEMode) aeMode
            block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get camera AE Mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getAEMode:(void(^)(NSError * _Nullable error,
                           YuneecCameraAEMode aeMode)) block;

/**
 * Set Camera ISO value
 *
 * @param isoValue input ISO value
 * @param block A block object to be executed when the command return.
 */
- (void)setISOValue:(NSInteger) isoValue
              block:(void(^)(NSError *_Nullable error)) block;

/**
 * Get camera ISO value
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getISOValue:(void(^)(NSError *_Nullable error,
                             NSInteger isoValue)) block;

/**
 * Set shutter time value
 *
 * @param shutterTime input shutter time value
 * @param block A block object to be executed when the command return.
 */
- (void)setShutterTimeValue:(YuneecRational *) shutterTime
                      block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get camera shutter time value
 
 @param block A block object to be executed when the command return.
 */
- (void)getShutterTimeValue:(void(^)(NSError * _Nullable error,
                                     YuneecRational *_Nullable shutterTime)) block;

/**
 * Set camera Exposure value
 
 @param exposureValue input exposure value
 @param block A block object to be executed when the command return.
 */
- (void)setExposureValue:(YuneecRational *) exposureValue
                   block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get camera Exposuer value
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getExposureValue:(void(^)(NSError * _Nullable error,
                                  YuneecRational * _Nullable exposureValue)) block;

/**
 * Set recording video resolution and framerate.
 * You can get the camera support resolution and framerate by YuneecCameraParameter Object.
 * @param videoResolution input video resolution
 * @param frameRate input video framerate
 * @param block A block object to be executed when the command return.
 */
- (void)setVideoResolution:(YuneecCameraVideoResolution) videoResolution
                 framerate:(YuneecCameraVideoFrameRate) frameRate
                     block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get current camera video resolution and frame rate
 *
 * @param block  A block object to be executed when the command return.
 */
- (void)getVideoResolution:(void(^)(NSError * _Nullable error,
                                    YuneecCameraVideoResolution resolution,
                                    YuneecCameraVideoFrameRate frameRate)) block;

/**
 * Set video file format
 *
 * @param videoFileFormat input video file format
 * @param block A block object to be executed when the command return.
 */
- (void)setVideoFileFormat:(YuneecCameraVideoFileFormat) videoFileFormat
                     block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get video file format
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getVideoFileFormat:(void(^)(NSError * _Nullable error,
                                    YuneecCameraVideoFileFormat videoFileFormat)) block;

/**
 * Set video compression format
 *
 * @param compressionFormat input compression format
 * @param block A block object to be executed when the command return.
 */
- (void)setVideoCompressionFormat:(YuneecCameraVideoCompressionFormat) compressionFormat
                            block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get video compression format
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getVideoCompressionFormat:(void(^)(NSError * _Nullable error,
                                           YuneecCameraVideoCompressionFormat compressionFormat)) block;

/**
 * Set photo aspect ratio
 *
 * @param photoAspectRatio input aspect ratio
 * @param block A block object to be executed when the command return.
 */
- (void)setPhotoAspectRatio:(YuneecCameraPhotoAspectRatio) photoAspectRatio
                      block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get current photo aspect ratio
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getPhotoAspectRatio:(void(^)(NSError * _Nullable error,
                                     YuneecCameraPhotoAspectRatio photoAspectRatio)) block;

/**
 *  Set Photo Quality
 *
 *  @param photoQuality Photo Quality to set.
 *  @param block        A block object to be executed when the command return.
 */
- (void)setPhotoQuality:(YuneecCameraPhotoQuality) photoQuality
                  block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get current camera photo quality
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getPhotoQuality:(void(^)(NSError * _Nullable error,
                                 YuneecCameraPhotoQuality photoQuality)) block;

/**
 * Set photo format
 *
 * @param photoFormat input photo format
 * @param block A block object to be executed when the command return.
 */
- (void)setPhotoFormat:(YuneecCameraPhotoFormat) photoFormat
                 block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get current photo format
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getPhotoFormat:(void(^)(NSError * _Nullable error,
                                YuneecCameraPhotoFormat photoFormat)) block;

/**
 * Set photo mode
 *
 @param photoMode   input photo mode
 @param amount      total take picture count
 @param evStep      in Aeb mode set exposure change between two picture
 @param millisecond in Timelapse mode, set millisecond between take photo in millisecond.
 @param block       A block object to be executed when the command return.
 */
- (void)setPhotoMode:(YuneecCameraPhotoMode) photoMode
              amount:(NSUInteger) amount
         millisecond:(NSUInteger) millisecond
              evStep:(YuneecRational * _Nullable) evStep
               block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get current photo mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getPhotoMode:(void(^)(NSError * _Nullable error,
                              YuneecCameraPhotoMode photoMode,
                              NSUInteger amount,
                              YuneecRational * _Nullable evStep,
                              NSUInteger millisecond)) block;

/**
 * Set Camera Image Quality Mode
 *
 * @param imageQualityMode input image quality mode
 * @param block A block object to be executed when the command return.
 */
- (void)setImageQualityMode:(YuneecCameraImageQualityMode) imageQualityMode
                      block:(void(^)(NSError *_Nullable error)) block;

/**
 * Get Camera Image Quality Mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getImageQualityMode:(void(^)(NSError *_Nullable error,
                                     YuneecCameraImageQualityMode imageQualityMode)) block;

/**
 * Set camera meter mode
 *
 * @param meterMode input meter mode
 * @param block A block object to be executed when the command return.
 */
- (void)setMeterMode:(YuneecCameraMeterMode) meterMode
               block:(void(^)(NSError *_Nullable error)) block;

/**
 * Get camera meter mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getMeterMode:(void(^)(NSError *_Nullable error,
                              YuneecCameraMeterMode meterMode)) block;

/**
 * Set Camera Meter Mode Spot Coordinate
 *
 * @param xCoordinate The click point on video preview x percent. (<= 1.0)
 * @param yCoordinate The click point on video preview y percent. (<= 1.0)
 * @param block A block object to be executed when the command return.
 */
- (void)setMeterModeSpotCoordinate:(float) xCoordinate
                       yCoordinate:(float) yCoordinate
                             block:(void(^)(NSError *_Nullable error)) block;

/**
 *  Set Camera Flicker Mode
 *
 * @param flickerMode input flicker mode value
 * @param block A block object to be executed when the command return.
 */
- (void)setFlickerMode:(YuneecCameraFlickerMode) flickerMode
                 block:(void(^)(NSError *_Nullable error)) block;

/**
 * Get Camera Flicker Mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getFlickerMode:(void(^)(NSError *_Nullable error,
                                YuneecCameraFlickerMode flickerMode)) block;

/**
 * Set Camera White Balance Mode
 *
 * @param whiteBalanceMode            input white balance mode
 * @param block A block object to be executed when the command return.
 */
- (void)setWhiteBalanceMode:(YuneecCameraWhiteBalanceMode) whiteBalanceMode
                      block:(void(^)(NSError *_Nullable error)) block;

/**
 * Get Camera White Balance Mode
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getWhiteBalanceMode:(void(^)(NSError *_Nullable error,
                                     YuneecCameraWhiteBalanceMode whiteBalanceMode)) block;

/**
 * Set Camera manual while balance value in manual white balance mode
 *
 * @param manualWhiteBalanceValue When while balance mode is manual, you can set manual white balance value.
 * The custom while balance value range is [30-80]. The real value is value (K) = value * 100.
 * @param block A block object to be executed when the command return.
 */
- (void)setManualWhileBalanceValue:(NSUInteger) manualWhiteBalanceValue
                             block:(void(^)(NSError *_Nullable error)) block;

/**
 * Get Camera manual while balance value in manual white balance mode
 *
 * @param block A block object to be executed when the command return. Returns custom while balance value range is [30-80]. The real value is value (K) = value * 100.
 */
- (void)getManualWhiteBalanceValue:(void(^)(NSError *_Nullable error,
                                     NSUInteger manualWhiteBalanceValue)) block;

/**
 * Set image flip degree
 *
 * @param imageFlipDegree image flip degree
 * @param block A block object to be executed when the command return.
 */
- (void)setImageFlipDegree:(YuneecCameraImageFlipDegree)imageFlipDegree
                    block:(void (^)(NSError * _Nullable error))block;

/**
 * Get image flip degree
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getImageFlipDegree:(void (^)(NSError * _Nullable error,
                                     YuneecCameraImageFlipDegree imageFlipDegree))block;

/**
 * Set camera stream encoder style
 *
 * @param streamEncoderStyle camera stream encoder style
 * @param block A block object to be executed when the command return.
 */
- (void)setCameraStreamEncoderStyle:(YuneecCameraStreamEncoderStyle)streamEncoderStyle
                     block:(void (^)(NSError * _Nullable error))block;

/**
 * Get camera stream encoder style
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getCameraStreamEncoderStyle:(void (^)(NSError * _Nullable error,
                                     YuneecCameraStreamEncoderStyle streamEncoderStyle))block;

/**
 * Set camera system time
 *
 * @param systemTime camera system time
 * @param block A block object to be executed when the command return.
 */
- (void)setCameraSystemTime:(UInt64)systemTime block:(void (^)(NSError * _Nullable))block;

/**
 * Set EIS Mode
 *
 * @param eISValue camera EIS switch value
 * @param block A block object to be executed when the command return.
 */
- (void)setEISMode:(NSInteger)eISValue block:(void (^)(NSError * _Nullable error))block;

/**
 * Get EIS Mode
 * Get camera EIS switch value
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getEISMode:(void (^)(NSError * _Nullable error, NSInteger value))block;


/**
 * Format camera internal storage
 *
 * @param block A block object to be executed when the command return.
 */
- (void)formatCameraStorage:(void(^)(NSError * _Nullable error)) block;

/**
 * Reset all camera settings
 *
 * @param block A block object to be executed when the command return.
 */
- (void)resetAllCameraSettings:(void(^)(NSError * _Nullable error)) block;


/**
 * for firmware upload md5 value check
 *
 * @param md5Value input md5 value
 * @param block A block object to be executed when the command return.
 */
- (void)sendFirmwareMD5Value:(NSString *) md5Value
                       block:(void(^)(NSError * _Nullable error)) block;

#pragma mark - Wi-Fi Name and Password

/**
 * Set Wi-Fi name
 *
 * @param wifiName input wifiName (maximum of 21 bytes 0-9 || a-z || A-Z || _underline)
 * @param block A block object to be executed when the command return.
 */
- (void)setWifiName:(NSString *) wifiName
              block:(void(^)(NSError * _Nullable error)) block;

/**
 * Get camera Wi-Fi name
 *
 * @param block A block object to be executed when the command return.
 */
- (void)getWifiName:(void(^)(NSError * _Nullable error,
                             NSString * _Nullable wifiName)) block;

/**
 * Set Wi-Fi password
 *
 * @param wifiPassword input Wi-Fi password
 * @param block A block object to be executed when the command return.
 */
- (void)setWifiPassword:(NSString *) wifiPassword
                  block:(void(^)(NSError * _Nullable error)) block;


#pragma mark - state

- (NSUInteger)getTotalStorageInKB;

- (NSUInteger)getFreeStorageInKB;

@end

NS_ASSUME_NONNULL_END
