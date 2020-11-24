#include "mykeypress.h"

MyKeyPress::MyKeyPress() : frameRate(16.7)
{
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan =  0x2D; // DirectInput key scancode for the "A" key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
}

void MyKeyPress::up(int frames)
{
    ip.ki.wScan = 0x2C;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(frames*frameRate);

    ip.ki.wScan = 0x2C;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));
}

void MyKeyPress::left(int frames)
{
    ip.ki.wScan = 0x2D;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(frames*frameRate);

    ip.ki.wScan = 0x2D;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));
}

void MyKeyPress::right(int frames)
{
    ip.ki.wScan = 0x2E;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(frames*frameRate);

    ip.ki.wScan = 0x2E;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));
}

void MyKeyPress::leftUp(int frames)
{
    ip.ki.wScan = 0x2C;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wScan = 0x2D;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(frames*frameRate);

    ip.ki.wScan = 0x2D;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wScan = 0x2C;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));
}

void MyKeyPress::rightUp(int frames)
{
    ip.ki.wScan = 0x2C;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wScan = 0x2E;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(frames*frameRate);

    ip.ki.wScan = 0x2E;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wScan = 0x2C;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));
}

void MyKeyPress::stay(int frames)
{
    Sleep(frames*frameRate);
}

void MyKeyPress::suicide()
{
    ip.ki.wScan = 0x2F;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(1);

    ip.ki.wScan = 0x2F;
    ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
    SendInput(1, &ip, sizeof(INPUT));
}


