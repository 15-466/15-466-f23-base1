# Nest

This and other 15-466 base code is built around a collection of useful libraries and functions which we will collectively call "nest".
This name captures the goal of having the various parts and functions relatively easy to reconfigure (and remove), while still forming a good support for your game.

## What Is Included

Here is a quick overview of what is included. For further information, ☺read the code☺ !
- Base code (files you will certainly edit):
	- [`main.cpp`](main.cpp) creates the game window and contains the main loop. Set your window title, size, and initial Mode here.
	- [`PlayMode.hpp`](PlayMode.hpp), [`PlayMode.cpp`](PlayMode.cpp) declaration+definition for a basic PPU demonstration. You'll probably build your game on it.
	- [`Maekfile.js`](Maekfile.js) build system. Edit to support new asset pipelines as needed. More info below.
	- [`.gitignore`](.gitignore) ignores generated files. You will need to change it if your executable name changes. (If you find yourself changing it to ignore, e.g., your editor's swap files you should probably, instead, be investigating making this change in the global git configuration.)
- Useful code (files you should investigate, but probably won't change):
	- [`PPU466.hpp`](PPU466.hpp), [`PPU466.cpp`](PPU466.cpp) very restricted sprite + background drawing class.
	- [`read_write_chunk.hpp`](read_write_chunk.hpp) templated helpers for reading chunk-based binary formats.
	- [`Load.hpp`](Load.hpp), [`Load.cpp`](Load.cpp) asset loading wrapper; load things in the global scope but not until after an OpenGL context is established.
	- [`Mode.hpp`](Mode.hpp), [`Mode.cpp`](Mode.cpp) base class for modes (things that recieve events and draw).
	- [`gl_compile_program.hpp`](gl_compile_program.hpp), [`gl_compile_program.cpp`](gl_compile_program.cpp) helper function to compiles OpenGL shader programs.
	- [`load_save_png.hpp`](load_save_png.hpp), [`load_save_png.cpp`](load_save_png.cpp) helper functions to load and save PNG images.
	- [`GL.hpp`](GL.hpp), [`GL.cpp`](GL.cpp) includes OpenGL 3.3 prototypes without the namespace pollution of (e.g.) SDL's OpenGL header; on Windows, deals with some function pointer wrangling.
	- [`gl_errors.hpp`](gl_errors.hpp) provides a `GL_ERRORS()` macro.
	- [`.github/workflows/build-workflow.yml`](.github/workflows/build-workflow.yml) sets up the repository to be built via github actions whenever it is pushed or released.
- Here be dragons (files you probably don't need to look at):
	- [`make-GL.py`](make-GL.py) does what it says on the tin. Included in case you are curious. You won't need to run it.
	- [`glcorearb.h`](glcorearb.h) used by `make-GL.py` to produce `GL.*pp`


## Build Instructions

This code is set up to build across Linux, Windows, and MacOS.

Building will be done from the command prompt, using Maek.
Maek is a build system implemented as a single javascript file.
To add or remove files from the build, read and edit [Maekfile.js](Maekfile.js).

### Setup

Setup for your development environment should be relatively simple:

 0. (Optional) Make sure your system is set up to make it easy to use your favorite code editor and git from the command prompt. So much nicer than using a GUI.
 1. Install one of our target C++ compilers:
 	- Linux: g++
	- MacOS: clang++ (from XCode). From the terminal: `xcode-select --install`
	- Windows: Visual Studio Community 2022
 2. Install [node](https://node.js):
    - Linux: e.g. `sudo apt-get install node`
	- MacOS: e.g. `brew install node`
	- Windows: [download from node's web page](https://nodejs.org/en/download/)
 3. Extract an appropriate [release of nest-libs](https://github.com/15-466/nest-libs/releases) to a sibling of this folder:
    - Linux: https://github.com/15-466/nest-libs/releases/download/v0.10/nest-libs-linux-v0.10.tar.gz
	- MacOS: https://github.com/15-466/nest-libs/releases/download/v0.10/nest-libs-macos-v0.10.tar.gz
	- Windows: https://github.com/15-466/nest-libs/releases/download/v0.10/nest-libs-windows-v0.10.zip

Once you are finished, your directory tree should looks something like this:

```
game-programming/ #can be called anything
	nest-libs/    #nest-libs from that repository's releases page
		windows/  #subdirectory name varies depending on platform
		...
	my-gameN/     #fork of the baseN code; can be called anything
		...
	...           #further subdirectories for other games
```

### Building

Once you have your development environment set up, building is as simple as opening a command prompt (see Windows Note below), changing to the game directory, and running `node Maekfile.js`.

Here are a few worthwhile variations:

```
# Simplest build command, runs as many tasks as you have CPUs:
  $ node Maekfile.js

# Variation: limit parallelism to one task at once:
  $ node Maekfile.js -j1

# Variation: run one task at once and quit if any job fails:
  $ node Maekfile.js -q -j1

# Variation: run game if build succeeds:
  $ node Maekfile.js && dist/pong

# Variation: show commands being run (perhaps useful for debugging):
  $ node Maekfile.js -v
```

*Windows Note:* you will need to use a command prompt with the visual studio tools and variables configured. The "x64 Native Tools Command Prompt for VS2022" start menu option provides this option.

## A Word About Github Actions

This repository is equipped with a `.github/workflows/build-workflow.yml` file that tells github that you would like it to build the code for you whenever you push code.
This is a great way to check if things are working cross-platform and even to package releases of your game (the workflow is set up such that if you create a release through the github web UI, it will automatically build, package, and upload binaries to the release).

It can also be a frustrating and time-wasting trap to try to debug any build failures solely using github actions. Use it as a check, but not a development environment.
