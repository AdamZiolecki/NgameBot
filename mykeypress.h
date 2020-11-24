#ifndef MYKEYPRESS_H
#define MYKEYPRESS_H

#include <Windows.h>


class MyKeyPress
{
public:
    MyKeyPress();

    void up(int frames);
    void left(int frames);
    void right(int frames);
    void leftUp(int frames);
    void rightUp(int frames);
    void stay(int frames);
    void suicide();

    INPUT ip;
    const double frameRate;
};

#endif // MYKEYPRESS_H
