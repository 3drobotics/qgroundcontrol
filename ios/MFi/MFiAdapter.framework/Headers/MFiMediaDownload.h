//
//  MfiMediaDownload.h
//  MFiAdapter
//
//  Created by Joe Zhu on 2018/8/20.
//  Copyright © 2018年 Yuneec. All rights reserved.
//
#import <YuneecCameraSDK/YuneecCameraSDK.h>


@interface MFiMediaDownload : NSObject <NSCopying>

@property (nonatomic, strong)   YuneecMedia *media;
@property (nonatomic, strong)   NSString *filePath;
@property (nonatomic)           BOOL isThumbnail;
@property (nonatomic)           BOOL isPreviewVideo; //only for video, it is a low resolution video

@end
