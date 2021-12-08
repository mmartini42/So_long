#!/bin/bash

echo "SRCS += " > ./Sources/Config/Sources.mk
find Sources -name '*.c' | sed 's/^/SRCS += /' > ./Sources/Config/Sources.mk
echo "HEADER += " > ./Sources/Config/Header.mk
find Includes -name '*.h' | sed 's/^/HEADER += /' > ./Sources/Config/Header.mk
