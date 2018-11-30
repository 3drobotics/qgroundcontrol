//
//  ResuableSampleFormat.h
//  MediaBase
//
//  Created by tbago on 16/12/19.
//  Copyright © 2016年 tbago. All rights reserved.
//

#ifndef ResuableSampleFormat_h
#define ResuableSampleFormat_h

typedef NS_ENUM(NSInteger, ResuableSampleFormat) {
    R_SAMPLE_FMT_NONE = -1,
    R_SAMPLE_FMT_U8,          ///< unsigned 8 bits
    R_SAMPLE_FMT_S16,         ///< signed 16 bits
    R_SAMPLE_FMT_S32,         ///< signed 32 bits
    R_SAMPLE_FMT_FLT,         ///< float
    R_SAMPLE_FMT_DBL,         ///< double
    
    R_SAMPLE_FMT_U8P,         ///< unsigned 8 bits, planar
    R_SAMPLE_FMT_S16P,        ///< signed 16 bits, planar
    R_SAMPLE_FMT_S32P,        ///< signed 32 bits, planar
    R_SAMPLE_FMT_FLTP,        ///< float, planar
    R_SAMPLE_FMT_DBLP,        ///< double, planar
    R_SAMPLE_FMT_S64,         ///< signed 64 bits
    R_SAMPLE_FMT_S64P,        ///< signed 64 bits, planar
    
    R_SAMPLE_FMT_NB           ///< Number of sample formats. DO NOT USE if linking dynamically
};

#endif /* ResuableSampleFormat_h */
