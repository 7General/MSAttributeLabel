//
//  MSViewController.m
//  MSAttributeLabel
//
//  Created by huizhou.wang on 03/28/2024.
//  Copyright (c) 2024 huizhou.wang. All rights reserved.
//

#import "MSViewController.h"
#import <MSAttributeLabel/MSAttributedLabel.h>

@interface MSViewController ()<MSAttributedLabelDelegate>

@end

@implementation MSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self NS];
}

- (void)NS {
    //添加文本信息
    MSAttributedLabel *butedText = [[MSAttributedLabel alloc]
                                      initWithFrame:CGRectMake(0,100,300,389)];
    butedText.backgroundColor = [UIColor lightGrayColor];
    butedText.delegate = self;
    butedText.lineHeightMultiple = 2;
    UIFont *font = [UIFont systemFontOfSize:20];
    butedText.font = font;
    butedText.numberOfLines = 0;
    butedText.lineBreakMode = NSLineBreakByWordWrapping;

    NSString * text = @"i have read, understood and agreed to the Terms & Conditions and Privacy Policy.";
    [butedText setText:text afterInheritingLabelAttributesAndConfiguringWithBlock:^NSMutableAttributedString *(NSMutableAttributedString *mutableAttributedString) {
        return mutableAttributedString;
    }];
    
    butedText.linkAttributes = @{
                                  (NSString*)kCTForegroundColorAttributeName : (id)[[UIColor greenColor] CGColor],
                                  (NSString*)kCTFontAttributeName : (id)[UIFont systemFontOfSize:20],
                                  };
    
    butedText.verticalAlignment = NSAttributedLabelVerticalAlignmentTop;
    
    NSDictionary * keyWords = @{@"Terms & Conditions and Privacy Policy.":@"keyWord"};
    
    for (NSString * item in keyWords.allKeys) {
        NSRange range = [text rangeOfString:item options:NSCaseInsensitiveSearch];
        [butedText addLinkToURL:[NSURL URLWithString:keyWords[item]] withRange:range];
    }
    [self.view addSubview:butedText];
    
  
}


- (void)attributedLabel:(MSAttributedLabel *)label didSelectLinkWithURL:(NSURL *)url {
    NSLog(@"------%@",url);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
