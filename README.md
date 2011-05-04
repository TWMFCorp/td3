coding guidelines for td3
=========================

All code commited to td3 should conform to the guidelines as listed below.

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
* README -- this readme file
* register_commands.cpp -- base language command registration handler

Classes
-------

Classes should all be separated with declarations in one (hpp) file and
implementations in another (cpp) file.

Style Guide
-----------

All code should be written using Allman style braces. To improve readability 
'using ns::func' statements should be used in places they will not affect 
other code. For class header files, this means they should be put within the 
class definition. For implementation files they can be placed anywhere.
Internal testing with 'using namespace std' is permitted, but code containing 
it should not be committed.
