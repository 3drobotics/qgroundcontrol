//
//  YuneecH264VideoFrame.h
//  YuneecSDK
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * H664 video frame from yuneec camera stream
 */
@interface YuneecCameraH264VideoFrame : NSObject

/**
 * Weather the video frame is key frame
 */
@property (nonatomic) BOOL              keyFrame;

/**
 * Video frame decompass timestamp value (100ns)
 */
@property (nonatomic) int64_t           decompassTimeStamp;

/**
 * Video frame present timestamp value (100ns)
 */
@property (nonatomic) int64_t           presentTimeStamp;

/**
 * H.264 frame data
 */
@property (copy, nonatomic) NSData      *frameData;

@end
