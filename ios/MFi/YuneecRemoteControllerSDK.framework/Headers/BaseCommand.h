//
//  BaseCommand.h
//  YuneecApp
//
//  Created by kenny on 13/04/2017.
//  Copyright © 2017 yuneec. All rights reserved.
//
#import <Foundation/Foundation.h>
//#import "CrcUtils.h"
@protocol Command <NSObject>



@end

//static const Boolean IS_BIGENDIAN = false;//保留

static const Byte COMMAND_SENDERID = 0x18;
static const Byte RESPONSE_SENDERID = 0x81;
static const Byte HANDERID = 0x40;


typedef NS_ENUM(uint8_t, RC_CMD_ID) {
    CMD_GET_BATTERY       = 0x01,     ///< 遥控器电池
    CMD_GET_GPS           = 0x02,     ///< 遥控器gps
    CMD_GET_GPS_TIME      = 0x03,     ///< 获取遥控器gps时间
    CMD_GET_HW_INPUT_VAL  = 0x04,     ///< 获取摇控器硬件值
    CMD_GET_CH_MAP        = 0x05,     ///< 获取遥控器摇杆操作模式
    CMD_SET_CH_MAP        = 0x06,     ///< 设置遥控器摇杆操作模式
    CMD_GET_CH_CURVE      = 0x07,     ///< 获取遥控器通道公式
    CMD_SET_CH_CURVE      = 0x08,     ///< 设置遥控器通道公式
    CMD_GET_CHS_VAL       = 0x09,     ///< 获取遥控器所有通道值
    CMD_SET_CH_VAL        = 0x0A,     ///< 设置通道值配置
    CMD_SCAN_AUTOPILOT    = 0x0B,     ///< 扫描飞机
    CMD_BIND_AUTOPILOT    = 0x0C,     ///< 绑定飞机
    CMD_UNBIND_AUTOPILOT  = 0x0D,     ///< 解绑飞机
    CMD_GET_BIND_INFO     = 0x0E,     ///< 获取当前绑定飞机信息
    CMD_EXIT_BIND         = 0x0F,     ///< 退出飞机绑定模式
    CMD_SCAN_CAMERA       = 0x10,     ///< 扫描相机
    CMD_BIND_CAMERA       = 0x11,     ///< 绑定相机
    CMD_UNBIND_CAMERA     = 0x12,     ///< 解绑相机
    CMD_GET_CAMERA_INFO   = 0x13,     ///< 获取当前绑定相机信息
    CMD_GET_SDCARD_INFO   = 0x14,     ///< 获取遥控器SDCard信息
    CMD_GET_CONTROL_TYPE  = 0x15,     ///< 获取遥控器类型
    CMD_GET_VERSION       = 0x16,     ///< 获取遥控器版本信息
    CMD_START_UPDATE      = 0x17,     ///< 开始升级遥控器
    CMD_TRANSFILEDATA     = 0x18,     ///< 分段传输文件内容
    CMD_CANCEL_UPDATE     = 0x19,     ///< 取消升级
    CMD_SEND_MD5          = 0x1A,     ///< 发送MD5值
    CMD_GET_UPGRADE_STATUS= 0x1B,     ///< 查询升级状态
    CMD_GET_CH_SETTING    = 0x0C,     ///< 获取通道值配置
    CMD_SEND_PAYLOAD      = 0x1D,     ///< 通过2.4G透传Payload给飞机
    CMD_CALIBRATE         = 0x1E,     ///< 开始、停止校准
    CMD_SET_GPS           = 0x1F,     ///< 设置是否使用遥控器自带的GPS
    CMD_GET_STATE         = 0x20,     ///< 获得遥控器的(Bind/Calibrate)状态
    MSG_TELEMETRY_DATA    = 0x80,     ///< 回传飞机信息
    MSG_REPORT_EVENT      = 0x81,     ///< 上报事件
    MSG_BYPASS_EX_PACKET  = 0x82,     ///< 透传飞机Extra Feedback包
    CMD_GPIO_SET          = 0x63      ///< 设置LED,Buzzer,Motor GPIO
};


typedef NS_ENUM(uint8_t, RC_ERROR_CODE) {
    // Response
    ERR_SUCCESS = 0,
    ERR_UNSUPPORT,
    ERR_INVAL_PARAM,
    ERR_INVAL_SETTING,
    ERR_BUSY,
    ERR_NOT_MATCH,
    ERR_GPS_NOT_FIXED,
    ERR_UNKNOW = 254,
    
    // Add by dj.yue , 自定义错误码
    CODE_LAST_REQUEST_NOT_FINISH=0x99,
    CODE_REQUEST_TIME_OUT=0x98,
    CODE_CONNECTION_ERROR=0x97,

    //new add by gavin
    ERR_DISCONNECTED = 0x80,
    ERR_INACTIVE = 0x81,
    ERR_INTERFACE_DISABLED = 0x82,
    ERR_SCANNING = 0x83,
    ERR_AUTHENTICATING = 0x84,
    ERR_ASSOCIATING = 0x85,
    ERR_ASSOCIATED = 0x86,
    ERR_4WAY_HANDSHAKE = 0x87,
    ERR_GROUP_HANDSHAKE = 0x88
    
};



@interface BaseCommand : NSObject  <Command>
//@property Byte commandId;

@property Byte *data;
@property int length;
@end
