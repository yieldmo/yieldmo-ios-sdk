//
//  YMSdkDelegate.h
//  Yieldmo
//
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol YMSdkDelegate <NSObject>

@required
/*!
 * @brief Your view controller receives this message when the placement views are loaded. You would typically declare the controller that's in charge of handling the placementViews as the delegate.
 * @param placementViews A dictionary wherein the key is the placement id and the value is the placement view, an instance of a subclass of YMView.
 */
- (void) placementDidFetchAds: (NSDictionary *) placementViews;

/*!
 * @brief Your view controller receives this message when the placement views fail to load.
 * @param erroredPlacements Error message for respective placements. The key is the placement ID and the value is a human readable error message.
 */
- (void) placementFailedToFetchAds: (NSDictionary<NSString *, NSString *> *) erroredPlacements;


@optional
/*!
 * @brief Called when a Yieldmo ad was tapped and resulted in the user leaving your app.
 */
- (void) adDidExitApp;
@end
