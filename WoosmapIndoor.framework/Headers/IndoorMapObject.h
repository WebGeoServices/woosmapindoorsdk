/*!
 IndoorMapObject.h
 Woosmap Indoor
 */

#ifndef IndoorMapObject_h
#define IndoorMapObject_h

#include <stdio.h>
#include <stdbool.h>
struct CGIndoorMapPoint {
    float lat;
    float lng;
    int floor;
};
typedef struct CGIndoorMapPoint CGIndoorMapPoint;

/**
 To make point with latitude, longitude and level
 
 @param xlat lattitude
 @param ylng longitude
 @param f level
 @return point with latitude, longitude and level
 */
CGIndoorMapPoint CGMakeMapPoint(float xlat,float ylng, int f);

/**
 To make CGIndoorMapPoint empty
 
 @return empty CGIndoorMapPoint
 */
CGIndoorMapPoint CGMakeMapPointEmpty(void);

/**
 To check whether CGIndoorMapPoint is empty
 
 @param map CGIndoorMapPoint
 @return whether CGIndoorMapPoint is empty or not
 */
bool CGIndoorMapPointIsEmpty(CGIndoorMapPoint map);

/**
 To check whether two CGIndoorMapPoint are equal
 
 @param map1 first point
 @param map2 second point
 @return whether map1 and second map2 are equal or not
 */
bool CGIndoorMapPointIsEqual(CGIndoorMapPoint map1,CGIndoorMapPoint map2);

#endif /* IndoorMapObject_h */
