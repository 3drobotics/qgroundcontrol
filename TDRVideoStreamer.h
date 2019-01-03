//
//  TDRVideoStreamer.h
//  3DRQGC
//
//  Created by Lauren on 12/19/18.
//

#ifndef TDRVideoStreamer_h
#define TDRVideoStreamer_h

//#include "TaisyncHandler.h"


@interface TDRVideoStreamer : NSObject

- (void) writeVideoData:(NSData *) h264Data;

//private:
//QUdpSocket*     _udpVideoSocket     = nullptr;


@end

#endif /* TDRVideoStreamer_h */
