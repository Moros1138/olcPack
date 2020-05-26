# olcPack

olcPack is a command-line utility for adding, and managing
files into the virtual filesystem used by the olcPixelGameEngine.

# olc::PixelGameEngine

This is meant to be used to create Resource Pack files for use
with the [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) by [Javidx9](https://github.com/OneLoneCoder)

# Building On Linux

I develop on **Ubuntu**, therefore I have instructions for the **Debian/Ubuntu** side of things.
Sorry if it seems like I'm leaving out a whole bunch of things. I am. But I promise it's
not that I don't want to do all of the research and install many versions of Linux and
do all of the testing myself... Except.... well... I don't want to.

If you develop for other Linux flavors and would like to contribute the instructions here;
feel free to make a pull request!

Building olcPack on Linux requires a modern C++ compiler. The following commands should
install everything that is necessary to build olcPack any modern **Debian/Ubuntu** based
Linux distribution.

### Installing GCC/G++/etc
```
sudo apt-get update
sudo apt-get install build-essential git
```

### Getting olcPack
```
git clone https://www.github.org/moros1138/olcPack.git
cd olcPack
```

## Building and Installing
```
make
sudo make install
```

# Building On Windows (MinGW)

### 
This video on [YouTube](https://www.youtube.com/watch?v=jnI1gMxtrB4) will tell you how to ensure you are using a modern version of MinGW, and configure your build environment. 

[![Updating MSYS2/MinGW Compiler on Windows](https://img.youtube.com/vi/jnI1gMxtrB4/0.jpg)](https://www.youtube.com/watch?v=jnI1gMxtrB4)

### Getting olcPack
```
git clone https://www.github.org/moros1138/olcPack.git
cd olcPack
```

### Building and Installing
```
mingw32-make
```

# Building On Windows (MSVC)

There's a Solution and Project provided. You should be able to simply open, build, and run it in the traditional Visual Studio way.

# Usage Examples

```
$ olcPack 
Usage:	olcPack [PACK FILE] [PACK KEY] COMMAND [file/s]

An archive for olc::PixelGameEngine Resource Packs

Commands
  add         Add files to the pack
  help        Show this menu
  list        List files in the pack
  license     Show the OneLoneCoder license
  remove      Remove files from the pack
  rename      Rename files within the pack
```

### Adding a file/s

```
$ olcPack path/to/packfile.pak "some key to use for scrambling" add file1 file2 file3
file1 added.
file2 added.
file3 added.
```

### Listing the files
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" list
file1
file2
file3
```

### Removing a file/s
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" remove file1
file1 has been removed.
```
### Renaming a file
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" rename file1 myfile1
file1 > myfile1
```

### Extract a file
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" extract file1
file1 has been extracted.
```

### Extract all files
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" extract
file1 has been extracted.
file2 has been extracted.
file3 has been extracted.
```


# License (OLC-3)

Copyright 2018, 2019, 2020 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

1. Redistributions or derivations of source code must retain the above 
   copyright notice, this list of conditions and the following disclaimer.

2. Redistributions or derivative works in binary form must reproduce 
   the above copyright notice. This list of conditions and the following 
   disclaimer must be reproduced in the documentation and/or other 
   materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its 
   contributors may be used to endorse or promote products derived 
   from this software without specific prior written permission.
    
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
