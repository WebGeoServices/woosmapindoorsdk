//
//  IndoorAPI.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Indoor API service
 */
@interface IndoorAPI : NSObject
/**
 *  Get Indoor API Object
 *
 *  @return API Object
 */
+ (instancetype)configuration;
/**
 *  Share Instance
 *
 *  @return API Object
 */
+ (instancetype)sharedInstance;

/**
 map ref

 @return mapid
 */
-(int)mapid;

/**
 language set for service

 @return language
 */
-(NSString *)language;

/**
 language for API service

 @param lang language ref
 */
-(void) setLanguage:(NSString *)lang;

/**
 Indoor API service

 @param mapid mapid
 @return
 */
- (instancetype)CreateInstance:(int)mapid;

/**
 Register new user

 @param request user detail
 @param response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)RegisterDevice:(NSDictionary *)request result:(void (^)(NSArray *posts, NSError *error))response;

/**
 list area on map

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getStoreList:(void (^)(NSArray *posts, NSError *error))response;

/**
 Area List With Category

 @param category category id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getStoreListWithCategory:(NSString *)category result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Get area list in category keyword

 @param category category
 @param q search
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getStoreListWithCategoryKeyword:(NSString *)category keyword:(NSString *)q result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Category list

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getCategory:(void (^)(NSArray *posts, NSError *error))response;

/**
 Search poi on server

 @param q search paramenter
 @param forLanguage language
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getSearch:(NSString *)q language:(NSString *)forLanguage result:(void (^)(NSArray *posts, NSError *error))response;
/**
 Search poi on server
 
 @param q search paramenter
 @param tag search group parameter
 @param forLanguage language
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getSearch:(NSString *)q tag:(NSString *)tag language:(NSString *)forLanguage result:(void (^)(NSArray *posts, NSError *error))response;

/**
 get movie list

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getMovieList:(void (^)(NSArray *posts, NSError *error))response;
/**
 *  Upload image of Profile
 *
 *  @param img image to be uploaded
 *  @param refno imge refrence number <UserID>
 */
-(void)uploadProfileImage:(UIImage *)img andRefNo:(NSString *)refno;

/**
 New buddy request

 @param buddyCode buddy code
 @param myid user id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)NewBuddyRequest:(NSString *)buddyCode user:(NSInteger)myid result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Accept buddy id

 @param buddyref buddy id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)acceptBuddyRequest:(NSString *)buddyref result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Reject buddy request

 @param buddyref buddy id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)rejectBuddyRequest:(NSString *)buddyref result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Active buddy id

 @param myid user id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getActiveMyBuddies:(NSInteger)myid result:(void (^)(NSArray *posts, NSError *error))response;

/**
 pending buddy list

 @param myid user id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getPendingMyBuddies:(NSInteger)myid result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Delete buddy request

 @param myid user id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)BuddiesDeleteRequest:(NSInteger)myid result:(void (^)(NSArray *posts, NSError *error))response;

/**
 REsend buddy request

 @param myid user id
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)BuddiesResendRequest:(NSInteger)myid result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Offer list for inapp offers

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)offerList:(void (^)(NSArray *posts, NSError *error))response;

/**
 GEneral post request

 @param param input
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)RequestApiCall:(NSDictionary *)param result:(void (^)(NSArray *posts, NSError *error))response;

/**
 Get Server message

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getServerMsg:(void (^)(NSArray *posts, NSError *error))response;

/**
 get language resource by given language

 @param mapRef maprefrence
 @param locallanguage local language
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getMapLanguage:(int)mapRef Local:(NSString *)locallanguage result:(void (^)(NSArray *posts, NSError *error))response;

/**
  List Restaurant sub categories

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getRestaurantList:(void (^)(NSArray *posts, NSError *error))response;

/**
  List Amenity sub categories

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getAmenitiesList:(void (^)(NSArray *posts, NSError *error))response;

/**
 List entertaintment sub categories

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getEntertainmentList:(void (^)(NSArray *posts, NSError *error))response;

/**
 List Area in Cuision caegory

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getCuisineCategory:(void (^)(NSArray *posts, NSError *error))response;

/**
 List area in entertaintment category

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getEntertaintmentCategory:(void (^)(NSArray *posts, NSError *error))response;

/**
 Search for Amenities

 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)getAmenitiesCategory:(void (^)(NSArray *posts, NSError *error))response;

/**
 Register user with more information

 @param extraFields User properties set in key/value pair
 @param userref User ID collected by App
 @param response response callback function return result, In case of error it will return error object to handle it on App end
 */
-(void)registerMoreAttribute:(NSDictionary *)extraFields withUser:(NSInteger) userref result:(void (^)(NSArray *posts, NSError *error))response;

@end
