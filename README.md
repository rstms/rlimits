# rlimits

Show resource limits on OpenBSD as reported by the getrlimit() function

## example output
```
ID			CUR	MAX	DETAIL
RLIMIT_CORE		inf	inf	core file size
RLIMIT_CPU		inf	inf	cpu time per process in seconds
RLIMIT_DATA		1.5G	128G	data segment size allocated with (malloc, mmap)
RLIMIT_FSIZE		inf	inf	file size
RLIMIT_MEMLOCK		85.3M	256M	memory lockable with (mlock)
RLIMIT_NOFILE		512B	1.0K	number of open files
RLIMIT_NPROC		256B	512B	number of processes per uid
RLIMIT_RSS		3.7G	3.8G	resident set size (deprecated)
RLIMIT_STACK		4.0M	32.0M	stack size
```
