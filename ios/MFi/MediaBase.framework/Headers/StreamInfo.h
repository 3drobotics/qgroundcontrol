//
//  StreamInfo.h
//  MediaBase
//
//  Created by tbago on 16/12/16.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaConstant.h"
#import "ResuableCodecID.h"
#import "ResuablePixelFormat.h"
#import "ResuableSampleFormat.h"
/**
 *  media stream info
 */
@interface StreamInfo : NSObject

@property (nonatomic) StreamType            streamType;
@property (nonatomic) int32_t               streamId;
@property (nonatomic, copy) NSString        *streamName;
@property (nonatomic) ResuableCodecID       codecID;
@property (nonatomic, copy) NSString        *codecName;
@property (nonatomic, copy) NSString        *language;
@property (nonatomic) int64_t               bitrate;    ///< The average bitrate of the encoded data (in bits per second)
@property (nonatomic) int64_t               duration;   ///< stream duration in ms, -1 is unkonwn
@property (nonatomic) uint32_t              codecTag;
@property (nonatomic) int32_t               bitsPerCodedSample;

///< video param
@property (nonatomic) int32_t               width;
@property (nonatomic) int32_t               height;
@property (nonatomic) ResuablePixelFormat   pixelFormat;
@property (nonatomic) int32_t               framerateNumerator;
@property (nonatomic) int32_t               framerateDenominator;
@property (nonatomic) int32_t               pixelAspectRatioNumerator;
@property (nonatomic) int32_t               pixelAspectRatioDenominator;
///< audio param
@property (nonatomic) ResuableSampleFormat  sampleFormat;
@property (nonatomic) int32_t               samplerate;
@property (nonatomic) int32_t               channels;

///< metadata
@property (strong, nonatomic, readonly) NSDictionary<NSString *, NSString *>    *metaData;          ///< stream metadata
- (void)addMetaDataToStreamInfo:(NSString *) key
                          value:(NSString *) value;

///< extra data
@property (nonatomic, copy) NSData          *extraData;
@end
