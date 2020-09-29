#! /bin/sh
cut -d: -f 1 | grep -i ^$1 | wc -l
