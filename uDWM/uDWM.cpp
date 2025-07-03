// uDWM.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "uDWM.h"


// This is an example of an exported variable
UDWM_API int nuDWM=0;

// This is an example of an exported function.
UDWM_API int fnuDWM(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CuDWM::CuDWM()
{
    return;
}
