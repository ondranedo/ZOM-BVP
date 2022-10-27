#include "LayerManager.h"

#include "Window/MainWindow.h"

namespace ZOM
{
	void LayerManager::init()
	{
		m_Path = Config::logEventPath();

		if(Config::logEvents()) {
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

	void LayerManager::addLayerOnTop(Layer* heap_layer_adr)
	{
		m_Layers.insert(m_Layers.begin(), heap_layer_adr);

		ZOM_TRACE("Added layer[{}] to the front", heap_layer_adr->getName());
	}

	void LayerManager::addLayerToTheBack(Layer* heap_layer_adr)
	{
		m_Layers.push_back(heap_layer_adr);

		ZOM_TRACE("Added layer[{}] to the back", heap_layer_adr->getName());
	}

	void LayerManager::deleteLayers() const
	{
		for(const Layer* layer : m_Layers) delete layer;

		ZOM_TRACE("All layers deleted");
	}

	void LayerManager::updateLayers() const
	{
		ZOM_FUNCTION_TIMER();

		for(Layer* layer : m_Layers) {
			layer->onUpdate();
		}
	}

	void LayerManager::handleEvents(EventQueue* queue)
	{
		ZOM_FUNCTION_TIMER();

		const size_t n_of_events = queue->getEventCount();

		if(n_of_events > 200)
			ZOM_WARNING("Number of queued events is way too hight");

		for(size_t i = 0 ; i < n_of_events ; i++) {
			Event* event = queue->getTopEvent();

			for(Layer* layer : m_Layers) {
				layer->onEvent(*event);
			}

			if(Config::logEvents()) {
				storeEventToFile(event);
			}

			delete event;
		}
	}

	void LayerManager::onCreateLayers() const
	{
		ZOM_FUNCTION_TIMER();

		for(Layer* layer : m_Layers) {
			layer->onCreate();
		}
	}

	void LayerManager::storeEventToFile(Event* event) const
	{
		FILE* fw;
		auto err = 0;
		err = fopen_s(&fw, m_Path.c_str(), "a");
		ZOM_ASSERT(fw, "Can't append event to the evenrt log file");

		err = fprintf(fw, (event->toString() + "\r\n").c_str());
		err =fclose(fw);
	}
}
