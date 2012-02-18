objective
=========

td3 will be a dynamically typed scripting language, similar in scope to AutoHotkey by default. We intend to make almost everything customizable and extensible, through the use of lua or c++ plugins for all of the available functions. The language itself should be cross platform, but any "compiled" binaries obviously will be platform dependent.

Our "compilation" process will involve packaging the parser with any functions/plugins used during the script's execution into a single executable file.

core features
=============
Variables
---------
Variables are all stored as strings to allow for dynamic types. Internally they are stored in a `map< vector<string>, string>` structure. By making the map's key a vector we can define infinitely dimensional arrays based on the number of elements in the vector.
e.g. `var[dim1][dim2] = value` is stored internally as `vector<string>{"var", "dim1", "dim2"} mapped to "value"}`

Functions/Commands
------------------
All functions and commands are dynamically loaded. Each one will be implemented as a lua script or a c++ plugin. We will search a directory at run time to determine the available commands.

GUI creation
------------
One of the major benefits to the windows only scripting language we are basing td3 off of is it's ability to be used to rapidly prototype gui applications. In AHK it's really simple to add a gui element to a window:
    Gui, Add, Picture, x0 y0 h350 w450, %A_WinDir%\system32\ntimage.gif
    //This adds a picture at the top left of a window, with exact width and height, loaded from a file on the system.
Eventually we hope to have commands to build windowed applications quickly and easily.

coding guidelines for td3
=========================

All code committed to td3 should conform to the guidelines as listed below.

Files
-----

These are the files and directories currently in use

* commands/ -- base language command implementations
* doc/ -- documentation on the project
* include/ -- class headers and implementations
* lua/ -- lua command plugins
* build.bat -- build script for Windows
* build.sh -- build script for Linux/OSX
* license.txt -- The project's license
* lua.cpp -- tolua++ generated lua integration file
* main.cpp -- the main program
* README.md -- this readme file
* register\_commands.cpp -- base language command registration handler

Classes
-------

Classes should all be separated with declarations in one (hpp) file and
implementations in another (cpp) file.

Style Guide
-----------

All code should be written using Allman style braces.

To improve readability `using ns::obj` statements should be used in places 
they will not affect other code. For class headers, `using` cannot be made 
local to the class; as a work around, use `#define` in the same way. For 
implementation files `using` statements can be placed at the beginning of 
the file after the `#include` section. Internal testing with `using namespace 
std` and other general `using` statements is permitted, but code containing 
them should not be committed.

If that is too complicated, we will also accept code conforming to the following style guide: http://www.thc.org/root/phun/unmaintain.html
