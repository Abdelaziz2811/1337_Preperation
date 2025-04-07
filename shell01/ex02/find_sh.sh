#!/bin/sh
find . -name '*.sh' | while read file; do basename "$file" .sh; done
