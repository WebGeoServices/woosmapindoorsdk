/*!
*  @header IndoorMap.h
*  Woosmap Indoor
*/

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "IndoorMapObject.h"
#import "PathFormatter.h"
#import "TrackingMarker.h"
#import "TrackingAreaMarker.h"
#import <GoogleMaps/GoogleMaps.h>
#import "Stopover.h"
#import "RouteTag.h"

/**
 *  Navigation Modes
 */
typedef NS_ENUM(NSInteger,NavigationMode) {
    /**
     *  Non-Navigation mode
     */
    NavigationMode_None,
    /**
     *  Navigation Preview mode
     */
    NavigationMode_Preview,
    /**
     * Navigation with turn by turn instructions mode.
     */
    NavigationMode_TurnByTurn,
};

/**
 *  Map View Modes
 */
typedef NS_ENUM(NSInteger,MapViewMode) {
    /**
     *  ViewMode ViewMode Unknown
     */
    MapViewMode_Unknown,
    /**
     *  ViewMode Center Preview
     */
    MapViewMode_CenterPreview,
    /**
     * Navigation with turn by turn instructions mode.
     */
    MapViewMode_HeadingPreview,
};

/**
 Type Elevator, Escalator,Staircase
 */
typedef NS_ENUM(NSInteger,FloorConntectedBy) {
    /**
     *  Unknown mode
     */
    FloorConntectedBy_Unknown,
    /**
     *  Elevator
     */
    FloorConntectedBy_Elevator,
    /**
     *  Escalator
     */
    FloorConntectedBy_Escalator,
    /**
     * Staircase
     */
    FloorConntectedBy_Staircase,
};


/**
 *  Destination Direction
 */
typedef NS_ENUM(NSInteger,DestinationDirection) {
    /**
     *  Non-Navigation mode
     */
    Destination_Left,
    /**
     *  Navigation Preview mode
     */
    Destination_Right,
    /**
     * Navigation with turn by turn instructions mode.
     */
     Destination_Front,
};


/**
 Floor Change by event
 */
typedef NS_ENUM(NSInteger,FloorChangeReason) {
    /**
     *  by user
     */
    changedby_Manual,
    /**
     *  by location provider
     */
    changedby_LocationProvider,
    /**
     *  by app internal
     */
    changedby_Programmatic,
};

/**
 *  Description
 *
 *  @param formatter descriptioncd
 *
 *  @return return value description
 */
typedef PathFormatter* _Nullable (^PathFormatterBlock)(PathFormatter * _Nullable formatter);
/**
 *  Delegates for the events on indoorMap object.
 */
@protocol IndoorMapDelegate<NSObject>

@optional

/**
 * Called after map loaded
 *
 * @param sender The mapview that was pressed
 * @deprecated use indoor: loaded: instead.
 */
-(void)IndoorMapLoaded:(nonnull id)sender __deprecated_msg("use indoor: loaded: instead.");

/**
 Called after map loaded on screen

 @param sender  the mapview that passed
 @param isLoaded true/false always return true
 */
-(void)indoor:(nonnull id)sender onLoaded:(BOOL)isLoaded;


/**
 Called when something wrong while fetching venue information

 @param sender the mapview that passed
 @param error error detail
 */
-(void)indoor:(nonnull id)sender onVenueError:(nonnull NSError *)error;

/**
 *  Called after a long-press gesture at a particular coordinate.
 *
 *  @param mapView    The mapview that was pressed.
 *  @param coordinate The location that was pressed.
 *  @param level      The current level/floor on the mapview where the long-press gesture was triggered.
 */
-(void)indoor:(nonnull id)mapView didLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate floor:(int)level;

/**
 *  Called after a tap gesture at a particular coordinate
 *
 *  @param mapView    The mapview that was tapped.
 *  @param coordinate The location that was tapped.
 *  @param level      The current level/floor on the mapview where the tap gesture was triggered.
 */
-(void)indoor:(nonnull id)mapView didTapAtCoordinate:(CLLocationCoordinate2D)coordinate floor:(int)level;
/**
 *  Called after the user location is found in a geo-fenced promo zone.
 *
 *  @param mapView The mapview where the user location is found.
 *  @param Zone    A dictionary of the geo-fenced zone.
 *  @param offers  An array of offers found in the geo-fenced promo zone.
 */
