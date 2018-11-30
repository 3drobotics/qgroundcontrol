//
//  YuneecRawVideoFrame.h
//  YuneecDecoder
//
//  Created by tbago on 17/1/26.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YuneecRawVideoFrame : NSObject

@property (nonatomic, readonly) uint32_t                width;
@property (nonatomic, readonly) uint32_t                height;
@property (nonatomic, readonly) uint64_t                timeStamp;      ///< 100ns
@property (nonatomic, readonly) uint32_t                duration;       ///< 100ns

@property (strong, nonatomic, readonly) NSArray         *lineSizeArray;
@property (strong, nonatomic, readonly) NSArray         *frameDataArray;

@end
