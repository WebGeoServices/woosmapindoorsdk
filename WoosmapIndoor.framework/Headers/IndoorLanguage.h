//
//  IndoorLanguage.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>

@interface IndoorLanguage : NSObject

/**
 Language service
 
 @return return language service
 */
+ (IndoorLanguage *)instance;

/**
 set local for language service
 
 @param mapid mapref
 @param locallanguage lnaguage local
 */
-(void)setNewLocal:(int)mapid Local:(NSString *)locallanguage;

/**
 Translate word into langiage
 
 @param word word in english
 @return in local language
 */
-(NSString *)translate:(NSString *)word;

@end