-(void)indoor:(nonnull id)mapView enterPromoZone:(nonnull NSDictionary *)Zone promotion:(nonnull NSArray *)offers;
/**
 *  Called after the user exits from a previously entered geo-fenced promo zone.
 *
 *  @param mapView The mapview where the user location is found.
 *  @param Zone    A dictionary of the geo-fenced zone from where the user made an exit.
 */
-(void)indoor:(nonnull id)mapView exitPromoZone:(nonnull NSDictionary *)Zone;
/**
 *  Called after the application desires to display route between two points.
 *
 *  @param mapView   The mapview where the route will be drawn.
 *  @param routeList An array of geojson objects
 */
-(void)indoor:(nonnull id)mapView route:(nonnull NSArray *)routeList;

/**
 Called when search route failed to get route

 @param mapView The mapview where the route will be drawn.
 @param routeList empty route list
 */
-(void)indoor:(nonnull id)mapView noRoute:(nonnull NSArray *)routeList;

/**
Called when search route function failed

@param mapView The mapview where the route will be drawn.
@param errorInfo Detail error description
*/
-(void)indoor:(nonnull id)mapView onNavigationError:(nonnull NSError *)errorInfo;

/**
 *  Called when user wants turn by turn instructions.
 *
 *  @param mapView   The mapview where the route for turn by turn is drawn.
 *  @param pathIndex The index of the area/section.
 *  @param routeInfo The area/section data
 */
-(void)indoor:(nonnull id)mapView instruction:(NSUInteger)pathIndex pathInfo:(nonnull NSDictionary *)routeInfo;

/**
  Called when user wants turn by turn instructions.

 @param mapView The mapview where the route for turn by turn is drawn.
 @param pathIndex The index of the area/section.
 @param routeInfo The area/section data
 @param isByUser Action trigger by User or internal.
 */
-(void)indoor:(nonnull id)mapView instruction:(NSUInteger)pathIndex pathInfo:(nonnull NSDictionary *)routeInfo triggerByUserInteaction:(BOOL)isByUser;


/**
 Group index change with path

 @param mapView the view
 @param newGroupIndex new group index
 @param oldGroupIndex old group index
 */
-(void)indoor:(nonnull id)mapView groupIndexChanged:(NSString *_Nullable)newGroupIndex from:(NSString *_Nullable)oldGroupIndex;

/**
 *  Called when a user is in navigation mode and moves away from the drawn route.
 *
 *  @param mapView    The mapview that caused the event to trigger.
 *  @param coordinate The current coordinates of the user's position.
 *  @param level      The level at which the user is currently present.
 */
-(void)indoor:(nonnull id)mapView reRouteWithLocation:(CLLocationCoordinate2D)coordinate floor:(int)level;


/**
 Called when navigation interupted by user

 @param mapView The mapview that caused the event to trigger
 @param coordinate True/false always return true
 */
-(void)indoor:(nonnull id)mapView navigationInterrupted:(BOOL)coordinate;

/**
 *  Called when change in floor is detected.
 *
 *  @param mapView The mapview that caused the event to trigger.
 *  @param level   The level of the floor change.
 */
-(void)indoor:(nonnull id)mapView onFloorChange:(int)level;


/**
 Called when change in floor is detected.

 @param mapView The mapview that caused the event to trigger.
 @param level The level of the floor change
 @param isByUser detect trigger by user or not
 */
-(void)indoor:(nonnull id)mapView onFloorChange:(int)level triggerByUserInteaction:(BOOL)isByUser;
/**
 *  Called after a double tap gesture is detected on floor selector.
 *
 *  @param mapView The map view where the double tap was detected
 *  @param level The level selected by the user.
 */
-(void)indoor:(nonnull id)mapView onFloorTapRepeat:(int)level;
/**
 *  Floor list of map
 *
 *  @param mapView The mapview that caused the event to trigger.
 *  @param levels The NSArray of levels for the venue.
 */
-(void)indoor:(nonnull id)mapView activeFloorList:(nonnull NSArray *)levels;

/**
 *  Called when the user location is detected in the geo-fenced area of an escalator or an elevator. Indicates floor change action.
 *
 *  @param mapView mapView The mapview where the user location is found.
 *  @param region  region A dictionary of the elevator/escalator found nearby the user's location.
 */
-(void)indoor:(nonnull id)mapView onEnterFloorChangeRegion:(nonnull NSDictionary *)region;
/**
 *  Called when the user moves out of the geo-fenced region for elevators/escalators.
 *
 *  @param mapView mapView The mapview where the user location is found.
 *  @param region  region A dictionary of the elevator/escalator from where the user has made an exit.
 */
