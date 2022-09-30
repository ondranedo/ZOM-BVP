#pragma once

#include <ZOM/ZOM.hpp>

class GameLayer : public ZOM::Layer {
public:
	GameLayer(const std::string& name):Layer(name){}

	void onUpdate() override;
	void onEvent(ZOM::Event& event) override;

protected:
	bool onCloseEvent(ZOM::WindowCloseEvent& wce);
	bool onKey(ZOM::KeyPressedEvent& kpe);
};