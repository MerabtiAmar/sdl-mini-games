# Mini-jeux en C++ avec SDL 1.2

Petits jeux écrits en 2021, pendant mes deux premières années de licence en informatique (USTHB), pour apprendre la programmation graphique en autodidacte : boucle d'événements, blitting de surfaces, collisions, états de jeu. Le code est d'époque, avec des noms de variables en partie en kabyle (`netta`, `nekk`, `mazal`…).

| Jeu | Principe | Contrôles |
|---|---|---|
| [`robocop/`](robocop) | shoot'em up dans l'esprit de Space Invaders : écran d'accueil, 4 niveaux de difficulté (facile → impossible), victoire / défaite, rejouer | souris ou flèches, espace pour tirer |
| [`serpent/`](serpent) | Snake en plein écran : le serpent grandit à chaque point mangé | flèches |
| [`pong/`](pong) | Pong en plein écran | souris |
| [`tic-tac-toe/`](tic-tac-toe) | morpion à deux joueurs (X et O) sur grille, effet de dégradé ; la détection de victoire est restée inachevée | clics gauche / droit, `R` pour recommencer |
| [`mini-golf/`](mini-golf) | balle rebondissante qui finit dans l'un des six trous | aucun (animation), `Échap` pour quitter |

## Compiler

Prérequis : un compilateur C++, CMake et **SDL 1.2** avec **SDL_image** et **SDL_ttf**. Les modules `FindSDL`, `FindSDL_image` et `FindSDL_ttf` sont fournis avec CMake.

```bash
# Debian / Ubuntu
sudo apt install libsdl1.2-dev libsdl-image1.2-dev libsdl-ttf2.0-dev cmake g++
# MSYS2 (Windows)
pacman -S mingw-w64-x86_64-SDL mingw-w64-x86_64-SDL_image mingw-w64-x86_64-SDL_ttf mingw-w64-x86_64-cmake

cmake -S . -B build
cmake --build build
```

Les images sont chargées par chemin relatif : lancer chaque jeu depuis son dossier.

```bash
cd robocop && ../build/robocop/robocop
```

## Note

Ces jeux ont été développés sous Code::Blocks sur Windows, avec SDL 1.2. La configuration CMake a été ajoutée pour les publier, mais elle **n'a pas pu être testée** sur la machine de publication, faute de SDL 1.2 installée.

## Licence

Code distribué sous [licence MIT](LICENSE).

## Auteur

**Amar Merabti** — 2021.
