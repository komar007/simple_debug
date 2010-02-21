#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>

#ifndef DEBUG
#define NDEBUG
#define D(...) {}
#else
#define D(...) __VA_ARGS__
#endif

#define CBLACK   "\033[30m"
#define CRED     "\033[31m"
#define CGREEN   "\033[32m"
#define CYELLOW  "\033[33m"
#define CBLUE    "\033[34m"
#define CMAGENTA "\033[35m"
#define CCYAN    "\033[36m"
#define CWHITE   "\033[37m"

#define CRESET   "\033[0m"
#define CUND     "\033[4m"
#define CBRT     "\033[1m"

#define VAR_COLOR    CBLUE
#define STAMP_COLOR  CMAGENTA
#define TIME_COLOR   CCYAN
#define ERROR_COLOR  CRED CBRT

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
