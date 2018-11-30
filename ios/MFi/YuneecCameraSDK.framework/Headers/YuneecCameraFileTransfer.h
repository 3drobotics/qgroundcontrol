//
//  YuneecCameraFileTransfer.h
//  YuneecCameraSDK
//
//  Created by tbago on 16/03/2018.
//  Copyright © 2018 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YuneecCameraFileTransfer : NSObject

/**
 * Transfer file to camera
 *
 * @param filePath file path
 * @param progressBlock transfer progress block
 * @param completionBlock transfer complate block
 */
- (void)transferFileToCamera:(NSString *) filePath
               progressBlock:(void (^)(float progress)) progressBlock
             completionBlock:(void (^)(NSError *_Nullable error)) completionBlock;

@end

NS_ASSUME_NONNULL_END
