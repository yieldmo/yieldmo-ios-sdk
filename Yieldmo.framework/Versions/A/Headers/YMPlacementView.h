//
//  YMPlacementView.h
//  Yieldmo
//
//  Copyright © 2016 Yieldmo. All rights reserved.
//

#import "YMError.h"
#import <UIKit/UIKit.h>
@class YMPlacementView;

/**
 *  Conform to this protocol to receive updates about ad lifecycle events
 */
@protocol YMPlacementViewDelegate <NSObject>

@optional
/**
 *  Invoked when the placement view fully loads an ad
 *  @param placementView the view that received an ad
 */
- (void) adViewDidReceiveAd: (nonnull YMPlacementView *) placementView;

/**
 *  Invoked when the ad request does not not fill or ad loading fails
 *
 *  @param placementView the view that did not receive an ad
 *  @param error         an object representing the error type
 */
- (void) adViewDidFailToReceiveAd: (nonnull YMPlacementView *) placementView withError: (YMError) error;
/**
 *  Invoked just before the ad presents a modal on the screen
 *
 *  @param placementView the view that presented a modal
 */
- (void) adViewWillPresentScreen: (nonnull YMPlacementView *) placementView;
/**
 *  Invoked when the ad dismisses a modal from the screen
 *
 *  @param placementView the view that dismissed a modal
 */
- (void) adViewDidDismissScreen: (nonnull YMPlacementView *) placementView;
/**
 *  Invoked when the ad leaves the application
 *
 *  @param placementView the view that left the application
 */
- (void) adViewWillLeaveApplication: (nonnull YMPlacementView *) placementView;
/**
 *  Invoked when the ad is clicked
 *
 *  @param placementView the view that was clicked
 */
- (void) adViewTapped: (nonnull YMPlacementView *) placementView;
/**
 *  Invoked when the ad changes size
 *
 *  @param placementView the view that changed size
 *  @param position      the new frame of the ad view
 */
- (void) adViewDidResize: (nonnull YMPlacementView *) placementView toPosition: (CGRect) position;


/**
 * Defines the region within which a placement animates.
 * This frame should not include regions that are occuluded by status bars, navigation bars, or other UI elements.  If this method is not implemented, we assume the ad is visible within the entire screen.
 *
 *  @param placementView the view for which the region is visible.
 *
 *  @return the frame that will contain the placement and controls its animation (for example, a UIScrollView's frame).
 */
- (CGRect) visibleContainerFrame: (nonnull YMPlacementView *) placementView;

@required
/**
 *  Request by a placement to change size.  Return YES to allow resizing. Returning NO may cause Yieldmo ads to fail because we cannot resize. If you need to modify your layout to accomodate the new size, do so in adViewDidResize.
 *
 *  @param placementView the placement that will change size
 *  @param position      the proposed new frame for the placement
 *
 *  @return A BOOL indicating whether the placement can resize to the new frame.
 */
- (BOOL) adViewShouldResize: (nonnull YMPlacementView *) placementView toPosition: (CGRect) position;
@end

/**
 *  A view that contains a Yieldmo ad
 */
@interface YMPlacementView : UIView

/**
 *  Get an ad view with a given size
 *
 *  @param frame       The initial frame for the view
 *  @param placementID A unique identifier for a placement.  Ask your Yieldmo account manager for appropriate placement id for production.  For testing, you can use a demo placement ID found in YMConstants.h
 *
 *  @return A UIView containing a Yieldmo ad
 */
- (nonnull YMPlacementView *) initWithFrame: (CGRect) frame withPlacementID: (nonnull NSString *) placementID;

/**
 *  API for sending an additional partner ID when initializing a placement.  Do not use this method unless instructed by your Yieldmo account manager.  Instead, use `initWithFrame withPlacementID`.
 *
 *  @param frame       The initial frame for the view
 *  @param placementID A unique identifier for a placement.  Ask your Yieldmo account manager for appropriate placement id for production.  For testing, you can use a demo placement ID found in YMConstants.h
 *  @param mediaPartnerID A unique identifier for media partner sales.  Ask your Yieldmo account manager for appropriate placement id for production.  For testing, you can use a demo placement ID found in YMConstants.h
 *
 *  @return A UIView containing a Yieldmo ad
 */
- (nonnull YMPlacementView *) initWithFrame: (CGRect) frame withPlacementID: (nonnull NSString *) placementID withMediaPartnerID: (nullable NSString *) mediaPartnerID;

/**
 *  A delegate that will receive updates about ad lifecycle events
 */
@property (nonatomic, weak, nullable) id<YMPlacementViewDelegate> delegate;

@end
