//
//  iTunesUtility.h
//  BaseFramework
//
//  Created by tbago on 16/12/24.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Open AppStore by app iTunes id
 *  This funciton is used to update app by you app id
 *
 *  @param iTunesId iTunesId you want to open
 */
void openAppStoreByiTunesId(NSString * iTunesId);

/**
 *  Get AppStore app version
 *
 *  @param iTunesId the iTunes app id
 *  @param block    return value in block
 */
void getiTunesAppVersionByiTunesId(NSString *iTunesId,
                                   void(^block)(NSError *error, NSString *versionString));