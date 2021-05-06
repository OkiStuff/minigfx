:: This is how you would compile a minigfx application under windows
set FILENAME=%1

gcc %FILENAME%.c -I ../include/ -L ../lib/ -lglfw3 -lopengl32 -lgdi32 -lwinmm -o %FILENAME%