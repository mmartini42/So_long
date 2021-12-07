#!/bin/bash

echo "SRCS += " > Sources.mk
find Sources -name '*.c' | sed 's/^/SRCS += /' > Sources.mk
echo "HEADER += " > Header.mk
find Includes -name '*.h' | sed 's/^/HEADER += /' > Header.mk
echo "OBJS_SOURCES += " > Objects.mk
cat Sources.mk | sed 's/SRCS/OBJS_SOURCES/' | sed 's/Sources/Objects/g' |sed 's/.$//'|sed 's/.$//'| sed 's/$/.o/g' > Objects.mk
