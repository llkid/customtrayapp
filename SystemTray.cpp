#include "SystemTray.h"

SystemTray::SystemTray(const QIcon& icon, QWidget* parent)
	: QSystemTrayIcon(icon, parent)
{
	trayMenu_ = new QMenu(parent);
	menuQss();
	trayMenu_->setFixedSize(360, 138);		//< ±ØÐëÊ¹ÓÃ setFixedSize

	createTitleWidget();
	createRemainTimeWidget();
	createExitWidget();

	trayMenu_->addAction(titleWidgetAction_);
	trayMenu_->addAction(rTWidgetAction_);
	trayMenu_->addAction(exitWidgetAction_);

	connect(titleWidgetAction_, &QWidgetAction::triggered, this, &SystemTray::__show);
	connect(exitWidgetAction_, &QWidgetAction::triggered, this, &SystemTray::__exit);
	setContextMenu(trayMenu_);
}

SystemTray::SystemTray(QWidget* parent)
	: QSystemTrayIcon(parent)
{
	trayMenu_ = new QMenu(parent);
	menuQss();
	trayMenu_->setFixedSize(360, 138);

	createTitleWidget();
	createRemainTimeWidget();
	createExitWidget();

	trayMenu_->addAction(titleWidgetAction_);
	trayMenu_->addAction(rTWidgetAction_);
	trayMenu_->addAction(exitWidgetAction_);

	connect(titleWidgetAction_, &QWidgetAction::triggered, this, &SystemTray::__show);
	connect(exitWidgetAction_, &QWidgetAction::triggered, this, &SystemTray::__exit);
	setContextMenu(trayMenu_);
}

SystemTray::~SystemTray()
{
}

void SystemTray::setDetialText(const TrayMessage& texts)
{
	titleLabel_->setText(std::get<0>(texts));
	rTLabel_->setText(std::get<1>(texts));
	exitLabel_->setText(std::get<2>(texts));
}

bool SystemTray::eventFilter(QObject* obj, QEvent* event)
{
	if (obj == titleWidget_ && event->type() == QEvent::Paint) {
		QPainter painter(titleWidget_);
		painter.setPen(Qt::NoPen);
		painter.setBrush(QBrush(qRgba(231, 242, 255, 1)));
		painter.drawRect(titleWidget_->rect());
	}

	if (obj == remainTimeWidget_ && event->type() == QEvent::Paint) {
		QPainter painter(remainTimeWidget_);
		painter.setPen(Qt::NoPen);
		painter.setBrush(QBrush(qRgba(255, 255, 255, 1)));
		painter.drawRect(remainTimeWidget_->rect());
	}
	
	if (obj == exitWidget_ && event->type() == QEvent::Paint) {
		QPainter painter(exitWidget_);
		painter.setPen(Qt::NoPen);
		painter.setBrush(QBrush(qRgba(255, 255, 255, 1)));
		painter.drawRect(exitWidget_->rect());
	}

	return QSystemTrayIcon::eventFilter(obj, event);
}

void SystemTray::createTitleWidget()
{
	titleWidget_ = new QWidget;
	titleWidgetAction_ = new QWidgetAction(trayMenu_);
	titleLabel_ = new QLabel(titleWidget_);

	titleLabel_->setStyleSheet(R"--(QLabel {
width: 91px;
height: 14px;
font-size: 14px;
font-family: MicrosoftYaHei;
color: #323232;
line-height: 14px;
})--");

	QVBoxLayout* vbLayout = new QVBoxLayout;
	vbLayout->addWidget(titleLabel_, 0, Qt::AlignCenter);
	vbLayout->setContentsMargins(24, 16, 24, 16);

	titleWidget_->setLayout(vbLayout);
	titleWidget_->installEventFilter(this);
	titleWidgetAction_->setDefaultWidget(titleWidget_);
}

void SystemTray::createRemainTimeWidget()
{
	remainTimeWidget_ = new QWidget;
	rTWidgetAction_ = new QWidgetAction(trayMenu_);
	rTLabel_ = new QLabel(remainTimeWidget_);
	rTLabel_->setStyleSheet(R"--(QLabel {
width: 143px;
height: 14px;
font-size: 14px;
font-family: MicrosoftYaHei;
color: #323232;
line-height: 14px;
})--");

	QVBoxLayout* vbLayout = new QVBoxLayout;
	vbLayout->addWidget(rTLabel_, 0, Qt::AlignCenter);
	vbLayout->setContentsMargins(24, 16, 24, 16);

	remainTimeWidget_->setLayout(vbLayout);
	remainTimeWidget_->installEventFilter(this);
	rTWidgetAction_->setDefaultWidget(remainTimeWidget_);
}

void SystemTray::createExitWidget()
{
	exitWidget_ = new QWidget;
	exitWidgetAction_ = new QWidgetAction(trayMenu_);
	exitLabel_ = new QLabel(exitWidget_);
	exitLabel_->setStyleSheet(R"--(QLabel {
width: 111px;
height: 14px;
font-size: 14px;
font-family: MicrosoftYaHei-Bold, MicrosoftYaHei;
font-weight: bold;
color: #323232;
line-height: 14px;
})--");

	QVBoxLayout* vbLayout = new QVBoxLayout;
	vbLayout->addWidget(exitLabel_, 0, Qt::AlignCenter);
	vbLayout->setContentsMargins(24, 16, 24, 16);

	exitWidget_->setLayout(vbLayout);
	exitWidget_->installEventFilter(this);
	exitWidgetAction_->setDefaultWidget(exitWidget_);
}

void SystemTray::menuQss()
{
	QFile file(":/customtrayapp/images/menu.qss");
	if (file.open(QFile::ReadOnly | QFile::Text)) {
		QByteArray content = file.readAll();
		QString styleSheet = trayMenu_->styleSheet();
		styleSheet = QString(content);
		trayMenu_->setStyleSheet(styleSheet);
		file.close();
	}
}
