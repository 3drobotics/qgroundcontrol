//
//  CompassedFrame.h
//  MediaBase
//
//  Created by tbago on 16/12/16.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaConstant.h"
#import "ResuableCodecID.h"

@interface CompassedFrame : NSObject

@property (nonatomic) StreamType        streamType;
@property (nonatomic) ResuableCodecID   codecID;
@property (nonatomic) BOOL              keyFrame;                   ///< weather is key frame
@property (nonatomic) int64_t           decompassTimeStamp;         ///< dts value (100ns)
@property (nonatomic) int64_t           presentTimeStamp;           ///< pts value (100ns)
@property (nonatomic) int64_t           duration;                   ///< frame duration (100ns)
@property (nonatomic) int64_t           position;                   ///< frame position
@property (copy, nonatomic) NSData      *frameData;                 ///< frame memory data
@property (copy, nonatomic) NSData      *extraData;
@end
