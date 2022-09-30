#include "LayerManager.h"

namespace ZOM {

	LayerManager::LayerManager()
	{

	}

	LayerManager::~LayerManager()
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
		ZOM_WARNING("All layers deleted");

		for (Layer* layer : m_Layers)
			delete layer;
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
		
		ZOM_ASSERT(nOfEvents < 200, "Number of queued events is way too hight");

		for (size_t i = 0; i < nOfEvents; i++)
		{
			Event* event = eventQueue->getTopEvent();

			for (Layer* layer : m_Layers)
			{
				layer->onEvent(*event);
			}

			delete event;
		}
	}
}

