# CPPProjects 

This is a collection of C++ projects 

## Directory

1. [River Problem](./RiverProblem)

1. [Yahtzee](./) (Not Started)

1. [Elevator](./Elevator)

1. [Password Cracker](./PasswordCracker)

1. [Tiling Estimator](./) (Not Started)

## How To Build / Run

Currently this is built in Visual Studio 2019 but that is mainly for the .sln and .vcxproj files. The projects do work without VS.

### Visual Studio

In order to build and run the projects you must open the main CPPProjects.sln in VS and then set the startup project to "Current Selection" or whichever project you'd like to run.\
You will need to use C++ 17 to compile.

### Linux

Using modern g++ simply navigate to the folder you want to use and run : `g++ -o ProjName *.cpp`\
Of course you can make object files first. No extra libraries are currently needed.

Future plans are to create a "Manager" startup project of sorts that will let you choose any project  from it.
