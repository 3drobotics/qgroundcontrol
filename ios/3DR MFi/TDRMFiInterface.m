//
//  TDRMFiInterface.m
//  QGroundControl
//
//  Created by Lauren on 11/29/18.
//

#import <Foundation/Foundation.h>
#include "TDRMFiInterface.h"
#include <MFiAdapter/MFiAdapter.h>

@implementation TDRMFiInterface
    
- (instancetype)init {
    if (self = [super init]) {
        
        [[MFiConnectionStateAdapter sharedInstance] startMonitorConnectionState];
        [[MFiRemoteControllerAdapter sharedInstance] startMonitorRCEvent];
        
        // For debug only
//        [[NSNotificationCenter defaultCenter] addObserver:self
//                                                 selector:@selector(handleConnectionStateNotification:)
//                                                     name:@"MFiConnectionStateNotification"
//                                                   object:nil];
    }
    return self;
}

- (void) handleConnectionStateNotification:(NSNotification *) notification {
    // Debugging information
    if ([[notification name] isEqualToString:@"MFiConnectionStateNotification"])
        NSLog (@"MFi connection notification:  %@", notification.userInfo);
}

@end
