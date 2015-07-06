# REQUIREMENTS:
#  A terminal that undestands:
#    curl, unzip, cmake-gui, mkdir, mv, rm, cd
# 
#  A working internet connection
#
# This file should be run in Recreito/utils
# Directory layout:
#
# Recreito/
#     build/
#     cmake/
#	  lib/
#     src/
#     utils/
#         installSDL2.sh
cd ..
echo "Downloading SDL 2.0.3..."
mkdir temp
curl https://www.libsdl.org/release/SDL2-2.0.3.zip > temp/SDL2.zip
echo "Unzipping..."
cd temp
unzip SDL2.zip
mv ./SDL2-2.0.3 ../lib/SDL2-2.0.3
cd ..
rm -r temp
echo "Fixing code layout..."
mkdir lib/SDL2-2.0.3/include/SDL2
cp lib/SDL2-2.0.3/include/* lib/SDL2-2.0.3/include/SDL2
echo "Building SDL2 with CMake GUI..."
cd lib/SDL2-2.0.3/build/debug
cmake-gui ../..