//
//  MFiOtaAdapter.h
//  MFiAdapter
//
//  Created by Joe Zhu on 2018/9/25.
//  Copyright © 2018年 Yuneec. All rights reserved.
//

#import <YuneecCameraSDK/YuneecCameraSDK.h>
#import "MFiHttp.h"


@interface MFiOtaAdapter : NSObject;

typedef NS_ENUM (NSUInteger, YuneecOtaModuleType) {
    YuneecOtaModuleTypeAutopilot,
    YuneecOtaModuleTypeCameraE50A,
    YuneecOtaModuleTypeCameraE50E,
    YuneecOtaModuleTypeCameraE50K,
    YuneecOtaModuleTypeCameraE90A,
    YuneecOtaModuleTypeCameraE90E,
    YuneecOtaModuleTypeCameraE90K,
    YuneecOtaModuleTypeCameraETA,
    YuneecOtaModuleTypeCameraETE,
    YuneecOtaModuleTypeCameraETK,
    YuneecOtaModuleTypeGimbalE10T,
    YuneecOtaModuleTypeGimbalE50,
    YuneecOtaModuleTypeGimbalE90,
    YuneecOtaModuleTypeGimbalET,
    YuneecOtaModuleTypeRcST10C,
};

+ (instancetype)sharedInstance;

- (void)getLatestVersion:(YuneecOtaModuleType) moduleType
                block:(void (^)(NSString *version))block;

- (void)getLatestHash:(YuneecOtaModuleType) moduleType
                block:(void (^)(NSString *hash))block;

- (void)downloadOtaPackage:(YuneecOtaModuleType) moduleType filePath:(NSString *)filePath
                progressBlock:(void (^)(float))progressBlock
                completionBlock:(void (^)(NSError * _Nullable))completionBlock;

- (void)uploadOtaPackage:(NSString *) filePath
                progressBlock:(void (^)(float)) progressBlock
                completionBlock:(void (^)(NSError *_Nullable)) completionBlock;

- (void)uploadRemoteControllerOtaPackage:(NSString *) filePath
                progressBlock:(void (^)(float progress)) progressBlock
                completionBlock:(void (^)(NSError *_Nullable error)) completionBlock;

-(NSString *)sha256OfPath:(NSString *)path;
@end
