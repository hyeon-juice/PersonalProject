#pragma once

#include <qwidget.h>
#include <qdialog.h>
#include <qmutex.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qobject.h>

#include "ui_dialog.h"

#include <qdebug.h>

#include "EventDialogmanager.h"

class CEventDialog : public QDialog
{
	Q_OBJECT

private:
	void init();
	void uninit();

public:
	explicit CEventDialog(QDialog* pParent = Q_NULLPTR) : QDialog(pParent){	 ui.setupUi(this); }


protected:
	virtual void showEvent(QShowEvent *event) {  init();  emit changeEventDialogStatus(true); }

	virtual void closeEvent(QCloseEvent *event) { uninit();   emit changeEventDialogStatus(false); }

signals : 
	void changeEventDialogStatus(bool IsON);

public slots : 
	void receiveimage(QImage img);

private :
	Ui::Dialog ui;

	QLabel* m_pLabel = nullptr;
	QVBoxLayout* m_pLayout = nullptr;

	
};

