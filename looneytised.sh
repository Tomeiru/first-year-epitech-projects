#! /bin/sh
grep 'theo1\|steven1\|arnaud1\|pierre-jean' | sed 's/theo1/Wile E. Coyote/gi' | sed 's/steven1/Daffy Duck/gi' | sed 's/arnaud1/Porky Pig/gi' | sed 's/pierre-jean/Marvin the Martian/gi'
