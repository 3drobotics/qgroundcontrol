//
//  FFMpegLowDelayDemuxer.h
//  FFMpegLowDelayDemuxer
//
//  Created by tbago on 20/11/2017.
//  Copyright © 2017 yuneec. All rights reserved.
//

#include <Foundation/Foundation.h>
#import <MediaBase/MediaBase.h>

@interface FFMpegLowDelayDemuxer : NSObject

/**
 *  Open file by path
 *
 *  @param filePath input file path
 *
 *  @return success or failed
 */
- (BOOL)openFileByPath:(NSString *) filePath;

- (void)closeInputFile;
/**
 *  Get file movie count
 *
 *  @return movie count
 */
- (uint32_t)getMovieCount;

- (MovieInfo *)getMovieInfoByIndex:(uint32_t) index;

- (CompassedFrame *)readFrame;

- (BOOL)seekToPosition:(int64_t) position
          realPosition:(int64_t *) realPosition;

- (int64_t)getCurrentTime;

- (int64_t)getCurrentPosition;
/**
 *  Whether read end of the file
 *
 *  @return weather read end of file
 */
- (BOOL)eof;

/**
 *  To stop reading, demux should stop read_frame or open_input immediately
 *
 *  @return void
 */
- (void)stopReading;

@end

/**
 *  Create Demuxer instance
 *
 *  @return demuxer instance
 */
FFMpegLowDelayDemuxer *createFFMpegLowDelayDemuxer();
