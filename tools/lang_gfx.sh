#!/bin/sh
# English builds: runs a graphics tool on the English source of a file.
# graphics_en/ mirrors graphics/ for the graphics with text; any other file is used as is.
# Usage: lang_gfx.sh <tool> <input> [args...]
tool="$1"
shift
input="$1"
shift
case "$input" in
    graphics/*)
        if [ -f "graphics_en/${input#graphics/}" ]; then
            input="graphics_en/${input#graphics/}"
        fi
        ;;
esac
exec "$tool" "$input" "$@"
