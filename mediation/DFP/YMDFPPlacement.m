//
//  YMDFPPlacement.m
//  DFPBannerExample
//
//  Copyright © 2016 Yieldmo. All rights reserved.
//

#import "YMDFPPlacement.h"
#import <UIKit/UIKit.h>

@implementation YMDFPPlacement

@synthesize delegate;

- (void) requestBannerAd: (GADAdSize) adSize
               parameter: (NSString *) serverParameter
                   label: (NSString *) serverLabel
                 request: (GADCustomEventRequest *) request  {
    if ([request userHasLocation]) {
        CLLocation * location = [[CLLocation alloc] initWithLatitude: [request userLatitude] longitude: [request userLongitude]];
        [Yieldmo setLocation: location];
        NSLog(@"Yieldmo: Received location through DFP");
    }
    
    // serverParameter should contain app ID, then placement ID — separated by an underscore
    NSArray<NSString *> * serverParameters = [serverParameter componentsSeparatedByString: @"_"];
    if (serverParameters.count == 2) {
        YMPlacementView * placementView = [Yieldmo placementWithFrame: CGRectMake(0, 0, 300, 250) withID: serverParameters[1]];
        placementView.delegate = self;
        
        // TODO: remove after events from js are implemented
        [self.delegate customEventBanner: self didReceiveAd: placementView];
    }
    else {
        NSLog(@"Yieldmo: Invalid DFP configuration for Yieldmo ads.  Expected: appID_placementID, received: %@.  Ads will not serve.", serverParameter);
        [delegate customEventBanner: self didFailAd: nil];
    }
}

- (BOOL) adViewShouldResize: (YMPlacementView *) placementView toPosition: (CGRect) position {
    return YES;
}

- (void) adViewDidResize: (YMPlacementView *) placementView toPosition: (CGRect) position {
    // center YMPlacementView in superview
    CGFloat superHeight = placementView.superview.frame.size.height;
    CGFloat placementHeight = placementView.frame.size.height;
    CGRect adjustedFrame = CGRectMake(0, (superHeight - placementHeight) / 2, position.size.width, position.size.height);
    
    placementView.frame = adjustedFrame;
}

- (void) adViewDidReceiveAd: (YMPlacementView *) placementView {
    NSLog(@"Yieldmo: Received ad");
    [self.delegate customEventBanner: self didReceiveAd: placementView];
}

- (void) adViewDidFailToReceiveAd: (YMPlacementView *) placementView WithError: (YMError) error {
    NSLog(@"Yieldmo: Failed to receive ad");
    [self.delegate customEventBanner: self didFailAd: nil];
}

- (void) adViewWillPresentScreen: (YMPlacementView *) placementView {
    NSLog(@"Yieldmo: Presented a modal on the screen");
    [self.delegate customEventBannerWillPresentModal: self];
}

- (void) adViewDidDismissScreen: (YMPlacementView *) placementView {
    NSLog(@"Yieldmo: Dismissed a modal from the screen");
    [self.delegate customEventBannerDidDismissModal: self];
}

- (void) adViewWillLeaveApplication: (YMPlacementView *) placementView {
    NSLog(@"Yieldmo: Left the application");
    [self.delegate customEventBannerWillLeaveApplication: self];
}

- (void) adViewTapped: (YMPlacementView *) placementView {
    NSLog(@"Yieldmo: Ad tapped");
    [self.delegate customEventBannerWasClicked: self];
}

@end
