//
//  TDRMFiInterface.m
//  QGroundControl
//
//  Created by Lauren on 11/29/18.
//

#import <Foundation/Foundation.h>
#include "TDRMFiInterface.h"
#include <MFiAdapter/MFiAdapter.h>

#import <YuneecDataTransferManager/YuneecDataTransferManager.h>
#import <YuneecDecoder/YuneecDecoder.h>
#import <YuneecPreviewView/YuneecPreviewView.h>

#import "GCDAsyncUdpSocket.h"

#include "TDRVideoStreamer.h"


@interface TDRMFiInterface () <YuneecDecoderDelegate, YuneecCameraStreamDataTransferDelegate, GCDAsyncUdpSocketDelegate>
    @property (strong, nonatomic) YuneecDecoder                     *decoder;
    @property (strong, nonatomic) YuneecCameraStreamDataTransfer    *cameraStreamTransfer;
    @property (strong, nonatomic) YuneecPreviewView                 *previewView;

    @property (strong, nonatomic) GCDAsyncUdpSocket                 *udpSocket;

    @property (strong, nonatomic) TDRVideoStreamer                 *udpVideoStreamer;

@end

@implementation TDRMFiInterface

    _Bool videoStarted = false;
    _Bool socketReady = false;

    _Bool largeVideoMode = false;
    CGSize smallVideoSize;
    CGSize largeVideoSize;

- (instancetype)init {
    if (self = [super init]) {
        
        [[MFiConnectionStateAdapter sharedInstance] startMonitorConnectionState];
        [[MFiRemoteControllerAdapter sharedInstance] startMonitorRCEvent];
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(handleConnectionStateNotification:)
                                                     name:@"MFiConnectionStateNotification"
                                                   object:nil];
        
        // Video stream view
        _previewView = [[YuneecPreviewView alloc] initWithFrame: CGRectMake(0, 0, 300, 200) ];
        
        [_previewView setBackgroundColor:UIColor.blackColor];
        socketReady = true;

        _previewView.translatesAutoresizingMaskIntoConstraints = false;

        UIWindow *mainWindow = [UIApplication sharedApplication].windows[0];
        UIView *mainView = mainWindow.rootViewController.view;
        [mainView addSubview:_previewView];
        
        CGFloat height = mainView.frame.size.height * 0.6;
        CGFloat width = height * 1.5;
        largeVideoSize = CGSizeMake(width, height);
        
        height = mainView.frame.size.height/5;
        width = height * 1.5;
        smallVideoSize = CGSizeMake(width, height);
        
        [_previewView setFrame:CGRectMake(10, mainView.frame.size.height - height - 10, width, height)];
        
        UITapGestureRecognizer *singleFingerTap = [[UITapGestureRecognizer alloc] initWithTarget:self
                                                action:@selector(handleSingleTap:)];
        singleFingerTap.numberOfTapsRequired = 1;
        [_previewView addGestureRecognizer:singleFingerTap];

        //[[[_previewView.leadingAnchor anchorWithOffsetToAnchor:mainView.leadingAnchor] constraintEqualToConstant:100] setActive:true];
        //[[[_previewView.topAnchor anchorWithOffsetToAnchor:mainView.topAnchor] constraintEqualToConstant:0] setActive:true];
        //[[[_previewView.bottomAnchor anchorWithOffsetToAnchor:mainView.bottomAnchor] constraintEqualToConstant:100] setActive:true];
        //[[[_previewView.trailingAnchor anchorWithOffsetToAnchor:mainView.trailingAnchor] constraintEqualToConstant:0] setActive:true];
    }
    return self;
}

- (void)handleSingleTap:(UITapGestureRecognizer *)recognizer {
    //CGPoint location = [recognizer locationInView:[recognizer.view superview]];
    
    UIWindow *mainWindow = [UIApplication sharedApplication].windows[0];
    UIView *mainView = mainWindow.rootViewController.view;
    
    largeVideoMode = !largeVideoMode;
    if (largeVideoMode == true) {
        CGFloat x = mainView.frame.size.width/2 - largeVideoSize.width/2;
        CGFloat y = mainView.frame.size.height/2 - largeVideoSize.height/2;
        [_previewView setFrame:CGRectMake(x, y, largeVideoSize.width, largeVideoSize.height)];
    } else {
        [_previewView setFrame:CGRectMake(10, mainView.frame.size.height - smallVideoSize.height - 10, smallVideoSize.width, smallVideoSize.height)];
    }
}

