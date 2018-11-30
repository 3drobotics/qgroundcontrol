//
//  YuneecMediaManager.h
//  YuneecSDK
//
//  Created by Mine on 2017/3/9.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YuneecCameraDefine.h"
@class YuneecMedia;
@class YuneecCamera;

/**
 *  YuneecMediaManager
 */
@interface YuneecMediaManager : NSObject

/**
 *  Returns an instance of 'YuneecMediaManager'
 *  Note: Must call this init method if it is http communication
 *
 *  @param cameraType Yuneec camera type
 *  @return Returns an instance of 'YuneecMediaManager'
 */
- (instancetype _Nullable )initWithCameraType:(YuneecCameraType)cameraType;

/**
 *  Fetch the media list from the remote album.
 *
 *  @param block Remote execute result. Objects in mediaArray are kind of class YuneecMedia. When failed the error will show failed reason.
 */
- (void)fetchMediaWithCompletion:(void(^_Nonnull)(NSArray<YuneecMedia *> *_Nullable mediaArray, NSError *_Nullable error))block;

/**
 *  Delete the media from the remote album.
 *  Note: This method only supports for udp communication
 *
 *  @param mediaArray Media need to be deleted.
 *  @param block Remote execute result. When failed the error will show failed reason.
 */
- (void)deleteMedia:(NSArray<YuneecMedia *> *_Nonnull)mediaArray withCompletion:(void (^_Nullable)(NSError *_Nullable error))block;

/**
 *  Delete the media from the remote album.
 *  Note: This method only supports for http communication
 *
 *  @param mediaArray Media need to be deleted.
 *  @param camera Instance of YuneecCamera. An initialized camera instance must be set if the camera type is not CGO serials.
 *  @param block Remote execute result. When failed the error will show failed reason.
 */
- (void)deleteMedia:(NSArray<YuneecMedia *> *_Nonnull)mediaArray camera:(YuneecCamera * _Nullable)camera withCompletion:(void (^_Nullable)(NSError *_Nullable error))block;

- (void)stopFetchListWithBlock:(void(^)(NSError *error))block;

@end
