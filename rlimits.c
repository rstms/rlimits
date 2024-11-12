#include <stdio.h>
#include <sys/resource.h>
#include <util.h>

struct resource_type {
    char *name;
    char *detail;
    int resource;
};

struct resource_type limits[] = {
    {"CORE", "core file size", RLIMIT_CORE},
    {"CPU", "cpu time per process in seconds", RLIMIT_CPU},
    {"DATA", "data segment size allocated with (malloc, mmap)", RLIMIT_DATA},
    {"FSIZE", "file size", RLIMIT_FSIZE},
    {"MEMLOCK", "memory lockable with (mlock)", RLIMIT_MEMLOCK},
    {"NOFILE", "number of open files", RLIMIT_NOFILE},
    {"NPROC", "number of processes per uid", RLIMIT_NPROC},
    {"RSS", "resident set size (deprecated)", RLIMIT_RSS},
    {"STACK", "stack size", RLIMIT_STACK},
    {NULL, NULL, -1}
};


int main(int argc, char *argv[]) {
    printf("ID\t\t\tCUR\tMAX\tDETAIL\n");
    struct rlimit result;
    for (int i=0; limits[i].name; i++) {
	struct resource_type *rp = &limits[i];
	if (getrlimit(rp->resource, &result) != 0) {
	    perror("getrlimit");
	    return(1);
	}
	char curbuf[FMT_SCALED_STRSIZE];
	char *cb = "inf";
	if (result.rlim_cur != RLIM_INFINITY) {
	    if (fmt_scaled((long long)result.rlim_cur, curbuf) != 0) {
		perror("fmt_scaled");
		return(1);
	    }
	    cb = curbuf;
	}

	char maxbuf[FMT_SCALED_STRSIZE];
	char *mb = "inf";
	if (result.rlim_max != RLIM_INFINITY) {
	    if (fmt_scaled((long long)result.rlim_max, maxbuf) != 0) {
		perror("fmt_scaled");
		return(1);
	    }
	    mb = maxbuf;
	}

	printf("RLIMIT_%s\t\t%s\t%s\t%s\n", rp->name, cb, mb, rp->detail);
    }
    return(0);
}
