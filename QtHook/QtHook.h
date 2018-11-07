#pragma once

#include <wtypes.h>
#include <QtWidgets/QDialog>
#include "ui_QtHook.h"

class QtHook : public QDialog
{
    Q_OBJECT

public:
    QtHook(QWidget *parent = Q_NULLPTR);

    ~QtHook();

protected:
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;

private:
    Ui::QtHookClass ui;
    HMODULE _lib;
    bool _isCap;
};
