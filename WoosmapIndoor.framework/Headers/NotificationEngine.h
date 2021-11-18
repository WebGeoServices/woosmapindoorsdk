//
//  NotificationEngine.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Notification Engine Protocol
 */
@protocol NotificationEngineProtocol <NSObject>

@optional

/**
 call when Notification receive

 @param note Notification data
 */
- (void) InMapsNotification: (NSNotification *) note;
@end

@interface NotificationEngine : NSObject{
}

/**
 Share instance for Notification service

 @return Notification service
 */
+ (NotificationEngine *)sharedInstance;

/**
 Create new notification service

 @param launchOptions App launch option
 @param inAppWindow App instance
 */
-(void)StartNotificationService:(NSDictionary *)launchOptions inApp:(UIWindow *)inAppWindow;

/**
 Set new REgister device token

 @param deviceToken  notification id
 */
-(void)registerWithToken:(NSData*)deviceToken;

/**
 Handle notification which receive by APNS

 @param userInfo Notification detail
 */
- (void)ShowNotification:(NSDictionary*)userInfo;


/**
 Handle notification in background

 @param userInfo Notification info
 */
- (void)ShowBackgroundNotification:(NSDictionary*)userInfo;

/**
 Setting new maca address

 @param newMac Mac address
 @param map map refrence
 */
-(void)setNewMacAddress:(NSString *)newMac andMapID:(NSInteger)map;


/**
 Register New User
 */
-(void)registerUser;

/**
 Register User attribute

 @param extraFields User Attribute
 */
-(void)registerMoreAttribute:(NSDictionary *)extraFields;
@end
