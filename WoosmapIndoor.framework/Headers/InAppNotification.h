//
//  InAppNotification.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>

@interface InAppNotification : NSObject{
   
}
@property (readonly) BOOL reloadFromDB;
@property (nonatomic,retain) NSString *notificationid;
@property (nonatomic,retain) NSString *message;
@property (nonatomic,retain) NSDate *notificationDate;


+(NSMutableArray *)getlist;

/**
 To get notification data

 @return notification data
 */
-(NSMutableDictionary *)getnotificationDetails;
-(id)init :(NSString *)ptr;
-(void)getDetails;
-(BOOL)update;
-(BOOL)deleteInfo;
@end
