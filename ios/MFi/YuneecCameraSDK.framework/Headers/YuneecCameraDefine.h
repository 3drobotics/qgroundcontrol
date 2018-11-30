//
//  YuneecCameraDefine.h
//  YuneecSDK
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#ifndef YUNEEC_CAMERA_DEFINE_H_
#define YUNEEC_CAMERA_DEFINE_H_

/**
 *  Yuneec Camera Type
 */
typedef NS_ENUM(NSUInteger, YuneecCameraType) {
    /**
     * Breeze Camera
     */
    YuneecCameraTypeBreeze,
    /**
     * CGO3Plus Camera
     */
    YuneecCameraTypeCGO3Plus,
    /**
     * CGOPro Camera
     */
    YuneecCameraTypeCGOPro,
    /**
     * CGOET Camera
     */
    YuneecCameraTypeCGOET,
    /**
     * CGOT Camera
     */
    YuneecCameraTypeCGOT,
    /**
     * V30 Camera
     */
    YuneecCameraTypeV30,
    /**
     * Firebird Camera
     */
    YuneecCameraTypeFirebird,
    /**
     * Q400 Camera
     */
    YuneecCameraTypeQ400,
    /**
     *Breeze 2 Camera
     */
    YuneecCameraTypeBreeze2,
    /**
     * E50(CGOCI) Camera
     */
    YuneecCameraTypeE50,
    /**
     * E90(CGOPPRO) Camera
     */
    YuneecCameraTypeE90,
    /**
     * E10T(CGOT) Camera
     */
    YuneecCameraTypeE10T,
    /**
     * E30Z(V30) Camera
     */
    YuneecCameraTypeE30Z,
    /**
     * HDRacer Camera
     */
    YuneecCameraTypeHDRacer,
    /**
     * OB Camera
     */
    YuneecCameraTypeOB,
    /**
     * V18S Camera
     */
    YuneecCameraTypeV18S,
    /**
     * Unknown Camera type
     */
    YuneecCameraTypeUnknown = 0xff,
};

/**
 * Yuneec camera mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraMode) {
    /**
     * Video mode. In this mode, the user can record video.
     */
    YuneecCameraModeVideo,
    /**
     * Audio mode. In this mode, the user can take photo.
     */
    YuneecCameraModePhoto,
    /**
     * Invalid mode. The camera mode is unknown.
     */
    YuneecCameraModeUnknown = 0xff,
};

/**
 * Yuneec Camera support video resolution
 * Different video resolution may support different framerate
 */
typedef NS_ENUM (NSUInteger, YuneecCameraVideoResolution) {
    /**
     *  The camera video resolution is 4096x2160
     */
    YuneecCameraVideoResolution4096x2160,
    /**
     *  The camera video resolution is 3840x2160
     */
    YuneecCameraVideoResolution3840x2160,
    /**
     * The camera video resolution is 2720x1530
     */
    YuneecCameraVideoResolution2720x1530,
    /**
     *  The camera video resolution is 2704x1520
     */
    YuneecCameraVideoResolution2704x1520,
    /**
     *  The camera video resolution is 2688x1520
     */
    YuneecCameraVideoResolution2688x1520,
    /**
     * The camera video resolution is 2560x1440
     */
    YuneecCameraVideoResolution2560x1440,
    /**
     *  The camera video resolution is 1920x1080
     */
    YuneecCameraVideoResolution1920x1080,
    /**
     *  The camera video resolution is 1280x720
     */
    YuneecCameraVideoResolution1280x720,
    /**
     * Unknown camera video resolution
     */
    YuneecCameraVideoResolutionUnknown = 0xff,
};

/**
 * Camera support video framerate
 */