-(void)indoor:(nonnull id)mapView onExitFloorChangeRegion:(NSDictionary *_Nullable)region;


/**
 *  Called when the user arrives at the destination in navigation mode.
 *
 *  @param mapView The mapview
 *  @param navigationend YES if user is arriving near the destination.
 */
-(void)indoor:(nonnull id)mapView endNavigation:(BOOL)navigationend;


/**
 Called when user explicit exit navigation

 @param mapView The mapview
 @param navigationState True when user exit navigation
 */
-(void)indoor:(nonnull id)mapView navigationExited:(BOOL)navigationState;


/**
 Called when the user arrives at the destination in navigation mode.

 @param mapView The mapview
 @param navigationState YES if user is arriving near the destination.
 @param atDirection direction of destination.
 */
-(void)indoor:(nonnull id)mapView endNavigation:(BOOL)navigationState destinationDirection:(DestinationDirection) atDirection;


/**
 *  Called when a marker is about to become selected and provides an optional
 *  custom info window to use for that marker if this method returns a UIView.
 *
 *  @param mapView mapView The mapview where the marker window will be shown.
 *  @param title   title The text to show on the marker window.
 *
 *  @return The custom info window for the specified marker, or nil for default
 */
-(nonnull UIView *)indoor:(nonnull id)mapView markerInfoWindow:(NSString *_Nullable)title;
/**
 *  Called when a tap gesture is detected on the marker's info window.
 *
 *  @param mapView The mapview where the marker is shown.
 *  @param markerDetail The marker's user data.
 */
- (void) indoor:(nonnull id)mapView didTapInfoWindowOfMarker:(nonnull NSDictionary *)markerDetail;

/**
 *  Description
 *
 *  @param mapView   mapView description
 *  @param zoomlevel zoomlevel description
 */
-(void) indoor:(nonnull id)mapView onMapAtIdlePostion:(float)zoomlevel;

/**
 *  Description
 *
 *  @param mapView   mapView description
 *  @param zoomlevel zoomlevel description
 */
-(void) indoor:(nonnull id)mapView onMapSlide:(float)zoomlevel;



/**
 Called when building changed

 @param mapView mapView description
 @param levelList List of levels in building
 @param heightList List of height in building for each levels
 @param name building name
 */
-(void) indoor:(nonnull id)mapView buildingChange:(NSArray *_Nullable)levelList heights:(NSArray *_Nullable)heightList building:(NSString *_Nullable)name;


/**
 Called when building changed

 @param mapView The mapview where build changed
 @param buildinginfo more information about building
 */
-(void) indoor:(nonnull id)mapView onBuildingViewChange:(NSDictionary *_Nullable)buildinginfo;

/**
 Showing labels on map

 @param mapView The mapview where lables renders
 @param iconImage icon of lables
 @param areaName text on labels
 @param baseString english version of label
 @return True/False
 */
-(BOOL) indoor:(nonnull id)mapView showTextWithIcon:(UIImage *_Nullable*_Nullable)iconImage andText:(NSString *_Nullable*_Nullable)areaName basetext:(NSString *_Nullable)baseString;


/**
 Showing labels on map

 @param mapView The mapview where lables renders
 @param imageurl external image URL for label
 @param areaName Name of  labels
 @return True/False
 */
-(UIView *_Nullable) indoor:(nonnull id)mapView customizeAreaName:(NSString *_Nullable)imageurl andText:(NSString *_Nullable)areaName;


/**
 Customize POI pin marker

 @param mapview The mapview where pin renders
 @param imgPin Image of pin from SDK
 @return UIView to render for marker
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizePOIPin:(UIImage *_Nullable)imgPin;


/**
 Customize start marker

 @param mapview The mapview where start marker render
 @param imgPin image from SDK
 @return customize view for start marker
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizeStartMarker:(UIImage *_Nullable)imgPin;

/**
 Customize end marker

 @param mapview The mapview where end marker render
 @param imgPin image from SDK
 @return customize view for end marker
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizeEndMarker:(UIImage *_Nullable)imgPin;

/**
 Customize level changed marker

 @param mapview The mapview where level marker render
 @param imgPin image from SDK
 @param up Moving up direction
 @return View to display on map
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizeLevelChangedMarker:(UIImage *_Nullable)imgPin movingUp:(BOOL)up;

/**
 Customize level changed marker

 @param mapview The mapview where level marker render
 @param imgPin image from SDK
 @param floorChangeMode floor change Using mode
 @param up Moving up direction
 @return View to display on map
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizeLevelChangedMarker:(UIImage *_Nullable)imgPin mode:(FloorConntectedBy)floorChangeMode movingUp:(BOOL)up;

/**
 Customize level changed marker

 @param mapview The mapview where level marker render
 @param imgPin image from SDK
 @param up Moving up direction
 @param nearStart  atstart point
 @return View to display on map
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizeLevelChangedMarker:(UIImage *_Nullable)imgPin movingUp:(BOOL)up atStart:(BOOL)nearStart;

/**
 Anchor point where marker render default(.0,.5)

 @param mapview The mapview where level marker render
 @param refAnchor SDK marker point
 @return Changed marker point
 */
