#!/bin/bash

# Linting script for C++ projects

# Specify the directories to lint
SOURCE_DIRS="src include"

# clang-tidy options
CLANG_TIDY_OPTIONS="-checks=*,-clang-analyzer-alpha*"

# Run clang-tidy on all cpp files in the source directories
echo "Running clang-tidy..."
for dir in $SOURCE_DIRS; do
    find "$dir" -name '*.cpp' | xargs clang-tidy $CLANG_TIDY_OPTIONS
done

# Run cpplint on all headers and cpp files in the source directories
echo "Running cpplint..."
for dir in $SOURCE_DIRS; do
    find "$dir" -name '*.cpp' -o -name '*.hpp' -o -name '*.h' | xargs cpplint
done

echo "Linting completed."
