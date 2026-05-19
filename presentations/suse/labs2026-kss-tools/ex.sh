#!/usr/bin/bash

DO_LESS=0

case "$1" in
	9) cmd='suse-get-maintainers --path drivers/tty/serial/samsung_tty.c --json | jq -C' ;;
	10) cmd='suse-get-maintainers --path 123 --json | jq -C' ;;
	22) cmd='f2c_cli -f fs/ext4/dir.c --json | jq -C'; DO_LESS=1 ;;
esac

{
	echo "# Running:"
	echo "> $cmd"
	eval "$cmd"
} | if [ $DO_LESS -eq 1 ]; then less -R; else cat; fi
