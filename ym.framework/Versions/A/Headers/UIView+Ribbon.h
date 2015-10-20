//
//  UIView+Ribbon.h
//  ym
//
//  Created by Sami B on 1/22/15.
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//
#import "YMRibbonComponent.h"
#import <UIKit/UIKit.h>

@interface UIView (Ribbon)
- (YMRibbonComponent*) attachRibbonLeftCorner:(BOOL)leftCorner;
@end