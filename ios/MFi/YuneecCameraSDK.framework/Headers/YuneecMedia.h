//
//  YuneecFile.h
//  YuneecSDK
//
//  Created by Mine on 2017/3/9.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Yuneec Meida Type
 */
typedef NS_ENUM (NSInteger, YuneecMediaType) {
    /**
     Unknown
     */
    YuneecMediaTypeUnknown,
    /**
     JPEG
     */
    YuneecMediaTypeJPEG,
    /**
     DNG
     */
    YuneecMediaTypeDNG,
    /**
     MP4
     */
    YuneecMediaTypeMP4,
    /**
     2nd, preview video
     */
    YuneecMediaType2nd,
    /**
     thm, thumbnail
     */
    YuneecMediaTypeThm,
};

/**
 * Yuneec Meida video resolution
 */
typedef NS_ENUM (NSUInteger, YuneecMediaVideoResolution) {
    /**
     * Unknown video resolution
     */
    YuneecMediaVideoResolutionUnknown,
    /**
     *  The video resolution is 4096x2160
     */
    YuneecMediaVideoResolution4096x2160,
    /**
     *  The video resolution is 3840x2160
     */
    YuneecMediaVideoResolution3840x2160,
    /**
     * The video resolution is 2720x1530
     */
    YuneecMediaVideoResolution2720x1530,
    /**
     *  The video resolution is 2704x1520
     */
    YuneecMediaVideoResolution2704x1520,
    /**
     * The video resolution is 2560x1440
     */
    YuneecMediaVideoResolution2560x1440,
    /**
     *  The video resolution is 1920x1080
     */
    YuneecMediaVideoResolution1920x1080,
    /**
     *  The video resolution is 1280x720
     */
    YuneecMediaVideoResolution1280x720,
};

/**
 *  Yuneec Media
 */
@interface YuneecMedia : NSObject

/**
 *  Returns the type of media file.
 */
@property (nonatomic, readonly) YuneecMediaType mediaType;

/**
 *  Returns the name of the media file.
 */
@property (nonatomic, readonly) NSString *_Nonnull fileName;

/**
 *  Returns the time when the media file was created as a string in
 *  the format "YYYY-MMM-dd HH:mm:ss".
 */
@property (nonatomic, readonly) NSString *_Nonnull createDate;

/**
 *  Returns the size (bytes) of the media file
 */
@property (nonatomic, readonly) NSString *_Nonnull fileSize;

/**
 Returns MD5 of the media file
 */
@property (nonatomic, readonly) NSString *_Nullable fileMD5;

/**
 *  If the media file is a video, this property returns the duration
 *  of the video in seconds.
 */
@property (nonatomic, readonly) float videoDuration;

/**
 *  If the media file is a video, this property returns the resolution
 *  of the video.
 */
@property (nonatomic, readonly) YuneecMediaVideoResolution videoResolution;

/**
 Returns thumbnail of the media file
 */
@property (nonatomic, strong, readonly) YuneecMedia *_Nullable thumbnailMedia;

/**
 Returns preview video of the media file
 */
@property (nonatomic, strong, readonly) YuneecMedia *_Nullable previewMedia;

/**
 * mark the media if has DNG, use to delete DNG file.
 */
@property (nonatomic, assign) BOOL hasDNG;

/**
 *  Fetches this media's thumbnail from the SD card.
 *
 *  @param filePath Full file storage path, including directory and file name
 *  @param block Return nil when media data has been received from the SD card or an error has occurred.
 *
 */
- (void)fetchThumbnailWithFilePath:(NSString *_Nonnull)filePath block:(void (^_Nonnull)(NSError *_Nullable error))block;

/**
 *  Fetches this media's image data from the SD card.
 *
 *  @param filePath Full file storage path, including directory and file name
 *  @param progress Progress callback will be invoked when downloading begins, progress range will be from 0.0 to 1.0. Progress also can be stopped when 'stop' is set to be YES.
 *  @param block Return nil when media data has been received from the SD card or an error has occurred.
 */
- (void)fetchImageDataWithFilePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress, BOOL *_Nullable stop))progress block:(void (^_Nonnull)(NSError *_Nullable error))block;

/**
 *  Fetches this media's video data from the SD card.
 *
 *  @param filePath Full file storage path, including directory and file name
 *  @param progress Progress callback will be invoked when downloading begins, progress range will be from 0.0 to 1.0. Progress also can be stopped when 'stop' is set to be YES.
 *  @param block Return nil when media data has been received from the SD card or an error has occurred.
 */
- (void)fetchVideoDataWithFilePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress, BOOL *_Nullable stop))progress block:(void (^_Nonnull)(NSError *_Nullable error))block;

/**
 *  Fetches this media's preview video data. The preview video is a lower resolution (720p, 30fps) version which provides an optimized storage choice for customer.
 *
 *  @param filePath Full file storage path, including directory and file name
 *  @param progress Progress callback will be invoked when downloading progress begins, progress range will be from 0.0 to 1.0. Progress also can be stopped when 'stop' is set to be YES.
 *  @param block Return nil when media data has been received from the SD card or an error has occurred.
 */
- (void)fetchPreviewVideoDataWithFilePath:(NSString *_Nonnull)filePath progress:(void(^_Nullable)(float progress, BOOL *_Nullable stop))progress block:(void (^_Nonnull)(NSError *_Nullable error))block;

@end
