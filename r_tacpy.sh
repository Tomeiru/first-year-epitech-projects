#! /bin/sh
cat Day02/passwd | cut -d: -f 1 | rev | sed -n 'n;p' | sort -r | sed 's/n\/, /gi'
