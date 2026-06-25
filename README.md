# Asteroids - Algoritmos e Programação

Este trabalho é uma versão simples do jogo Asteroids desenvolvida em C usando a biblioteca Raylib, desenvolvido para a cadeira de Algoritmos de Programacao UFRGS 2026/1.

## Sobre o projeto

O jogo carrega níveis a partir de arquivos de texto em `files/niveis/`. Cada nível define a posição inicial do jogador e os asteroides que devem aparecer na fase.

## Estrutura do código

- `src/main.c` - entrada principal do programa
- `src/game/game.c`, `src/game/game.h` - lógica do jogo, estados e fluxo principal
- `src/game/definitions.c`, `src/game/definitions.h` - utilitários de desenho e movimento
- `src/entities/player.c`, `src/entities/player.h` - controle do jogador e disparo de balas
- `src/entities/bullet.c`, `src/entities/bullet.h` - comportamento das balas
- `src/entities/asteroid.c`, `src/entities/asteroid.h` - lógica e desenho de asteroides
- `src/systems/collision.c`, `src/systems/collision.h` - detecção de colisões e penalidades

## Como compilar

### Linux (GCC)

No diretório raiz do projeto, execute:

```bash
gcc $(find src -name '*.c' | sort) -I src -o asteroids -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
```

Isso compila todos os arquivos `.c` em `src/` e linka com a biblioteca Raylib.

### Windows (GCC / MinGW)

No diretório raiz do projeto, execute:

```bash
gcc $(find src -name '*.c' | sort) -I src -o asteroids.exe -lraylib -lopengl32 -lgdi32 -lwinmm -lws2_32
```

Certifique-se de que MinGW e Raylib estejam instalados e acessíveis via `PATH`.

## Como executar

Depois de compilar, execute o binário gerado:

```bash
./asteroids
```

No Windows:

```bash
asteroids.exe
```

## Observações

- Os arquivos de nível devem estar em `files/niveis/nivel_1.txt`, `nivel_2.txt`, etc.
- O jogo salva o estado em `files/save.bin`.