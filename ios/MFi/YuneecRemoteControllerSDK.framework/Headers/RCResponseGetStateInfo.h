//
//  RCResponseGetStateInfo.h
//  YuneecApp
//
//  Created by dj.yue on 2017/5/22.
//  Copyright © 2017年 yuneec. All rights reserved.
//

#import "RCResponseInfo.h"


/**
 遥控器的(Bind/Calibrate)状态
 */
@interface RCResponseGetStateInfo : RCResponseInfo

@property (nonatomic, assign) BOOL isBinding;///<是否绑定状态
@property (nonatomic, assign) BOOL isCalibrating;///<是否正在校准

@end