- (void) initVideoStream {
//    [NSThread sleepForTimeInterval:1.0f];
//    [self startVideo];
}

- (void) handleConnectionStateNotification:(NSNotification *) notification {
    [self startVideo]; // xxx LRW
    
    if (_udpSocket == nil)
    {
        [self setupSocket];
    }
    
    if (_udpVideoStreamer == nil) {
        _udpVideoStreamer = [TDRVideoStreamer alloc];
    }
    
    // Debugging information
//    if ([[notification name] isEqualToString:@"MFiConnectionStateNotification"])
//        NSLog (@"MFi connection notification:  %@", notification.userInfo);
}

- (void)startVideo {
    if (videoStarted == true) {
        return;
    }
    videoStarted = true;
    BOOL isConnected = [[MFiConnectionStateAdapter sharedInstance] connected];
    if (isConnected) {
        //NSDictionary *connectionInfo = [[MFiConnectionStateAdapter sharedInstance] getConnectionStatus];
        if (isConnected) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
                BOOL ret = [self.decoder openCodec];
                if (!ret) {
                    NSLog(@"Open Yuneec Decoder failed");
                }
                [self.cameraStreamTransfer openCameraSteamDataTransfer];
            });
            
            // Create UDP connection
                      
            //LinkConfiguration* config = new UDPConfiguration(name);
            
//            UDPConfiguration* udpConfig = new UDPConfiguration(_defaultUPDLinkName);
//            udpConfig->setDynamic(true);
//            SharedLinkConfigurationPointer config = addConfiguration(udpConfig);
//            createConnectedLink(config);
        }
    }
    else {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
            [self.decoder closeCodec];
            //[self.previewView clearFrame];
        });
    }
}
-(void) stopVideo {
    
    if (videoStarted == false) {
        return;
    }
    videoStarted = false;
    BOOL isConnected = [[MFiConnectionStateAdapter sharedInstance] connected];
    if (isConnected) {
        //NSDictionary *connectionInfo = [[MFiConnectionStateAdapter sharedInstance] getConnectionStatus];
        if (isConnected) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
                [self.decoder closeCodec];
                [self.cameraStreamTransfer closeCameraStreamDataTransfer];
            });
        }
    }
    else {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
            [self.decoder closeCodec];
            //[self.previewView clearFrame];
        });
    }
}

#pragma mark - get & set

- (YuneecCameraStreamDataTransfer *)cameraStreamTransfer {
    if (_cameraStreamTransfer == nil) {
        _cameraStreamTransfer = [YuneecDataTransferManager sharedInstance].streamDataTransfer;
        _cameraStreamTransfer.cameraStreamDelegate = self;
        _cameraStreamTransfer.enableLowDelay = YES;
    }
    return _cameraStreamTransfer;
}

- (YuneecDecoder *)decoder {
    if (_decoder == nil) {
        BOOL enableLowDelay = YES;
        _decoder = createYuneecDecoder(self, NO, enableLowDelay);
    }
    return _decoder;
}

#pragma mark - YuneecDecoderDelegate

static uint64_t preDisplayTime = 0;
static const uint64_t displayInternal = 20;

- (void)decoder:(YuneecDecoder *) decoder didDecoderVideoFrame:(YuneecRawVideoFrame *) rawVideoFrame {
// xxx   if (appIsActive == false) {
//        return;
//    }
    
    uint64_t currentTime = [[NSDate date] timeIntervalSince1970]*1000;
    if (currentTime - preDisplayTime > displayInternal) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self renderVideoFrame:rawVideoFrame];
            preDisplayTime = currentTime;
        });
    }
}

