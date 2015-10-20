#import <UIKit/UIKit.h>

@interface YMNativePlacementView : UIView
@property (nonatomic,assign) CGFloat maxWidth;
@property (nonatomic,assign) CGFloat minWidth;
@property (nonatomic,assign) CGFloat maxHeight;
- (void) removeHeader:(UIView*) headerView;
@end
