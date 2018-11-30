//
//  MFiHttp.h
//  MFiAdapter
//
//  Created by Joe Zhu on 2018/9/26.
//  Copyright © 2018年 Yuneec. All rights reserved.
//
#import <BaseFramework/BaseFramework.h>


@interface MFiHttp: NSObject;


+ (instancetype)sharedInstance;

- (void)downloadSmallFileWithURL:(NSString *)urlString filePath:(NSString *)filePath block:(void (^)(NSError * _Nullable))block;

- (void)downloadFileWithURL:(NSString *)urlString filePath:(NSString *)filePath progress:(void (^)(float))progress block:(void (^)(NSError * _Nullable))block;

- (void)uploadFileWithURL:(NSString *)filePath url:(NSString *)urlString progress:(void (^)(float))progress block:(void (^)(NSError * _Nullable))block;
@end
