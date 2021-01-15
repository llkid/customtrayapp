#pragma once

#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include "ui_customtrayapp.h"

//struct {
//    uint cbSize;
//
//} NOTIFYICONDATA;

class customtrayapp : public QMainWindow
{
    Q_OBJECT

public:
    customtrayapp(QWidget *parent = Q_NULLPTR);

protected:
    void closeEvent(QCloseEvent* e) override;

private:
    Ui::customtrayappClass ui;

    QSystemTrayIcon* tray;

    bool closed = false;
};
