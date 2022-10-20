#include "LayerManager.h"

#include "Window/MainWindow.h"

namespace ZOM {

	void LayerManager::init()
	{
		m_Path = Config::logEventPath();

		if (Config::logEvents())
		{
			FILE* fw;
			fopen_s(&fw, m_Path.c_str(), "w");
			ZOM_ASSERT(fw, "Cant create event log file");
			fprintf(fw, "-------ZOM FILE EVENT LOG------\r\n");
			fclose(fw);
		}
	}

	void LayerManager::release()
	{
		deleteLayers();
	}

	void LayerManager::addLayerOnTop(Layer* heap_layer_addr)
	{
		m_Layers.insert(m_Layers.begin(), heap_layer_addr);

		ZOM_TRACE("Added layer[{}] to the front", heap_layer_addr->getName());
	}

	void LayerManager::addLayerToTheBack(Layer* heap_layer_addr)
	{
		m_Layers.push_back(heap_layer_addr);

		ZOM_TRACE("Added layer[{}] to the back", heap_layer_addr->getName());
	}

	void LayerManager::deleteLayers()
	{
		for (Layer* layer : m_Layers)
			delete layer;

		ZOM_TRACE("All layers deleted");
	}

	void LayerManager::updateLayers()
	{
		for (Layer* layer : m_Layers)
		{
			layer->onUpdate();
		}
	}

	void LayerManager::handleEvents(EventQueue* eventQueue)
	{	
		size_t nOfEvents = eventQueue->getEventCount();

		if(nOfEvents > 200)
			ZOM_WARNING( "Number of queued events is way too hight");

		for (size_t i = 0; i < nOfEvents; i++)
		{
			Event* event = eventQueue->getTopEvent();

			for (Layer* layer : m_Layers)
			{
				layer->onEvent(*event);
			}

			if (Config::logEvents())
			{
				storeEventToFile(event);
			}

			delete event;
		}
	}

	void LayerManager::onCreateLayers()
	{
		for (Layer* layer : m_Layers)
		{
			layer->onCreate();
		}
	}

	void LayerManager::storeEventToFile(Event* event)
	{
	
		FILE* fw;
		fopen_s(&fw, m_Path.c_str(), "a");
		ZOM_ASSERT(fw, "Can't append event to the evenrt log file");

		fprintf(fw, (event->toString() + "\r\n").c_str());
		fclose(fw);
	
	}

}

