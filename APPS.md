# How to properly work with minigfx
Since minigfx.h includes "external/stb_image.h", you will need both the source file and the "external" folder.

## Solution
Make a directory called minigfx_apps. This is where you will store all your minigfx apps. It can be any name, but it must be a directory
```
$ mkdir minigfx_apps
```

Assuming you're standing in the minigfx_apps directory, copy both of those files into your dir
```
$ cp -r path/to/minigfx/external/ path/to/minigfx/minigfx.h .
```

Now you can manage minigfx apps easily. Just make sure that on your include you will always specify where the header file is.

Also, the header file should stay in a constant position (as an example, minigfx_apps root directory, not inside another folder)
```
#define MINIGFX_IMPLEMENTATION
// ~/minigfx_apps/, and the hierarchy can change (../../minigfx.h. Just don't make it too long... two .. should be okay)
#include "../minigfx.h"
```