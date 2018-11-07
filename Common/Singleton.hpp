#pragma once
#include <cassert>
#include <memory>
#include <mutex>

namespace COMMON
{
    template<typename _T>
    class Singleton
    {
    public:
        static Singleton& instance()
        {
            if (nullptr == _instance.get())
            {
                std::lock_guard<decltype(_instanceMutex)> guard(_instanceMutex);
                if (nullptr == _instance.get())
                {
                    _instance.reset(new Singleton);
                }
                assert(nullptr != _instance.get());
            }

            return *_instance.get();
        }

    protected:
        Singleton()
        {

        }

        ~Singleton()
        {

        }

    private:
        static std::unique_ptr<Singleton> _instance;
        static std::mutex _instanceMutex;
    };

    //template<typename _T>
    //std::unique_ptr < Singleton<_T> > Singleton<_T>::_instance;

    //template<typename _T>
    //std::mutex Singleton<_T>::_instanceMutex;
}