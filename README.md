# mylist
The library `mylist` is a library of generic linked lists in C language

## Installation
- Clone the repo and copy the `lib` directory into your project
- In the root directory of your project :
```sh
make re -C lib/mylist
```

## Usage
### Header to include
```c
#include <mylist.h>
// #include <mylist/generic_list.h>
// #include <mylist/ptr_list.h>
// #include <mylist/string_list.h>
```
### Compilation
```sh
gcc -Iinclude {all_files.c} {all_files.o} -Llib -lmylist
```
## Wiki
Check out the [wiki](https://github.com/francis-clairicia/mylist/wiki) to see the purpose of the 3 linked lists

## License
[MIT](https://github.com/francis-clairicia/mylist/blob/main/LICENSE)
