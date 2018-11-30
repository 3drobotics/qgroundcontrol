//
//  MovieInfo.h
//  MediaBase
//
//  Created by tbago on 16/12/16.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "StreamInfo.h"

@interface MovieInfo : NSObject
/**
 *  Add stream info to movie info
 *
 *  @param streamInfo
 */
- (void)addStreamInfoToMovieInfo:(StreamInfo *) streamInfo;

/**
 *  Add metadata to movie info
 *
 *  @param key   metadata key
 *  @param value metadata value
 */
- (void)addMetaDataToMovieInfo:(NSString *) key
                         value:(NSString *) value;

@property (nonatomic) int32_t                                                   identify;
@property (nonatomic, copy) NSString                                            *name;
@property (nonatomic, copy) NSString                                            *format;            ///< media format
@property (strong, nonatomic, readonly) NSArray<StreamInfo *>                   *streamArray;       ///< stream info array
@property (strong, nonatomic, readonly) NSDictionary<NSString *, NSString *>    *metaData;          ///< movie metadata
@end
