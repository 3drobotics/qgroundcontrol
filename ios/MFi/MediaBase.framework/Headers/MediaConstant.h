//
//  MediaConstant.h
//  MediaBase
//
//  Created by tbago on 16/12/16.
//  Copyright © 2016年 tbago. All rights reserved.
//

#ifndef MediaConstant_h
#define MediaConstant_h

/**
 *  Stream type enumeration
 */
typedef NS_ENUM(NSInteger, StreamType) {
    UnknownStream,          ///< unknown stream type
    VideoStream,            ///< video stream
    AudioStream,            ///< audio stream
    SubtitleStream,         ///< subtitle stream
};

#endif /* MediaConstant_h */
