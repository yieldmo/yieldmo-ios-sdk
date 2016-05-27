//
//  YMView.h
//  Yieldmo
//
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface YMView : UIView
/*!
 * @brief The placement identifier
 */
@property (nonatomic, readonly) NSString * placementId;

/*!
 * @brief The placement format class name
 */
@property (nonatomic, readonly) NSString * format;
@end
