/*
    mtr  --  a network diagnostic tool
    Copyright (C) 1997,1998  Matt Kimball

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <netinet/in.h>

/* Don't put a trailing comma in enumeration lists. Some compilers
   (notably the one on Irix 5.2) do not like that. */
enum { ActionNone, ActionQuit, ActionReset, ActionDisplay, ActionCompact,
    ActionClear, ActionPause, ActionResume, ActionMPLS, ActionDNS,
#ifdef HAVE_IPINFO
    ActionII, ActionAS,
#endif
    ActionScrollDown, ActionScrollUp
};

enum {
    DisplayReport,
#ifdef HAVE_CURSES
    DisplayCurses,
#endif
#ifdef HAVE_GTK
    DisplayGTK,
#endif
    DisplaySplit,
    DisplayRaw,
    DisplayXML,
    DisplayCSV,
    DisplayTXT,
#ifdef HAVE_JANSSON
    DisplayJSON,
#endif
};

// if we have libncursesw and braille graphs were enabled, build with them
#if HAVE_CURSESW && ENABLE_BRAILLE
#define WITH_BRAILLE_DISPLAY 1
#endif

enum {
    DisplayModeDefault,
    DisplayModeBlockmap,
    DisplayModeBlockmapScale,
#ifdef WITH_BRAILLE_DISPLAY
    DisplayModeBraille,
#endif
    DisplayModeMAX              /* this must be the last DisplayMode entry */
};

/*  Prototypes for display.c  */
extern void display_detect(
    struct mtr_ctl *ctl,
    int *argc,
    char ***argv);
extern void display_open(
    struct mtr_ctl *ctl);
extern void display_close(
    struct mtr_ctl *ctl);
extern void display_redraw(
    struct mtr_ctl *ctl);
extern void display_rawxmit(
    struct mtr_ctl *ctl,
    int hostnum,
    int seq);
extern void display_rawping(
    struct mtr_ctl *ctl,
    int hostnum,
    int usec,
    int seq);
extern void display_rawhost(
    struct mtr_ctl *ctl,
    int hostnum,
    ip_t *ip_addr,
    struct mplslen *mpls);
extern int display_keyaction(
    struct mtr_ctl *ctl);
extern void display_loop(
    struct mtr_ctl *ctl);
extern void display_clear(
    struct mtr_ctl *ctl);
extern char *host_error_to_string(
    int err);
