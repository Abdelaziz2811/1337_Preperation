#!/bin/sh
printf "%s" "$(id -Gn "$FT_USER" | tr ' ' ',')"
