//
//  YMMacros.h
//  Demo
//
//  Created by Sami B on 1/26/15.
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//
#define RGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGB(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define HEIGHT(view) view.bounds.size.height
#define WIDTH(view) view.bounds.size.width
#define X(view) view.frame.origin.x
#define Y(view) view.frame.origin.y