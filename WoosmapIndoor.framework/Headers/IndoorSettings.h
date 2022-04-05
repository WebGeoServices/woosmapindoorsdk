//
//  IndoorSettings.h
//  Woosmap Indoor
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <GoogleMaps/GoogleMaps.h>
#import "IndoorMapObject.h"
#import "PathFormatter.h"
#import "RouteTag.h"
/**
 Internal map Information
 */
@interface IndoorSettings : NSObject

/**
 Internal map properties
 
 @return
 */
+ (nonnull IndoorSettings *)instance;

/**
 New Map instance
 
 @param details Map configurations dictionary
 @return
 */
+(nonnull instancetype )createNewMap:(nonnull NSDictionary *)details;

/**
 Floor name for map
 
 @param ioFloor internal floor
 @return
 */
-(nonnull NSString *)FloorName:(int)ioFloor;

/**
 internal map
 
 @return
 */
-(nonnull NSString *)ioMapID;

/**
 Internal Floor plan id for Indoor atlas
 
 @param ioFloor internal floor plan
 @return
 */
-(nullable NSString *)IAFloorPlanID:(int)ioFloor;

/**
 Indoor atlas APi Key
 
 @return key
 */
-(nullable NSString *)IAAPIapikey;

/**
 Indoor atlas api key secret
 
 @return secret
 */
-(nullable NSString *)IAAPIapiSecret;

/**
 Convert to virtual coordinate
 
 @param location gps coordinate
 @return
 */
-(CLLocationCoordinate2D)virtualCoordinate:(CGIndoorMapPoint)location;

/**
 Convert to gps to virtual coordinate
 
 @param location virtual coordinate
 @return 
 */
-(CLLocationCoordinate2D)geoCoordinateFromVirtual:(CGIndoorMapPoint)location;

/**
 Resizing facor
 
 @return
 */
-(int)getMapFactor;

/**
 To get the categories data for venue
 
 @return An array of categories
 */
-(nonnull NSArray *)venueCategories;

/**
 To set stores information
 
 @param stores An array of stores
 */
-(void)setStoreCount:(nonnull NSArray *)stores;

/**
 To get name of venue
 
 @return Returns venue name
 */
-(nonnull NSString *)mapname;

/**
 To get category image name
 
 @param storeid An ID of store
 @return Store category image name
 */
-(nullable NSString *)storeCategoryIcon:(nonnull NSString *)storeid;

/**
 To get levels information
 
 @return An array of levels
 */
-(nonnull NSArray *)LevelInformation;

/**
 To get ID's of the floors
 
 @return An array of loor ID's
 */
-(nonnull NSArray *)FloorListIDs;

/**
 To get map center coordinates with level
 
 @return The center coordinates of map with level
 */
-(CGIndoorMapPoint)mapCenterPoint;

/**
 To get initial zoom loevel of map
 
 @return THe initial zoom level
 */
-(float) mapInitialZoom;

/**
 To get store labels data
 
 @return An array of store labels
 */
-(nonnull NSArray *)StoreLables;

/**
 To set store labels
 
 @param listLables An array of stores
 */
-(void)SetStoreLables:(nonnull NSArray *)listLables;

/**
 To get Mapbox floor id for floor
 
 @param ioFloor floor number
 @return Mapbox floor ID
 */
-(nonnull NSString *)MapboxFloorPlanID:(int)ioFloor;

/**
 To get Mapbox floor id for floor
 
 @param ioFloor floor number
 @param buildingid building number
 @return Mapbox floor ID
 */
-(nonnull NSString *)MapboxFloorPlanID:(int)ioFloor forBuilding:(nonnull NSString *) buildingid;


/**
 To fetch Mapbox token
 
 @return Mapbox token
 */
-(nonnull NSString *)MapboxMapToken;

/**
 To get area bounds for venue
 
 @return area bounds
 */
-(nonnull GMSCoordinateBounds *)getAreaBound;

/**
 To get area bounds for venue
 
 @return area path
 */
-(nonnull GMSPath *)getAreaRect;

/**
 To get maximum map zoom level
 
 @return zoom level
 */
-(float)maxMapZoom;

/**
 To get minimaum map zoom level
 
 @return zoom level
 */
-(float)minMapZoom;

/**
 TO get leash distance
 
 @return leash distance
 */
-(int)BackToLeashDistance;

/**
 The value of path diversion
 
 @return path diversion
 */
-(int)maxPathDiversion;

