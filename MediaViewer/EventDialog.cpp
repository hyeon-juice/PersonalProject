#include "EventDialog.h"


void CEventDialog::init()
{
	this->setWindowTitle("Image Viewer ");

	this->setFixedSize(520, 520);

	if (m_pLabel == nullptr)
	{
		m_pLabel = new QLabel();
		m_pLabel->setText("ViewLabel");
		m_pLabel->setFixedSize(500, 500);
	}

	if (m_pLayout == nullptr)
	{
		m_pLayout = new QVBoxLayout();
	}

	m_pLayout->addWidget(m_pLabel);
	this->setLayout(m_pLayout);

	QObject::connect( CEventDialogmanager::getInstance(), &CEventDialogmanager::sendimage, this, &CEventDialog::receiveimage );
	QObject::connect( this, &CEventDialog::receiveimage, CEventDialogmanager::getInstance(), &CEventDialogmanager::IsEventDialogShow );

}

void CEventDialog::uninit()
{
	if (m_pLabel != nullptr)
	{
		delete m_pLabel;
		m_pLabel = nullptr;
	}

	if (m_pLayout != nullptr)
	{
		delete m_pLayout;
		m_pLayout = nullptr;
	}

}


void CEventDialog::receiveimage(QImage Out)
{
	if (m_pLabel == nullptr || m_pLayout == nullptr)
		return;

	if (Out.isNull() == true)
		return;

	QPixmap buffer; 
	buffer = QPixmap::fromImage(Out);
	m_pLabel->setPixmap(buffer.QPixmap::scaled( 500, 500, Qt::IgnoreAspectRatio));

	return;
}

