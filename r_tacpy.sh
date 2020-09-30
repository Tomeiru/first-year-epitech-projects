#! /bin/sh
cut -d: -f 1 | rev | sed -n 'n;p' | sort -r | sed ':a;N;$!ba;s/\n/, /g'
