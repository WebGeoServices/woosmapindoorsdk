//
//  WoosmapIndoorUtils.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

extern NSString *const kIndoorid;
extern NSString *const kIOAPIURLString;
extern NSString *const kFuzzySearchAPIURLString;
extern NSString *const kIASecrate;
extern NSString *const kIAKey;

extern NSString *const kSOMEFONTCOLOR;
extern NSString *const kFONTCOLOR;
extern NSString *const kBORDERCOLOR;
extern NSString *const kNAVIGATIONCOLOR;
extern NSString *const kNEXTSTEPCOLOR;
extern NSString *const kBUDDYBORDERCOLOR;
extern NSString *const kHIGHLIGHTCOLOR;
extern NSString *const kFONTCOLORFORFLOOR;
extern NSString *const kBlueDotIconPath;
extern NSString *const kResourceBundle;
extern NSString *const kCOLORFORCOVEREDPATH;

/// Utility Class
@interface WoosmapIndoorUtils : NSObject
{
    NSDate *applicationStartTime;
}
/**
 *  Rotation Mode
 */
@property(nonatomic,retain) NSNumber *mapRotationMode;
/**
 *  Use Indoor Atlas
 */
@property(nonatomic,retain) NSNumber *mapuseIndoorAtlas;
/**
 *  Map Scale
 */
@property (nonatomic,retain)  NSNumber *MapScale;
/**
 *  Single instance of Enviroment
 *
 *  @return Enviroment object
 */
+ (WoosmapIndoorUtils *)instance;
/**
 * @deprecated
 *  Resource path
 *
 *  @return asset folder path on server
 */
- (NSString *)getResourcePath __attribute__ ((deprecated));
/**
 *  Store Image Path
 *
 *  @return folder path on server
 */
- (NSString *)getStoreImagePath;
/**
 *  Offer Image location
 *
 *  @return folder path on server
 */
- (NSString *)getOfferImagePath;
/**
 *  Buddy image location
 *
 *  @return folder path on server
 */
- (NSString *)getBuddyImagePath;
/**
 *  Movie Image Location
 *
 *  @return folder path on server
 */
- (NSString *)getMovieImagePath;
/**
 *  Predefine Colors
 *
 *  @return List of Color
 */
- (NSArray *)getColors;
/**
 *  Floor Name
 *
 *  @param level Floor number fetch from Woosmap SDK
 *
 *  @return String
 */
- (NSString *)LevelString:(int)level;
/**
 *  Border to View
 *
 *  @param source View
 */
+(void) AddBorder:(UIView *)source;
/**
 *  Border With Corners
 *
 *  @param source View
 */
+ (void) AddBorderWithSharpCorners:(UIView *)source;
/**
 *  Border With Rounded corners
 *
 *  @param source view
 */
+ (void) AddRoundedCorners:(UIView *)source;
/**
 *  Border No Corner
 *
 *  @param source View
 */
+ (void) AddBorderNoCorner:(UIView *)source;
/**
 *  Yellow border
 *
 *  @param source view
 */
+ (void) AddBorderYellow:(UIView *)source;
/**
 *  Circle shape view
 *
 *  @param source view
 */
+ (void) circleView:(UIView *)source;
/**
 *  Circle shape button
 *
 *  @param source Button object which circle should be apply
 *  @param bordercolor border color of circle.in case of no border set this parameter as transparent
 */
+ (void) circleButton:(UIButton *)source withColor:(UIColor *)bordercolor;
/**
 *  Circle shape button
 *
 *  @param source Button object which circle should be apply
 */
+ (void) circleButton:(UIButton *)source;
/**
 *  Rounded Corners For Alert
 *
 *  @param source View which rounded corner apply
 */
+ (void) AddRoundedCornersForAlert:(UIView *)source;
/**
 *  Add Blue Border
 *
 *  @param source View which border  apply
 */
+ (void) AddBlueBorder:(UIView *)source;
/**
 *  make Floor Super Script
 *
 *  @param stringText Text which super script should apply
 *
 *  @return Super Scripted string
 */
+(NSString *)makeFloorSuperScript:(NSString *)stringText;

