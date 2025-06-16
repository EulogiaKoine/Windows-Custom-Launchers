#include<windows.h>
#include<string>
#include<vector>
using namespace std;

string encodeURL(const string& S){
	string encoded;
	for(char c : S)
		encoded += c == ' '? '+': c;
	return encoded;
}

string convertWCharToMultiByte(LPCWSTR wideStr) {
    if (!wideStr) {
        return "";
    }

    // 필요한 버퍼 크기 계산
    int bufferSize = WideCharToMultiByte(
        CP_UTF8,       // 대상 코드 페이지: UTF-8
        0,             // 플래그 (0으로 설정하여 기본 동작 사용)
        wideStr,       // 원본 유니코드 문자열
        -1,            // -1은 문자열이 null-terminated임을 의미
        NULL,          // 버퍼 (크기 계산용이므로 NULL)
        0,             // 버퍼 크기 (크기 계산용이므로 0)
        NULL, NULL     // 기본 문자 및 해당 플래그 (NULL로 설정)
    );

    if (bufferSize == 0) {
        // 변환 실패 또는 빈 문자열
        return "";
    }

    // 계산된 크기로 버퍼 할당
    std::string multiByteStr(bufferSize, 0); // null-terminator 공간 포함
    WideCharToMultiByte(
        CP_UTF8,       // 대상 코드 페이지: UTF-8
        0,             // 플래그
        wideStr,       // 원본 유니코드 문자열
        -1,            // null-terminated
        &multiByteStr[0], // 변환된 문자열을 저장할 버퍼
        bufferSize,    // 버퍼 크기
        NULL, NULL     // 기본 문자 및 해당 플래그
    );

    multiByteStr.resize(bufferSize - 1); // null-terminator 제거

    return multiByteStr;
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	string baseUrl = "http://www.google.com/search?q=";
	string query;

	// arguments
	int argc;
	LPWSTR* argv = CommandLineToArgvW(
		GetCommandLineW(), // LPWSTR entire cmd input
		&argc
	);

	if(argc > 1){
		// except program name
		for(int i = 1; i < argc; i++){
			string arg = convertWCharToMultiByte(argv[i]);
			if(i > 1)
				query += " ";
			query += arg;
		}
	}

	LocalFree(argv); // CommandLineToArgv 계열은 메모리 할당; 해제 필요
	string endpoint = baseUrl + encodeURL(query);

	// Chrome 기준
	ShellExecute(NULL, "open", "chrome.exe", endpoint.c_str(), NULL, SW_SHOWNORMAL);

	return 0;
}
