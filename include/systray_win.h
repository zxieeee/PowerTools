#pragma once
#include <windows.h>
#include <shellapi.h>


class SysTrayApp {
public:
    SysTrayApp(HINSTANCE hInstance);
    ~SysTrayApp();
    
    int Run();

private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void AddTrayIcon();
    void RemoveTrayIcon();
  static  void ShowContextMenu();

    static HWND hWnd;
    static NOTIFYICONDATA nid;
    static HMENU hMenu;
};

