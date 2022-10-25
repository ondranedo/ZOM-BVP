#pragma once

#include <ZOM/ZOM.hpp>

class GameLayer : public ZOM::Layer {
public:
	GameLayer(const std::string& name):Layer(name)
	{
	}

	void onUpdate() override;
	void onEvent(ZOM::Event& event) override;
	void onCreate() override;

protected:
	bool onCloseEvent(ZOM::WindowCloseEvent& wce);
	bool onKey(ZOM::KeyPressedEvent& kpe);
	bool onKeyRelease(ZOM::KeyReleasedEvent& kpe);

	glm::fvec2 m_Position = {0.0,0.0};
	float m_Zoom = 1.0f;
};