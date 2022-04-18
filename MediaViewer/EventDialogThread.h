#pragma once

#include <QThread>
#include <qmutex.h>
#include <queue>

#include "ObjectDetector.h"


class CEventDialogThread: public QThread
{
	Q_OBJECT


public:
	void run() override;
	
	void push(cv::Mat* Frame);

private:
	std::queue< cv::Mat> m_viewFrameQue;

	QMutex m_viewFrameQueMutex;
};
