# ECE 5750 — Lock Microbenchmark (Incomplete Archive)

Incomplete CPU synchronization coursework snapshot containing `microbench.c` and `lock.s`. It preserves lock primitives and the beginnings of a threaded benchmark.

This snapshot is not buildable as supplied: the C file refers to a missing `pthreads.h` support header, unresolved types/variables, and unfinished lock/test code. Recover the original support files and complete those sections before compiling with a matching assembler and POSIX-thread toolchain. No benchmark or correctness pass is claimed.

Source comments retain course, instructor, library, and collaborator attribution. This repository does not grant a new license over third-party material. Generated logs, waveforms, debugging captures, and result directories are omitted from this public source edition.
