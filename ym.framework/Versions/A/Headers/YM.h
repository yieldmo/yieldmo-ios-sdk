#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "YMPlacement.h"
#import "YMNativePlacement.h"
#import "YMPlacementRequest.h"
#import "YMConstants.h"
#import "YMViewParams.h"
#import "UIView+Layout.h"
#import "YMView.h"
#import "YMDominoView.h"
#import "YMTickerView.h"
#import "YMViewDelegate.h"
#import "YMHyperScrollerView.h"
#import "YMPullView.h"
#import "YMWindowView.h"
#import "YMRibbonComponent.h"
#import "YMButtonComponent.h"
#import "UIView+Ribbon.h"

#define Yieldmo YMWrapperViewController

@class YMWebViewController;

@interface YM : NSObject <CLLocationManagerDelegate>

/*!
 * @brief Fetches placement views and returns them to the @p YMViewDelegate object
 * @param placements An array of YMNativePlacement objects each initialized with a @p placementId and their respective preferred width
 * @param delegate An object (typically a @p UIViewController) conforming to the @p YMViewDelegate protocol
 * @return A dictionary of rendered placement views keyed by placement id
 */
- (void) fetchNativePlacements:(NSArray*)placements delegate:(id<YMViewDelegate>)delegate;

/**
 * @deprecated Non-native JS placement requests are deprecated as of Yieldmo SDK 2.2
 * @note Please use native placements instead: @code - (void) fetchNativePlacements:(NSArray*)placements delegate:(id<YMViewDelegate>)delegate @endcode
 */
- (void) fetchPlacements:(NSArray*) placementIds withCompletionHandler:(void (^)(NSArray *placements, NSError *error))handler __attribute__((deprecated));

+ (instancetype) sharedYM;

/*!
 * @brief Initializes the Yieldmo SDK
 * @param appId Your Yieldmo application identifier
 * @note You must call this method in your application's delegate in @p applicationDidFinishLaunchingWithOptions:
 */
- (void) setAppId: (NSString*) appId;

/*!
 * @brief Sets the SDK in test mode
 * @param dryRun Test mode flag
 * @warning You @b must set this to NO before going live
 */
- (void) setDryRun: (BOOL) dryRun;

/*!
 * @brief Enables YM internal logging
 * @param value True IFF logging is to be enabled
 */
- (void) enableLogging:(BOOL) value;

/*!
 * @brief Returns the Yieldmo SDK version
 * @return The SDK version as a string
 */
- (NSString *) sdkVersion;

/*!
 * @brief Returns the Publisher's app version and build number
 * @return The main bundle version as a string
 */
-(NSString*) publisherAppVersion;

@property (nonatomic, readonly, weak) YMWebViewController* ymWebViewController;

@property (nonatomic, readwrite) BOOL openAdsInSafari;

@end
