//
//  StoryboardExampleTableViewController.m
//  Simple Demo
//
//  Created by Muthu Arumugam on 10/6/15.
//  Copyright © 2015 Yieldmo, Inc. All rights reserved.
//

#import "SimpleTableViewController.h"
#import <ym/YM.h>
#import <ym/YMWrapperViewController.h>

@interface SimpleTableViewController () <YMViewDelegate>

@property (nonatomic, strong) YMView *adContent;

@end

@implementation SimpleTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Init YM Views
    [[YM sharedYM] fetchNativePlacements:@[[[YMNativePlacement alloc] initWithPlacementId:kDemoDominoFormat4AdPlacementId width:self.view.bounds.size.width]] delegate:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 20;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell;
    
    // Configure the cell...
    if (indexPath.row == self.parallaxRowIndex) {
        // For Yieldmo Ad Cell
        if (self.adContent) {
            // If ad request succeeds, fill the row with ad content
            cell = [tableView dequeueReusableCellWithIdentifier:@"placementCellId" forIndexPath:indexPath];
            [cell addSubview:self.adContent];
        } else {
            // Load a dummy row if the ad request fails
            cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
            cell.textLabel.text = @"";
        }
    } else {
        cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
        cell.textLabel.text = [NSString stringWithFormat:@"Row %ld", indexPath.row];
    }
    
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == self.parallaxRowIndex) {
        // For Yieldmo Ad Cell
        if (self.adContent)
            return self.adContent.preferredHeight; // Ad available
        else
            return 0.0; // No Ad
    } else {
        return 40.0f;
    }
}

#pragma mark - YMViewDelegate methods

- (void)placementFailedToFetchAds:(NSArray *)erroredPlacements {
    NSLog(@"Failed to get ad from server for placements: %@", erroredPlacements);
    [self.tableView reloadData];
}

- (void)placementDidFetchAds:(NSDictionary *)placementViews {
    NSLog(@"Successfully received an ad for %ld view(s)", [placementViews count]);
    self.adContent = placementViews[kDemoDominoFormat4AdPlacementId];
    [self.tableView reloadData];
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    [self.adContent didScroll];
}

- (UIScrollView *)placementScrollView {
    return self.tableView;
}

// The row number specified here will be replaced with Yieldmo Ad View when ad is available
- (NSUInteger)parallaxRowIndex {
    return 3;
}

#pragma mark - Prepare for Wrapper Demo

- (IBAction)wrapperClicked:(id)sender {
    YMNativePlacement *wrapperPlacement = [[YMNativePlacement alloc] initWithPlacementId:kDemoWrapperFormatPlacementId width:self.view.bounds.size.width];
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    WrapperTableViewController *wrapperViewController = [storyboard instantiateViewControllerWithIdentifier:@"wrapperdemo"];
    YMWrapperViewController *ymVC = [[YMWrapperViewController alloc] initWithChildViewController:wrapperViewController placements:@[wrapperPlacement]];
    [self.navigationController pushViewController:ymVC animated:YES];
}

@end
