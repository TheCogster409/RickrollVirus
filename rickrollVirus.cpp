#include <Windows.h>
#include "mmsystem.h"
#include <random>

#pragma comment(lib, "winmm.lib")
using namespace std;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    int waitTime = 0;
    random_device rd;
    
    HRSRC handle = FindResource(NULL, TEXT("WAVFILE"), TEXT("WAV"));
    HGLOBAL handleToLoaded = LoadResource(NULL, handle);
    void* audio = LockResource(handleToLoaded);

    while (true){
        uniform_int_distribution<int> dist(600, 1200);
        waitTime = dist(rd);
        Sleep(waitTime * 1000);

        PlaySound((LPCSTR)audio, NULL, SND_MEMORY | SND_SYNC);
    }
    return 0;
}