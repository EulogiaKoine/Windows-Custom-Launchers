#include<windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ShellExecute(NULL, "open", "chrome.exe --args https://gemini.google.com", NULL, NULL, SW_SHOWNORMAL);
}
