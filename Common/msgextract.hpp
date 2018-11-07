#pragma once
#include <utility>
#include <WinUser.h>
#include "common.h"

namespace COMMON
{
#ifndef __WM_MSG_TYPE__
#define __HOOK_CODE__ int
#endif




    template<__HOOK_CODE__, typename _T2 = void >
    struct MsgExtract
    {

    };

    template<__HOOK_CODE__ __Code>
    struct MsgExtract<__Code, 
        typename std::enable_if<
        __or__<__Code == WH_KEYBOARD_LL, __Code == WH_KEYBOARD>::value, void>::type
    >
    {
        static WM_MYMESSAGE const myMsg = WM_MyMessage_KeyBoard;
        static __HOOK_CODE__ const hookCode = __Code;
    };

    template<__HOOK_CODE__ __Code>
    struct MsgExtract<__Code,
        typename std::enable_if<
        __or__<__Code == WH_MOUSE_LL, __Code == WH_MOUSE>::value,  void>::type
    >
    {
        static WM_MYMESSAGE const myMsg = WM_MyMessage_Mouse;
        static __HOOK_CODE__ const hookCode = __Code;
    };
}