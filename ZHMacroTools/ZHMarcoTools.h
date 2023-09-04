#ifndef Header_h
#define Header_h

#import <AudioToolbox/AudioToolbox.h>
#pragma mark - weak strong 转换
#define DECLARE_WEAK_SELF  __weak typeof(self)weakSelf = self;
#define DECLARE_STRONG_SELF __typeof(&*self) __strong strongSelf = weakSelf

#pragma mark - app
#define kApp          ((AppDelegate *)([UIApplication sharedApplication].delegate))
#define kWindow       kApp.window

#pragma mark - 路径
//document
#define  kDocmentFilePath  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) firstObject]
//bundle main
#define MAINBUNDLE(NAME) [[NSBundle mainBundle] pathForResource:NAME ofType:nil]

#pragma mark - 字体
#define kFontOfSys(F) [UIFont systemFontOfSize:F]
#define kFontOfSysBold(F) [UIFont boldSystemFontOfSize:F]
#define kFontWith(N,S) [UIFont fontWithName:N size:S]

#pragma mark - NSAttributedStr
#define ZHAttributedStr(str, ...) [[NSAttributedString alloc] initWithString:str attributes:@{ __VA_ARGS__ }]
#define ZHMutableAttributedStr(str, ...) [[NSMutableAttributedString alloc]initWithString:str attributes:@{ __VA_ARGS__ }]

///font --- > UIFont
#define ZHFontAttribute(font) NSFontAttributeName:font
///style --- > NSParagraphStyle
#define ZHParagraphStyleAttribute(style) NSParagraphStyleAttributeName:style
///color --- >  UIColor, default blackColor
#define ZHForegroundColorAttributeName(color) NSForegroundColorAttributeName:color
///color ---> UIColor, default nil: no background
#define ZHBackgroundColorAttributeName(color) NSBackgroundColorAttributeName:color
///number --- > NSNumber  containing integer, default 1: default ligatures, 0: no ligatures
#define ZHLigatureAttribute(number) NSLigatureAttributeName:number
///number --- > NSNumber containing floating point value, in points; amount to modify default kerning. 0 means kerning is disabled.
#define ZHKernAttribute(number) NSKernAttributeName:number
///number --- > NSNumber containing floating point value, in points; amount to modify default tracking. 0 means tracking is disabled.
#define ZHTrackingAttribute(number) NSTrackingAttributeName:number
///number --- > NSNumber containing integer, default 0: no strikethrough
#define ZHStrikethroughStyleAttribute(number) NSStrikethroughStyleAttributeName:number
///number --- > NSNumber containing integer, default 0: no underline
#define ZHUnderlineStyleAttribute(number) NSUnderlineStyleAttributeName:number
///color ---> UIColor, default nil: same as foreground color
#define ZHStrokeColorAttribute(color) NSStrokeColorAttributeName:color
///number --- > NSNumber containing floating point value, in percent of font point size, default 0: no stroke; positive for stroke alone, negative for stroke and fill (a typical value for outlined text would be 3.0)
#define ZHStrokeWidthAttribute(number) NSStrokeWidthAttributeName:number
///shadow --->  NSShadow, default nil: no shadow
#define ZHShadowAttribute(shadow) NSShadowAttributeName:shadow
///str --- >  NSString, default nil: no text effect
#define ZHTextEffectAttribute(str) NSTextEffectAttributeName:str
///attachment --- >  NSTextAttachment, default nil
#define ZHAttachmentAttribute(attachment) NSAttachmentAttributeName:attachment
///url --- > NSURL (preferred) or NSString
#define ZHLinkAttribute(url) NSLinkAttributeName:url
///number --- > NSNumber containing floating point value, in points; offset from baseline, default 0
#define ZHBaselineOffsetAttribute(number) NSBaselineOffsetAttributeName:number
///color ---> UIColor, default nil: same as foreground color
#define ZHUnderlineColorAttribute(color) NSUnderlineColorAttributeName:color
///color ---> UIColor, default nil: same as foreground color
#define ZHStrikethroughColorAttribute(color) NSStrikethroughColorAttributeName:color
///number --- > NSNumber containing floating point value; skew to be applied to glyphs, default 0: no skew
#define ZHObliquenessAttribute(number) NSObliquenessAttributeName:number
///number --- > NSNumber containing floating point value; log of expansion factor to be applied to glyphs, default 0: no expansion
#define ZHExpansionAttribute(number) NSExpansionAttributeName:number
///array --- > NSArray of NSNumbers representing the nested levels of writing direction overrides as defined by Unicode LRE, RLE, LRO, and RLO characters.  The control characters can be obtained by masking NSWritingDirection and NSWritingDirectionFormatType values.  LRE: NSWritingDirectionLeftToRight|NSWritingDirectionEmbedding, RLE: NSWritingDirectionRightToLeft|NSWritingDirectionEmbedding, LRO: NSWritingDirectionLeftToRight|NSWritingDirectionOverride, RLO: NSWritingDirectionRightToLeft|NSWritingDirectionOverride,
#define ZHWritingDirectionAttribute(array) NSWritingDirectionAttributeName:array
///number ---> An NSNumber containing an integer value.  0 means horizontal text.  1 indicates vertical text.  If not specified, it could follow higher-level vertical orientation settings.  Currently on iOS, it's always horizontal.  The behavior for any other value is undefined.
#define ZHVerticalGlyphFormAttribute(number) NSVerticalGlyphFormAttributeName:number

