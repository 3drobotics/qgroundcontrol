//
//  MediaCodecInfo.h
//  MediaBase
//
//  Created by tbago on 11/01/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaBase/ResuableCodecID.h>

typedef NS_ENUM(NSInteger, MediaDecoderType) {
    MediaUnknownDecoder,
    MediaVideoDecoder,
    MediaAudioDecoder,
    MediaSubtitleDecoder,
};

@interface MediaCodecInfo : NSObject

@property (nonatomic) MediaDecoderType      type;
@property (nonatomic) ResuableCodecID       codecID;
@property (nonatomic, copy) NSString        *name;
@property (nonatomic) uint32_t              score;

@end
