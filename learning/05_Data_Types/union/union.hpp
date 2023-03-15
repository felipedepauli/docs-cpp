#pragma once

union Data {
    int i;
    float f;
    char str[20];
};

typedef struct Gentee {
    union {
        int x;
        int y;
    };
    int z;
} Gentee;