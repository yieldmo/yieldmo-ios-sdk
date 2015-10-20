#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Limitations: Only width at this point is considered when rendering placements.
// Height is up to YieldMo
//
@interface YMPlacementRequest : NSObject

// Designated initializer
//
-(instancetype) initWithPlacementId: (NSString*) placementId
                      landscapeSize: (CGSize) land
                       portraitSize: (CGSize) port
                    flatOrientation: (UIDeviceOrientation) orientation;

// Assumes portrait for orientation, full width and height for landscape and portrait sizes
//
-(instancetype) initWithPlacementId: (NSString*) placementId;
@property(nonatomic,strong) NSString* placementId;
@property(nonatomic,strong) NSString* tag;
@property(nonatomic,strong) NSString* metaDescription;
@property(nonatomic,assign) CGSize landscapeSize;
@property(nonatomic,assign) CGSize portraitSize;
@property(nonatomic,assign) UIDeviceOrientation flatOrientation;
@end


