# Game Information

Title: (TODO: your game's title)

Author: (TODO: your name)

Design: (TODO: In two sentences or fewer, describe what is new and interesting about your game.)

Screen Shot:

![Screen Shot](screenshot.png)

How To Play:

(TODO: describe the controls and (if needed) goals/strategy.)

# Using This Code

This base code includes a variety of helpful functions and classes to get you started.

## What Is Included

Before you dive into the code, it helps to understand the overall structure of this repository.
- Files you will certainly edit:
    - ```main.cpp``` creates the game window and contains the main loop. Set your window title, size, and initial Mode here.
    - ```PongMode.*pp``` declaration+definition for a basic pong game.
    - ```Jamfile``` responsible for telling FTJam how to build the project. Change this when you add additional .cpp files and to change your runtime executable's name.
    - ```.gitignore``` ignores the ```objs/``` directory and the generated executable file. You will need to change it if your executable name changes. (If you find yourself changing it to ignore, e.g., your editor's swap files you should probably, instead be investigating making this change in the global git configuration.)
- Files you should at least read the header for:
    - ```Mode.hpp``` base class for modes (things that recieve events and draw).
    - ```gl_compile_program.hpp``` compiles OpenGL shader programs.
    - ```load_save_png.hpp``` load and save PNG images.
- Files you probably don't need to read or edit:
    - ```GL.hpp``` includes OpenGL prototypes without the namespace pollution of (e.g.) SDL's OpenGL header.
	- ```glcorearb.h```, ```gl_shims.*pp``` used by ```GL.hpp```
    - ```make-gl-shims.py``` does what it says on the tin. Included in case you are curious. You won't need to run it.

## Build Instructions

This code is set up to build across Linux, Windows, and MacOS.
This is enabled by using FTJam, the freetype projects' fork of Perforce's excellent "Jam" build tool.
For more information on Jam, see the [Jam Documentation](https://www.perforce.com/documentation/jam-documentation) page at Perforce, which includes both reference documentation and a getting started guide.

In addition, this code relies on a pre-built set of libraries to enable easy binary distrubution.
The notes below cover setting up your build environment on each platform.

### Linux

Prerequisites:
 - a recent g++
 - ftjam
 - git

These can generally be installed using your distribution's package manager, e.g.:
```
sudo apt-get install ftjam gcc git #on Debian-like Linux
```

Libraries:

The pre-build `nest-libraries` package can be downloaded from ... .


### MacOS

Prerequisites:
 - clang++ (from XCode w/ command line tools)
 - ftjam
 - git

The easiest way to install ftjam on osx is to use 
On unixish OSs, Jam is available from your package manager:
```
	brew install ftjam #on OSX
	apt-get install ftjam #on Debian-ish Linux
```



### Windows

Prerequisites:
 - a recent cl.exe
 - ftjam
 - git

These can be installed piecemeal as follows:

For cl.exe, install <a href="https://visualstudio.microsoft.com/vs/community/">Visual Studio Community</a> and select the "Desktop Development with C++" workflow.

For ftjam, download the binary [from sourceforge](https://sourceforge.net/projects/freetype/files/ftjam/2.5.2/ftjam-2.5.2-win32.zip/download),
and put it somewhere in your `%PATH%`.

For git, you can install the tools [from git-scm.com](https://git-scm.com/download/win). Make sure git is available in your `%PATH%`.

hmmm.


### Libraries

This code uses the [libSDL](https://www.libsdl.org/) library to create an OpenGL context, and the [glm](https://glm.g-truc.net) library for OpenGL-friendly matrix/vector types.
On MacOS and Linux, the code should work out-of-the-box if if you have these installed through your package manager.

If you are compiling on Windows or don't want to install these libraries globally there are pre-built library packages available in the
[kit-libs-linux](https://github.com/ixchow/kit-libs-linux),
[kit-libs-osx](https://github.com/ixchow/kit-libs-osx),
and [kit-libs-win](https://github.com/ixchow/kit-libs-win) repositories.
Simply clone into a subfolder and the build should work.

### Building

Open a terminal (or ```x64 Native Tools Command Prompt for VS 2017``` on Windows), change to the directory containing this code, and type:

```
jam
```

That's it. You can use ```jam -jN``` to run ```N``` parallel jobs if you'd like; ```jam -q``` to instruct jam to quit after the first error; ```jam -dx``` to show commands being executed; or ```jam main.o``` to build a specific file (in this case, main.cpp).  ```jam -h``` will print help on additional options.
