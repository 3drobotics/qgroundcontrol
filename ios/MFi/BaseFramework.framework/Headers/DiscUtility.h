//
//  DiscUtility.h
//  BaseFramework
//
//  Created by tbago on 16/12/24.
//  Copyright © 2016年 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Get current phone remain device
 *  http://stackoverflow.com/questions/11717304/why-does-the-value-from-nsfilesystemfreesize-differ-from-the-free-size-reported
 *  The disc space is differ from iOS settings free space. In my test, this value is bigger than the free space(200MB).
 *
 *  @return current device remain space (Bytes value)
 */
NSInteger getDiskFreeSize();

/**
 *  Get readable string value of disc space
 *
 *  @return readable string value for disc space
 */
NSString *getReadableDiscFreeSpace();