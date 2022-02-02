//
//  SDKCacheManager.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>

/**
 Cache manager
 */
@interface SDKCacheManager : NSObject{}

/**
 Get Cache data from app
 
 @param days day count
 @param cacheid cache id
 @return List of Cache Data
 */
-(NSArray *)getFromCache:(int )days WithIdentifier:(NSString *)cacheid;

/**
 Get Cache data from app
 
 @param days day count
 @param cacheid cache id
 @return Dictionary of cache data
 */
-(NSMutableDictionary *)getDictFromCache:(int )days WithIdentifier:(NSString *)cacheid;

/**
 Get Cache data from app
 
 @param minutes minute count
 @param cacheid cache id
 @return List of cache data
 */
-(NSArray *)getFromCacheWithMinute:(int )minutes WithIdentifier:(NSString *)cacheid;

/**
 add Data in cahce
 
 @param data list of data
 @param cacheid cache refrence
 @return True/False
 */
-(BOOL)putInCache:(NSArray *)data WithIdentifier:(NSString *)cacheid;

/**
 Add data in Cache
 
 @param data Data Dictionary
 @param cacheid cache id
 @return True/False
 */
-(BOOL)putDictInCache:(NSMutableDictionary *)data WithIdentifier:(NSString *)cacheid;

/**
 Check cache expired
 
 @param days day count
 @param inDirectory location of cache file
 @param cacheid cache refrence
 @return True/False
 */
-(BOOL)isCacheExpired:(int )days searchIn:(NSSearchPathDirectory) inDirectory WithIdentifier:(NSString *)cacheid;

/**
 Delete From cache file
 
 @param cacheid Cache id
 @return True/False
 */
-(BOOL)removeFromCache:(NSString *)cacheid;

/**
 Delete All from cache file
 
 @param cacheRef Cache id
 */
-(void)cleanCache:(NSString *)cacheRef;
@end
