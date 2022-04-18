#include "EventDialogmanager.h"

CEventDialogmanager* CEventDialogmanager::s_pEventDialogmanager = nullptr;


void CEventDialogmanager::init()
{
	m_eventDialogThread.start();
}

void CEventDialogmanager::push( QString CamID, cv::Mat* Frame)
{
	if (m_IsEventDialogShow == false)
		return;

	if (CamID == m_CamID)
		return;

	m_eventDialogThread.push(Frame);
}
