#pragma once

#include <ZOM/ZOM.hpp>
#include "trinagle.h"

class GameLayer : public ZOM::Layer {
public:
	GameLayer(const std::string& name):Layer(name){}

	void onUpdate() override;
	void onEvent(ZOM::Event& event) override;

protected:
	bool onCloseEvent(ZOM::WindowCloseEvent& wce);
	bool onKey(ZOM::KeyPressedEvent& kpe);
	bool onKeyRelease(ZOM::KeyReleasedEvent& kpe);

private:
	TrinageMesh m_Triangle;
};