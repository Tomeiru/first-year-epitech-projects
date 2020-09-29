#! /bin/sh
cat Day02/passwd | sed -n 'p;n' | sort -r
