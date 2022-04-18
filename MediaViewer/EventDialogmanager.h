#pragma once

#include <QObject>
#include <QMutex>
#include <QDateTime>
#include <QTimer>
#include <qimage.h>
#include <qstring.h>

#include "EventDialogThread.h"


class CEventDialogmanager : public QObject
{
	Q_OBJECT

private : 
	CEventDialogmanager() {}
	~CEventDialogmanager() {}

	static CEventDialogmanager* s_pEventDialogmanager;

public : 
	CEventDialogmanager(const CEventDialogmanager&) = delete;
	CEventDialogmanager& operator =(const CEventDialogmanager&) = delete;

	static CEventDialogmanager* getInstance()
	{
		if (nullptr == s_pEventDialogmanager)
		{
			static QMutex mutex;

			{
				QMutexLocker mutexLocker(&mutex);

				if (nullptr == s_pEventDialogmanager)
					s_pEventDialogmanager = new CEventDialogmanager;
			}
		}

		return s_pEventDialogmanager;
	}

public : 
	void init();
	void push( QString CamID, cv::Mat* Frame );


public : 
	bool getEventDialogShowStatus() { return m_IsEventDialogShow;  }

	void setViewCameraID(QString CamID) { m_CamID = CamID;  }
	QString getViewCameraID() { return m_CamID;  }

signals : 
	void sendimage(QImage img);

public slots : 
	void IsEventDialogShow(bool IsShow) { m_IsEventDialogShow = IsShow; }

private : 

	
	bool m_IsEventDialogShow = false;

	QString m_CamID = ""; 	//QString m_StorIP;


	CEventDialogThread m_eventDialogThread;





};

