//
//  DeviceUtility.h
//  BaseFramework
//
//  Created by tbago on 16/12/24.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Get Device type name string
 *
 *  @return device type name
 */
NSString *getDeviceTypeName();

/**
 * Get Device type code, you can get more device info by device code.
 *
 * @return device type code
 */
NSString *getDeviceTypeCode();

/**
 * Get Device system version
 *
 * @return system version
 */
NSString *getDeviceSystemVersion();

/**
 *  Check weather the current device is iPad(iPad Air, iPad Pro, iPad Mini)
 *
 *  iPad Mini               1024*768
 *  iPad Air                2048*1536
 *  9.7-inch iPad Pro       2048*1536
 *  12.9-inch iPad Pro      2732*2048
 *
 *  @return weather is iPad device
 */
BOOL isIPadDevice();

/**
 *  Check weather the current device is iPad Pro 12.9-inch
 *  iPad Pro 12.9 inch has different aspect ratio between other iPad device.
 *
 *  @return weather is iPad Pro device
 */
BOOL isIPadPro12Point9InchDevice();


/**
 * Check the device is iPhone 4, iPhone 4s
 *
 * @return weather is 3.5 inch iphone device
 */
BOOL is3Point5InchIPhoneDevice();

/**
 * Check the device is iPhone 5, iPhone 5s, iPhone SE
 *
 * @return weather is 4 inch iPhone device
 */
BOOL is4InchIPhoneDevice();

/**
 * Check the devide is iPhone 6, iPhone 6s, iPhone 7
 *
 * @return weather is 4.7 inch iPhone device
 */
BOOL is4Point7InchIPhoneDevice();

/**
 * Check the devide is iPhone 6 Plus, iPhone 6s Plus, iPhone 7 Plus
 *
 * @return weather is 5.5 inch iPhone device
 */
BOOL is5Point5InchIPhoneDevice();

/**
 *  Get current device ip address
 *  For simulator device this will return the current computer ip address
 *  For real device when the device is connect to the wifi, this address will be the wifi address.
    When there is not wifi connection, will return empty string.
 *
 *  @return current device ip address
 */
NSString *getDeviceIPAddress();

/**
 *  Get current wifi connect SSID
 *  This function is not work on simulator, in simluator function will return nil.
 *
 *  @return current wifi SSID
 */
NSString *getCurrentWifiSSID();
