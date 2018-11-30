//
//  YNCFB_MediasDownloadServer.h
//  OBClient
//
//  Created by hank on 26/03/2018.
//  Copyright © 2018 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YuneecMediasDownloadServer : NSObject

+ (instancetype)sharedInstance;
- (void)openTCPSocket;
- (void)closeTCPSocket;

@end
