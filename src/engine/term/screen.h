#ifndef __SCREEN_H__
#define __SCREEN_H__

#if defined __linux__
#include <semaphore.h>
#elif defined _WIN32 || defined _WIN64
#include <windows.h>
#else
#error "unknown platform"
#endif

// Engine
#include "color.h"
#include "term.h"
#include "geometry/geometry.h"
#include "list/tree.h"

// Set this flag to 1 when the window has been resized
int resize_flag;

typedef struct Screen {
    int id;

    TermSize ts;

    int margin_x;
    int margin_y;

    Point camera;
    Rect camera_bounds;

    Color *light_buffer;

    // Current frame that the engine draws to
    Pixel *pixel_buffer;

    // Current frame that the screen manager is piping out
    Pixel *current_pixel_buffer;

    // Refers to previous frame
    Pixel *prev_pixel_buffer;

    int times_init;
} Screen;

typedef struct ScreenManager {
    Screen main_screen;

#if defined __linux__
    sem_t writes_allowed;
    sem_t reads_allowed;
#elif defined _WIN32 || defined _WIN64
    HANDLE writes_allowed;
    HANDLE reads_allowed;
#endif

    char *_line_buffer;
} ScreenManager;

ScreenManager screen_manager;

void initScreenManager();
void closeScreenManager();
int renderScreens();

void setCamera(Screen *screen, Point loc);

void initScreen(Screen *screen);
void clearScreen(Screen *screen);
int closeScreen(Screen *screen);

int swapScreen();

Pixel getPixel(Screen *s, Point p);

#endif

