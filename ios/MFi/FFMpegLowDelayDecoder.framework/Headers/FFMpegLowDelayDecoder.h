//
//  FFMpegLowDelayDecoder.h
//  FFMpegLowDelayDecoder
//
//  Created by tbago on 20/11/2017.
//  Copyright © 2017 yuneec. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FFMpegLowDelayDecoder/FFMpegLowDelayDecoderEnumerator.h>
#import <MediaBase/RawVideoFrame.h>
#import <MediaBase/CompassedFrame.h>

@class MediaCodecInfo;

@interface AVLowDelayCodecParam : NSObject

@property (nonatomic) uint32_t      numThreads;
@property (nonatomic) uint32_t      width;
@property (nonatomic) uint32_t      height;
@property (nonatomic) uint32_t      channels;
@property (nonatomic) uint32_t      sampleRate;
@property (nonatomic, copy) NSData  *extraData;
/**
 * fourcc (LSB first, so "ABCD" -> ('D'<<24) + ('C'<<16) + ('B'<<8) + 'A').
 * This is used to work around some encoder bugs.
 * A demuxer should set this to what is stored in the field used to identify the codec.
 * If there are multiple such fields in a container then the demuxer should choose the one
 * which maximizes the information about the used codec.
 * If the codec tag field in a container is larger than 32 bits then the demuxer should
 * remap the longer ID to 32 bits with a table or other structure. Alternatively a new
 * extra_codec_tag + size could be added but for this a clear advantage must be demonstrated
 * first.
 * - encoding: Set by user, if not then the default based on codec_id will be used.
 * - decoding: Set by user, will be converted to uppercase by libavcodec during init.
 */
@property (nonatomic) uint32_t      codecTag;
/**
 * bits per sample/pixel from the demuxer (needed for huffyuv).
 * - encoding: Set by libavcodec.
 * - decoding: Set by user.
 */
@property (nonatomic) int32_t       bitsPerCodedSample;

@end

/**
 *  Decoder media packet by ffmpeg
 */
@interface FFMpegLowDelayDecoder : NSObject

- (instancetype)initWithCodecInfo:(MediaCodecInfo *) codecInfo;

- (BOOL)openCodec:(AVLowDelayCodecParam *) codecParam;

- (void)closeCodec;

- (RawVideoFrame *)decodeVideoFrame:(CompassedFrame *) compassedFrame;

@end

/**
 *  Create Decoder instance
 *
 *  @return decoder instance
 */
FFMpegLowDelayDecoder *createFFmpegLowDelayDecoder();

