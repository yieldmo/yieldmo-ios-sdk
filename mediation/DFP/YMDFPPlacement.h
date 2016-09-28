//
//  YMDFPPlacement.h
//  DFPBannerExample
//
//  DFP mediation version: 0.1
//  Copyright © 2016 Yieldmo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@import Yieldmo;
@import GoogleMobileAds;

@interface YMDFPPlacement : NSObject<YMPlacementViewDelegate,GADCustomEventBanner>

@property (nonatomic, weak) id<GADCustomEventBannerDelegate> delegate;

@end
