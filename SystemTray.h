#pragma once
#include <qsystemtrayicon.h>
#include <QtWidgets>
#include <tuple>

using TrayMessage = std::tuple<QString, QString, QString>;

class SystemTray :
    public QSystemTrayIcon
{
    Q_OBJECT

public:
    explicit SystemTray(const QIcon& icon, QWidget* parent = nullptr);
    explicit SystemTray(QWidget* parent = nullptr);
    ~SystemTray();

    /*
        @brief 设置菜单项显示文本
        @params texts 
    */
    void setDetialText(const TrayMessage& texts);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

Q_SIGNALS:
    void __exit();
    void __show();

private:
    QMenu* trayMenu_;

    QWidget* titleWidget_;
    QLabel* titleLabel_;
    QWidgetAction* titleWidgetAction_;

    QWidget* remainTimeWidget_;
    QLabel* rTLabel_;
    QWidgetAction* rTWidgetAction_;

    QWidget* exitWidget_;
    QLabel* exitLabel_;
    QWidgetAction* exitWidgetAction_;

private:
    void createTitleWidget();
    void createRemainTimeWidget();
    void createExitWidget();
    void menuQss();
};

