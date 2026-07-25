#!/bin/sh
# Update the CMake project version from the CMakeLists.txt
# Usage: sh scripts/update-cmake-version.sh <new_version>

set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <new_version>"
  exit 1
fi

NEW_VERSION="$1"
CMAKE_FILE="CMakeLists.txt"

if [ ! -f "$CMAKE_FILE" ]; then
  echo "Error: $CMAKE_FILE not found"
  exit 1
fi

# Replace the VERSION line in the project() declaration
# Matches: project(console\n    VERSION x.y.z
sed -i "s/^project(console$/project(console/" "$CMAKE_FILE"
sed -i "s/    VERSION [0-9]*\.[0-9]*\.[0-9]*/    VERSION $NEW_VERSION/" "$CMAKE_FILE"

echo "Updated CMake version to $NEW_VERSION"
