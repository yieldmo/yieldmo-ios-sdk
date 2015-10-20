//
//  YMView.h
//  ym
//
//  Created by Sami B on 2/19/15.
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//
#import "YM.h"
#import <UIKit/UIKit.h>

@protocol YMViewDelegate;
@class YMWrapperViewController;

typedef void (^YMViewCompletion)(YMView * renderedView, id error);

@interface YMView : UIView

/*!
 * @brief The placement view's delegate object
 */
@property (nonatomic,weak) id<YMViewDelegate> delegate;

/*!
 * @brief The placement identifier
 */
@property (nonatomic,strong) NSString * placementId;

/*!
 * @brief The placement meta object. Contains creative data + rendered placement view
 */
@property (nonatomic,strong) YMNativePlacement * placement;

/*!
 * @brief The placement view's preferred width
 */
@property (nonatomic,assign) CGFloat preferredWidth;

/*!
 * @brief The placement view's preferred height
 */
@property (nonatomic,readonly) CGFloat preferredHeight;

/*!
 * @brief The placement view's error info object in case of a rendering issue
 */
@property (nonatomic,strong) NSError * error;

/*!
 * @brief The placement view parent view controller
 */
@property (nonatomic,strong) id wrapper;

/*!
 * @brief Used for viewability tracking: you @b must call this method when content is being scrolled within 
    your @p UIScrollView @p, @p UITableView or @p UICollectionView delegate method 

@code
- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    [self.myYieldmoPlacementView didScroll]
}
@endcode
 */
- (void) didScroll;

@end
