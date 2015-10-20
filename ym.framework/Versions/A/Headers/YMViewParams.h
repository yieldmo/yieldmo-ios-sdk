#import <Foundation/Foundation.h>

@interface YMViewParams : NSObject

@property (nonatomic, readwrite, strong) NSString *viewControllerTitle;
@property (nonatomic, readwrite, strong) NSString *viewControllerDescription;
@property (nonatomic, readwrite, strong) NSString *viewControllerUrl;
@property (nonatomic, readwrite, strong) NSDictionary *dynamicCreative;

- (id) init:(NSString*) title url:(NSString*) url description:(NSString*) description dynamicCreative:(NSDictionary*) dynamicCreative;

@end
