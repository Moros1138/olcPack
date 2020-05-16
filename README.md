# olcPack

olcPack is a command-line utility for adding, and managing
files into the virtual filesystem used by the olcPixelGameEngine.

# olc::PixelGameEngine

This is meant to be used to create Resource Pack files for use
with the [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) by [Javidx9](https://github.com/OneLoneCoder)

# Usage Examples

```sh
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

## Adding a file/s

```
$ olcPack path/to/packfile.pak "some key to use for scrambling" add file1 file2 file3
file1 added.
file2 added.
file3 added.
```

## Listing the files
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" list
file1
file2
file3
```

## Removing a file/s
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" remove file1
file1 has been removed.
```
## Renaming a file
```
$ olcPack path/to/packfile.pak "some key to use for scrambling" rename file1 myfile1
file1 > myfile1
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