//
//  YuneecSampleVideoFrame.m
//  YuneecDecoder
//
//  Created by alexlin on 18/1/15.
//  Copyright © 2018年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>

@interface YuneecSampleVideoFrame : NSObject

@property (nonatomic, readonly) uint32_t               width;
@property (nonatomic, readonly) uint32_t               height;
@property (nonatomic, readonly) CMSampleBufferRef      sampleBuffer;
@property (nonatomic, readonly) BOOL                   bIsCompressedData;
@property (nonatomic) BOOL                            bHasVideoProc;

- (instancetype)initWithWidth:(uint32_t) width
                       height:(uint32_t) height
                   isCompressed:(BOOL) bIsCompressedData
                       Buffer:(CMSampleBufferRef) sampleBuffer;
@end