typedef NS_ENUM (NSUInteger, YuneecCameraVideoFrameRate) {
    /**
     *  The camera video frame rate is 24fps
     */
    YuneecCameraVideoFrameRate24FPS,
    /**
     *  The camera video frame rate is 25fps
     */
    YuneecCameraVideoFrameRate25FPS,
    /**
     *  The camera video frame rate is 30fps
     */
    YuneecCameraVideoFrameRate30FPS,
    /**
     *  The camera video frame rate is 48fps
     */
    YuneecCameraVideoFrameRate48FPS,
    /**
     *  The camera video frame rate is 50fps
     */
    YuneecCameraVideoFrameRate50FPS,
    /**
     *  The camera video frame rate is 60fps
     */
    YuneecCameraVideoFrameRate60FPS,
    /**
     *  The camera video frame rate is 100fps
     */
    YuneecCameraVideoFrameRate100FPS,
    /**
     *  The camera video frame rate is 120fps
     */
    YuneecCameraVideoFrameRate120FPS,
    /**
     * The camera video frame rate is 240fps
     */
    YuneecCameraVideoFrameRate240FPS,
    /**
     *  The camera video frame rate is unknown
     */
    YuneecCameraVideoFrameRateUnknown = 0xff,
};

/**
 * Camera support video file format
 */
typedef NS_ENUM(NSUInteger, YuneecCameraVideoFileFormat) {
    /**
     * MP4 video file format
     */
    YuneecCameraVideoFileFormatMP4,
    /**
     * MOV video file format
     */
    YuneecCameraVideoFileFormatMOV,
    /**
     * Unknown video file format
     */
    YuneecCameraVideoFileFormatUnknown = 0xff,
};

/**
 * Camera support video standard value
 */
typedef NS_ENUM (NSUInteger, YuneecCameraVideoStandard) {
    /**
     * The camera video standard value is NTSC
     */
    YuneecCameraVideoStandardNTSC,
    /**
     * The camera video standard value is PAL
     */
    YuneecCameraVideoStandardPAL,
    /**
     * The camera video standard value is unkonwn
     */
    YuneecCameraVideoStandardUnknown    = 0xff,
};

/**
 * Camera support video mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraVideoMode) {
    /**
     * The camera video mode is normal
     */
    YuneecCameraVideoModeNormal,
    /**
     * The camera video mode is slow motion
     */
    YuneecCameraVideoModeSlowMotion,
    /**
     * The camera video mode is time lapse
     */
    YuneecCameraVideoModeTimeLapse,
    /**
     * The camera video mode is unkonwn
     */
    YuneecCameraVideoModeUnknown    = 0xff,
};

/**
 * Yuneec Camera support photo resolution
 */
typedef NS_ENUM (NSUInteger, YuneecCameraPhotoResolution) {
    /**
     * The camera photo resolution is 4060x3120
     */
    YuneecCameraPhotoResolution4160x3120,
    /**
     * The camera photo resolution is 4000x3000
     */
    YuneecCameraPhotoResolution4000x3000,
    /**
     * The camera photo resolution is 4000x2250
     */
    YuneecCameraPhotoResolution4000x2250,
    /**
     * The camera photo resolution is 3968x2232
     */
    YuneecCameraPhotoResolution3968x2232,
    /**
     * The camera photo resolution is 3936x2624
     */
    YuneecCameraPhotoResolution3936x2624,
    /**
     * The camera photo resolution is 3264x2448
     */
    YuneecCameraPhotoResolution3264x2448,
    /**
     * The camera photo resolution is 3008x3000
     */
    YuneecCameraPhotoResolution3008x3000,
    /**
     * The camera photo resolution is 2592x1944
     */
    YuneecCameraPhotoResolution2592x1944,
    /**
     * The camera photo resolution is unknown
     */
    YuneecCameraPhotoResolutionUnknown = 0xff,
};

/**
 * Yuneec Camera support photo quality
 */
