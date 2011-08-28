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
