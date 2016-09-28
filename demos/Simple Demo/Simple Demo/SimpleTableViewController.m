//
//  StoryboardExampleTableViewController.m
//  Simple Demo
//
//  Created by Muthu Arumugam on 10/6/15.
//  Copyright © 2015 Yieldmo, Inc. All rights reserved.
//

#import "SimpleTableViewController.h"
@import Yieldmo;

static NSUInteger const kAdIndex = 3;

@interface SimpleTableViewController () <YMPlacementViewDelegate>

@property (nonatomic, strong) YMPlacementView * adView;
@property (nonatomic, strong) NSString * placementID;

@end

@implementation SimpleTableViewController

- (void) viewDidLoad {
    [super viewDidLoad];

    // Init YM Views
    self.placementID = kDemoPlacement_Domino_4Ads;
    self.adView = [Yieldmo placementWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 600) withID:self.placementID];
    self.adView.delegate = self;
}

- (void) didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger) numberOfSectionsInTableView: (UITableView *) tableView {
    return 1;
}

- (NSInteger) tableView: (UITableView *) tableView numberOfRowsInSection: (NSInteger) section {
    return 20;
}

- (UITableViewCell *) tableView: (UITableView *) tableView cellForRowAtIndexPath: (NSIndexPath *) indexPath {
    UITableViewCell * cell;

    // Configure the cell...
    if (indexPath.row == kAdIndex) {
        // For Yieldmo Ad Cell
        if (self.adView) {
            // If ad request succeeds, fill the row with ad content
            cell = [tableView dequeueReusableCellWithIdentifier: @"placementCellId" forIndexPath: indexPath];
            if (![cell.subviews containsObject: self.adView]) {
                [cell addSubview: self.adView];
            }
        }
        else {
            // Load a dummy row if the ad request fails
            cell = [tableView dequeueReusableCellWithIdentifier: @"cell" forIndexPath: indexPath];
            cell.textLabel.text = @"";
        }
    }
    else {
        cell = [tableView dequeueReusableCellWithIdentifier: @"cell" forIndexPath: indexPath];
        cell.textLabel.text = [NSString stringWithFormat: @"Row %ld", (long)indexPath.row];
    }

    return cell;
}

- (CGFloat) tableView: (UITableView *) tableView heightForRowAtIndexPath: (NSIndexPath *) indexPath {
    if (indexPath.row == kAdIndex) {
        // For Yieldmo Ad Cell
        if (self.adView) {
            return self.adView.frame.size.height; // Ad available
        }
        else {
            return 0.0; // No Ad
        }
    }
    else {
        return 40.0f;
    }
}

#pragma mark - YMPlacementViewDelegate methods

// Optional
- (void) adViewDidReceiveAd: (YMPlacementView *) placementView {
    NSLog(@"Received ad from server for placement: %@", self.placementID);
}

// Optional
- (void) adViewDidFailToReceiveAd: (YMPlacementView *) placementView WithError: (YMError) error {
    NSLog(@"Failed to get ad from server for placement: %@", self.placementID);
}

// Required delegate method
- (BOOL) adViewShouldResize: (YMPlacementView *) placementView toPosition: (CGRect) position {
    return YES;
}

// Optional method that gets called if adViewShouldResize returns YES. Use it to trigger any events that need to happen after the adView resizes
- (void) adViewDidResize: (YMPlacementView *) placementView toPosition: (CGRect) position {
    [self.tableView reloadRowsAtIndexPaths: [NSArray arrayWithObjects: [NSIndexPath indexPathForRow: kAdIndex inSection: 0], nil] withRowAnimation: UITableViewRowAnimationNone];
}

@end