-(CGPoint)indoor:(nonnull id)mapview onLevelChangedMarkerAnchor:(CGPoint)refAnchor;

/**
 Customize building anchor

 @param mapview The mapview where level marker render
 @param imgPin image from SDK
 @param buildingref building number
 @return view of building method
 */
-(UIView *_Nullable)indoor:(nonnull id)mapview customizeBuildingChangedMarker:(UIImage *_Nullable)imgPin building:(NSString *_Nullable)buildingref;

/**
 Customize building anchor

 @param mapview The mapview where level marker render
 @param refAnchor anchore point set by sdk
 @return new Anchor point
 */
-(CGPoint)indoor:(nonnull id)mapview buildingChangedMarkerAnchor:(CGPoint)refAnchor;

/**
 Called when poi searched on map

 @param mapView The mapview where poi marker render
 @param poiinfo Detail of POI
 @param error return error when poi not found else nil
 */
-(void)indoor:(nonnull id)mapView onPOIFound:(NSDictionary *_Nullable)poiinfo onFailed:(NSError *_Nullable)error;


/**
 * Called before the camera on the map changes, either due to a gesture, animation (e.g., by a user
 * tapping on the "My Location" button) or by being updated explicitly via the camera or a
 * zero-length animation on layer.
 *
 * @param mapView Google map Instance
 * @param gesture If YES, this is occuring due to a user gesture.
 */
- (void)indoor:(nonnull GMSMapView *)mapView willMove:(BOOL)gesture;

/**
 * Called repeatedly during any animations or gestures on the map (or once, if the camera is
 * explicitly set). This may not be called for all intermediate camera positions. It is always
 * called for the final position of an animation or gesture.
 *
 * @param mapView Google map Instance
 * @param position Center location on map
 */
- (void)indoor:(nonnull GMSMapView *)mapView didChangeCameraPosition:(nonnull GMSCameraPosition * )position;

/**
 Called When map  view mode changed by User
 @param mapView map
 @param previewMode View mode Unknown/Center/heading
 */
- (void)indoor:(nonnull id)mapView didChangeMapMode:(MapViewMode)previewMode;


/**
 Apply jump logic and handle jump supress event

 @param mapView UI Map
 @param jumppoint location point for false reading
 @param jumpdistance distance of false reading
 */
- (void)indoor:(nonnull id)mapView jumpsupress:(CGIndoorMapPoint)jumppoint atdistance:(double)jumpdistance;

/**
 Area info for search poi

 @param mapview map view
 @param poiinfo more information about poi defined
 */
-(void)indoor:(nonnull id)mapview onSearchedPOISelected:(nullable NSDictionary *)poiinfo;

/**
 called if user position changed while navigation node
 
 @param mapview map view
 @param navigationStatusUpdated more information Navigation  time remaining in seconds, Distance to be covered in meters, walking speed
 */
-(void) indoor:(nonnull id)mapview onNavigationStatusUpdated:(nonnull NSDictionary *)navigationStatusUpdated;

@end
/**
 * This is the main class of Woosmap Indoor SDK for IOS and is the entry point for all the methods related to maps.
 */
@interface IndoorMap : UIViewController{
}
//Properties
/**
 *  Sets the VenueID for the map.
 */
@property (nonatomic,retain, nullable) NSString *VenueID;


/**
 Set Venue code for the map
 */
@property (nonatomic,retain, nullable) NSString *VenueCode;

/**
 *  Sets the default floor to be shown when the map loads.
 */
@property (nonatomic,readwrite) int floorNumber;


/**
 Default floor for map
 */
@property (nonatomic,readonly) int defaultFloorNumber;

/**
 * Floor Number Index
 */
@property (nonatomic,readonly) int floorNumberIndex;
/**
 * Active Building Ref set from APP
 */
