//
//  RawVideoFrame.h
//  MediaBase
//
//  Created by tbago on 16/12/29.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResuablePixelFormat.h"

/**
 *  Decoder readable video frame
 */
@interface RawVideoFrame : NSObject

/**
 *  must use this method to init object, the default init method will only return nil
 *
 *  @param pixelFormat video pixel format
 *  @param width       video width
 *  @param height      video height
 *
 *  @return new raw video frame instance
 */
- (instancetype)initWithPixFormat:(ResuablePixelFormat) pixelFormat
                            width:(uint32_t) width
                           height:(uint32_t) height;

@property (nonatomic, readonly) ResuablePixelFormat     pixelFormat;
@property (nonatomic, readonly) uint32_t                width;
@property (nonatomic, readonly) uint32_t                height;
@property (nonatomic) uint64_t                          timeStamp;
@property (nonatomic) uint32_t                          duration;

@property (strong, nonatomic, readonly) NSArray         *lineSizeArray;
@property (strong, nonatomic, readonly) NSArray         *frameDataArray;

- (void)pushFrameData:(uint32_t) lineSize
            frameByte:(uint8_t *) frameByte;

@end
