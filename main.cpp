#include "stdafx.h"
#include "Framework.h"

int main()
{
    FRAMEWORK.Init(1920, 1080, "Timber!!");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}