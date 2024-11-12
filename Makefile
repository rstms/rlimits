
rlimits: rlimits.c 
	cc -o $@ $< -lutil

install: rlimits
	install -o root -g wheel -m 0755 rlimits /usr/local/bin/rlimits

clean:
	rm -f rlimits
