#pragma once

#include <cstdint>
#include <string>

#include "Engine/ISystem.hpp"

struct GLFWwindow;

namespace Ngine
{
	class ENGINE_EXPORT Renderer : public ISystem
	{
	private:
		uint32_t m_windowWidth;
		uint32_t m_windowHeight;
		uint32_t m_fullscreenWidth;
		uint32_t m_fullscreenHeight;
		float m_aspectRatio;

		uint32_t m_positionX;
		uint32_t m_positionY;

		std::string m_title;
		std::string m_iconPath;
		bool m_antialiasing;
		bool m_fullscreen;

		GLFWwindow* m_window;

	public:
		Renderer();
		~Renderer();

		void Update() override;

	private:
		friend void CallbackError(int32_t error, const char* description);

		void CreateGlfw();
	};
}