#!/bin/sh

if [ ! -f "src/ReverseSolver" ]
then
	echo "You should compile first ! Use the make command, or see the readme if it's your first use :)"
	exit 99
fi

oldLDPath=$LD_LIBRARY_PATH
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:`pwd`/resources/smax/lib"

./src/ReverseSolver "$*"

export LD_LIBRARY_PATH=$oldLDPath
