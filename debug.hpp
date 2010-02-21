#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <cstdarg>

#ifndef DEBUG
#define NDEBUG
#define D(...) {}
#else
#define D(...) __VA_ARGS__
#endif

#ifndef NOCOLOR
#define ATTR(x) "\033[" #x "m"
#else
#define ATTR(x) ""
#endif

/* vt100 foreground colors */
#define CBLACK   ATTR(30)
#define CRED     ATTR(31)
#define CGREEN   ATTR(32)
#define CYELLOW  ATTR(33)
#define CBLUE    ATTR(34)
#define CMAGENTA ATTR(35)
#define CCYAN    ATTR(36)
#define CWHITE   ATTR(37)

/* vt100 special attributes */
#ifndef NOATTRIBS
#define CUND     ATTR(4)
#define CBRT     ATTR(1)
#else
#define CUND     ""
#define CBRT     ""
#endif
#define CRESET   ATTR(0)

/* user config */
#define VAR_COLOR    CBLUE
#define STAMP_COLOR  CMAGENTA
#define TIME_COLOR   CCYAN
#define ERROR_COLOR  CRED CBRT

/* debug printing functions */
#define P(x, ...)  fprintf(stderr, CRESET x CRESET, ##__VA_ARGS__)
#define PN(x, ...) fprintf(stderr, CRESET x "\n" CRESET, ##__VA_ARGS__)
#define PV(var) cerr << CRESET VAR_COLOR CUND << #var << CRESET " = " VAR_COLOR << (var) << CRESET "; "
#define N cerr << endl
#define STAMP cerr << CRESET STAMP_COLOR CUND << __FILE__ \
                   << CRESET STAMP_COLOR ":" CBRT << __LINE__ << " " \
                   << CRESET STAMP_COLOR << __PRETTY_FUNCTION__ << " : " CRESET
#define TIME print_timestamp() 
#define FUCK(...) { \
	PN(ERROR_COLOR CUND "********** EXTREMELY IMPORTANT NOTICE! **********"); \
    PN(ERROR_COLOR      "*        Something very bad has happened        *"); \
	__VA_ARGS__; \
	PN(ERROR_COLOR      "**********        end of notice        **********"); \
}

/* auxiliary functions */
struct tm* get_t()
{
	time_t sec;	
	sec = time(NULL);	
	return localtime(&sec);	
}

char* get_time()
{
	char *str;
	int ret;
	struct tm* t = get_t();
	ret = asprintf(&str,"%.2i:%.2i:%.2i",
			t->tm_hour,
			t->tm_min,
			t->tm_sec
	); assert(ret != -1);
	return str;
}

char* get_date()
{
	char *str;
	int ret;
	struct tm* t = get_t();
	ret = asprintf(&str,"%.4i/%.2i/%.2i",
			t->tm_year+1900,
			t->tm_mon+1,
			t->tm_mday
	); assert(ret != -1);
	return str;
}

void print_timestamp()
{
	char *d = get_date();
	char *t = get_time();
	std::cerr << CRESET TIME_COLOR "[" << d << " " << CBRT << t << CRESET TIME_COLOR "] " CRESET;
	free(d);
	free(t);
}
