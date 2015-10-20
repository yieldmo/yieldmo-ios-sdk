//
//  YMViewDelegate.h
//  ym
//
//  Created by Sami B on 3/27/15.
//  Copyright (c) 2015 Yieldmo. All rights reserved.
//

@protocol YMViewDelegate <NSObject>
@required

/*!
 * @brief Your view controller receives this message when the placement views failed to render
 * @param erroredPlacements An array of errors for each placement
 */
- (void) placementFailedToFetchAds:(NSArray*)erroredPlacements;

/*!
 * @brief Your view controller receives this message when the placement views are rendered. Typically where you would add the views to your controller and reload your table view
 * @param placementViews A dictionary wherein the key is the placement id and the value is the placement view, a YMView subclass instance
 */
- (void) placementDidFetchAds:(NSDictionary *)placementViews;

/*!
 * @brief Provide the table view or scrollview instance containing your placements. Used to track viewability and ad engagement
 * @return placementScrollView A UIScrollView subclass instance
 */
- (UIScrollView*) placementScrollView;

/*!
 * @brief Used by parallax formats (hyperscroller, pull, window) to map the location of the placement within the table view to an indexPath row
 * @return parallaxRowIndex Typically the indexPath.row value of your in-content placement
 */
- (NSUInteger) parallaxRowIndex;
@optional
/*!
 * @brief Used by parallax formats (hyperscroller, pull, window) to map the location of the placement within the table view to an indexPath section
 * @return parallaxRowIndex Typically the indexPath.section value of your in-content placement
 */
- (NSUInteger) parallaxSectionIndex;

- (/*__kindof*/ YMView*) wrappedInContentPlacementView;

- (/*__kindof*/ UIScrollView*) wrappedScrollView;

@end