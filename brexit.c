#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <dlfcn.h>

#define HOUSE_OF_COMMONS(x) fprintf(stderr, x)

typedef void (*exit_fn)(int status) __attribute__((noreturn));

void exit(int status) __attribute__((noreturn));

void exit(int status)
{
	exit_fn orig_exit = (exit_fn)dlsym(RTLD_NEXT, "exit");
	srand(time(NULL)); // yes this deserves shitty random numbers

	HOUSE_OF_COMMONS(""
" ____  ____  _______  _____ _____\n"
"| __ )|  _ \\| ____\\ \\/ /_ _|_   _|\n"
"|  _ \\| |_) |  _|  \\  / | |  | |\n"
"| |_) |  _ <| |___ /  \\ | |  | |\n"
"|____/|_| \\_\\_____/_/\\_\\___| |_|\n"
"We vote for:\n");

	for (;;) {
		switch (rand()%6) {
			case 0:
				HOUSE_OF_COMMONS("soft brexit!\n");
				orig_exit(status);
				break;
			case 1:
				HOUSE_OF_COMMONS("uniliteral brexit!\n");
				orig_exit(42);
				break;
			case 2:
				HOUSE_OF_COMMONS("medium hard brexit!\n");
				_exit(status);
				break;
			case 3:
				HOUSE_OF_COMMONS("no deal at all brexit - fooog off!\n");
				*(volatile char *)0;
				break;
			case 4:
				HOUSE_OF_COMMONS("delay the whole thing!\n");
				sleep(5);
				break;
			default:
				HOUSE_OF_COMMONS("let's do more voting!\n");
				continue;
		}
	}

	orig_exit(status);
}
