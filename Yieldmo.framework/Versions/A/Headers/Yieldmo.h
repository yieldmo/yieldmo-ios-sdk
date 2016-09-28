//
//  Yieldmo.h
//  Yieldmo
//
//  Copyright © 2016 Yieldmo. All rights reserved.
//

#import "YMConstants.h"
#import "YMPlacementView.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@import CoreLocation;

/**
 *  Convenience class to access Yieldmo API
 */
@interface Yieldmo : NSObject

/**
 *  Get an ad view with a given size
 *  @param frame The initial frame for the view
 *  @param placementID A unique identifier for a placement.  Ask your Yieldmo account manager for appropriate placement id for production.  For testing, you can use a demo placement ID found in YMConstants.h
 *  @code [Yieldmo placementWithFrame:self.view.frame withID:kDemoPlacement_Hyperscroller];
 *  @return A UIView containing a Yieldmo ad
 */
+ (nonnull YMPlacementView *) placementWithFrame: (CGRect) frame withID: (nonnull NSString *) placementID;

/**
 *  Pass the user's current geolocation.  We recommend calling this each time you receive a location update, and at least once before requesting a placement view.   This is used for location-based ads.
 *  @param currentLocation the user's location
 */
+ (void) setLocation: (nonnull CLLocation *) currentLocation;

/**
 *  The level of logging by Yieldmo.  Each level includes messages from previous log levels (eg, 'YMLogLevelWarning' includes all messages from YMLogLevelError).
 */
typedef NS_ENUM (NSInteger, YMLogLevel) {
    /// No logging
    YMLogLevelNone,
    /// Only log serious problems
    YMLogLevelError,
    /// Log warning messages that indicate potential problems
    YMLogLevelWarning,
    /// Log informational messages that do not indicate problems
    YMLogLevelInfo,
    /// Log detailed debugging messages
    YMLogLevelDebug,
};

/**
 *  Change the level of logging by Yieldmo.  If log level is not set, the default value is YMLogLevelInfo.  In production, this should always be set to YMLogLevelWarning or YMLogLevelNone.
 *
 *  @param logLevel the level of logging.
 */
+ (void) setLogLevel: (YMLogLevel) logLevel;

/**
 *  Get the version number of the Yieldmo framework
 *
 *  @return A String representing the version and build of the SDK, for example "4.0.0 (1)"
 */
+ (nonnull NSString *) version;

+ (void) startWithAppID: (nonnull NSString *) appID;

+ (nonnull NSString *) YMMRAIDVersion;


+ (nonnull NSString *) JSSdkVersion;

/**
 *  Starts a new page view.  Page views are used for reporting purposes when multiple placements are displayed within an article.  As a guideline, each new article load should result in a new page view.
 */
+ (void) startPageView;

/**
 *  End the current page view.
 */
+ (void) endPageView;

@end
