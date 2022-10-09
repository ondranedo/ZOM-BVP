#include "MainWindow.h"

#include "events/EventQueue.h"

namespace ZOM {
	
	void MainWindow::init()
	{
		ZOM_TRACE("MainWindow initialization started");
		if (!s_Created)
		{
			s_Window = Window::createWindow(s_WindowParam);
			s_Window->init();
			s_Created = true;
		}
		else
		{
			ZOM_ERROR("Main Window already created");
			return;
		}

		ZOM_TRACE("MainWindow initialization ended");

	}

	void MainWindow::release()
	{
		if (s_Created)
		{
			ZOM_TRACE("MainWindow release started");

			s_Window->release();
			s_Created = false;

			ZOM_TRACE("MainWindow release ended");
		}
		else
			ZOM_ERROR("Can't release MainWindow, Window not initialized");
	}

	void MainWindow::setBeforeInitWindowParam(const WindowParam& param)
	{
		if (!s_Created)
			s_WindowParam = param;
		else
			ZOM_ERROR("Window already initialized, try running setBeforeInitWindowParam([Param])");
	}

	void MainWindow::setEventQueue(EventQueue& event_queue)
	{
		if (s_Created)
			s_Window->setEventCallbackFn(event_queue.getEventCallBack());
		else
			ZOM_ERROR("You have to create window, in order to set event queue");
	}

	void MainWindow::pollEvents()
	{
		if (s_Created)
			s_Window->pollEvents();
		else
			ZOM_ERROR("You have to create window, in order to poll events");
	}

	Window* MainWindow::windowPtr()
	{
		return s_Window;
	}

	Window* MainWindow::s_Window = nullptr;
	bool MainWindow::s_Created = false;
	WindowParam MainWindow::s_WindowParam = WindowParam();
}