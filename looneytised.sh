#! /bin/sh
cat Day02/passwd | grep 'theo1\|steven1\|arnaud1\|pierre-jean' | sed 's/theo1/wile e. coyote/gi' | sed 's/steven1/daffy duck/gi' | sed 's/arnaud1/porky pig/gi' | sed 's/pierre-jean/marvin the martian/gi'