- (void)renderVideoFrame:(YuneecRawVideoFrame *) rawVideoFrame {
    const uint32_t yFrameSize = rawVideoFrame.width * rawVideoFrame.height;
    uint32_t bufferSize = yFrameSize * 3 / 2 + 1;
    int8_t *buffer = (int8_t *)malloc(bufferSize);
    uint32_t bufferIndex = 0;
    
    uint32_t lineSize0 = (uint32_t)[rawVideoFrame.lineSizeArray[0] integerValue];
    uint8_t *yBuffer = (uint8_t *)[rawVideoFrame.frameDataArray[0] bytes];
    
    uint32_t lineSize1 = (uint32_t)[rawVideoFrame.lineSizeArray[1] integerValue];
    uint8_t *uBuffer = (uint8_t *)[rawVideoFrame.frameDataArray[1] bytes];
    
    uint32_t lineSize2 = (uint32_t)[rawVideoFrame.lineSizeArray[2] integerValue];
    uint8_t *vBuffer = (uint8_t *)[rawVideoFrame.frameDataArray[2] bytes];
    
    ///< copy y data
    if(lineSize0 == rawVideoFrame.width) {
        bufferIndex = yFrameSize;
        memcpy(buffer, yBuffer, bufferIndex);
    }
    else {
        for (uint32_t i = 0; i < rawVideoFrame.height; i++) {
            memcpy(buffer + bufferIndex, yBuffer + i * lineSize0, rawVideoFrame.width);
            bufferIndex += rawVideoFrame.width;
        }
    }
    
    ///< copy u data
    if(lineSize1 == rawVideoFrame.width/2) {
        memcpy(buffer + bufferIndex, uBuffer, yFrameSize/4);
        bufferIndex += yFrameSize/4;
    }
    else {
        for (uint32_t i = 0; i < rawVideoFrame.height/2; i++) {
            memcpy(buffer + bufferIndex, uBuffer + i * lineSize1, rawVideoFrame.width/2);
            bufferIndex += rawVideoFrame.width/2;
        }
    }
    
    ///< copy v data
    if(lineSize2 == rawVideoFrame.width/2) {
        memcpy(buffer + bufferIndex, vBuffer, yFrameSize/4);
        bufferIndex += yFrameSize/4;
    }
    else {
        for (uint32_t i = 0; i < rawVideoFrame.height/2; i++) {
            memcpy(buffer + bufferIndex, vBuffer + i * lineSize2, rawVideoFrame.width/2);
            bufferIndex += rawVideoFrame.width/2;
        }
    }
    
    [self.previewView displayYUV420pData:buffer
                                   width:rawVideoFrame.width
                                  height:rawVideoFrame.height
                                pixelFmt:YuneecPreviewPixelFmtTypeI420];
    
//    NSData* h264Data = [NSData dataWithBytes:buffer length:bufferSize];
//    //NSData* h264Data = [NSData dataWithBytesNoCopy:buffer length:bufferSize];
//    if (_udpSocket != nil && socketReady) {
//        socketReady = false;
//        NSLog(@"udpSocket camera data stream, socket ready");
//
//        //NSString * string = @"R/103";
//        NSString * address = @"192.168.66.1";
//        UInt16 port = 1555;
//        //NSData * data = [string dataUsingEncoding:NSUTF8StringEncoding];
//
//        dispatch_async(dispatch_get_main_queue(), ^{
//            NSLog(@"udpSocket camera data stream, sending to port");
//            [_udpSocket sendData:h264Data toHost:address port:port withTimeout:-1 tag:1];
//        });
//    } else {
//        NSLog(@"udpSocket camera data stream, socket NOT ready");
//    }
    free(buffer);
}

#pragma mark - YuneecCameraStreamDataTransferDelegate

