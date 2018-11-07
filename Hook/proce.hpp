#pragma  once
#include <cassert>
#include <memory>
#include <utility>
#include <unordered_map>
#include <windef.h>

#include "Common/common.h"

#pragma data_seg("HookWnd")
HINSTANCE g_instance = nullptr;

#pragma  data_seg()
std::unordered_map<COMMON::WM_MYMESSAGE, HHOOK> hooks;
HWND g_dstWnd = nullptr;

#pragma comment( linker, "/section:HookWnd,RWS" )

namespace COMMON
{

    template<COMMON::WM_MYMESSAGE, typename _T2 = void>
    struct HookProcess
    {
        //static LRESULT CALLBACK process(int code, WPARAM wParam, LPARAM lParam)
        //{
        //    return ::CallNextHookEx(g_hookWnd, code, wParam, lParam);
        //}
    };

    template< COMMON::WM_MYMESSAGE _Type>
    struct HookProcess<_Type, typename std::enable_if<
        __or__<_Type == WM_MyMessage_KeyBoard, _Type == WM_MyMessage_Mouse>::value, void >::type
    >
    {
        static LRESULT CALLBACK process(int code, WPARAM wParam, LPARAM lParam)
        {
            //code 
            if (HC_ACTION == code)
            {
                ::SendMessage(g_dstWnd, _Type, wParam, lParam);
            }

            auto hookPair = hooks.find(_Type);
            assert(hooks.end() != hookPair);
            return ::CallNextHookEx(hookPair->second, code, wParam, lParam);
        }
    };

    template <int code>
    bool DoSetHook(HWND hwnd)
    {
        using MsgExtract = COMMON::MsgExtract<code>;
        g_dstWnd = hwnd;
        if (hooks.end() == hooks.find(MsgExtract::myMsg))
        {
            auto hook = ::SetWindowsHookEx(MsgExtract::hookCode, COMMON::HookProcess<MsgExtract::myMsg>::process, g_instance, 0);
            hooks.insert(std::make_pair(MsgExtract::myMsg, hook));
            return true;
        }

        return false;
    }

    void DoDestroyHook()
    {
        for (auto const& hookPair : hooks)
        {
            ::UnhookWindowsHookEx(hookPair.second);
        }

        hooks.clear();
    }

}