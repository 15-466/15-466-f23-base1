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
    - ```make-GL.py``` does what it says on the tin. Included in case you are curious. You won't need to run it.
