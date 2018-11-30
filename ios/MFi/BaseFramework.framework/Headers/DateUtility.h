//
//  DateUtility.h
//  BaseFramework
//
//  Created by tbago on 16/12/24.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

///< Special info
///< NSLog output NSDate as UTC time value. ext:NSLog(@"%@", [NSDate date]); will print UTC time value
///< http://stackoverflow.com/questions/13486754/need-information-on-printing-nsdate-date

/**
 *  Convert current date to UTC date
 *
 *  @param localDate current date value
 *
 *  @return UTC date value
 */
NSDate *getUTCDateFromDate(NSDate * localDate);


/**
 * Convert second to NSString with format 00:00:00

 @param seconds input second
 @return HH:mm:ss format string
 */
NSString *convertSecondToShortNSString(NSUInteger seconds);
