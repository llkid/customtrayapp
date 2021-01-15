#include "customtrayapp.h"

#include <QMenu>
#include <iostream>
#include <QCloseEvent>
#include "SystemTray.h"

using namespace std;

struct Data {
	uint8_t a;
	uint8_t b;
	QByteArray ba;
};

customtrayapp::customtrayapp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	//setWindowFlags(Qt::WindowSystemMenuHint);

	/*QAction* showMainAction = new QAction(QObject::tr("Show main window"), this);
	connect(showMainAction, &QAction::triggered, [this] { show(); });

	QAction* exitAppAction = new QAction(QObject::tr("Quit"), this);
	connect(exitAppAction, &QAction::triggered, [this] { closed = true; this->close(); });

	QMenu* menu = new QMenu(this);
	menu->addSeparator();
	menu->addAction(showMainAction);
	menu->addAction(exitAppAction);

	tray = new QSystemTrayIcon(this);
	tray->setIcon(QIcon(":/customtrayapp/images/detail_luna_off.png"));
	tray->show();
	tray->setToolTip("eMeetLink");
	tray->setContextMenu(menu);*/

	SystemTray* systemTray = new SystemTray(this);
	connect(systemTray, &SystemTray::__show, [this] { show(); });
	connect(systemTray, &SystemTray::__exit, [this] {
		closed = true;
		this->close();
		});
	systemTray->setIcon(QIcon(":/customtrayapp/images/detail_luna_off.png"));
	systemTray->show();
	systemTray->setToolTip("eMeetLink");
	systemTray->setDetialText(TrayMessage(
		QString::fromLocal8Bit("eMeet HS100"),
		QString::fromLocal8Bit("剩余通话时间：12小时"),
		QString::fromLocal8Bit("退出 eMeet Link")
	));
}

void customtrayapp::closeEvent(QCloseEvent* e)
{
	if (closed) {
		e->accept();
	}
	else {
		e->ignore();
		this->hide();
	}
}