typedef NS_ENUM (NSUInteger, YuneecCameraPhotoQuality) {
    /**
     * Low photo quality
     */
    YuneecCameraPhotoQualityLow,
    /**
     * Normal photo quality
     */
    YuneecCameraPhotoQualityNormal,
    /**
     * High photo quality
     */
    YuneecCameraPhotoQualityHigh,
    /**
     * Ultra high photo quality
     */
    YuneecCameraPhotoQualityUltraHigh,
    /**
     * Unknown photo quality
     */
    YuneecCameraPhotoQualityUnknown = 0xff,
};


/**
 * Yuneec Camera support photo mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraPhotoMode) {
    /**
     * The basic photo mode.
     */
    YuneecCameraPhotoModeSingle,
    /**
     * In timelapse mode，you should set millisecond parameter between take photo in millisecond. 
     */
    YuneecCameraPhotoModeTimeLapse,
    /**
     * In burst mode, you should set amount parameter as target total pictures number,
     */
    YuneecCameraPhotoModeBurst,
    /**
     *  enable set expusure change between two picture
     */
    YuneecCameraPhotoModeAeb,
    /**
     *Horizon panorama photo mode
     */
    YuneecCameraPhotoModePanoramaHorizon,
    /**
     * Hemisphere panorama photo mode
     */
    YuneecCameraPhotoModePanoramaHemisphere,
    /**
     * 360 panorama photo mode, implemented by drone
     */
    YuneecCameraPhotoModePanorama360,
    /**
     * Gesture photo mode, implemented by app
     */
    YuneecCameraPhotoModeGesture,
    /**
     * Face recognition photo mode, implemented by app
     */
    YuneecCameraPhotoModeFaceRecognition,
    /**
     * Unknown photo mode
     */
    YuneecCameraPhotoModeUnknown = 0xff,
};


/**
 * Yuneec Camera support photo aspect ratio (width:height).
 */
typedef NS_ENUM (NSUInteger, YuneecCameraPhotoAspectRatio) {
    /**
     * The camera photo aspect ratio is 4:3
     */
    YuneecCameraPhotoAspectRatio4_3,
    /**
     * The camera photo aspect ratio is 16:9
     */
    YuneecCameraPhotoAspectRatio16_9,
    /**
     * The camera photo aspect ratio is 3:2
     */
    YuneecCameraPhotoAspectRatio3_2,
    /**
     * The camera photo aspect ratio is unknown
     */
    YuneecCameraPhotoAspectRatioUnknown = 0xff,
};

/**
 * Yuneec Camera support photo format
 */
typedef NS_ENUM (NSUInteger, YuneecCameraPhotoFormat) {
    /**
     * Jpg photo format
     */
    YuneecCameraPhotoFormatJpg,
    /**
     * Raw photo format
     */
    YuneecCameraPhotoFormatRaw,
    /**
     * Dng photo format
     */
    YuneecCameraPhotoFormatDng,
    /**
     * jpg+raw photo format
     */
    YuneecCameraPhotoFormatJpgRaw,
    /**
     * jpg+dng photo format
     */
     YuneecCameraPhotoFormatJpgDng,
    /**
     * Unknown camera photo format
     */
    YuneecCameraPhotoFormatUnknown = 0xff,
};

/**
 * Yuneec Camera AEMode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraAEMode) {
    /**
     * In AEMode Auto, you can only set the Exposure value
     */
    YuneecCameraAEModeAuto,
    /**
     * In AEMode Manual, you can only set the shutter time and iso value
     */
    YuneecCameraAEModeManual,
    /**
     * Lock AEMode
     */
    YuneecCameraAEModeLock,
    /**
     * Unknown AEMode
     */
    YuneecCameraAEModeUnknown,
};

/**
 * Yuneec Camera meter mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraMeterMode) {
    /**
     * center meter mode
     */
    YuneecCameraMeterModeCenter,
    /**
     * average meter mode
     */
    YuneecCameraMeterModeAverage,
    /**
     * spot meter mode
     */
    YuneecCameraMeterModeSpot,
    /**
     * unknown meter mode
     */
    YuneecCameraMeterModeUnknown = 0xff,
};

