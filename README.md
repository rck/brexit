# BREXIT

With this shared library everybody can enjoy the pleasures of Brexit!

Simply `LD_PRELOAD` the brexit library to any program and see the random outcome. Everything is possible, from
a soft Brexit to a hard Brexit, to endless voting.


```
$ make run
gcc -o main main.c
gcc -shared -fPIC -o brexit.so brexit.c -ldl
LD_PRELOAD=$PWD/brexit.so ./main
 ____  ____  _______  _____ _____
| __ )|  _ \| ____\ \/ /_ _|_   _|
|  _ \| |_) |  _|  \  / | |  | |
| |_) |  _ <| |___ /  \ | |  | |
|____/|_| \_\_____/_/\_\___| |_|
We vote for:
let's do more voting!
let's do more voting!
delay the whole thing!
no deal at all brexit - fooog off!
Segmentation fault
make: *** [Makefile:11: run] Error 139
```
