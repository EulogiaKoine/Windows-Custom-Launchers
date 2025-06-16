#include<windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ShellExecute(NULL, "open", "C:\\Users\\USER\\AppData\\Local\\Obsidian\\Obsidian.exe", NULL, NULL, SW_SHOWNORMAL);
}
