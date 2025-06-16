#include<windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ShellExecute(NULL, "open", "C:\\Program Files (x86)\\Kakao\\KakaoTalk\\KakaoTalk.exe", NULL, NULL, SW_SHOWNORMAL);
}
