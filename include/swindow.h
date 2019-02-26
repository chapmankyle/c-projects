#ifndef SWINDOW_H
#define SWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* defining boolean values */
typedef enum {
	false = 0,
	true = 1
} bool;

/* defining errors */
typedef enum {
	SFAILURE = -1, SSUCCESS, SWINDOW_NOT_CREATED, SUNKNOWN
} serror_t;

/* defining all events */
typedef enum {
	SEVENT_NONE, SEVENT_KEY_PRESS, SEVENT_KEY_RELEASE, SEVENT_QUIT, \
	SEVENT_RESIZE, SEVENT_FOCUS_GAINED, SEVENT_FOCUS_LOST, \
	SEVENT_MOUSE_PRESSED, SEVENT_MOUSE_RELEASED
} sevent_type_t;

/* used for setting width and height of the window */
typedef struct {
	int16_t width;
	int16_t height;
} swindow_t;

/* defining frame buffer */
typedef struct {
	int16_t width;
	int16_t height;
	uint32_t *pixels;
} sframe_buffer_t;

/* definitions for mouse */
typedef struct {
	float x;
	float y;
	uint32_t buttons;
} smouse_t;

static sframe_buffer_t sframe_buffer;
float sdelta = 0;

#ifdef __cplusplus
}
#endif

#endif
