#include<windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ShellExecute(NULL, "open", "brave", "--incognito https://www.youtube.com", NULL, SW_SHOWNORMAL);
}
