//
//  TDRMFiInterface.h
//  QGroundControl
//
//  Created by Lauren on 11/29/18.
//
    
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
    
@interface TDRMFiInterface : NSObject

- (void) initVideoStream;

//private:
//QUdpSocket*     _udpVideoSocket     = nullptr;

@end

NS_ASSUME_NONNULL_END
