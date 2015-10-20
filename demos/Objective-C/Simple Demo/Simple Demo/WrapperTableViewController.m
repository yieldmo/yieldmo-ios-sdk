//
//  WrapperTableViewController.m
//  Simple Demo
//
//  Created by Muthu Arumugam on 10/6/15.
//  Copyright © 2015 Yieldmo, Inc. All rights reserved.
//

#import "WrapperTableViewController.h"

@interface WrapperTableViewController () 

@property (nonatomic, strong) YMView *adContent;

@end

@implementation WrapperTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Init YM Views
//    [[YM sharedYM] fetchNativePlacements:@[[[YMNativePlacement alloc] initWithPlacementId:kDemoDominoFormat4AdPlacementId width:self.view.bounds.size.width]] delegate:self];
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
    if (indexPath.row == self.parallaxRowIndex && self.adContent) {
        // For Yieldmo Ad Cell
        cell = [tableView dequeueReusableCellWithIdentifier:@"placementCellId" forIndexPath:indexPath];
        [cell addSubview:self.adContent];
    } else {
        cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
        cell.textLabel.text = [NSString stringWithFormat:@"Row %ld", indexPath.row];
    }
    
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == self.parallaxRowIndex && self.adContent) {
        // For Yieldmo Ad Cell
        return self.adContent.preferredHeight;
    } else {
        return 40.0f;
    }
}

#pragma mark - YMViewDelegate methods

- (void)placementFailedToFetchAds:(NSArray *)erroredPlacements {
    NSLog(@"Failed to get ad from server for placements: %@", erroredPlacements);
}

- (void)placementDidFetchAds:(NSDictionary *)placementViews {
    NSLog(@"Successfully received an ad for %ld view(s)", [placementViews count]);
    self.adContent = placementViews[kDemoWrapperFormatPlacementId];
    [self.tableView reloadData];
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    [self.adContent didScroll];
}

- (UIScrollView *)placementScrollView {
    return self.tableView;
}

- (NSUInteger)parallaxRowIndex {
    return 5;
}

@end