- (void)cameraStreamDataTransfer:(YuneecCameraStreamDataTransfer *) cameraStreamDataTransfer
              didReceiveH264Data:(NSData *) h264Data
                        keyFrame:(BOOL) keyFrame
              decompassTimeStamp:(int64_t) decompassTimeStamp
                presentTimeStamp:(int64_t) presentTimeStamp
                       extraData:(NSData * __nullable) extraData
{
    [self.decoder decodeVideoFrame:h264Data
                decompassTimeStamp:decompassTimeStamp
                  presentTimeStamp:presentTimeStamp];
    
    if (_udpVideoStreamer != nil) {
        NSLog(@"_udpVideoStreamer write data");
        [_udpVideoStreamer writeVideoData:h264Data];
    }
    
    //NSLog(@"udpSocket camera data stream ready");
    /*
    if (_udpSocket != nil && socketReady) {
        socketReady = false;
        NSLog(@"udpSocket camera data stream, socket ready");

        //NSString * string = @"R/103";
        NSString * address = @"localhost"; // @"192.168.66.1";
        UInt16 port = 1555;
        //NSData * data = [string dataUsingEncoding:NSUTF8StringEncoding];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSLog(@"udpSocket camera data stream, sending to port");
            [_udpSocket sendData:h264Data toHost:address port:port withTimeout:-1 tag:1];
        });
    } else {
        NSLog(@"udpSocket camera data stream, socket NOT ready");
    }
     */
    
//    if (_udpSocket == nil && _udpSocket.isConnected) {
//        NSLog(@"udpSocket sending data");
//        [_udpSocket sendData:h264Data withTimeout:-1 tag:0];
//    }
}

#pragma mark - UDP socket

- (void)setupSocket {
    
    
    // Setup our socket.
    // The socket will invoke our delegate methods using the usual delegate paradigm.
    // However, it will invoke the delegate methods on a specified GCD delegate dispatch queue.
    //
    // Now we can configure the delegate dispatch queues however we want.
    // We could simply use the main dispatc queue, so the delegate methods are invoked on the main thread.
    // Or we could use a dedicated dispatch queue, which could be helpful if we were doing a lot of processing.
    //
    // The best approach for your application will depend upon convenience, requirements and performance.
    //
    // For this simple example, we're just going to use the main thread.
    
    _udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
    
    NSError *error = nil;
    
    //if (![_udpSocket bindToPort:666 interface:@"rtsp://192.168.66.1" error:&error])
    //if (![_udpSocket bindToPort:554 interface:@"rtsp://192.168.42.1/live" error:&error])
    //if (![_udpSocket connectToHost:@"192.168.42.1" onPort:1554 error:&error])
    
//    if (![_udpSocket bindToPort:1554 error:&error])
//    {
//        //NSLog(@"udpSocket Error binding: %@", [error localizedDescription]);
//        NSLog(@"udpSocket Error binding");
//        return;
//    }
    
//    if (![_udpSocket beginReceiving:&error])
//    {
//        NSLog(@"udpSocket Error receiving: %@", [error localizedDescription]);
//        return;
//    }
    
//    _udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
//    [_udpSocket bindToPort:554 error:&error];
//    [_udpSocket setPreferIPv4];
//    [_udpSocket  enableBroadcast:YES error:&error];
//    [_udpSocket  beginReceiving:&error];
    
    NSLog(@"Ready");
}

- (void)udpSocket:(GCDAsyncUdpSocket *)sock didSendDataWithTag:(long)tag {
    // You could add checks here
    NSLog(@"udpSocket SEND: socketReady = true");
    socketReady = true;
}

- (void)udpSocket:(GCDAsyncUdpSocket *)sock didNotSendDataWithTag:(long)tag dueToError:(NSError *)error {
    // You could add checks here
}

- (void)udpSocket:(GCDAsyncUdpSocket *)sock didReceiveData:(NSData *)data
      fromAddress:(NSData *)address
withFilterContext:(id)filterContext {
    NSString *msg = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    if (msg)
    {
        NSLog(@"udpSocket RECV: %@", msg);
    }
    else
    {
        NSString *host = nil;
        uint16_t port = 0;
        [GCDAsyncUdpSocket getHost:&host port:&port fromAddress:address];
        
        NSLog(@"udpSocket RECV: Unknown message from: %@:%hu", host, port);
    }
}
@end
