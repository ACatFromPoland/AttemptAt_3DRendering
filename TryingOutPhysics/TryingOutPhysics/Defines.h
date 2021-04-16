#pragma once

#define WINDOWX 800
#define WINDOWY 800

#define XY(v) (v).x,(v).y

#define getrandom(min, max) ((rand()%(int)(((max) + 1) - (min)))+ (min))