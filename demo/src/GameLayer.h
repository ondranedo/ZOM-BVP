#pragma once

#include <ZOM/ZOM.hpp>

class GameLayer final : public ZOM::Layer {
public:
	GameLayer(const std::string& name): Layer(name) { }

	virtual void onUpdate() override;
	virtual void onEvent(ZOM::Event& event) override;
	virtual void onCreate() override;

protected:
	bool onCloseEvent(ZOM::WindowCloseEvent& wce);
	bool onKey(ZOM::KeyPressedEvent& kpe);
	bool onKeyRelease(ZOM::KeyReleasedEvent& kpe);

	glm::fvec2 m_Position = {0.0, 0.0};
	float m_Zoom          = 1.0f;
	glm::fvec2 m_Pos = { 0.0, 0.0 };
};
