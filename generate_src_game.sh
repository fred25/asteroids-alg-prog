#!/usr/bin/env bash
set -euo pipefail

ROOT="$(pwd)"
SRC_DIR="$ROOT/src"
DEST_DIR="$ROOT/src_game"

mkdir -p "$DEST_DIR"

echo "// Auto-generated from src/*" > "$DEST_DIR/main.c"
sed 's@#include \".*\"@#include "functions.h"@' "$SRC_DIR/main.c" >> "$DEST_DIR/main.c"

# Build functions.h with include guard, system includes, and all header bodies.
{
  echo "// Auto-generated functions header"
  echo "#ifndef SRC_GAME_FUNCTIONS_H"
  echo "#define SRC_GAME_FUNCTIONS_H"
  echo
  find "$SRC_DIR" -type f \( -name '*.h' -o -name '*.c' \) | sort | while IFS= read -r file; do
    grep -hE '^#include[[:space:]]+<.*>' "$file" || true
    grep -hE '^#include[[:space:]]+"(raylib.h|SDL2/.*|SDL.h)"' "$file" || true
  done | sort -u
  echo
  find "$SRC_DIR" -type f -name '*.h' | sort | while IFS= read -r header; do
    echo "// structs from ${header#$ROOT/}"
    awk '/^#ifndef|^#define|^#endif/ { next } { print }' "$header"
    echo
  done
  echo "#endif // SRC_GAME_FUNCTIONS_H"
} > "$DEST_DIR/functions.h"

# Build functions.c by collecting all .c implementation files except src/main.c.
{
  echo '#include "functions.h"'
  echo
  find "$SRC_DIR" -type f -name '*.c' | sort | while IFS= read -r impl; do
    if [ "$impl" = "$SRC_DIR/main.c" ]; then
      continue
    fi
    echo "// functions from ${impl#$ROOT/}"
    grep -vE '^#include[[:space:]]+"[^"]+"' "$impl" || true
    echo
  done
} > "$DEST_DIR/functions.c"

echo "Generated $DEST_DIR/main.c, $DEST_DIR/functions.c, and $DEST_DIR/functions.h"
