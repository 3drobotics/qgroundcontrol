//
//  YuneecDecoder.h
//  YuneecDecoder
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <YuneecDecoder/YuneecRawVideoFrame.h>
#import <YuneecDecoder/YuneecSampleVideoFrame.h>

NS_ASSUME_NONNULL_BEGIN

@class YuneecDecoder;

/**
 * Delegate method for decoder callback
 */
@protocol YuneecDecoderDelegate <NSObject>

@optional

/**
 * the decoder decode frame complate callback method
 *
 * @param decoder the decoder instance
 * @param rawVideoFrame output YUV420P raw frame
 */
- (void)decoder:(YuneecDecoder *) decoder didDecoderVideoFrame:(YuneecRawVideoFrame *)  rawVideoFrame;

/**
 * the decoder decodes frame complete callback or deliver comprassed video for HW decoding & HW display
 *
 *
 * @param decoder the decoder instance
 * @param sampleVideoFrame is compressed video or decoded uncompressed video
 */
- (void)decoder:(YuneecDecoder *) decoder didDisplaySampleFrame:(YuneecSampleVideoFrame *) sampleVideoFrame;

/**
 * the video resolution changed callback method
 *
 * @param decoder the decoder instance
 * @param videoWidth current video width
 * @param videoHeight current video height
 */
- (void)decoder:(YuneecDecoder *) decoder didChangeVideoWidth:(uint32_t) videoWidth videoHeight:(uint32_t) videoHeight;

@end

@interface YuneecDecoder : NSObject

/**
 * Open decoder for decode frame.
 *
 * @return Weather the decoder open success.
 */
- (BOOL)openCodec;

/**
 * Close decoder when not need use.
 */
- (void)closeCodec;

/**
 * decode video frame
 *
 * @param frameData input H.264 video frame
 * @param decompassTimeStamp video frame decompass timestamp
 * @param presentTimeStamp video frame present timestamp
 */
- (void)decodeVideoFrame:(NSData *) frameData
      decompassTimeStamp:(int64_t) decompassTimeStamp
        presentTimeStamp:(int64_t) presentTimeStamp;

@end


/**
 * Create decoder instance
 *
 * @param enableHardwareDecoder weather enable hardware decoder
 * @param enableLowDelay weather enable low delay decoder
 * @return Yuneec decoder instance
 */
YuneecDecoder * createYuneecDecoder(id<YuneecDecoderDelegate> decoderDelegate, BOOL enableHardwareDecoder, BOOL enableLowDelay);

NS_ASSUME_NONNULL_END
