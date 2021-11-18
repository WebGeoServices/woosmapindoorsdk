//
//  Preferences.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>
extern NSString *const PREF_DEVICEID;
extern NSString *const PREF_MACID;
extern NSString *const PREF_SETTINGMACID;
extern NSString *const PREF_NAME;
extern NSString *const PREF_EMAIL;
extern NSString *const PREF_PHONE;
extern NSString *const PREF_ORG;
extern NSString *const PREF_DESIGNATION;
extern NSString *const PREF_MAPID;
extern NSString *const PREF_LOG_LEVEL;
extern NSString *const PREF_PASSCODE;
extern NSString *const PREF_REGISTERID;
extern NSString *const PREF_BIRTH;
extern NSString *const PREF_GENDER;
extern NSString *const PREF_ACCESSTOKEN;
extern NSString *const PREF_BUDDYOPTIN;
extern NSString *const PREF_CACHEVERSION;
extern NSString *const PREF_COUNTRYCODE;

@interface Preferences : NSObject


/**
 To get value of the prefernce

 @param key The name of the preference
 @return Returns the string value of preference
 */
+(NSString *)getPreferences : (NSString *)key;

/**
 To set preferences

 @param key The name of the preference
 @param preferencesValue The value of the preference
 @return Returns whether prefernce is set or not
 */
+(BOOL)setPreferences : (NSString *)key forValue : (NSString *)preferencesValue;

/**
 To set attributes

 @param key The name of the attribute
 @param preferencesValue The value of the attribute
 @return Returns whether attribute is set or not
 */
+(BOOL)setAttribute : (NSString *)key forValue : (NSDictionary *)preferencesValue;

/**
 To get user name

 @return Returns name of user
 */
+(NSString *)getOwnerName;

/**
 To get user email address
 
 @return Returns email id of user
 */
+(NSString *)getEmail;

/**
 To get user phone number
 
 @return Returns phone number of user
 */
+(NSString *)getPhone;

/**
 To get an organisation name
 
 @return Returns an organisation name
 */
+(NSString *)getOrg;

/**
 To get an user's designation
 
 @return Returns designation of user
 */
+(NSString *)getTitle;

/**
 To get notification id
 
 @return Returns an id of notification
 */
+ (NSString *) getNotificationID;

/**
 To get Mac address of device
 
 @return Returns device's Mac address
 */
+ (NSString *) getMyMacAddress;

/**
 To get Mac address of device
 
 @return Returns device's Mac address
 */
+ (NSString *) getSettingMacAddress;

/**
 To get venue id
 
 @return Returns an id of the venue
 */
+ (NSString *) getMap;

/**
 To get user's passcode for buddy finder
 
 @return Returns passcode of user
 */
+ (NSString *) getPassCode;

/**
 To get user name
 
 @return Returns name of user
 */
+ (NSInteger) getDiagnosticLevel;

/**
 To get an unique id of user
 
 @return Returns user's id
 */
+ (NSInteger) getRegisterID;

/**
 To get date of birth of user
 
 @return Returns user birth date
 */
+ (NSString *)getBirth;

/**
 To get gender of user
 
 @return Returns user's gender
 */
+ (NSString *)getGender;

/**
 To get user name
 
 @return Returns name of user
 */
+ (NSString *)getAccessToken;

/**
 To get wheter buddy finder is on or off
 
 @return Returns buddy finder preference YES/NO
 */
+ (BOOL) isBuddy_OptIn;

/**
 To get cache vesion
 
 @return Returns version of cache
 */
+ (NSInteger) getCacheVersion;

/**
 To get country code
 
 @return Returns country code
 */
+ (NSString *) getCountryCode;

@end
