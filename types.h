#ifndef TYPES_H_
#define TYPES_H_

#include <X11/Xlib.h>

typedef union {
  long i;
  unsigned long ui;
  float f;
  const void *v;
} Arg;

typedef struct Monitor Monitor;
typedef struct Client Client;
struct Client {
  char name[256];
  float mina, maxa;
  int x, y, w, h;
  int oldx, oldy, oldw, oldh;
  int basew, baseh, incw, inch, maxw, maxh, minw, minh;
  int bw, oldbw;
  unsigned int tags;
  int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;
  Client *next;
  Client *snext;
  Monitor *mon;
  Window win;
};

typedef struct {
  const char *symbol;
  void (*arrange)(Monitor *);
} Layout;

typedef struct TagState TagState;
struct TagState {
  int selected;
  int occupied;
  int urgent;
};

struct Monitor {
  char ltsymbol[16];
  char lastltsymbol[16];

  float mfact;
  int nmaster;
  int num;
  int by;             /* bar geometry */
  int mx, my, mw, mh; /* screen size */
  int wx, wy, ww, wh; /* window area  */
  unsigned int seltags;
  unsigned int sellt;
  unsigned int tagset[2];
  TagState oldtagstate;
  int showbar;
  int topbar;
  Client *clients;
  Client *sel;
  Client *lastsel;
  Client *stack;
  Monitor *next;
  Window barwin;
  const Layout *lt[2];
};

#endif //  TYPES_H_