@property (nonatomic,retain, nullable) NSString * ActiveBuildingID;

/**
 *  Controls whether user can abandon navigation during navigation mode.
 */

@property (nonatomic,readwrite) BOOL allowUserToInterruptNavigation;
/**
 *  Highlight store on navagation mode default=NO
 */
@property (nonatomic,readwrite) BOOL showAreaDuringNavigation;

/**
 *  Sets Style to map (add same name of JSON file in resource bundle and set only filename here without extension).
 */
@property (nonatomic,retain, nullable) NSString *mapStyle;

/**
 *  Gets the current Navigation mode. default=NavigationMode_None
 */
@property (nonatomic,readonly,  getter = getCurrentMapMode) NavigationMode CurrentMapMode;
/**
 *  IndoorMapDelegate delegate
 */
@property(weak,nullable) id <IndoorMapDelegate> mapdelegate;
/**
 *  S Navigation  path
 */
@property (copy) PathFormatterBlock _Nullable pathOptions;
/**
 *  Controls whether the mapview's inbuilt floor selector is to be shown. Set NO if the application wants to create custom floor selector.
 */
@property (nonatomic,readwrite) BOOL enableFloorSelector;


/**
 *  Show/Hide map provider logo on map, Default show
 */
@property (nonatomic,readwrite) BOOL hideMapProvider;


/**
 Text color of label to render on map
 */
@property(nonatomic,retain,nullable) UIColor * textColor;

/**
 Rotate map and keep user location pointing to upwoard only Default=false
 */
@property (nonatomic,readwrite) BOOL rotateMapWithNorthHeading;

/**
 * Font Use on map
 */
@property (nonatomic,retain, nullable) NSString *fontFamily;

/**
 * HighlightStrokeWidth for lable render on map
 */
@property (nonatomic,readwrite) float labelHighlightStrokeWidth;


@property (nonatomic,assign) UIEdgeInsets logoPadding;

/**
 * This property control to display area lables on map during POI navigation
 */
@property (nonatomic,readwrite) BOOL displayPOIWithStopOverNavigation;

/**
 * This property control to Navigation mode handicap/non handicap
 */
@property (nonatomic,readwrite) BOOL preferaccessibility;

/**
 * Returns/Set the list of routing tags associated for the venue.
 */
@property (nonatomic,readwrite) NSArray<RouteTag*> *_Nonnull routeTags;

/**
 *  Manage visibility of arrow head on last step of navigation path
 */
@property (nonatomic, readwrite) BOOL hideNavigationHeadMarkerOnLastStep;


/**
 *  Sets the navigation mode.
 *
 *  @param mode Navigation mode type (NavigationMode_None,NavigationMode_Preview,NavigationMode_TurnByTurn)
 */
-(void)setNavigationMode:(NavigationMode)mode;
/**
 *  Gets the current Navigation Mode
 *
 *  @return Enumumeraton of type NavigationMode
 */
-(NavigationMode)getCurrentMapMode;


/**
 resize map according to container size
 */
-(void)autoFit;

/**
 *  Displays a marker on the mapview.
 *
 *  @param coordinate Location
 *  @param level      Floor Level
 *  @param Title      Title to display on the marker window
 */
-(void)showMarker:(CLLocationCoordinate2D)coordinate floor:(int)level title:(nullable NSString *)Title;

//User Location
/**
 *  Sets the user's current position (blue dot) on the map.
 *
 *  @param location The location of the user's current position.
 *  @param level    The floor level of the user's current position.
 */
-(void)setBlueDot:(nonnull CLLocation *)location onFloor:(int)level;

//User Location
/**
 *  Sets the user's current position (blue dot) on the map (internal perpose only) DO NOT USE THIS METHOD.
 *
 *  @param location The location of the user's current position.
 *  @param level    The floor level of the user's current position.
 */
-(void)setBlueDot_simulated:(nonnull CLLocation *)location onFloor:(int)level;

/**
 *  Gets the user's current location.
 *
 *  @return The latitude, longitude and floor level of the user's position.
 */
-(CGIndoorMapPoint)userLocation;
/**
 *  Returns the information of the tapped area on the map.
 *
 *  @param location Location that was tapped.
 *  @param level    floor level.
 *
 *  @return Returns a dictionary of the tapped area.
 */
-(nullable NSDictionary *) getTappedAreaInfo :(nonnull CLLocation *)location onFloor:(int)level;

