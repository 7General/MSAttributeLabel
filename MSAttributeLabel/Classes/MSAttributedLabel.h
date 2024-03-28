

#import <UIKit/UIKit.h>
#import "MSAttributedLabelLink.h"
#import <CoreText/CoreText.h>


FOUNDATION_EXPORT double MSAttributedLabelVersionNumber;


FOUNDATION_EXPORT const unsigned char NSAttributedLabelVersionString[];


typedef NS_ENUM(NSInteger, NSAttributedLabelVerticalAlignment) {
    NSAttributedLabelVerticalAlignmentCenter   = 0,
    NSAttributedLabelVerticalAlignmentTop      = 1,
    NSAttributedLabelVerticalAlignmentBottom   = 2,
};

extern NSString * const kNSStrikeOutAttributeName;

extern NSString * const kNSBackgroundFillColorAttributeName;

extern NSString * const kNSBackgroundFillPaddingAttributeName;

extern NSString * const kNSBackgroundStrokeColorAttributeName;

extern NSString * const kNSBackgroundLineWidthAttributeName;

extern NSString * const kNSBackgroundCornerRadiusAttributeName;

@protocol MSAttributedLabelDelegate;

// Override UILabel @property to accept both NSString and NSAttributedString
@protocol NSAttributedLabel <NSObject>
@property (nonatomic, copy) IBInspectable id text;
@end

IB_DESIGNABLE

@interface MSAttributedLabel : UILabel <NSAttributedLabel, UIGestureRecognizerDelegate>


- (instancetype) init NS_UNAVAILABLE;

@property (nonatomic, unsafe_unretained) IBOutlet id <MSAttributedLabelDelegate> delegate;

@property (nonatomic, assign) NSTextCheckingTypes enabledTextCheckingTypes;


@property (readonly, nonatomic, strong) NSArray *links;


@property (nonatomic, strong) NSDictionary *linkAttributes;


@property (nonatomic, strong) NSDictionary *activeLinkAttributes;


@property (nonatomic, strong) NSDictionary *inactiveLinkAttributes;


@property (nonatomic, assign) UIEdgeInsets linkBackgroundEdgeInset;


@property (nonatomic, assign) BOOL extendsLinkTouchArea;

@property (nonatomic, assign) IBInspectable CGFloat shadowRadius;

@property (nonatomic, assign) IBInspectable CGFloat highlightedShadowRadius;

@property (nonatomic, assign) IBInspectable CGSize highlightedShadowOffset;

@property (nonatomic, strong) IBInspectable UIColor *highlightedShadowColor;


@property (nonatomic, assign) IBInspectable CGFloat kern;

@property (nonatomic, assign) IBInspectable CGFloat firstLineIndent;


@property (nonatomic, assign) IBInspectable CGFloat lineSpacing;


@property (nonatomic, assign) IBInspectable CGFloat minimumLineHeight;

@property (nonatomic, assign) IBInspectable CGFloat maximumLineHeight;


@property (nonatomic, assign) IBInspectable CGFloat lineHeightMultiple;


@property (nonatomic, assign) IBInspectable UIEdgeInsets textInsets;


@property (nonatomic, assign) NSAttributedLabelVerticalAlignment verticalAlignment;

@property (nonatomic, strong) IBInspectable NSAttributedString *attributedTruncationToken;


@property (nonatomic, strong, readonly) UILongPressGestureRecognizer *longPressGestureRecognizer;


+ (CGSize)sizeThatFitsAttributedString:(NSAttributedString *)attributedString
                       withConstraints:(CGSize)size
                limitedToNumberOfLines:(NSUInteger)numberOfLines;

- (void)setText:(id)text;


- (void)setText:(id)text
afterInheritingLabelAttributesAndConfiguringWithBlock:(NSMutableAttributedString *(^)(NSMutableAttributedString *mutableAttributedString))block;


@property (readwrite, nonatomic, copy) NSAttributedString *attributedText;


- (void)addLink:(MSAttributedLabelLink *)link;


- (MSAttributedLabelLink *)addLinkWithTextCheckingResult:(NSTextCheckingResult *)result;


- (MSAttributedLabelLink *)addLinkWithTextCheckingResult:(NSTextCheckingResult *)result
                                               attributes:(NSDictionary *)attributes;


- (MSAttributedLabelLink *)addLinkToURL:(NSURL *)url
                               withRange:(NSRange)range;


- (MSAttributedLabelLink *)addLinkToAddress:(NSDictionary *)addressComponents
                                   withRange:(NSRange)range;


- (MSAttributedLabelLink *)addLinkToPhoneNumber:(NSString *)phoneNumber
                                       withRange:(NSRange)range;


- (MSAttributedLabelLink *)addLinkToDate:(NSDate *)date
                                withRange:(NSRange)range;


- (MSAttributedLabelLink *)addLinkToDate:(NSDate *)date
                                 timeZone:(NSTimeZone *)timeZone
                                 duration:(NSTimeInterval)duration
                                withRange:(NSRange)range;


- (MSAttributedLabelLink *)addLinkToTransitInformation:(NSDictionary *)components
                                              withRange:(NSRange)range;


- (BOOL)containslinkAtPoint:(CGPoint)point;


- (MSAttributedLabelLink *)linkAtPoint:(CGPoint)point;

@end


@protocol MSAttributedLabelDelegate <NSObject>
@optional

- (void)attributedLabel:(MSAttributedLabel *)label
   didSelectLinkWithURL:(NSURL *)url;


- (void)attributedLabel:(MSAttributedLabel *)label
didSelectLinkWithAddress:(NSDictionary *)addressComponents;


- (void)attributedLabel:(MSAttributedLabel *)label
didSelectLinkWithPhoneNumber:(NSString *)phoneNumber;


- (void)attributedLabel:(MSAttributedLabel *)label
  didSelectLinkWithDate:(NSDate *)date;


- (void)attributedLabel:(MSAttributedLabel *)label
  didSelectLinkWithDate:(NSDate *)date
               timeZone:(NSTimeZone *)timeZone
               duration:(NSTimeInterval)duration;


- (void)attributedLabel:(MSAttributedLabel *)label
didSelectLinkWithTransitInformation:(NSDictionary *)components;


- (void)attributedLabel:(MSAttributedLabel *)label
didSelectLinkWithTextCheckingResult:(NSTextCheckingResult *)result;


- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithURL:(NSURL *)url
                atPoint:(CGPoint)point;


- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithAddress:(NSDictionary *)addressComponents
                atPoint:(CGPoint)point;


- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithPhoneNumber:(NSString *)phoneNumber
                atPoint:(CGPoint)point;



- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithDate:(NSDate *)date
                atPoint:(CGPoint)point;



- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithDate:(NSDate *)date
               timeZone:(NSTimeZone *)timeZone
               duration:(NSTimeInterval)duration
                atPoint:(CGPoint)point;



- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithTransitInformation:(NSDictionary *)components
                atPoint:(CGPoint)point;

- (void)attributedLabel:(MSAttributedLabel *)label
didLongPressLinkWithTextCheckingResult:(NSTextCheckingResult *)result
                atPoint:(CGPoint)point;

@end


