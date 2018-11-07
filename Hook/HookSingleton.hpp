#pragma once

#include <utility>
#include <shared_mutex>
#include "Common/Singleton.hpp"
#include "Common/common.h"

namespace HOOK_TOOLS
{
    enum SingletonType
    {
        SingletonType_Instance,
        SingletonType_HookWnd,
        SingletonType_DestHookWnd,
    };

    template<SingletonType _Type, typename _Invalid = void>
    struct HookSingleTypeExtract
    {

    };

    template<SingletonType _Type>
    struct HookSingleTypeExtract<_Type, 
        typename std::enable_if< COMMON::__or__<_Type==SingletonType_HookWnd, _Type==SingletonType_DestHookWnd>::value, void>::type >
    {
        typedef HHOOK type;
    };

    template<SingletonType _Type>
    struct HookSingleTypeExtract<_Type, 
        typename std::enable_if< COMMON::__or__<_Type==SingletonType_Instance>::value, void>::type >
    {
        typedef HINSTANCE type;
    };
    

    template< SingletonType _Type, typename _ValueType = HookSingleTypeExtract<_Type>::type>
    struct HookSt:
    {
        using type = std::remove_const_t<std::remove_reference<_ValueType> >;
    public:
        type _value;
        mutable std::shared_mutex _rwMutex;
    };

    using InstanceSt   = HookSt<SingletonType_Instance>;
    using HookWndSt    = HookSt<SingletonType_HookWnd>;
    using DstHookWndSt = HookSt<SingletonType_DestHookWnd>;

}