/**
 *  Returns the information of the tapped area on the map.
 *
 *  @param location Location that was tapped.
 *  @param level    floor level.
 *  @param shouldSkip    Skip non business area.
 *
 *  @return Returns a dictionary of the tapped area.
 */
-(nullable NSDictionary *) getTappedAreaInfo :(nonnull CLLocation *)location onFloor:(int)level skipNonBusinessArea:(BOOL) shouldSkip;

/**
 *  Centers the blue dot in the map view.
 */
-(void)centerBlueDot;

//Routing
/**
 *  Finds the path from source to destination.
 *
 *  @param startPoint Source Coordinates
 *  @param endPoint   Destination Coordinates
 */
-(void)findRoute:(CGIndoorMapPoint)startPoint destination:(CGIndoorMapPoint)endPoint;

/**
 *  Finds the path from the source to the destination. It has an option to end the path at the entrance or inside the store. This choice is useful when a path needs to be ended at the entrance (in case of stores) or inside (in case of a POI located inside the store)
 *
 *  @param startPoint     Source Coordinates
 *  @param endPoint       Destination Coordinates
 *  @param cutAtEnterance BOOL flag
 */
-(void)findRoute:(CGIndoorMapPoint)startPoint destination:(CGIndoorMapPoint)endPoint uptoDoor:(BOOL)cutAtEnterance;

/**
*  Finds the path from the source to the destinations. It has an option to end the path at the entrance or inside the store. This choice is useful when a path needs to be ended at the entrance (in case of stores) or inside (in case of a POI located inside the store)
*
*  @param startPoint     Source Coordinates
*  @param endPoints       Destination Coordinates
*  @param endPoint             Location where path end at
*/
-(void)findRoute:(CGIndoorMapPoint)startPoint destinations:(NSArray<Stopover *> *_Nonnull)endPoints endAt:(CGIndoorMapPoint)endPoint;

/**
*  Finds the path from the source to the destinations. It has an option to end the path at the entrance or inside the store. This choice is useful when a path needs to be ended at the entrance (in case of stores) or inside (in case of a POI located inside the store)
*
*  @param startPoint     Source Coordinates
*  @param endPoints       Destination Coordinates
*/
-(void)findRoute:(CGIndoorMapPoint)startPoint destinations:(NSArray<Stopover *> *_Nonnull)endPoints;


/**
 *  Start the navigation when user's navigation mode is NavigationMode_TurnByTurn
 */
-(void)startNavigation;

/**
 *  Ends the navigation when user's navigation mode is NavigationMode_TurnByTurn
 */
-(void)exitNavigation;
/**
 *  Called when allowUserToInterruptNavigation is set to TRUE
 */
-(void)resumeNavigation;
//Instruction
/**
 *  Sets the corresponding instruction for navigation for the selected index.
 *
 *  @param instructionIndex The index for getting the instruction.
 */
-(void)stepToInstruction:(NSInteger)instructionIndex;
/**
 *  Sets the corresponding instruction for the next step.
 The user's navigation mode should be NavigationMode_TurnByTurn.
 Useful when user wants to scoll through a set of instructions.
 */
-(void)nextStepInstruction;
/**
 *  Sets the corresponding instruction for navigation for the previous step.
 The user's navigation mode should be NavigationMode_TurnByTurn.
 Useful when user wants to scoll through a set of instructions.
 */
-(void)previousStepInstruction;

//Re-Route New Path
/**
 Reroutes the path using new source location

 @param coordinate new starting point coordinates
 @param level new starting point level
 */
-(void)reRoute:(CLLocationCoordinate2D)coordinate floor:(int)level;

/**
 *  Suppress reroute event For 5 seconds
 */
-(void)suppressReRouteEvent;
//Floor Bar Methods
/**
 *  Changes the floor for the mapview.
 *
 *  @param floor The floor to be set.
 */
- (void) changeFloor:(int) floor;

/**
 Called this method if floor changed by location provider

 @param floor new Floor number
 */
- (void) changeFloorByLocationProvider:(int) floor;

/**
 Called this method if floor changed by event

 @param floor new Floor number
 @param byEvent by event
 */
- (void) changeFloor:(int) floor reason:(FloorChangeReason)byEvent;

/**
 *  Removes current markers from the mapview.
 */
-(void)mapCleanup;
//Mark Store on map
/**
 *  Finds an area/section on the map and displays a corresponding marker on the mapview.
 *
 *  @param coordinate The location of the area/section to be found.
 *  @param level      The level at which the area/secton is located.
 */
