
![woosmap](https://avatars.githubusercontent.com/u/1203240?s=200&v=4)
# Woosmap Indoor SDK

The Woosmap Indoor SDK for iOS (henceforth, “The SDK”) helps developers to create indoor location based applications.
The SDK has the following features:
1. Can be used with Google Indoor maps or Custom Maps.
2. Way-finding with turn by turn instructions.
3. Seamless floor transition with an option to use the in-built floor selector, or work with a user’s custom-made floor selector.
4. Search for Products or Places inside a venue.
5. Trigger proximity alerts at geo-fenced zones for offers or advertisements.

- [Woosmap Indoor SDK](#woosmap-indoor-sdk)
  - [Setup](#setup)
  - [Developer Guide](#developer-guide)
    - [Displaying your first map in the application](#displaying-your-first-map-in-the-application)
    - [Interacting with the map](#interacting-with-the-map)
    - [Finding a POI on the map](#finding-a-poi-on-the-map)
    - [Highlighting/Un-highlighting a POI on the map](#highlightingun-highlighting-a-poi-on-the-map)
    - [way-finding](#way-finding)
    - [Multi-stop way-finding](#multi-stop-way-finding)
    - [Customizing Stopover pins in multi-stop way-finding](#customizing-stopover-pins-in-multi-stop-way-finding)
    - [Tag based way-finding](#tag-based-way-finding)
    - [Displaying Route with turn by turn instructions](#displaying-route-with-turn-by-turn-instructions)
    - [Way finding and navigation callbacks](#way-finding-and-navigation-callbacks)
    - [Switching between multiple floors](#switching-between-multiple-floors)
    - [Detect user near Escalators/Elevators](#detect-user-near-escalatorselevators)
    - [Enabling Search](#enabling-search)
    - [Highlighting multiple POIs on the map](#highlighting-multiple-pois-on-the-map)
    - [Proximity alerts for geo-fenced zones](#proximity-alerts-for-geo-fenced-zones)
    - [Customizable elements](#customizable-elements)
  - [API reference](#api-reference)
  - [License](#license)

## Setup
This section covers the SDK integration.

**System Requirements**
- Xcode version 11.0 or later
- iOS 12.0 or later

**Creating an SDK Client project**
Start by creating a new, regular Xcode project using the “Single View Application” template. You can pick Swift or Objective–C. The SDK works seamlessly with both.

**Download the SDK using CocoaPods (recommended)**
1. Create a file called PodFile in your project directory.
2. Edit the Podfile and add WoosmapIndoor SDK dependencies. Here is an example of adding the dependency
        source 'https://github.com/Woosmap/woosmapindoor.git'
        use_frameworks!
        pod 'WoosmapIndoor'


3. Save the Podfile.
4. Open the terminal and go to the directory containing the Podfile.
5. Run the ```pod install``` command.
6. Close Xcode. Henceforth, use your project’s .xcworkspace file to open the project.

**Manual download and setup of the SDK (not recommended)**

If your project cannot use CocoaPods, you have the option to manually add the SDK to your project. To achieve this, download the current version of the SDK from <<GitHub https://github.com/Woosmap/woosmapindoorsdk.git>> and add it to your Xcode project.

**Add Google Maps SDK**

The Google Maps SDK needs to be added to render the maps in your project.
The procedure to add the Google Maps SDK through CocoaPods is similar to the steps for adding the WoosmapIndoor SDK described above.
Your PodFile should look like this:


      source 'https://github.com/CocoaPods/Specs.git'
      source 'https://github.com/Woosmap/woosmapindoor.git'
      use_frameworks!
      pod 'WoosmapIndoor'
      pod 'GoogleMaps'

**Authorization**
Every application using the WoosmapIndoor SDK needs to have a unique MapAPIKey to use its services. This key will be provided to you once the SDK is activated for your application. In your project’s appdelegate class, import the SDK by using ```import WoosmapIndoor```
Instantiate the WoosmapIndoorService instance in the AppDelegate’s ```application:didFinishLaunching``` method. See example below.
``` Objective-c
  WoosmapIndoorService.provideAPIKey("<<MapAPIKey>>", andGMSMapKey: "<<GoogleMapsKey>>")
```
## Developer Guide
### Displaying your first map in the application
The central component of the SDK is the ```IndoorMap``` class. Map events are delivered to its delegate, which should confirm to the ```IndoorMapDelegate``` protocol.

To load the venue map inside your application, follow the steps below:
- Import the framework header file using ```import WoosmapIndoor``` in your ViewController class file.
- Add the IndoorMapDelegate delegate.
- Create an instance of IndoorMap class and point the delegate to the receiver.
- Load the venue map using the following lines of code in your ViewController’s viewDidLoad method.

*Here is a code snippet:*
``` Objective-c
import WoosmapIndoor    
class ViewController: UIViewController,IndoorMapDelegate{
  var IndoorMap: IndoorMap = IndoorMap.init()
  override func viewDidLoad() {
      super.viewDidLoad()
      IndoorMap.view.frame = self.vwMap.bounds
      IndoorMap.mapdelegate = self
      IndoorMap.VenueID=<<VenueID>>; //The VenueID will be provided to you when you activate the SDK.
      IndoorMap.enableFloorSelector = false
      vwMap.addSubview(IndoorMap.view)
      IndoorMap.autoFit() //This will resize map for size of container
    }
```

###  Interacting with the map
The ```IndoorMapDelegate``` protocol exposes events to the client application for interacting with the map. They are as follows:

  - Long press on map
``` Objective-c
func indoor(_ mapView: Any, didLongPressAt coordinate: CLLocationCoordinate2D, floor level: Int32) {
    //coordinate consists of the location where there was a long press
    //level indicates the active floor where the long press event was called
}
```

- Single tap on map
``` Objective-c
func indoor(_ mapView: Any, didTapAt coordinate: CLLocationCoordinate2D, floor level: Int32){
//coordinate consists of the location user did a single tap on map
//level indicates the active floor where the single tap event was called
}
```

- Single tap on marker window
``` Objective-c
func indoor(_ mapView: Any, didTapInfoWindowOfMarker markerDetail: [AnyHashable : Any]){
}
```

### Finding a POI on the map

To search a POI on the map use ```findPOI``` method. This method searches map for the given store id. Returns Dictionary object with POI information in the callback. Returns Error object if the POI not located.


### Highlighting/Un-highlighting a POI on the map

Use ```showPOIMarker``` method to show a marker at specific POI. This method accepts POI information in form of Dictionary object and an object of UIView class which gets rendered as a marker on the map.

### way-finding
To display the route between two points, the ```findRoute:``` method of the SDK should be called.

``` Objective-c
IndoorMap.findRoute(sourcePoint destination:destination)
```

This method displays the route in preview mode by drawing a path between the source and destination points.
Calling the above method will trigger the delegate’s, ```indoor:route:``` event. The client application needs to listen to this event to collect the data between the multiple points found in that route.

``` Objective-c
func indoor(_ mapView: Any, noRoute routeList: [Any]!){
  //routeList consists of a GeoJSON feature collection.
  //Any additional UI elements to be performed can be added here.
}
```
The path rendered between two points is customizable. In order to change the look and feel of the path to be rendered, use the following code snippet in your ViewController’s ```viewDidLoad``` method after instantiating the object of ```IndoorMap``` class. See the code snippet below:

``` Objective-c
IndoorMap.pathOptions={ formatter in
  format.pathColor = UIColor.red //To change the path color.
  format.pathWidth = NSNumber(value: 8.0)//Sets the width of the path
  format.borderColor = UIColor(red: 0.247, green: 0.000, blue: 0.002, alpha: 1.000) //Sets the bordercolor for the path.
  format.borderWidth = NSNumber(value: 4.0) //Sets the border width for the path.
  format.SelectedPathColor = UIColor.white //Sets the selected path color.
  return format
  }
```
### Multi-stop way-finding
Multi-stop way-finding is the feature where SDK plots the shortest possible path from the start position and the given list of points.
To display multi-stop itinerary path following overloaded form of findRoute method should be called.
``` Objective-c
  -(void)findRoute:(CGIndoorMapPoint)startPoint destinations:(NSArray<Stopover *> *_Nonnull)endPoints;
```
Function above accepts start point and an array of Stopover object. Calling this method will also trigger the delegate’s, ```indoor:route:``` event. Just as it would when finding path between two points. **Please note** that as of now multi- stop itinerary takes maximum of six stopover points. Following screen shot shows how multi-stop itinerary gets rendered on the map.

<img src="http://s3-us-west-2.amazonaws.com/documentation-assets/ios_multipath.png" width="250">

Following code snippet shows and example call of multi-stop itinerary.
``` Objective-c
private func plotStopOverList(){
      let stopover1 = Stopover();
      stopover1.mapPoint = CGMakeMapPoint(59.91902645797848,10.585014671087265,0)
      stopover1.title = "Pizza"
      let stopover2 = Stopover();
      stopover2.mapPoint = CGMakeMapPoint(59.91900561998954,10.585307031869888,0)
      stopover2.title = "Pickles"
      let stopover3 = Stopover();
      stopover3.mapPoint = CGMakeMapPoint(59.918976883709114,10.585519932210445,0)
      stopover3.title = "Ice-cream"
      let stopover4 = Stopover();
      stopover4.mapPoint = CGMakeMapPoint(59.91903032308789,10.58555044233799,0)
      stopover4.title = "Sweets"
      let stopover5 = Stopover();
      stopover5.mapPoint = CGMakeMapPoint(59.91907485583784,10.585437454283237,0)
      stopover5.title = "Baby Food"
      let stopover6 = Stopover();
      stopover6.mapPoint = CGMakeMapPoint(59.919056874696935,10.585566200315952,0)
      stopover6.title = "Sanitary"
      let currentUserLocation = IndoorMap.userLocation() if(!CGIndoorMapPointIsEmpty(currentUserLocation)){
            SwiftLoader.show(animated: true)
            IndoorMap.findRoute(currentUserLocation, destinations: [stopover1,stopover2,stopover3,stopover4,stopover5,stopover6])?? "")")
            lblStoreName.text = "Shopping list"
            lblEndPoint.text = LocalizedString("To \(lblStoreName.text
            showNavigationDetail(true, animation: true) changeTopBarForNavigation()
} else {
  //Please Select your location on map
  let alert = UIAlertController(title: "", message: "Please location on map and try again", preferredStyle:UIAlertController.Style.actionSheet)
  let doneAction : UIAlertAction = UIAlertAction(title: "OK", style: .default) { (alertAction) in
  }
  alert.addAction(doneAction)
  self.present(alert, animated: true, completion: nil)
}
```

### Customizing Stopover pins in multi-stop way-finding

You can use ```addCustomePOI``` method in order to customize stopover pins. Following code snippet can be used to add custom pins at every stopover point.

``` Objective-c
let pointTrack = TrackingMarker()
pointTrack.position = CLLocationCoordinate2DMake(pointCoordinate[1], pointCoordinate[0])
pointTrack.level = NSNumber(0)
pointTrack.title = waypoint
let listIndexView = ShoppingListIndexView() listIndexView.createUI(shoppingListCounter)
pointTrack.iconView = listIndexView.view //New Icon created from XIB pointTrack.groundAnchor = CGPoint(x: 0.5, y: 1.0)
pointTrack.isFlat = false
pointTrack.zIndex = 999
IndoorMap.addCustomePOI(pointTrack)
```


### Tag based way-finding

Tag based routing is a way for defining for each path which type of person can use it to navigate from a location to a destination. Typical example of route tags inside a venue like an airport are:

- Security employee
- Maintenance employee
- People with limited mobility
- Passenger  

Paths taken by above people in an airport may differ as some paths may be restricted or be exclusive for certain people.

These tags are predefined for each venue and are created at the time of venue creation. Developer cannot create these tags on the fly. List of available tags can be accessed in the `IndoorSettings` object.

```Swift

func indoor(_ sender: Any, onLoaded isLoaded: Bool) {
  let avalibleRoutingOptions = IndoorSettings.instance().getRouteTags()
}        
```

`IndoorSettings.instance().getRouteTags()` returns a list of `RouteTag` objects. Each object represents a routing tag defined in the venue. `RouteTag` object can be passed to Indoor maps way-finding method which will return the path for the specified tag.

Example below shows how to use route tags while finding route between two points.

``` Objective-c
indoorMapObj.routeTags = selectedRoutingOptions[0]

indoorMapObj.findRoute(startLocation, destination: endLocation)  
```
Or

``` Objective-c
indoorMapObj.pathOptions={ format in
      if let pathFormatOptions = format{
          pathFormatOptions.pathColor = UIColor.red //To change the path color.
          pathFormatOptions.pathWidth = NSNumber(value: 8.0)//Sets the width of the path
          pathFormatOptions.borderColor = UIColor(red: 0.247, green: 0.000, blue: 0.002, alpha: 1.000) //Sets the bordercolor for the path.
          pathFormatOptions.borderWidth = NSNumber(value: 4.0) //Sets the border width for the path.
          pathFormatOptions.routeTag = selectedRoutingOptions[0]
          return pathFormatOptions
      }
      return format
    }

    indoorMapObj.findRoute(startLocation, destination: endLocation)     
```


### Displaying Route with turn by turn instructions
To display route with turn by turn instructions, the client application should call ```startNavigation()``` method of the SDK. The ```NavigationMode``` for this will be ```Navigation_TurnByTurn```. See the code snippet below:

``` Objective-c
   IndoorMap.startNavigation()
```

The client application should listen to the delegate’s ```instruction:``` method in order to get the step by step instructions for each place found on that route.

``` Objective-c
func indoor(_ mapView: Any, instruction pathIndex: UInt, pathInfo routeInfo: [AnyHashable : Any]!){
//routeInfo will have a dictionary of the current step instruction.
}
```

To browse between the set of instruction steps you can use the SDK’s ```nextStepInstruction()``` and ```peviousStepInstruction()``` methods.

``` Objective-c
IndoorMap.nextStepInstruction() //Gets next step instruction.
IndoorMap.previousStepInstruction() //Gets previous step instruction.
```
Both the methods listed above will subsequently call the delegate’s ```instruction:``` method as listed above.


### Way finding and navigation callbacks

The `IndoorMapDelegate` interface raises callbacks related to way finding and navigation. They are as follows:

| Callback | Description |
| ------ | ------ |
| `-(void)indoor:(id)mapView route:(NSArray *)routeList` | Called when way-finding is successfully executed and return path to app. |
| `-(void)indoor:(id)mapView noRoute:(NSArray *)routeList` | Called when way-finding is successfully executed but not finding any suitable paths. |
| `-(void)indoor:(id)mapView onNavigationError:(NSError *)errorInfo` | Called when Woosmap Indoor cloud platform fails to find a path. |
| `-(void)indoor:(id)mapView endNavigation:(BOOL)navigationState destinationDirection:(DestinationDirection)atDirection` | Called when user reaches destination of way-finding.|
| `func indoor(_ mapView: Any, navigationExited navigationState: Bool)` | Called when user explicitly exit way-finding.|
| `-(void)indoor:(id)mapView instruction:(NSUInteger)pathIndex pathInfo:(NSDictionary *)routeInfo` | Called when user moves closer to one path segment than any other path segment. This listener also called when user switches to preview mode. Exposes two parameters, **pathIndex**:  Position of path segment. **routeInfo**: current path segment details|
| `-(void)indoor:(id)mapView reRouteWithLocation:(CLLocationCoordinate2D)coordinate floor:(int)level` | Called when user deviates from the path.|
| `-(void)indoor:(id)mapView navigationInterrupted:(BOOL)coordinate` | Called when user explicitly changes the current Segment. This may happen when user browses through the instructions for current way-finding route using navigationPager|
| `-(void)indoor:(id)mapView onFloorChange:(int)level triggerByUserInteaction:(BOOL)isByUser` | This callback is called prior to rendering floor change markers. Use this method to create your custom floor change markers. You can inflate and return your own view to use as floor change marker. Return null to user default markers.|
| `-(void)indoor:(id)mapview onNavigationStatusUpdated:(NSDictionary *)navigationParams` | This callback will trigger every time user's location is updated when in navigation mode.|


### Switching between multiple floors
You can use the in-built floor selector in your application or you can create your custom floor selector. To disable the in-built floor selector, set the ```enableFloorSelector``` property of the ```IndoorMap``` class to ```NO```. See the code snippet below:
``` Objective-c
  IndoorMap.enableFloorSelector=false; //true to use in-built floor selector.
```
  If you use your custom floor selector, you will have to pass the floor number to the SDK’s ```changeFloor()``` method to switch to the corresponding floor’s map.

``` Objective-c
   IndoorMap.changeFloor(floor)
```

When a floor change event occurs, the SDK will notify the client application if it listens to the delegate’s ```onFloorChange:``` method.

``` Objective-c
  func indoor(_ mapView: Any, onFloorChange level: Int32){
  }
```

### Detect user near Escalators/Elevators
The SDK can notify the client application when the user enters/exits escalator/elevator area through its ```onEnterFloorChangeRegion``` and ```onExitFloorChangeRegion``` delegate methods. If the client application needs to add any functionality when the user is found near the closest elevator/escalator, it can do so by implementing the following:
``` Objective-c
func indoor(_ mapView: Any, onEnterFloorChangeRegion region: [AnyHashable : Any]!){
//Called when user found near Escalator/Elevator area.
//region consists of an NSDictionary of the elevator/escalator near to the user
}
```

### Enabling Search

The SDK provides the ability to add search to your application. Searching for POIs, amenities (restrooms, atm’s, cafes and info desks) inside the venue can be done with a few lines of code.
The ```MapSearch``` class of the SDK is the central component to perform search operations within your application. The Search events are delivered to the MapSearch’s, delegate, which should confirm to the ```MapSearchDelegate``` protocol.
To implement search using SDK in your client project, follow these steps:

- Import the framework header file using ```import
WoosmapIndoor``` in your ViewController class file.

- Add the MapSearchDelegate delegate.
``` Objective-c
import WoosmapIndoor
class SearchViewController : UIViewController, MapSearchDelegate{
      var poiSearch: MapSearch = MapSearch.init(SearchType.POI)
      var aminitySearch: MapSearch = MapSearch.init(SearchType.amenity)
}
```

*Note: We have created two separate instances of ```MapSearch``` class, one for POI search and another for Amenities search. The MapSearch constructor accepts a ```SearchType``` constant. ```SearchType``` values could be ```Search_POI``` or ```Search_Amenity```

- Create the instance of ```MapSearch``` class using its convenience constructor and point the delegate to the receiver.

``` Objective-c
override func viewDidLoad(){
    poiSearch.mapSearchDelegate = self
    aminitySearch.mapSearchDelegate = self
}
```
- Call the ```MapSearch``` class’s ```searching:``` method to perform search.

``` Objective-c
  poiSearch.searching(<<text to search>>)
```
- Implement the ```searchDidStartLoad:``` and ```searchDidFinishLoad:``` methods of the ```MapSearchDelegate protocol```.
When the client application makes a call to ```searching:``` method of the ```MapSearch``` class, the SDK will notify the client application by triggering the ```searchDidStartLoad:``` method of the MapSearchDelegate.

``` Objective-c
func searchDidStartLoad(_ sender: MapSearch?){
  //Showing custom progress bar or any other additional functionality can be implemented over.
}
```

When the SDK is ready with the search results, it will notify the client application by triggering the ```searchDidFinishLoad:``` method of the ```MapSearchDelegate```.

``` Objective-c
func searchDidFinishLoad(_ sender: MapSearch!, result response: [Any]!){
  //response will an NSArray of results returned from the SDK for the application’s search operation.
  // Additional functionality of binding the search results can be implemented over here.
}
```
### Highlighting multiple POIs on the map
SDK has support to display search result in form of pins. Following new methods and callback have been exposed in order to accomplish this.
``` Objective-c
func showSearchedPOIs(onMap searchresult: [Any]?, completion result: @escaping (_ searchResult: [Any]?, _ error: Error?) -> Void) {
}
```
- ```func showSearchedPOIs(onMap searchresult: [Any]?, completion result: @escaping (_ searchResult: [Any]?, _ error: Error?) -> Void)```: This method accepts a String array containing POI ids and also returns String array containing the POI ids that were highlighted on the map. Highlighted POIs will be displayed as pins. When search results are displayed on the map other POIs (i.e. POIs which were not passed to this function) get disabled. They are faded out and interaction with them is disabled.
- ```func indoor(_ mapview: Any, onSearchedPOISelected poiinfo: [Any : Any]?)```: A new event has been added. This event is raised when user taps on any searched/highlighted POI.
- ```func clearSearchedPOIs()```: As the name suggests this method clears the search result from the map. POI icons will come back to their original state.

|<img src="http://s3-us-west-2.amazonaws.com/documentation-assets/ios_multipoi.png" width="250">|
|---|

### Proximity alerts for geo-fenced zones

WoosmapIndoor SDK allows you to setup proximity alerts for your venue. Once the geo-fenced zones for your venue are set-up through our backend services, your application is ready to receive the proximity alerts as in-app notifications just through a few lines of code.

The SDK will notify the client application when the user’s location is found in any of the geo-fenced zones inside the venue.

The client application needs to implement the delegate’s ```enterPromoZone:``` method in order to receive the notifications from the SDK.

``` Objective-c
func indoor(_ mapView: Any, enterPromoZone Zone: [AnyHashable : Any]!, promotion offers: [Any]!){
  //Zone consists of NSDictionary of the geo-fenced area in which the user is found
  //offers consists of NSArray of all the active offers found in the geo-fenced zone.
}
```

The SDK can also recognize when the user exits from a geo-fenced zone and can notify the client application through the ```exitPromoZone:``` method of the ```IndoorMapDelegate```.

``` Objective-c
func indoor(_ mapView: Any, exitPromoZone Zone: [AnyHashable : Any]!){
  //Zone consists of NSDictionay of the zone from where the user makes an exit.
}
```

### Customizable elements
The SDK offers the client application to customize certain elements rendered on the map. The client application can use their own assets to customize the look and feel of the following elements:


|# | Customizable | Elements Image name to use|
|---|---|---|
|1|Blue dot – User’s current position|blue-dot.png (***add it in app resource folder***)|
|2|Routing – Start pin|```func indoor(_ mapview: Any, customizeEndMarker imgPin: UIImage?) -> UIView?```|
|3|Routing – End pin|```func indoor(_ mapview: Any, customizeStartMarker imgPin: UIImage?) -> UIView?```|
|4|Routing – Level change indicator pin|```func indoor(_ mapview: Any, customizeLevelChangedMarker imgPin: UIImage?, mode floorChangeMode: FloorConntectedBy, movingUp up: Bool) -> UIView? ```|
|5|Navigation Head Arrow|```indoorMapObj.setNavigationHeadMarker(UIImage.init(named: "arrowHead"))indoorMapObj.hideNavigationHeadMarkerOnLastStep = True```|
|6|Navigation Head Arrow visibility|```indoorMapObj.hideNavigationHeadMarkerOnLastStep = True/ False```|

## API reference
[WoosmapIndoor Map iOS SDK Reference](http://woosmap-indoor-apiref.s3-website.ap-south-1.amazonaws.com/ios/index.html)

## License
&copy; 2021-2022 Web Geo Services. All rights reserved.
