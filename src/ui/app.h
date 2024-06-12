#ifndef _APP_H
#define _APP_H

// #define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR



   void start_app(void);




#endif // !_APP_H

