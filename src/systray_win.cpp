#include "../include/systray_win.h"
#include <iostream>

#define WM_TRAYICON (WM_USER + 1)

HWND SysTrayApp::hWnd;
NOTIFYICONDATA SysTrayApp::nid;
HMENU SysTrayApp::hMenu;

SysTrayApp::SysTrayApp(HINSTANCE hInst) {
  WNDCLASS wc = {0};
  wc.lpfnWndProc = SysTrayApp::WndProc;
  wc.hInstance = hInst;
  wc.lpszClassName = TEXT("SysTrayApp");

  RegisterClass(&wc);

  hWnd = CreateWindow(wc.lpszClassName, TEXT("Hidden Window"),
                      WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, NULL, NULL, hInst, NULL);

  if (!hWnd) {
    std::cerr << "Window creation failed!\n";
  }
}

SysTrayApp::~SysTrayApp() {
  RemoveTrayIcon();
  DestroyWindow(hWnd);
}

void SysTrayApp::AddTrayIcon() {
  nid.cbSize = sizeof(NOTIFYICONDATA);
  nid.hWnd = hWnd;
  nid.uID = 1;
  nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
  nid.uCallbackMessage = WM_TRAYICON;
  nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  lstrcpy(nid.szTip, TEXT("gtk_multimedia_organiser"));

  Shell_NotifyIcon(NIM_ADD, &nid);
}

void SysTrayApp::RemoveTrayIcon() { Shell_NotifyIcon(NIM_DELETE, &nid); }

void SysTrayApp::ShowContextMenu() {
  POINT pt;
  GetCursorPos(&pt);
  hMenu = CreatePopupMenu();
  AppendMenu(hMenu, MF_STRING, 1, TEXT("Open"));
  AppendMenu(hMenu, MF_STRING, 2, TEXT("Exit"));

  SetForegroundWindow(hWnd);
  int cmd = TrackPopupMenu(hMenu, TPM_RETURNCMD | TPM_NONOTIFY, pt.x, pt.y, 0,
                           hWnd, NULL);
  DestroyMenu(hMenu);

  switch (cmd) {
  case 1:
    MessageBox(NULL, TEXT("OOps work in progress 🛠️"), TEXT("Info"), MB_OK);
    break;
  case 2:
    PostQuitMessage(0);
    break;
  }
}

LRESULT CALLBACK SysTrayApp::WndProc(HWND hWnd, UINT message, WPARAM wParam,
                                     LPARAM lParam) {
  switch (message) {
  case WM_TRAYICON:
    if (lParam == WM_RBUTTONUP) {
      ShowContextMenu(); // Directly call the method
    }
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

// Runs the message loop
int SysTrayApp::Run() {
  AddTrayIcon();

  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 1;
}
