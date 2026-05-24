@echo off
setlocal EnableDelayedExpansion

set "ROOT=%~dp0"
set "SRC_DIR=%ROOT%src"
set "DEST_DIR=%ROOT%src_game"

if not exist "%DEST_DIR%" mkdir "%DEST_DIR%"

powershell -NoProfile -Command ^
  $src = Join-Path $PSScriptRoot 'src'; ^
  $dest = Join-Path $PSScriptRoot 'src_game'; ^
  if (-not (Test-Path $dest)) { New-Item -ItemType Directory -Path $dest | Out-Null }; ^
  $main = Get-Content (Join-Path $src 'main.c') | ForEach-Object { if ($_ -match '^	*#include\s+"game\.h"\s*$') { '#include "functions.h"' } else { $_ } }; ^
  Set-Content -Path (Join-Path $dest 'main.c') -Value $main; ^
  $includes = Get-ChildItem -Path $src -Recurse -Include *.c,*.h | ForEach-Object { Select-String -Pattern '^[ \t]*#include\s+<.*>|^[ \t]*#include\s+"(raylib\.h|SDL2/.*|SDL\.h)"' -Path $_.FullName -AllMatches } | ForEach-Object { $_.Matches } | ForEach-Object { $_.Value.Trim() } | Sort-Object -Unique; ^
  $headerLines = @(); ^
  $headerLines += '// Auto-generated functions header'; ^
  $headerLines += '#ifndef SRC_GAME_FUNCTIONS_H'; ^
  $headerLines += '#define SRC_GAME_FUNCTIONS_H'; ^
  $headerLines += ''; ^
  $headerLines += $includes; ^
  $headerLines += ''; ^
  Get-ChildItem -Path $src -Recurse -Filter *.h | Sort-Object FullName | ForEach-Object { ^
    $relative = $_.FullName.Substring($src.Length + 1).Replace('\', '/'); ^
    $headerLines += "// structs from src/$relative"; ^
    Get-Content $_.FullName | Where-Object { $_ -notmatch '^[ \t]*#ifndef|^[ \t]*#define|^[ \t]*#endif' } | ForEach-Object { $headerLines += $_ }; ^
    $headerLines += ''; ^
  }; ^
  $headerLines += '#endif // SRC_GAME_FUNCTIONS_H'; ^
  Set-Content -Path (Join-Path $dest 'functions.h') -Value $headerLines; ^
  $functions = @(); ^
  $functions += '#include "functions.h"'; ^
  $functions += ''; ^
  Get-ChildItem -Path $src -Recurse -Filter *.c | Sort-Object FullName | Where-Object { $_.Name -ne 'main.c' } | ForEach-Object { ^
    $relative = $_.FullName.Substring($src.Length + 1).Replace('\', '/'); ^
    $functions += "// functions from src/$relative"; ^
    Get-Content $_.FullName | Where-Object { $_ -notmatch '^[ \t]*#include\s+".*"' } | ForEach-Object { $functions += $_ }; ^
    $functions += ''; ^
  }; ^
  Set-Content -Path (Join-Path $dest 'functions.c') -Value $functions

echo Generated %DEST_DIR%\main.c, %DEST_DIR%\functions.c, and %DEST_DIR%\functions.h
endlocal
