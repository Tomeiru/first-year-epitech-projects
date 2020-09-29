#! /bin/sh
cat Day02/passwd | grep 'theo1\|steven1\|arnaud1\|pierre-jean' | sed -e '/theo1/wile e. coyote' | sed -e '/steven1/daffy duck' | sed -e '/arnaud1/porky pig' | sed -e '/pierre-jean/marvin the martian'



