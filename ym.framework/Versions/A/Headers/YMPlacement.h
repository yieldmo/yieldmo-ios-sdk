#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YMPlacementRequest.h"

@protocol YMPlacementListener, YMPlacementViewabilityListener;

@class  YMWebViewController;

@protocol YMPlacementProtocol
@required
-(UIView*)   view;
-(NSString*) placementId;
-(NSString*) dataId;
-(NSString*) tag;
@end

@interface YMPlacement : NSObject <YMPlacementProtocol>

-(instancetype)initWithWebView: (UIWebView*)web
              placementRequest: (YMPlacementRequest *)plid
             inPageViewRequest: (id)pv; // hidden

-(UIView*) view;
-(NSString*) placementId;
-(NSString*) dataId;
-(NSString*) tag;
-(void) setDelegate:(id<YMPlacementListener>) delegate;

@end

@protocol YMPlacementListener <NSObject>


// the placement might change size on device orientation events
// to accomodate the landscape/portrait view
//
@optional
-(void) placement:(YMPlacement*)yieldmoPlacement changedDimensions:(CGSize)dimensions;

@end