/**
 * Yuneec Camera Flick mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraFlickerMode) {
    /**
     * Auto Flicker mode
     */
    YuneecCameraFlickerModeAuto,
    /**
     * 60Hz Flicker mode
     */
    YuneecCameraFlickerMode60Hz,
    /**
     * 50Hz Flicker mode
     */
    YuneecCameraFlickerMode50Hz,
    /**
     * No 60Hz Flicker mode
     */
    YuneecCameraFlickerModeNo60Hz,
    /**
     * No 50Hz Flicker mode
     */
    YuneecCameraFlickerModeNo50Hz,
    /**
     * Camera flicker mode is unknown
     */
    YuneecCameraFlickerModeUnknown = 0xff,
};


/**
 * Yuneec Camera White Balance Mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraWhiteBalanceMode) {
    /**
     * Auto White Balance Mode
     */
    YuneecCameraWhiteBalanceModeAuto,
    /**
     * Sunny White Balance Mode
     */
    YuneecCameraWhiteBalanceModeSunny,
    /**
     * Sunrise White Balance Mode
     */
    YuneecCameraWhiteBalanceModeSunrise,
    /**
     * Sunset White Balance Mode
     */
    YuneecCameraWhiteBalanceModeSunset,
    /**
     * Cloudy White Balance Mode
     */
    YuneecCameraWhiteBalanceModeCloudy,
    /**
     * Flucrescent White Balance Mode
     */
    YuneecCameraWhiteBalanceModeFlucrescent,
    /**
     * Incandescent White Balance Mode
     */
    YuneecCameraWhiteBalanceModeIncandescent,
    /**
     * Manual White Balance Mode
     */
    YuneecCameraWhiteBalanceModeManual,
    /**
     * Lock White Balance Mode
     */
    YuneecCameraWhiteBalanceModeLock,
    /**
     * Manual Color Temp White Balance Mode
     */
    YuneecCameraWhiteBalanceModeManualColorTemp,
    /**
     * Unknown White Balance Mode
     */
    YuneecCameraWhiteBalanceModeUnknown = 0xff,
};


/**
 * Yuneec Camera Image Quality Mode
 */
typedef NS_ENUM (NSUInteger, YuneecCameraImageQualityMode) {
    /**
     * Nature Image Quality Mode
     */
    YuneecCameraImageQualityModeNature,
    /**
     * Saturation Image Quality Mode
     */
    YuneecCameraImageQualityModeSaturation,
    /**
     * Raw Image Quality Mode
     */
    YuneecCameraImageQualityModeRaw,
    /**
     * Night Image Quality Mode
     */
    YuneecCameraImageQualityModeNight,
    /**
     * Log Image Quality Mode
     */
    YuneecCameraImageQualityModeLog,
    /**
     * Soft Image Quality Mode
     */
    YuneecCameraImageQualityModeSoft,
    /**
     * Unknown Image Quality Mode
     */
    YuneecCameraImageQualityModeUnknown = 0xff,
};

/**
 * Yuneec Camera video compression format
 */
typedef NS_ENUM (NSUInteger, YuneecCameraVideoCompressionFormat) {
    /**
     *  H.264 video compression format.
     */
    YuneecCameraVideoCompressionFormatH264,
    /**
     *  H.264 video compression format.
     */
    YuneecCameraVideoCompressionFormatH265,
    /**
     *  Unknown video compression format.
     */
    YuneecCameraVideoCompressionFormatUnknown = 0xff,
};


/**
 * Yuneec Camera encoder style
 */
typedef NS_ENUM (NSUInteger, YuneecCameraStreamEncoderStyle) {
    /**
     * No camera stream encoder style (disable lowdelay)
     */
    YuneecCameraStreamEncoderStyleNo,
    /**
     * Intra camera stream encoder style
     */
    YuneecCameraStreamEncoderStyleIntra,
    /**
     * Slice camera stream encoder style
     */
    YuneecCameraStreamEncoderStyleSlice,
    /**
     * Slice and intra camera stream encoder style (enable lowdelay)
     */
    YuneecCameraStreamEncoderStyleSliceAndIntra,
    /**
     * Unknown camera stream encoder style
     */
    YuneecCameraStreamEncoderStyleUnknown = 0xff,
};

