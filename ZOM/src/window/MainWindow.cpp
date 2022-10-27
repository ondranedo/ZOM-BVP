#include "MainWindow.h"

#include "events/EventQueue.h"

namespace ZOM
{
	void MainWindow::init()
	{
		ZOM_FUNCTION_TIMER();
		ZOM_TRACE("MainWindow initialization started");
		if(!m_SCreated) {
			m_SWindow = Window::createWindow(m_SWindowParam);
			m_SWindow->init();
			m_SCreated = true;
		}
		else {
			ZOM_ERROR("Main Window already created");
			return;
		}

		ZOM_TRACE("MainWindow initialization ended");
	}

	void MainWindow::release()
	{
		ZOM_FUNCTION_TIMER();
		if(m_SCreated) {
			ZOM_TRACE("MainWindow release started");

			m_SWindow->release();
			m_SCreated = false;

			ZOM_TRACE("MainWindow release ended");
		}
		else {
			ZOM_ERROR("Can't release MainWindow, Window not initialized");
		}
	}

	void MainWindow::setBeforeInitWindowParam(const windowParam& param)
	{
		if(!m_SCreated) m_SWindowParam = param;
		else
			ZOM_ERROR("Window already initialized, try running setBeforeInitWindowParam([Param])");
	}

	glm::vec2 MainWindow::getDims()
	{
		return {m_SWindowParam.m_Dimensions.second, m_SWindowParam.m_Dimensions.first};
	}

	void MainWindow::setEventQueue(EventQueue& event_queue)
	{
		ZOM_FUNCTION_TIMER();

		if(m_SCreated) m_SWindow->setEventCallbackFn(event_queue.getEventCallBack());
		else
			ZOM_ERROR("You have to create window, in order to set event queue");
	}

	void MainWindow::pollEvents()
	{
		ZOM_FUNCTION_TIMER();

		if(m_SCreated) m_SWindow->pollEvents();
		else
			ZOM_ERROR("You have to create window, in order to poll events");
	}

	void* MainWindow::getContextCreationAdr()
	{
		return m_SWindow->getContextCreationAdr();
	}

	std::unique_ptr<Window> MainWindow::m_SWindow;
	bool MainWindow::m_SCreated            = false;
	windowParam MainWindow::m_SWindowParam = windowParam();
}
