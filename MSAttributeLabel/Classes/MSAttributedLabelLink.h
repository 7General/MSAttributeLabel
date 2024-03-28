//
//  NSAttributedLabelLink.h
//  HHHAttribute
//
//  Created by zzg on 2018/4/9.
//  Copyright © 2018年 王会洲. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MSAttributedLabel;
@interface MSAttributedLabelLink : NSObject <NSCoding>

typedef void (^NSAttributedLabelLinkBlock) (MSAttributedLabel *, MSAttributedLabelLink *);


@property (readonly, nonatomic, strong) NSTextCheckingResult *result;


@property (readonly, nonatomic, copy) NSDictionary *attributes;


@property (readonly, nonatomic, copy) NSDictionary *activeAttributes;


@property (readonly, nonatomic, copy) NSDictionary *inactiveAttributes;


@property (nonatomic, copy) NSString *accessibilityValue;


@property (nonatomic, copy) NSAttributedLabelLinkBlock linkTapBlock;

@property (nonatomic, copy) NSAttributedLabelLinkBlock linkLongPressBlock;

- (instancetype)initWithAttributes:(NSDictionary *)attributes
                  activeAttributes:(NSDictionary *)activeAttributes
                inactiveAttributes:(NSDictionary *)inactiveAttributes
                textCheckingResult:(NSTextCheckingResult *)result;

- (instancetype)initWithAttributesFromLabel:(MSAttributedLabel*)label
                         textCheckingResult:(NSTextCheckingResult *)result;

@end
