
#include <windows.h>
#include <sstream>
#include <iostream>
#include "Common/msgextract.hpp"
#include "Common/Singleton.hpp"
#include "proce.hpp"




BOOL WINAPI DllMain(HINSTANCE hinstance, DWORD reasonForCall, LPVOID reserve)
{
    switch (reasonForCall)
    {
    case DLL_PROCESS_ATTACH:
    {
        if (nullptr == g_instance)
        {
            //MessageBox(nullptr, TEXT("dll initial"), TEXT("tip"), MB_OK);
            g_instance = hinstance;
        }
        else
        {
            //MessageBox(nullptr, TEXT("dll has call once"), TEXT("tip"), MB_OK);
        }

        break;

    }
    case DLL_PROCESS_DETACH:
    {
        g_instance = nullptr;
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    default:
        break;


    }
    return TRUE;
}


EXTERN_C
{
    __declspec(dllexport) BOOL SetHooK(HWND hwnd)
    {
        if (NULL == hwnd)
        {
            return FALSE;
        }
        return COMMON::DoSetHook<WH_KEYBOARD_LL>(hwnd);
    }

    __declspec(dllexport) void DestroyHook()
    {
       COMMON::DoDestroyHook();
    }

}