/**
 * Yuneec Camera image flip degree
 */
typedef NS_ENUM (NSUInteger, YuneecCameraImageFlipDegree) {
    /**
     * No image flip
     */
    YuneecCameraImageFlipDegree0,
    /**
     * Image flip degree: 90°
     */
    YuneecCameraImageFlipDegree90,
    /**
     * Image flip degree: 180°
     */
    YuneecCameraImageFlipDegree180,
    /**
     * Image flip degree: 270°
     */
    YuneecCameraImageFlipDegree270,
    /**
     * Unknown image flip degree
     */
    YuneecCameraImageFlipDegreeUnknown = 0xff,
};

/**
 * Yuneec Camera style
 */
typedef NS_ENUM (NSUInteger, YuneecCameraStyle) {
    /**
     * Standard camera style
     */
    YuneecCameraStyleStandard,
    /**
     * Landscape camera style
     */
    YuneecCameraStyleLandscape,
    /**
     * Soft camera style
     */
    YuneecCameraStyleSoft,
    /**
     * Custom camera style
     */
    YuneecCameraStyleCustom,
    /**
     * Unknown camera style
     */
    YuneecCameraStyleUnknown = 0xff,
};

/**
 * Yuneec Camera center points type
 */
typedef NS_ENUM (NSUInteger, YuneecCameraCenterPointsType) {
    /**
     * None center points / Closed center points
     */
    YuneecCameraCenterPointsTypeNone,
    /**
     * Circle center points
     */
    YuneecCameraCenterPointsTypeCircle,
    /**
     * Cross center points
     */
    YuneecCameraCenterPointsTypeCross,
    /**
     * Square with no point
     */
    YuneecCameraCenterPointsTypeSquareWithNoPoint,
    /**
     * Square with point
     */
    YuneecCameraCenterPointsTypeSquareWithPoint,
    /**
     * Unknown center points
     */
    YuneecCameraCenterPointsTypeUnknown = 0xff,
};

/**
 * Yuneec Camera upgrade type
 */
typedef NS_ENUM (NSUInteger, YuneecCameraUpgradeType) {
    /**
     * upgrade auto pilot
     */
    YuneecCameraUpgradeTypeAutoPilot,
    /**
     * upgrade gimbal
     */
    YuneecCameraUpgradeTypeGimbal,
    /**
     * upgrade camera
     */
    YuneecCameraUpgradeTypeCamera,
    /**
     * upgrade optical flow
     */
    YuneecCameraUpgradeTypeOpticalFlow,
    /**
     * upgrade remote controller
     */
    YuneecCameraUpgradeTypeRemoteController,
    /**
     * decompress firmware
     */
    YuneecCameraUpgradeTypeDecompressFirmware,
    /**
     * unknown upgrade type
     */
    YuneecCameraUpgradeTypeUnknown = 0xff,
};

/**
 * Yuneec camera upgrade status
 */
typedef NS_ENUM (NSUInteger, YuneecCameraUpgradeStatus) {
    /**
     * ready for upgrade
     */
    YuneecCameraUpgradeStatusReady,
    /**
     * upgrade in progress
     */
    YuneecCameraUpgradeStatusInProgress,
    /**
     * upgrade finished
     */
    YuneecCameraUpgradeStatusFinished,
    /**
     * decompress firmware failed
     */
    YuneecCameraUpgradeStatusFailed,
    /**
     * unknown upgrade status
     */
    YuneecCameraUpgradeStatusUnknown = 0xff,
};
#endif /* YUNEEC_CAMERA_DEFINE_H_ */
