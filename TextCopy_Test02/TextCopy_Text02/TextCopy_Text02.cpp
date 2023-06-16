/*
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

// Notepad의 핸들을 반환하는 함수
HWND GetNotepadHandle() {
    HWND hwnd = nullptr;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };

    if (Process32First(hSnap, &pe32)) {
        do {
            if (_tcscmp(pe32.szExeFile, _T("notepad.exe")) == 0) {
                hwnd = FindWindowEx(NULL, NULL, _T("Notepad"), NULL);
                break;
            }
        } while (Process32Next(hSnap, &pe32));
    }

    CloseHandle(hSnap);
    return hwnd;
}

// Notepad의 텍스트를 가져오는 함수
std::string GetNotepadText(HWND hwnd) {
    const int BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE] = { 0 };

    // Notepad의 텍스트를 읽어옵니다.
    SendMessage(hwnd, WM_GETTEXT, BUFFER_SIZE, (LPARAM)buffer);

    return std::string(buffer);
}

int main() {
    // Notepad 핸들을 얻습니다.
    HWND notepadHwnd = GetNotepadHandle();

    if (notepadHwnd != nullptr) {
        // Notepad의 텍스트를 가져옵니다.
        std::string text = GetNotepadText(notepadHwnd);

        // 텍스트를 출력합니다.
        std::cout << text << std::endl;
    }
    else {
        std::cout << "Notepad이 실행 중이 아닙니다." << std::endl;
    }

    return 0;
}
*/
#include <iostream>
#include <windows.h>

int main() {
    HWND notepadHwnd = FindWindow(NULL, TEXT("*111.txt - Windows 메모장"));

    if (notepadHwnd != NULL) {
        HWND editHwnd = FindWindowEx(notepadHwnd, NULL, TEXT("Edit"), NULL);
        if (editHwnd != NULL) {
            int textLength = SendMessage(editHwnd, WM_GETTEXTLENGTH, 0, 0);
            if (textLength > 0) {
                textLength++; // Null 문자 공간 추가

                TCHAR* buffer = new TCHAR[textLength];
                SendMessage(editHwnd, WM_GETTEXT, textLength, (LPARAM)buffer);

                std::wcout << buffer << std::endl;

                delete[] buffer;
            }
        }
    }
    else {
        std::cout << "Notepad이 실행 중이 아닙니다." << std::endl;
    }

    return 0;
}