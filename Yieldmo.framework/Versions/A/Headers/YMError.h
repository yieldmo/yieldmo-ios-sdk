//
//  YMError.h
//  Yieldmo
//
//  Copyright © 2016 Yieldmo. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Error types that describe why an ad failed to load
 */
typedef NS_ENUM (NSInteger, YMError) {
    /// The placement id was incorrect, or the ad request was invalid
    YMErrorInvalidRequest,
    /// Yieldmo did not receive an ad for the placement, or no ads were bid to the placement.
    YMErrorNoFill,
    /// There was a network connectivity problem
    YMErrorNetwork,
    /// YMPlacementeViewDelegate's adViewShouldResize:toPosition: returned NO
    YMErrorResize,
    /// We encountered an uncategorized error
    YMErrorInternal,
};
