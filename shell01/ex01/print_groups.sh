#!/bin/sh
printf "%s" "$(id -Gn | tr ' ' ',')"
