//
//  TrackingLog.h
//  BaseFramework
//
//  Created by tbago on 17/1/13.
//  Copyright © 2017年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  For tracking app runing log info
 *  This object is Singleton Object, only generate one single tracking log file in path
 *  The default log path is in app document with file name tracking.log
 */

@interface TrackingLog : NSObject

+ (instancetype)sharedInstance;

- (BOOL)initTrackingLog:(BOOL) enableTrackingLog
                newFile:(BOOL) newFile;

- (void)logOneInfoWithFormat:(NSString *)format, ... ;
@end

#ifdef ENABLE_TRACK_LOG

#ifndef TRACK_BEGIN
#define TRACK_BEGIN [[TrackingLog sharedInstance]                                           \
                    logOneInfoWithFormat:@"track begin file:%@ function:%s line:%d",        \
                    [[NSString stringWithFormat:@"%s", __FILE__] lastPathComponent],        \
                    __FUNCTION__,                                                           \
                    __LINE__];                                                              
#endif

#ifndef TRACK_END
#define TRACK_END [[TrackingLog sharedInstance]                                            \
                    logOneInfoWithFormat:@"track end file:%@ function:%s line:%d",         \
                    [[NSString stringWithFormat:@"%s", __FILE__] lastPathComponent],       \
                    __FUNCTION__,                                                          \
                    __LINE__];
#endif
#else
    #define TRACK_BEGIN
    #define TRACK_END
#endif
