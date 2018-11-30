//
//  DebugLog.h
//  BaseFramework
//
//  Created by tbago on 22/03/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#ifndef BASE_FRAMEWORK_DEBUG_LOG_H_
#define BASE_FRAMEWORK_DEBUG_LOG_H_

#ifndef DNSLOG
    #ifdef DEBUG
        #define DNSLog(format, ...) NSLog(format, ## __VA_ARGS__)
    #else
        #define DNSLog(format, ...)
    #endif
#endif

#endif /* BASE_FRAMEWORK_DEBUG_LOG_H_ */
