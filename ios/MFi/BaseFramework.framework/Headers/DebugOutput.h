//
//  DebugOutputInstance.h
//  BaseFramework
//
//  Created by tbago on 14/12/2017.
//  Copyright © 2017 tbago. All rights reserved.
//

#import <Foundation/Foundation.h>

#if ENABLE_DEBUG_OUTPUT
#define DebugOutputConsole(string)    [[DebugOutput sharedInstance] addOneDebugOutputString:string debugOutputType:DebugOutputTypeConsole]
#define DebugOutputInfo(string)       [[DebugOutput sharedInstance] addOneDebugOutputString:string debugOutputType:DebugOutputTypeInfo]
#define DebugOutputWarning(string)    [[DebugOutput sharedInstance] addOneDebugOutputString:string debugOutputType:DebugOutputTypeWarning]
#define DebugOutputError(string)      [[DebugOutput sharedInstance] addOneDebugOutputString:string debugOutputType:DebugOutputTypeError]
#else
#define DebugOutputInfo(string)
#define DebugOutputWarning(string)
#define DebugOutputError(string)
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, DebugOutputType) {
    DebugOutputTypeConsole,
    DebugOutputTypeInfo,
    DebugOutputTypeWarning,
    DebugOutputTypeError,
    DebugOutputTypeUnknown = 0xff,
};

@class DebugOutput;

@protocol DebugOutputDelegate <NSObject>

@required
- (void)debugOutputInstance:(DebugOutput *) debugOutputInstance
            didAddNewString:(NSString *) debugOutputString
            debugOutputType:(DebugOutputType) debugOutputType;

@end

@interface DebugOutput : NSObject

+ (instancetype)sharedInstance;

@property (weak, nonatomic, nullable) id<DebugOutputDelegate>   delegate;

- (void)addOneDebugOutputString:(NSString *) debugOutputString
                debugOutputType:(DebugOutputType) debugOutputType;

@end

NS_ASSUME_NONNULL_END

