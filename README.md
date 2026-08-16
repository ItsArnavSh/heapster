# heapster

A custom Malloc (Memory Allocator) written in C.

## Goals

- Create a memory allocator using syscalls like `mmap`
- It should be able to efficiently allocate/free memory as asked

## Layout

```
Heapster/
├── src/            # C source files
├── include/        # C header files
├── experimentation/  # Throwaway experiments (minalloc, pagesize)
├── Makefile
└── README.md
```

## Build & Run

```
make build     # compile the allocator into ./heapster
make run       # build and run ./heapster
make clean     # remove object files and the binary
```
