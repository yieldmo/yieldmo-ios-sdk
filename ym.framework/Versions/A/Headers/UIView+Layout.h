//
//  UIView+Layout.h
//  Demo
//
//  Created by Sami B on 1/22/15.
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface UIView (Layout)
- (void) centerInSuperview;
- (NSLayoutConstraint*) centerHorizontallyInSuperview;
- (void) centerVerticallyInSuperview;
- (void) pinInsideSuperview;
- (NSLayoutConstraint*) autoSetWidth:(CGFloat)width;
- (void) autoSetHeight:(CGFloat)height;
- (NSLayoutConstraint*) autoSetMinWidth:(CGFloat)minWidth;
@end