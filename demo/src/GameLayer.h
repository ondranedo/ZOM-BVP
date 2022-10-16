#pragma once

#include <ZOM/ZOM.hpp>
#include "trinagle.h"
#include "square.h"

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

private:
	SquareMesh m_Mesh;
	std::shared_ptr<ZOM::Shader>shader;
};