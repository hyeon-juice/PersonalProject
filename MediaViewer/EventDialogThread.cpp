#include "EventDialogThread.h"
#include "Define.h"
#include <QDateTime>
#include <qimage.h>
#include "EventDialogmanager.h"

const unsigned int Frame_Que_Max_Size = 10;

void CEventDialogThread::push(cv::Mat* Frame)
{
	QMutexLocker Locker(&m_viewFrameQueMutex);

	if (Frame_Que_Max_Size < m_viewFrameQue.size())
		m_viewFrameQue.pop();

	m_viewFrameQue.push(Frame->clone());

}

void CEventDialogThread::run()
{
	cv::Mat frame;

	while(true)
	{
		{
			QMutexLocker Locker(&m_viewFrameQueMutex);

			if (m_viewFrameQue.size() == 0)
				continue;

			frame = m_viewFrameQue.front();
			m_viewFrameQue.pop();

		}

		QImage Out( (uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

		CEventDialogmanager::getInstance()->sendimage(Out);

		msleep(100);

		if(true == isInterruptionRequested())
			break;
	}
}
