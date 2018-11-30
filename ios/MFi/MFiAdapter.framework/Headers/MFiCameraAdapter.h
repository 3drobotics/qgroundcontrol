//
//  MFiCameraAdapter.h
//  MFiAdapter
//
//  Created by Joe Zhu on 2018/8/15.
//  Copyright © 2018年 Yuneec. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import <YuneecCameraSDK/YuneecCameraSDK.h>
#import "MFiMediaDownload.h"

@interface MFiCameraAdapter : NSObject;


@property (nonatomic, assign) BOOL isCancel;

+ (instancetype)sharedInstance;

- (void)requestMediaInfo:(void(^)(NSArray *dateArray, NSError * error))completeCallback;
- (void)stopRequestMediaInfo:(void(^)(NSError *error))completeCallback;
- (void)downloadMediasArray:(NSArray<MFiMediaDownload *> *)downloadArray
                        progress:(void (^)(int index,
                                      NSString *fileName,
                                      NSString *fileSize,
                                      CGFloat progress))progressCallback
                        complete:(void (^)(NSError * _Nullable))completeCallback;
- (void)deleteMediasArray:(NSArray<YuneecMedia *> *)mediaArray
                        complete:(void (^)(NSError * _Nullable))completeCallback;
/**
 * Format camera internal storage
 *
 * @param completionCallback A block object to be executed when the command return.
 */
- (void)formatCameraStorage:(void(^)(NSError * _Nullable error)) completionCallback;
/**
 * Set camera system time to current local time
 *
 */
- (void)setCameraSystemTime;
- (void)firmwareUpdate:(NSString *) filePath
            progressBlock:(void (^)(float progress)) progressBlock
            completionBlock:(void (^)(NSError *_Nullable error)) completionBlock;
- (void)getFirmwareVersion:(void(^)(NSString * _Nullable firmwareVersion)) completionBlock;
- (void)getGimbalFirmwareVersion:(void(^)(NSString * _Nullable firmwareVersion)) completionBlock;
@end
