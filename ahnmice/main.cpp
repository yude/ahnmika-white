#include <random>
#include <windows.h>

int row;
bool flag;

static void say(HWND hwnd, const wchar_t *format, ...)
{
    HDC hdc;
    RECT rect;
    wchar_t buffer[256] = {0};
    va_list args;

    hdc = GetDC(hwnd);
    GetClientRect(hwnd , &rect);

    va_start(args, format);
    vswprintf(buffer, format, args);
    va_end(args);

    ExtTextOut(hdc, 0, (row % 22) * 14, ETO_CLIPPED, &rect, buffer, wcslen(buffer), NULL);

    row++;
    ReleaseDC(hwnd , hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch(msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_KEYDOWN:
        flag = true;
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmd, int nShow)
{
    HWND hwnd;
    WNDCLASS winc;
    MSG msg;
    int count = 0;
    std::random_device rnd;
    wchar_t buf[256] = {0};

    winc.style = CS_HREDRAW | CS_VREDRAW;
    winc.lpfnWndProc = WndProc;
    winc.cbClsExtra = winc.cbWndExtra = 0;
    winc.hInstance = hInst;
    winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    winc.hCursor = LoadCursor(NULL, IDC_ARROW);
    winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    winc.lpszMenuName = NULL;
    winc.lpszClassName = TEXT("AHNMIKA");

    if (!RegisterClass(&winc)) return 0;

    hwnd = CreateWindow(
        TEXT("AHNMIKA"), TEXT("AHNMIKA"),
        WS_OVERLAPPEDWINDOW  | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL,
        hInst, NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    for (;;count++) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            DispatchMessage(&msg);
        }

        if (flag)
        {
            break;
        }

        say(hwnd, L"Shirotte %d shoku annen", 100 + (rnd() % 901));
    }

    swprintf(buf, L"%d nin no Ahnmika", count);
    MessageBox(hwnd, buf, L"Result", MB_ICONERROR);

    return msg.wParam;
}