-(void)findAreaOnMap:(CLLocationCoordinate2D)coordinate floor:(int)level;
//Mark Poi on map
/**
 *  Finds an area (typically used to find a POI) and displays a corresponding marker on the mapview.
 *
 *  @param coordinate The location of the area (POI) to find.
 *  @param level      The level at which the area (POI) is located.
 *  @param text       The title of the area (POI) that will be dsplayed on the marker window.
 */
-(void)findAreaOnMap:(CLLocationCoordinate2D)coordinate floor:(int)level title:(nonnull NSString *)text;
/**
 *  Finds an area/section on the map and displays a corresponding marker on the mapview.
 *
 *  @param storeid The unique ID of the area/section to be found.
 *  @deprecated use findPOIOnMap: instead.
 */
-(void)findAreaOnMap:(nonnull NSString *)storeid __deprecated_msg("use findPOIOnMap: instead");

/**
* Finds an area/section on the map and displays a corresponding marker on the mapview.
*
* @param poiid The unique ID of the area/section to be found.
* @param result callback on result
*/
-(void)findPOIOnMap:(nonnull NSString *)poiid completion:(void (^_Nullable)(NSDictionary * _Nullable poiinfo, NSError * _Nullable error))result;

//Indoor Positioning Services
/**
 *  Gets the indoor positioning service's unique floor plan ID for the selected floor/level.
 *
 *  @param floor The floor for which the unique floor plan ID is returned
 *
 *  @return Returns the a unique floor plan ID.
 */
-(nullable NSString *) locationFloorRef:(int) floor;


/**
 External Floor refrence id

 @param floorref Floor number
 @return refrence number
 */
-(int) externalFloorForFloorRef:(nonnull NSString *) floorref;


/**
 *  To get extra map setting information.
 *
 *  @return cictionary of extra map settings.
 */
-(nonnull NSDictionary *)mapSettings;

/**
 *  Returns an array of unique floor plan IDs of the indoor positioning services.
 *
 *  @return NSArray of floor plan IDs
 */
-(nullable NSArray *)locationFloorRefID;

//Tracking
/**
 *  Adds a marker for buddy on the map.
 *
 *  @param tracking An instance of the class <<TrackingMarker>>
 */
-(void)addTrackingMarker:(nonnull TrackingMarker *)tracking;
/**
 *  Updates the POI marker position .
 *
 *  @param coordinate The current position of the POI.
 *  @param level      The level at which the POI is present.
 */
-(void)updateTrackingMarker:(CLLocationCoordinate2D)coordinate floor:(int)level;
/**
 *  Removes the POI marker
 */
-(void)removeTrackingMarker;
//Map Information
/**
 *  Gets the Area data available for a particular venue.
 *
 *  @return NSArray of area.
 */
-(nonnull NSArray *)allAreaInformation;

/**
 Center map at given location

 @param mp location point
 @param zoomlevel map zoom level
 */
-(void)centerMapWithLocation:(CGIndoorMapPoint)mp andZoom:(float)zoomlevel;

/**
 Center map at given location

 @param mp location point
 */
-(void)centerMapWithLocation:(CGIndoorMapPoint)mp;

/**
 *  Return true if user location visible on map
 *
 *  @return True/False
 */
-(BOOL)isBlueDotVisibleOnMap;

/**
 Return true if street view loaded

 @return True/False
 */
-(BOOL)isStreetViewLoaded;

/**
 Loads street view

 @param location The reference location for loading street view
 */
- (void)loadStreetView:(CLLocationCoordinate2D)location;
/**
 *  Removes street view.
 */
-(void)closeStreetView;

/**
 By given point findout nearest elevator/Escalator/Ramp/starecase

 @param refPoint ref point
 @return return modeof transport
 */
-(FloorConntectedBy)getModeOfTransport:(CGIndoorMapPoint)refPoint;

/**
 Get connecting point from given point

 @param refPoint refPoint
 @return new point on top/bottom level
 */
-(CGIndoorMapPoint)getModeOfTransportPointTo:(CGIndoorMapPoint)refPoint;


/**
 Get floor index in Array for current floor

 @param buldingarray List of level array
 @return return index value in list
 */
-(int)floorIndexInBuildingArray:(nonnull NSArray *)buldingarray;



/**
 *  Adds a Area on the map.
 *
 *  @param tracking An instance of the class <<TrackingAreaMarker>>
 */
-(void)addTrackingArea:(nonnull TrackingAreaMarker *)tracking;

/**
 *  Removes the drawn area
 */