#pragma mark - 颜色
#define COLOR_RANDOM [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]
#define COLOR_HEX(s) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s & 0xFF00) >> 8))/255.0 blue:((s & 0xFF))/255.0  alpha:1.0]
#define COLOR_HEX_ALPHA(s,a) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s & 0xFF00) >> 8))/255.0 blue:((s & 0xFF))/255.0  alpha:a]
#define COLOR_BLOACK [UIColor blackColor]
#define COLOR_DGRAY [UIColor darkGrayColor]
#define COLOR_LGRAY [UIColor lightGrayColor]
#define COLOR_WHITE [UIColor whiteColor]
#define COLOR_GRAY [UIColor grayColor]
#define COLOR_RED [UIColor redColor]
#define COLOR_GREEN [UIColor greenColor]
#define COLOR_BLUE [UIColor blueColor]
#define COLOR_CYAN [UIColor cyanColor]
#define COLOR_YELLOW [UIColor yellowColor]
#define COLOR_MAGENTA [UIColor magentaColor]
#define COLOR_ORGANGE [UIColor orangeColor]
#define COLOR_PURPLE [UIColor purpleColor]
#define COLOR_BROWN [UIColor brownColor]
#define COLOR_CLEAR [UIColor clearColor]

#pragma mark - 图像
#define IMAGEWithMainBundle(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]
#define IMAGENAME(B) [UIImage imageNamed:B]
#define IMAGENAMEWithOri(A)  [[UIImage imageNamed:A]imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal]
#define IMAGENAME_MODE(a,m) [[UIImage imageNamed:a]imageWithRenderingMode:m]

#pragma mark - 屏幕
#define kSCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define kSCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
#define kStatusBarHeight 20
#define kNavigationBarHeight 44
#define kNavigationBarIcon 20
#define kTabBarHeight 49
#define kTabBarIcon 30

#pragma mark - bangs
#define kHasBangs [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0
#define kBangsTop [[UIApplication sharedApplication] delegate].window.safeAreaInsets.top
#define kBangsBottom [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom
#define kBangsLeft [[UIApplication sharedApplication] delegate].window.safeAreaInsets.left
#define kBangsRight [[UIApplication sharedApplication] delegate].window.safeAreaInsets.right

#pragma mark - 单例化一个类
#define SHAREINSTANCE(_ClassName) \
\
+(_ClassName *)sharedInstance

#define SHAREINSTANCE_IMPLEMENT(_ClassName) \
\
+(_ClassName *)sharedInstance\
{\
static _ClassName *sharedInstance = nil;\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
sharedInstance = [[_ClassName alloc] init];\
});\
return sharedInstance;\
}

#pragma mark - 线程执行

NS_INLINE void GCD_DO_BACK(dispatch_block_t block){ dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block);}
NS_INLINE void GCD_DO_MAIN(dispatch_block_t block) {dispatch_async(dispatch_get_main_queue(), block);}
NS_INLINE void GCD_DO_AFTER_QUEUE(NSInteger second,dispatch_queue_t queue,dispatch_block_t block){dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC)),queue, block);}
NS_INLINE void GCD_DO_AFTER_MAIN(NSInteger second,dispatch_block_t block){GCD_DO_AFTER_QUEUE(second, dispatch_get_main_queue(), block);}

#pragma mark - 角度弧度互转
///角度转弧度
#define DEGREES_2_RADIAN(x) (M_PI * (x) / 180.0)
///弧度转角度
#define RADIAN_2_DEGREES(radian) ((radian*180.0)/(M_PI))

#pragma mark - 调试
#ifdef DEBUG
// 定义是输出Log
#define DELog(format, ...) NSLog(@"Line[%d] %s " format, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#else
// 定义是输出Log
#define DELog(format, ...)
#endif

#pragma mark - block
//block 检查
#define BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); }
//block 声明
#define DECLARE_BLOCK(return,name,...) @property(nonatomic,copy) return(^name)(__VA_ARGS__);

#define DECLARE_BLOCK_VOID(name) DECLARE_BLOCK(void,name,void)

#pragma mark - 设备判断
#define IS_IPHONE ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)

#pragma mark - other
///类名
#define CLASSNAME(cls) NSStringFromClass([cls class])
///一半
#define HALF(a) ((a)/2)
///系统震动
#define SYSTEM_SHOC AudioServicesPlaySystemSound(1519);
///镜像
#define MIRROR CGAffineTransformMakeScale(-1,1)
//打开链接
#define OPENURL(UrlStr) [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UrlStr] options:@{} completionHandler:nil]
///delegaete检查
#define DELEGETE_CHECK(delegate,selector) (delegate && [delegate respondsToSelector:selector])

#endif /* ZHMarcoTools */
