#!/usr/bin/env bash

sed -i -e "s|'-D__has_include(STR)=__has_include__(STR)' '-D__has_include_next(STR)=__has_include_next__(STR)'||g" compile_commands.json
