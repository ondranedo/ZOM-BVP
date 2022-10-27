#pragma once

#include "Layer.h"
#include "events/EventQueue.h"

namespace ZOM
{
	class ZOM_API LayerManager {
	public:
		void addLayerOnTop(Layer* heap_layer_adr);
		void addLayerToTheBack(Layer* heap_layer_adr);

		void init();
		void release();

		void deleteLayers() const;
		void updateLayers() const;
		void handleEvents(EventQueue* queue);

		void onCreateLayers() const;

		void storeEventToFile(Event* event) const;

		void printLayerLayout() const
		{
			std::cout << "~~~~~~~~~~~\n";
			std::cout << " |  EVENTS  \n";
			std::cout << " |          \n";
			std::cout << " |          \n";
			std::cout << "\\|/        \n";

			for(auto i = 0 ; i < m_Layers.size() ; i++) {
				std::cout << m_Layers[i]->getName() << "\n";
			}
			std::cout << "~~~~~~~~~~~\n";
		}

	private:
		std::vector<Layer*> m_Layers;
		std::string m_Path;

	};
}
