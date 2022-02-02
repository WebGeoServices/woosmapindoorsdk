//
//  LastKnownLocation.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Last known location
 */
@interface LastKnownLocation : NSObject

/**
 Map refrence
 */
@property (nonatomic,retain)  NSNumber *mapid;

/**
 Level number
 */
@property (nonatomic,retain)  NSNumber *floor;

/**
 Last location instance
 
 @return Location service
 */
+ (LastKnownLocation *)instance;

/**
 Get known user location
 
 @param mapid maprefrence
 @return mapid
 */
-(CGPoint)getLocation:(int)mapid;

/**
 set new location
 
 @param location location
 */
-(void)setLocation:(CGPoint)location;

/**
 set  location
 
 @param lat latitude
 @param lng longitude
 */
-(void)setgeoLocation:(double)lat longitude:(double)lng;

/**
 get latitude
 
 @return latitude
 */
-(double)getlatitude;

/**
 get longitude
 
 @return longitude
 */
-(double)getlongitude;

@end
