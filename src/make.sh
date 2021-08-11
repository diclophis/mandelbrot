#!/bin/sh

set -x

FLAGS="-O6 -ffast-math -fprefetch-loop-arrays -fexpensive-optimizations -funroll-loops -frerun-cse-after-loop -frerun-loop-opt -fomit-frame-pointer -fschedule-insns2 -minline-all-stringops -mfancy-math-387 -mfp-ret-in-387 -m3dnow -msse -mfpmath=sse -mmmx -malign-double -falign-functions=4 -fforce-addr -pipe"
#FLAGS="-O6"

g++ $FLAGS -o jbardin-fractal main.cpp `pkg-config --cflags --libs gdlib`

ls -lh jbardin-fractal
