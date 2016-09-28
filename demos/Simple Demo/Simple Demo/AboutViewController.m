//
//  AboutViewController.m
//  Simple Demo
//
//  Created by Muthu Arumugam on 10/6/15.
//  Copyright © 2015 Yieldmo, Inc. All rights reserved.
//

#import "AboutViewController.h"
@import Yieldmo;
@import AdSupport;

@interface AboutViewController () <UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UILabel * sdkVersionLabel;

@end

@implementation AboutViewController

- (void) viewDidLoad {
    [super viewDidLoad];

    self.sdkVersionLabel.text = [NSString stringWithFormat: @"v %@", [Yieldmo version]];
}

- (void) didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
