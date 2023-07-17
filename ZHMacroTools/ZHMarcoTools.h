#ifndef Header_h
#define Header_h

#import <AudioToolbox/AudioToolbox.h>
#pragma mark - weak strong 转换
#define DECLARE_WEAK_SELF  __weak typeof(self)weakSelf = self;
#define DECLARE_STRONG_SELF __typeof(&*self) __strong strongSelf = weakSelf

#pragma mark - app
#define kApp          ((AppDelegate *)([UIApplication sharedApplication].delegate))
#define kWindow       kApp.window

#pragma mark - 字体
#define kFontOfSys(F) [UIFont systemFontOfSize:F]
#define kFontOfSysBold(F) [UIFont boldSystemFontOfSize:F]
#define kFontWith(N,S) [UIFont fontWithName:N size:S]

#pragma mark - docment路径
#define  kDocmentFilePath  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) firstObject]

#pragma mark - 颜色
#define COLOR_RANDOM [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]
#define COLOR_HEX(s) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s & 0xFF00) >> 8))/255.0 blue:((s & 0xFF))/255.0  alpha:1.0]
#define COLOR_HEX_ALPHA(s,a) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s & 0xFF00) >> 8))/255.0 blue:((s & 0xFF))/255.0  alpha:a]

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

#pragma mark - delegate检查

#define DELEGETE_CHECK(delegate,selector) (delegate && [delegate respondsToSelector:selector])

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
//bundle main
#define MAINBUNDLE(NAME) [[NSBundle mainBundle] pathForResource:NAME ofType:nil]
//打开链接
#define OPENURL(UrlStr) [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UrlStr] options:@{} completionHandler:nil]

#endif /* ZHMarcoTools */
