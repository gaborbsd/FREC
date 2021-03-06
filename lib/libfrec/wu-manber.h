#ifndef WU_MANBER_H
#define WU_MANBER_H 1

#include <stdint.h>
#include <wchar.h>

#include "frec.h"
#include "mregex.h"

#define WM_MAXPAT 64

#define MHEUR_NONE 0
#define MHEUR_SINGLE 1
#define MHEUR_LITERAL 2
#define MHEUR_LONGEST 3

typedef struct {
	int cflags;
	char **pat;		/* Patterns */
	size_t *siz;		/* Pattern sizes */
	size_t n;		/* No of patterns */
        size_t m;		/* Shortest pattern length */
	size_t defsh;		/* Default shift */
	void *shift;		/* Wu-Manber shift table */

	wchar_t **wpat;		/* Patterns (wide) */
	size_t *wsiz;		/* Pattern sizes (wide) */
	size_t wn;		/* No of patterns (wide) */
	size_t wm;		/* Shortest pattern length (wide) */
	size_t wdefsh;		/* Default shift (wide) */
	void *wshift;		/* Wu-Manber shift table (wide) */
} wmsearch_t;

typedef struct {
	size_t shift;			/* Shift value for fragment */
	size_t suff;			/* No of pats ending w/ fragment */
	uint8_t suff_list[WM_MAXPAT];	/* Pats ending w/ fragment */
	size_t pref;			/* No of pats starting w/ fragment */
	uint8_t pref_list[WM_MAXPAT];	/* Pats starting w/ fragment */
} wmentry_t;

int
frec_wmcomp(wmsearch_t *wm, size_t nr, const wchar_t **regex,
	   size_t *n, int cflags);
int
frec_wmexec(const wmsearch_t *wm, const void *str, size_t len,
	   int type, size_t nmatch, frec_match_t pmatch[],
	   int eflags);
void
frec_wmfree(wmsearch_t *wm);
#endif