/**
 *  Gray image
 *
 *  @return
 */
- (NSString *)getGrayDotIconPath;
/**
 *  Description: Set ApplicationStartTime
 */
- (void)setApplicationStartTime;
/**
 *  get Application Start Time
 *
 *  @return
 */
- (NSDate *)getApplicationStartTime;
/**
 *  Is User in mall
 *
 *  @return YES/NO
 */
-(BOOL)getUserInVenue;
/**
 *  Set User in mall
 *
 *  @param set YES/NO
 */
-(void)setUserInVenue:(BOOL)set;
/**
 *  Walking Distance in text
 *
 *  @param distanceInpx Distance in meter
 *
 *  @return distance in minutes
 */
-(int)WalkingAway:(int)distanceInpx;
/**
 *  Create image from UIView
 *
 *  @param view View
 *
 *  @return Image File
 */
+ (UIImage *) imageWithView:(UIView *)view;
/**
 *  Create Image With View
 *
 *  @param view view which  converted to image
 *
 *  @return Image File
 */
+ (UIImage *)imageByRenderingView:(UIView *)view;
/**
 *  Create Image With View
 *
 *  @return Image File
 */
+ (UIImage *)screenshot;
/**
 *  Hit Test in polygon
 *
 *  @param vertices Ends of polygon
 *  @param test     test point
 *
 *  @return YES/NO
 */
+ (BOOL)HitTestInPolygon:(NSArray *)vertices point:(CGPoint)test;
/**
 *  Add Offer in Push List
 *
 *  @param offer Detail of offers
 */
-(void)addinpushoffers:(NSDictionary *)offer;
/**
 *  All offer from push list
 *
 *  @return List of offers
 */
-(NSArray *)getAllPushoffers;
/**
 *  Mark offer as seen
 *
 *  @param offer Offer Info
 */
-(void)setAsSeen:(NSDictionary *)offer;
/**
 *  List of unseen offers count
 *
 *  @return
 */
- (int) getUnSeenOffers;
/**
 *  Play sound
 *
 *  @param musicFile waev file path
 */
-(void)playSound:(NSURL *)musicFile;
/**
 *  Get north heading
 *
 *  @param fromLoc start location
 *  @param toLoc   End location
 *
 *  @return Heading in Degree
 */
+ (float)getHeading:(CLLocationCoordinate2D)fromLoc toCoordinate:(CLLocationCoordinate2D)toLoc;
/**
 *  Search Word in sentence
 *
 *  @param inText     sentence
 *  @param searchWord word
 *
 *  @return match Word
 */
-(NSString *)searchWord:(NSString *)inText andSearch:(NSString *)searchWord;
/**
 *  Convert meter to time
 *
 *  @param inMeters Distance in meter
 *
 *  @return number of seconds
 */
-(NSString *)convertFeetToTimeCustom:(double)inMeters;
-(NSString *)convertFeetToTime:(double)inMeters;
/**
 *  distance To Time
 *
 *  @param inMeters Distance in meter
 *
 *  @return number of seconds
 */
-(NSString *)convertdistanceToTime:(double)inMeters;

-(BOOL)getUserInMall;
/**
 *  Set User in mall
 *
 *  @param set YES/NO
 */
-(void)setUserInMall:(BOOL)set;


/**
 get location service enable or not
 
 @return BOOL value
 */
-(BOOL)getLocationServiceEnabled;
/**
 *  Set LocationService Enable
 *
 *  @param set YES/NO
 */

-(void)setLocationServiceEnabled:(BOOL)set;

/**
 user location icon path
 
 @return image file name in resource buindle
 */
- (NSString *)getBlueDotIconPath;

/**
 Resize image with new dimention
 @param sourceImage Source image
 @param i_width  new Width of image
 @return New image with resize scale
 */
+(UIImage*)imageWithResizeImage: (UIImage*) sourceImage scaledToWidth: (float) i_width;

+ (CLLocationCoordinate2D)calculateCoordinateFrom:(CLLocationCoordinate2D)coordinate  onBearing:(double)bearingInDegree atDistance:(double)distanceInMetres;
@end
