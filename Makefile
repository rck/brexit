all: main brexit.so

main: main.c
	gcc -o $@ $^

brexit.so: brexit.c
	gcc -shared -fPIC -o $@ $^ -ldl

.PHONY: run
run: all
	LD_PRELOAD=$$PWD/brexit.so ./main

.PHONY: clean
clean:
	rm -f main brexit.so
