//
//  RouteTag.h
//  Woosmap Indoor

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Object store information about avalible route option with venue
@interface RouteTag : NSObject

/// The name of the tag
@property (nonatomic,readwrite) NSString *name;

/// The description of the routing tag
@property (nonatomic,readwrite) NSString *tagDescription;

/// The unique code of the routing tag
@property (nonatomic,readwrite) NSString *code;


/// Instance type
+ (instancetype)init;

/// Create object with code
/// @param code  Route Option code
- (instancetype)init:(NSString *)code;

/// Created new RouteTag object from Dictionary schema
/// @param copy  detail of tag object
-(void)objectFromDictionary:(NSDictionary *)copy;
@end

NS_ASSUME_NONNULL_END
