#include<windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// open 모드에서 매개변수는 lpParameter 쪽에 지정
	ShellExecute(NULL, "open", "chrome", "--args https://gemini.google.com", NULL, SW_SHOWNORMAL);
}
