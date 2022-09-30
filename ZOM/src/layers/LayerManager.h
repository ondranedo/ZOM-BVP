#pragma once

#include "Layer.h"
#include "events/EventQueue.h"

namespace ZOM {
	class ZOM_API LayerManager {
	public:
		LayerManager();
		~LayerManager();
		void addLayerOnTop(Layer* heap_layer_addr);
		void addLayerToTheBack(Layer* heap_layer_addr);

		void deleteLayers();
		void updateLayers();
		void handleEvents(EventQueue* queue);

		void printLayerLayout()
		{
			std::cout << "~~~~~~~~~~~\n";
			std::cout << " |  EVENTS  \n";
			std::cout << " |          \n";
			std::cout << " |          \n";
			std::cout << "\\|/        \n";

			for (int i = 0; i < m_Layers.size(); i++)
			{
				std::cout << m_Layers[i]->getName() << "\n";
			}
			std::cout << "~~~~~~~~~~~\n";
		}
	private:
		std::vector<Layer*> m_Layers;
	};
}