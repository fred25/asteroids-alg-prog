Fred
player.c / player.h
bullet.c / bullet.h
input handling
score / UI (optional)

Ana
asteroid.c / asteroid.h
collision.c / collision.h
spawning.c / spawning.h
game states (game over, restart)

## Compiling the project

### Linux (GCC)

From the project root directory, run:

```bash
gcc $(find src -name '*.c' | sort) -I src/game -o asteroids -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
```

This finds all C files under `src/` recursively and adds `src/game/` to the header search path so `#include "game.h"` works.

If your project uses additional SDL2 modules or libraries, add them as needed, for example `-lSDL2_image` or `-lSDL2_mixer`.

### Windows (GCC / MinGW)

From the project root directory, run:

```bash
gcc $(find src -name '*.c' | sort) -I src/game -o asteroids.exe -lraylib -lopengl32 -lgdi32 -lwinmm -lws2_32
```

This also uses recursive file discovery, so new source modules under `src/` are included automatically.

Make sure MinGW and raylib are installed and available in your PATH. If you need raylib include or library paths, add them with `-I` and `-L` flags.

### Build and run `src_game`

After generating `src_game/`, compile it with:

```bash
gcc src_game/main.c src_game/functions.c -o asteroids -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
```

Then run the compiled game with:

```bash
./asteroids
```
