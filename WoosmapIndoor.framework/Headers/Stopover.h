//
//  Stopover.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>
#import "IndoorMapObject.h"
NS_ASSUME_NONNULL_BEGIN
/**
Use for multistep navigation
*/
@interface Stopover : NSObject

/**
*  Gets/Sets the Title for stop point .
*/
@property (nonatomic,retain) NSString *title;
/**
*  Gets/Sets Location of stop point.
*/
@property (readwrite) CGIndoorMapPoint mapPoint;
@end

NS_ASSUME_NONNULL_END
