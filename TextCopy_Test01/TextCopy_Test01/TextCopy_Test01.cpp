#include <iostream>
#include <Windows.h>
#include <Richedit.h>
int main() {
    /*
    // Notepad 창 핸들 찾기
    HWND notepadWindow = FindWindowA(NULL, "111.txt - Windows 메모장");

    if (notepadWindow == NULL) {
        std::cout << "Notepad 창을 찾을 수 없습니다." << std::endl;
        return 0;
    }

    // Notepad 텍스트 길이 가져오기
    int textLength = SendMessageA(notepadWindow, WM_GETTEXTLENGTH, 0, 0);
    if (textLength == 0) {
        std::cout << "텍스트가 없습니다." << std::endl;
        return 0;
    }

    // 텍스트를 저장할 버퍼 동적 할당
    char* buffer = new char[textLength + 1];

    // Notepad 텍스트 가져오기
    SendMessageA(notepadWindow, WM_GETTEXT, textLength + 1, (LPARAM)buffer);

    // 텍스트 출력
    std::cout << "Notepad 텍스트:\n" << buffer << std::endl;

    // 동적 할당한 버퍼 메모리 해제
    delete[] buffer;

    //
    HWND editWindow = FindWindowExA(notepadWindow, NULL, "Edit", NULL);
    if (editWindow != NULL) {
        int length = GetWindowTextLengthA(editWindow);
        std::cout << "텍스트 길이: " << length << std::endl;
    }

    //WND editWindow = FindWindowExA(notepadWindow, NULL, "Edit", NULL);
    if (editWindow != NULL) {
        int length = GetWindowTextLengthA(editWindow);
        char* buffer = new char[length + 1];
        GetWindowTextA(editWindow, buffer, length + 1);
        std::cout << "텍스트 값: " << buffer << std::endl;
        delete[] buffer;
    }

    */

    /*
    // 메모장 창 핸들 찾기
    HWND notepadWindow = FindWindowA(NULL, "111.txt - Windows 메모장");
    if (notepadWindow == NULL) {
        std::cout << "Notepad 창을 찾을 수 없습니다." << std::endl;
        return 0;
    }

    // Edit 컨트롤 핸들 찾기
    HWND editWindow = FindWindowExA(notepadWindow, NULL, "Edit", NULL);
    if (editWindow == NULL) {
        std::cout << "Edit 컨트롤을 찾을 수 없습니다." << std::endl;
        return 0;
    }

    // 텍스트 길이 가져오기
    int textLength = GetWindowTextLengthA(editWindow);
    if (textLength == 0) {
        std::cout << "텍스트가 없습니다." << std::endl;
        return 0;
    }

    // 텍스트를 저장할 버퍼 동적 할당
    char* buffer = new char[textLength + 1];

    // 텍스트 가져오기
    GetWindowTextA(editWindow, buffer, textLength + 1);

    // 텍스트 출력
    std::cout << "Edit 컨트롤 텍스트: " << buffer << std::endl;

    // 동적 할당한 버퍼 메모리 해제
    delete[] buffer;

    */
    
    // 메모장 창 핸들 찾기
    HWND notepadWindow = FindWindowA(NULL, "111.txt - Windows 메모장");
    if (notepadWindow == NULL) {
        std::cout << "Notepad 창을 찾을 수 없습니다." << std::endl;
        return 0;
    }

    // Edit 컨트롤 찾기
    HWND editControl = FindWindowExA(notepadWindow, NULL, "Edit", NULL);
    if (editControl == NULL) {
        std::cout << "Edit 컨트롤을 찾을 수 없습니다." << std::endl;
        return 0;
    }

    // 텍스트 길이 가져오기
    int textLength = GetWindowTextLength(editControl);
    if (textLength == 0) {
        std::cout << "텍스트 없음" << std::endl;
        return 0;
    }

    // 텍스트를 저장할 버퍼 동적 할당
    WCHAR* buffer = new WCHAR[textLength + 1];

    // 텍스트 가져오기
    GetWindowText(editControl, buffer, textLength + 1);

    // 텍스트 출력
    std::cout << "Edit 컨트롤 텍스트: " << buffer << std::endl;

    // 동적 할당한 버퍼 메모리 해제
    delete[] buffer;

    return 0;
}