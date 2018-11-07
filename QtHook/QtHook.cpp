#include <wtypes.h>
#include <tchar.h>
#include <QLibrary>

#include "QtHook.h"
#include "Common/common.h"


QtHook::QtHook(QWidget *parent)
    : QDialog(parent)
{
    _isCap = false;
    //QLibrary lib("Hook.dll");
    //lib.load();
    //if (lib.isLoaded())
    //{
    //    using SetHooKFun = BOOL (*)(HWND);
    //    auto fun = (SetHooKFun)lib.resolve("SetHooK");
    //    if (fun)
    //    {
    //        fun((HWND)winId());
    //    }
    //}
    //lib.unload();

#ifdef _DEBUG
    _lib = ::LoadLibrary(_T("Hookd.dll"));
#else
    _lib = ::LoadLibrary(_T("Hook.dll"));
#endif // DEBUG

    if (_lib)
    {
        using SetHooKFun = BOOL(*)(HWND);
        auto callFun = (SetHooKFun)::GetProcAddress(_lib, "SetHooK");
        if (nullptr != callFun)
        {
            callFun((HWND)winId());
        }

    }


    ui.setupUi(this);
}

QtHook::~QtHook()
{
    if (_lib)
    {
        using DestroyFun = void(*)();
        auto destroyFun = (DestroyFun)::GetProcAddress(_lib, "DestroyHook");
        if (nullptr != destroyFun)
        {
            destroyFun();
        }

    }

}

bool QtHook::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = (MSG*)message;
    if (msg->message == COMMON::WM_MyMessage_KeyBoard && msg->wParam == WM_KEYDOWN)
    {
        auto keyNum = (KBDLLHOOKSTRUCT *)msg->lParam;
        if (WM_KEYDOWN == msg->wParam)
        {
            if(VK_CAPITAL == keyNum->vkCode)
            {
                _isCap = !_isCap;
            }

            if ('A' <= keyNum->vkCode && keyNum->vkCode <= 'Z')
            {
                QString tmp = ui._textEdit->toPlainText();
                char curValue = keyNum->vkCode;
                if (!_isCap)
                {
                   curValue += 32;
                }
                tmp.append(curValue);
                ui._textEdit->setText(tmp);
            }
        }
    }
    return false;

}
