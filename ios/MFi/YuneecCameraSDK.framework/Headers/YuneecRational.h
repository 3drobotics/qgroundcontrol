//
//  YuneecRational.h
//  YuneecSDK
//
//  Copyright © 2017 yuneec. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Rational object
 */
@interface YuneecRational : NSObject


/**
 * Create instance for yuneec rational object

 @param numerator object numerator
 @param denominator object denominator
 @return yuneec rational instance
 */
- (instancetype)initWithNumerator:(NSInteger) numerator
                      denominator:(NSInteger) denominator NS_DESIGNATED_INITIALIZER;


/**
 * Check weather the rational is equal value
 *
 * @param inputRational object want to compare
 * @return weather equal value
 */
- (BOOL)equalValue:(YuneecRational *) inputRational;

/**
 * Compare rational values
 *
 * @param inputRational object want to compare
 * @return Returns comparison result
 */
- (NSComparisonResult)compare:(YuneecRational *) inputRational;

@property (nonatomic, readonly) NSInteger  numerator;
@property (nonatomic, readonly) NSInteger  denominator;

@end
