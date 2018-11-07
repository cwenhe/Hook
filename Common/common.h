#pragma once
#include <WinUser.h>
#include <utility>

namespace COMMON
{
    enum WM_MYMESSAGE
    {
        WM_MyMessage_Mouse = WM_USER + 1,
        WM_MyMessage_KeyBoard,
    };

    template<bool t1, bool ...others>
    struct __or__
    {
        static  const bool value = t1 || __or__<others...>::value;
    };

    template<bool t1>
    struct __or__<t1>
    {
        static  const bool value = t1;
    };

    template<bool true_or_false>
    struct __not__
    {
        static  const bool value = !true_or_false;
    };

}
