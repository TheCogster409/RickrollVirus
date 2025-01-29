# RickrollVirus
A simple virus to play Rick Astley's "Never Gonna Give You Up" around every 15 minutes.


To build:
Run windres music.rc -O coff -o music.res to build the audio file
Run g++ rickrollVirus.cpp music.res -o rickrollVirus.exe -lwinmm -mwindows -s -O2 to build the EXE

Then run the EXE to start!