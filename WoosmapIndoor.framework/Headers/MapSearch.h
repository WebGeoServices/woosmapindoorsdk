/*!
  MapSearch.h
  Woosmap Indoor
*/

#import <Foundation/Foundation.h>
#define ToRadian(x) ((x) * M_PI/180)
#define ToDegrees(x) ((x) * 180/M_PI)
@class MapSearch;
/**
 *  Search types for MapSearch
 */
typedef NS_ENUM(NSInteger, SearchType) {
    /**
     *  Use for POI Search
     */
    Search_POI,
    /**
     *  Use for Amenities Search
     */
    Search_Amenity
};
/**
 *  Delegates for the events on MapSearch object.
 */
@protocol MapSearchDelegate<NSObject>

@optional
/**
 *  Called when the user starts typing in the search box.
 *
 *  @param sender An instance of MapSearch class.
 */
- (void)searchDidStartLoad:(MapSearch *)sender;
/**
 *  Called when the server returns the search results response.
 *
 *  @param sender   An instance of MapSearch class.
 *  @param response NSArray of search results to be displayed.
 */
- (void)searchDidFinishLoad:(MapSearch *)sender result:(NSArray *)response;

@end
/**
 *  This is the class used for Search operations in the Woosmap Indoor SDK.
 */
@interface MapSearch : NSObject
 @property(nonatomic,weak) id <MapSearchDelegate> mapSearchDelegate;

/**
 *  This use for filter search result using group tag.
 */
@property (nonatomic,strong) NSString *filterTag;

/**
 *  Initializes search API's
 *
 *  @param searchFor Enum of SearchType (Search_POI/Search_Amenity)
 *
 *  @return Instance of MapSearch class.
 */
-(id)init:(SearchType)searchFor;


/**
 Initializes search API's

 @param searchFor SearchType Search_POI/Search_Amenity
 @param show heighlight area
 @return an instance of MapSearch class
 */
-(id)init:(SearchType)searchFor showArea:(BOOL)show;

/**
 Initializes search API's

 @param searchFor searchFor SearchType Search_POI/Search_Amenity
 @param map ID of the map
 @return an instance of MapSearch class
 */
-(id)init:(SearchType)searchFor withMapid:(int)map;


/**
 Initializes search API's

 @param searchFor searchFor searchFor SearchType Search_POI/Search_Amenity
 @param map ID of the map
 @return an instance of MapSearch class
 */
-(id)init:(SearchType)searchFor withMapCode:(NSString *)map;

/**
 *  Performs the search operation by calling the relevant Search API's.
 *
 *  @param text The text/term to search for.
 */
-(void)searching:(NSString *)text;

/**
 Performs the search operation by calling the relevant Search API's.

 @param text text The text/term to search for
 @param result result of search
 */
-(void)searching:(NSString *)text completion:(void (^)(NSArray *searchResult, NSError *error))result;

@end