/**
 Extra setting
 
 @return Dictionary of settings
 */
-(nonnull NSDictionary *)extraSettings;

/**
 To get data of building according to user's location
 
 @param userLocation user coordinates with floor
 @return a dictionary of building
 */
-(nonnull NSDictionary *)getBuildingAtUserLocation:(CGIndoorMapPoint)userLocation;

/**
 To get external floor ID
 
 @param ioFloor Floor number
 @return an External floor ID
 */
-(int)IAExternalFloorID:(nonnull NSString *)ioFloor;

/**
 To get data of building
 
 @return An array of building
 */
-(nonnull NSArray *)buildingList;

/**
 To
 
 @return BOOL value
 */
-(BOOL) useMapBoxMap;


/**
 Should display google map bellow indoormap or not
 
 @return true/false
 */
-(BOOL)isLoadGoogleBasemap;

/**
 Display outline for floor
 
 @param levelCode Level currently display
 @param mapview map view on which area draw
 */
-(void)showOutlineForLevel:(int)levelCode onMap:(nonnull GMSMapView *)mapview;

/**
 Capture Default Floor which indoor map to display
 
 @return Level Nimber
 */
-(int)initializeWithDefaultFloor;

/**
 Logo location
 
 @return Position topleft, topright, bottomleft, bottomright
 */
-(nonnull NSString *)defaultLogoLocation;

/**
 Promotion Snooze Time
 
 @return time in minutes
 */
-(int)getPromotionSnoozeTime;//In minutes

/**
 Re-Route CoolDown Time
 
 @return Time in seconds
 */
-(int)getReRouteCoolDownTime;//In Seconds

-(int)getAutoCenteringTime;//In Seconds

/**
 URL From map image to be fetch
 
 @return Tile URL
 */
-(nonnull NSString *)TileServerURL;//Tile server URL

/**
 Rotate map according true heading
 
 @return True/False
 */
-(BOOL)shouldRotateMapWithHeading;

/**
 Rotate map to true north for user location
 
 @return True/False
 */
-(BOOL)shouldRotateMapInitially;

/*
 Allow Hybrid map to render on screen
 
 @return True/False
 */
-(BOOL)allowHybridMap;

/*
 Re-route buffer count
 
 @return number of
 */
-(int)maxReroutePathDiversionCount;

/*
 Support Floor Change
 
 @return Yes/No
 */
-(BOOL)supportFloorChange;


/**
 Use logic for floor Detection
 
 @return Yes/No
 */
-(BOOL)applyFloorDetection;

/**
 Use Senser for Heading
 
 @return Yes/No
 */
-(BOOL)useInbuildMagneticsensorForHeading;
/**
 Show Destination event reached
 
 @return X meters
 */
-(int)getDestinationBuffer;

/**
 Color of text on map
 
 @return color value
 */
-(nonnull UIColor *)textColorFromServer;

/**
 Get Walking speed for venue
 
 @return X minute/meters
 */
-(double)getWalkingSpeedPerMeter;
/**
 Get Map orientation
 
 @return X angle againt north direction (in degree)
 */

-(float) mapInitialRotation;

/**
 Get Map Tilt position
 
 @return X tilt angle (in degree)
 */
-(float) mapInitialTilt;
/**
 Use Reroute by Heading
 
 @return Yes/No
 */
-(bool)useRerouteUsingBearing;

/**
 Image For Multipoint POI Item
 
 @return Image nameOnserver
 */
-(NSString * _Nullable)multiPointNavImage;

/**
 Return font family for map
 
 @return Font Font name on server
 */
-(NSString * _Nonnull)mapFont;
/**
 Return font family for map
 
 @return Font Font name on server
 */
-(PathFormatter * _Nonnull)pathFormat;

-(float)lableStrokeWidth;
/**
 Number of items in searching Multiple waypoint
 
 @return no of count
 */
-(int)multiPointNavLimit;

/// Path optimization at SDK End
-(float)dynamicSplitPath;

/// map rotation while navigation mode
-(BOOL)shouldRotateMapWithPathSegment;

/// Center map in navigation Mode
-(BOOL)enableAutoCenteringInNavMode;

/// Show Google map 3d buldings on map for external view
-(BOOL)show3DBuildings;

///Listing all route option with given venue
-(NSArray<RouteTag*> *_Nonnull)getRouteTags;

/**
 * Cleanup IndoorMap setting from memory
 */
-(void)clearMemory;
@end
