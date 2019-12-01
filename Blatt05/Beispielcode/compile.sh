#!/bin/bash

CC="$(which gcc)"
CFLAGS="-g3"
LDFLAGS=""

function compile() {
	echo "$CC $CFLAGS $LDFLAGS -o $1 $1.c"
	$CC $CFLAGS $LDFLAGS -o $1 $1.c
}

compile argv &&
compile change1 &&
compile change2 &&
compile pointer_to_pointer &&
compile pointer_to_struct
