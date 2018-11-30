//
//  RCInfo.h
//  YuneecApp
//
//  Created by dj.yue on 2017/4/17.
//  Copyright © 2017年 dj.yue. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseCommand.h"


/**
 Build info from MFi response payload
 摇杆校准模块
 */
@interface RCResponseInfo : NSObject
//@property (nonatomic, assign) RC_CMD_ID command;///<命令

@property (nonatomic, assign) RC_CMD_ID command;///<命令


/**
 错误码
 */
@property (nonatomic, assign) RC_ERROR_CODE code;


+ (id)infoWithPayload:(NSData *)payload withCommand:(RC_CMD_ID)command;



@end
