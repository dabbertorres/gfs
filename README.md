# gfs
A Generic File System library for C++.  

Created out of my own need for easy access to the filesystem without plaguing code with macros and such for each OS.

## Archiving in favor of the standard [Filesystem library](https://en.cppreference.com/w/cpp/filesystem).

## Requirements
* C++11 compatible compiler.
* A not-broken OS

## Concepts
A 'Path' class is what this lib centers around. A 'Path' represents a file system entity. File, directory, link, etc. (Other file system entities (sockets, pipes, blocks, etc) are recognized, but essentially nothing is done with them, at the moment)

A Path object can be created by giving it a string, anything really. If the OS can recognize it as a path, it will attempt to use it as a path. If it is valid, it can be used.

A Path simply contains info about itself. Does it exist? If so, what is it? When was it last modified? What is its size? Permissions? Etc. It can also be easily casted to a std::string or a c-string (and a bool to check if it exists).

Paths can also be concatenated. Using the '+' operator simply combines, using the '/' operator adds a directory divider between the two Paths before putting them together.

File system operations are done via free-functions.
Current listing:
* workingDir: returns a Path to the current working directory
* selfPath: returns a Path to the current running executable
* userHome: returns a Path to the current user's home directory
* readSymlink: Accepts a Path, and if it is a symlink, returns a Path to it's target
* hardLinkCount: Accepts a Path, and returns the number of hard links to it's file's data.
* contents: Accepts a Path, and if it is a directory, returns it's contents.
* makeDir: Accepts a Path, and if it does not exist, creates a directory there.
* makeFile: Accepts a Path, and if it does not exist, creates a file there.
* remove: Accepts a Path, and if it exists, removes it.
* move: Accepts two Paths, a source, and a destination, and if the source exists, and the destination doesn't, moves the source to the destination.

## Progress
* Linux implementation is done. 
* Windows implementation is pretty much done. Needs some tweaking (not liking symlinks at the moment).
* OSX is non-existent, as I have no OSX machine to test on. Will try to get it done regardless though.
