//
//  YMSdk.h
//  Yieldmo
//
//  Copyright © 2016 Yieldmo. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol YMSdkDelegate;

typedef NS_OPTIONS(NSUInteger, YMSdkOptions) {
    YMSdkOptions_Default = 0,
    YMSdkOptions_Logging = 1 << 0,
    YMSdkOptions_UseExternalBrowser = 1 << 1,
    YMSdkOptions_LocationEnabled = 1 << 2,
    YMSdkOptions_UsePlacementTracker = 1 << 3,
    YMSdkOptions_UseIntelliQA = 1 << 4,
};

@interface YMSdk : NSObject

/*!
 * @brief Get a reference to the shared YMSDK singleton instance.
 * @return An instance of YMSdk.
 */
+ (instancetype) sharedYM;

/*!
 * @brief Get the SDK's version number. This is of the format Major-Version.Minor-Version.Patch-Version (Build-Number)
 * @return A string instance having the version number.
 */
+ (NSString*) version;

/*!
 * @brief Initializes the shared YMSdk singleton. You would normally call this method in your App's Delegate, and call it before invoking any Yieldmo SDK methods.
 * @param appID Your Yieldmo app ID that your account manager should have provided you with.
 * @param options A bitwise-OR of all the available YMSdkOptions.
 */
- (void) startWithAppID:(NSString *)appID features:(YMSdkOptions)options;

/*!
 * @brief Fetches placement views and returns them to the @p YMViewDelegate object
 * @param placements An array of placement identifiers
 * @param delegate An object (typically your @p UIViewController) conforming to the @p YMViewDelegate protocol
 * @param parentScrollView A UIScrollView (or any Views that inherit from it), which will have the YMView as either a direct subView, or a subView of one of its subViews. Pass nil if your current view doesn't support scrolling.
 * @return A dictionary of rendered placement views keyed by placement id
 */
- (void) fetchNativePlacements:(NSArray<NSString *> *)placementIds
                      delegate:(id<YMSdkDelegate>)delegate
                  inScrollView:(__kindof UIScrollView*)parentScrollView;


/*!
 * @brief QA helper method that returns a comma separated string of all the placement IDs for which ads were requested during the current session.
 * @return A comma separated string of placement IDs used to make ad requests.
 */
+ (NSString *) getPlacementRequestHistory;

/*!
 * @brief QA helper method that adds test devices for IntelliQA. Read more about IntelliQA here: https://github.com/yieldmo/yieldmo-ios-sdk/wiki/iOS-QA-Guide#intelliqa
 * @param deviceIdentifiers An NSArray of NSString device IDs. You can get a device's device ID by executing [[[UIDevice currentDevice] identifierForVendor] UUIDString]
 */
+ (void) addTestDevices:(NSArray<NSString *>*)deviceIdentifiers;

+ (void) switchToStaging;
+ (void) switchToProduction;


@end
