#pragma once

#include <iostream>

typedef enum {
    CAR,
    TRUCK,
    MOTORCYCLE,
    BICYCLE,
    BOAT,
    PLANE,
    HELICOPTER,
    TRAIN,
    SUBMARINE,
    SHIP,
    UFO
} type_t;

typedef struct LittleBox {
    type_t type;
    int xlt;
    int ylt;
    int width;
    int height;
    struct Points {
        int x;
        int y;
    } points[4];

    LittleBox() : type(TRUCK), xlt(-1), ylt(-1), width(1), height(1) {
        points[0].x = xlt;
        points[0].y = ylt;
        points[1].x = xlt + width;
        points[1].y = ylt;
        points[2].x = xlt + width;
        points[2].y = ylt + height;
        points[3].x = xlt;
        points[3].y = ylt + height;
    }

    // Overload the == operator
    // This is a member function
    // The first parameter is a reference to the object that is calling the function
    // The second parameter is a reference to the object that is being compared to the object that is calling the function
    // The return value is a boolean
    // The function is const because it does not change the object that is calling the function
    // The function is inline because it is a small function
    inline bool operator == (const LittleBox& other) const {
        return (xlt == other.xlt && ylt == other.ylt && width == other.width && height == other.height && type == other.type);
    }

} little_box_t;