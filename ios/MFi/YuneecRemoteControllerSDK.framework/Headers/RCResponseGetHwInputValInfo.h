//
//  RCResponseGetHwInputValInfo.h
//  YuneecApp
//
//  Created by dj.yue on 2017/4/25.
//  Copyright © 2017年 dj.yue. All rights reserved.
//

#import "RCResponseInfo.h"


/**
 监视器模块
 控器硬件值(CMD_GET_HW_INPUT_VAL)
 */
@interface RCResponseGetHwInputValInfo : RCResponseInfo

@property (nonatomic, strong) NSArray * jValues;//摇杆值
@property (nonatomic, strong) NSArray * kValues;//旋钮值
@property (nonatomic, strong) NSArray * sValues;//switch开关值
@property (nonatomic, strong) NSArray * bValues;//button按钮值

@end
