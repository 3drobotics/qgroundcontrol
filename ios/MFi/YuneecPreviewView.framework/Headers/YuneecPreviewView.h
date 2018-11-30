//
//  YuneecPreviewView.h
//  YuneecPreviewView
//
//  Copyright © 2017 Yuneec. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * Yuneec Preview View scale mode
 */
typedef NS_ENUM(NSUInteger, YuneecPreviewViewScaleMode) {
    /**
     * Uniform scale until one dimension fits
     * default view scale mode
     */
    YuneecPreviewViewScaleModeAspectFit,
    /**
     * Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
     */
    YuneecPreviewViewScaleModeAspectFill,
    /**
     * Non-uniform scale. Both render dimensions will exactly match the visible bounds
     */
    YuneecPreviewViewScaleModeFill,
};

/**
 * Yuneec Video Pixel Format Type
 */
typedef NS_ENUM(NSUInteger, YuneecPreviewPixelFmtType)
{
    YuneecPreviewPixelFmtTypeI420 = 0,
    YuneecPreviewPixelFmtTypeNV12,
    YuneecPreviewPixelFmtTypeNV21,
};

/**
 * Use this view to render YUV420 video frame
 */
@interface YuneecPreviewView : UIView

/**
 * Get and set current scale mode
 */
@property (nonatomic) YuneecPreviewViewScaleMode    scaleMode;

/**
 * Get the video current rendering rect in UIView.
 */
@property (nonatomic, readonly) CGRect renderingRect;

/**
 * Indicate whether opengl had been initialized.
 */
@property (nonatomic) BOOL bOpenGlInited;

/**
 * Indicate the pixel format type of input video.
 */
@property (nonatomic) YuneecPreviewPixelFmtType pixelFmtType;

/**
 * Call this method to display YUV frame
 *
 * @param data input YUV420P data
 * @param width input video width
 * @param height input video height
 */
- (void)displayYUV420pData:(void *)data
                     width:(NSInteger) width
                    height:(NSInteger) height
                  pixelFmt:(YuneecPreviewPixelFmtType)fmtType;

/**
 * Clear current video frame
 */
- (void)clearFrame;

@end
