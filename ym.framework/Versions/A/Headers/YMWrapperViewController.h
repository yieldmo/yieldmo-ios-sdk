//
//  YMWrapperViewController.h
//  YieldmoDemo
//
//  Created by Sami B on 7/8/15.
//  Copyright © 2015 MSA. All rights reserved.
//

@protocol YMViewDelegate;

@class YMView;

@interface YMWrapperViewController : UIViewController

/*!
 * @brief Initializes a view controller containing a Yieldmo placement
 * @param delegateVc An instance of UIViewController conforming to the YMViewDelegate
 * @param placements An array of YMNativePlacement objects
 * @return The instantiated view controller instance
 * @note You must call this method when presenting your view controller or pushing it onto a navigation stack
 */
- (instancetype) initWithChildViewController:(UIViewController<YMViewDelegate>*)delegateVc placements:(NSArray*)placements;

/*!
 * @brief Optional: you may register a nib for a header view to float above the wrapped view
 * @param nibName An instance of UIViewController conforming to the YMViewDelegate
 * @param height The preferred header height
 * @param headerClass The Class object for the owning nib. This class should have a UIView property
 * @note See YMHeaderView in the Yieldmo demo app for an example implementation
 */
- (void) registerNibForHeader:(NSString*)nibName withHeight:(CGFloat)height owningClass:(Class)headerClass;

@end
