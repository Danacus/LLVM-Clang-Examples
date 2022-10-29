# Taint Propagation via Dataflow

### Description

LLVM/Clang Version: test on LLVM 16 (should also work on 14 and 15)

This llvm transform pass implements a flow-sensitive, field- and context-insensitive taint propagation based on classic dataflow analysis. 

Taint data can be accessed using `getTaintMap`.

### Build

```shell
$ cd /path/to/taint-propagation
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

### Example

Take `testcase/test_global.c` as a simple example.

Build LLVM IR bitcode from test_global.c.

```shell
$ cd testcase
$ clang -c -emit-llvm test_global.c -o test_complex.bc
```

Run this taint propagation pass, and it will print the taint map.

```shell
$ cd testcase
$ opt -enable-new-pm=0 -load ../build/libTaintPropagation.so -taint-propagation < test_complex.bc > /dev/null
```

