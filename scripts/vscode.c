#include<windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ShellExecute(NULL, "open", "C:\\Users\\USER\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe", NULL, NULL, SW_SHOWNORMAL);
}
