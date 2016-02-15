//
//  AboutViewController.m
//  Simple Demo
//
//  Created by Muthu Arumugam on 10/6/15.
//  Copyright © 2015 Yieldmo, Inc. All rights reserved.
//

#import "AboutViewController.h"
#import <Yieldmo/Yieldmo.h>

@interface AboutViewController ()

@property (weak, nonatomic) IBOutlet UILabel *versionLabel;

@end

@implementation AboutViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.versionLabel.text = [NSString stringWithFormat:@"SDK v%@", [YMSdk version]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
