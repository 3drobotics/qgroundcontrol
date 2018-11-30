//
//  FFMpegDecoderEnumerator.h
//  FFMpegDecoder
//
//  Created by tbago on 16/12/29.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaBase/ResuableCodecID.h>

@class FFMpegLowDelayDecoder;

/**
 *  Enum all ffmpeg decoders
 */
@interface FFMpegLowDelayDecoderEnumerator : NSObject
/**
 *  init all decoder info array
 */
- (void)initDecoderArray;

/**
 *  Create ffmpeg decoder by codec info array index
 *
 *  @param codecID create decoder codec ID type 
 *
 *  @return ffmpeg decoder
 */
- (FFMpegLowDelayDecoder *)createFFMpegDecoderByCodecId:(ResuableCodecID) codecID;

@property (strong, nonatomic, readonly) NSArray     *codecInfoArray;
@end
