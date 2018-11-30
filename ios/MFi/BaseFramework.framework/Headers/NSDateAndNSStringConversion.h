//
//  NSDateAndNSStringConversion.h
//  BaseFramework
//
//  Created by tbago on 16/12/24.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - NSDate to NSString
/**
 *  Convert NSDate to special format NSString
 *
 *  @param date   input NSDate value
 *  @param format NSString date format. ext:yyyy-MM-dd HH:mm:ss
 *
 *  @return NSString formate date value
 */
NSString* convertNSDateToFormatNSString(NSDate *date, NSString *format);

/**
 *  Convert NSDate to NSString with format yyyy-MM-dd HH:mm:ss
 *
 *  @param date input NSDate value
 *
 *  @return NSString date value
 */
NSString* convertNSDateToStandString(NSDate *date);

/**
 *  Convert NSDate to NSString with format HH:mm:ss
 *
 *  @param date input NSDate value
 *
 *  @return NSString date value
 */
NSString* convertNSDateToShortNSString(NSDate *date);

#pragma mark - NSString to NSDate

NSDate *convertNSStringToNSDate(NSString *stringDate, NSString *format);