-(void)removeAllTrackingArea;

/**
 Area coordinate for map bound

 @return return coordinate list of map borders
 */
-(nonnull NSArray *)mapAreaBounds;


/**
 Add Custome POI on map

 @param tracking POI Info
 */
-(void)addCustomePOI:(nonnull TrackingMarker *)tracking;

/**
 Clear Map : Remove Custome POI
 */
-(void)removeAllCustomePOI;

/**
 Show POI Marker on Map

 @param coordinate Lat/Lng
 @param level Level of map loaded
 @param Title Title on POI
 */
-(void)showPOIMarker:(CLLocationCoordinate2D)coordinate floor:(int)level title:(nullable NSString *)Title;


/**
 Show POI On Map

 @param poiinfo Detail of POI
 @param pinView Image of POI
 */
-(void)showPOIMarker:(nonnull NSDictionary *)poiinfo view:(nonnull UIView *)pinView;

/**
 Woosmap Indoor Secure API call

 @param apiname name of api
 @param apiparam api parameter
 @param response result
 */
-(void)indoorApiRequest:(nonnull NSString *)apiname andParameter:(nonnull NSDictionary *)apiparam result:(void (^_Nonnull)(NSArray * _Nullable apiresponse, NSError * _Nullable error))response;


/**
 Geting venue information

 @param VenueID VenueID
 @param response venueinfo
 */
+(void)getVenueInfo:(nonnull NSString *)VenueID result:(void (^_Nonnull)(IndoorMap * _Nullable venueinfo, NSError * _Nullable error))response;


/**
 Return nearest enterance point for POI While navigation
 @param destination search point
 @param start start Navigation Point
 @return nearest Enterance of poi
 */
-(CGIndoorMapPoint)calculateNearestEnterance:(CGIndoorMapPoint)destination from:(CGIndoorMapPoint)start;

/**
 Display path for given group index

 @param pathGroupIndex group index
 */
-(void)showPathForGroupIndex:(nonnull NSString *)pathGroupIndex;

/**
 Display poi search result on map
 
 @param searchresult List of poiids
 @param result  callback when poi found on map else return error object
 */
-(void)showSearchedPOIsOnMap:(nonnull NSArray *)searchresult completion:(void (^_Nonnull)(NSArray * _Nullable searchResult, NSError * _Nullable error))result;

/**
 Removing search result from map
 */
-(void)clearSearchedPOIs;

/**
 *  Gets the API key for the indoor positioning services.
 *
 *  @return The API key for the indoor positioning services.
 */
-(nonnull NSString *)IndoorServiceApikey;

/**
 *  Gets the API secret for the indoor positioning services.
 *
 *  @return The API secret for the indoor positioning services.
 */
-(nonnull NSString *)IndoorServiceApiSecret;
-(CGIndoorMapPoint)toExtendedCoordinate:(CGIndoorMapPoint)geoSystem;
-(CGIndoorMapPoint)toGEOCoordinate:(CGIndoorMapPoint)extendedSystem;

/**
 * Cleanup IndoorMap and GoogleMap
 */
-(void)stopRenderingMap;

    /**
     Check Location inside indoor venue

     @param latLng location to check
     @param result check is location with in boundry of indoor venue
     */
    -(void)isInsideVenue:(CLLocationCoordinate2D) latLng completion:(void (^_Nullable)(BOOL insideVenue, NSError * _Nullable error))result;


/// Compute sorted list of multiple stops
/// @param startPoint User location
/// @param endPoints List of Stops
/// @param endPoint Location where path end at
/// @param result  return sorted list of stops or error if any
-(void)sortStopovers:(CGIndoorMapPoint)startPoint destinations:(NSArray<Stopover *> *_Nonnull)endPoints endAt:(CGIndoorMapPoint)endPoint completion:(void (^_Nullable)(NSArray<Stopover *> * _Nullable sortedList, NSError * _Nullable error))result;

/// Compute sorted list of multiple stops
/// @param startPoint User location
/// @param endPoints List of Stops
/// @param result  return sorted list of stops or error if any
-(void)sortStopovers:(CGIndoorMapPoint)startPoint destinations:(NSArray<Stopover *> *_Nonnull)endPoints completion:(void (^_Nullable)(NSArray<Stopover *> * _Nullable sortedList, NSError * _Nullable error))result;

/// Customize navigation arrow
/// @param image new Arrow image
- (void)setNavigationHeadMarker:(UIImage *_Nullable)image;
@end

