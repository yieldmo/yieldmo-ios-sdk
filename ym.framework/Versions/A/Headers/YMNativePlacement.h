#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YMNativePlacementView.h"

@class YMView;

@interface YMNativePlacement : NSObject

@property (nonatomic,readonly,strong) NSString*  placementId;
@property (nonatomic,strong) UIView*    containerView;
@property (nonatomic,assign) CGFloat preferredWidth;
@property (nonatomic,strong) YMNativePlacementView *    placementView;
@property (nonatomic,readwrite,strong) NSError*   error;
@property (nonatomic,readwrite,strong) NSString*  transformationTag;
@property (nonatomic,readwrite) BOOL fetched;
@property (nonatomic,strong) NSDictionary* placementData;
@property (nonatomic,strong) NSMutableArray* ads;
@property (nonatomic,strong) NSMutableDictionary * adsByTag;
@property (nonatomic,strong) NSString * pageViewId;
@property (nonatomic,assign) NSTimeInterval pageViewTime;

- (BOOL) populateCreatives;

- (id) init:(NSString*) placementId;
- (id) init:(NSString*) placementId containerView:(UIView*) containerView;

- (instancetype) initWithPlacementId:(NSString*)placementId
                               width:(CGFloat) width;

@end
