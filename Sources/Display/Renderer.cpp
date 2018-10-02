#include "Renderer.hpp"

#include <GLFW/glfw3.h>

#include <cassert>
#include <iostream>

namespace Ngine
{
	void CallbackError(int32_t error, const char* description)
	{
		std::cerr << error << ' ' << description << '\n';
	}

	Renderer::Renderer() :
		m_windowWidth(1080u),
		m_windowHeight(720u),
		m_fullscreenWidth(0u),
		m_fullscreenHeight(0u),
		m_aspectRatio(1.5f),
		m_positionX(0u),
		m_positionY(0u),
		m_title("Engine"),
		m_iconPath(""),
		m_antialiasing(true),
		m_fullscreen(false)
	{
		CreateGlfw();
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Update()
	{
		glfwPollEvents();
	}

	void Renderer::CreateGlfw()
	{
		glfwSetErrorCallback(CallbackError);

		if (glfwInit() == GLFW_FALSE)
		{
			assert(false && "GLFW runtime error!");
		}

		if (glfwVulkanSupported() == GLFW_FALSE)
		{
			assert(false && "GLFW runtime error!");
		}

		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		glfwWindowHint(GLFW_STENCIL_BITS, 8);
		glfwWindowHint(GLFW_STEREO, GLFW_FALSE);

		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);

		if (m_fullscreen)
		{
			m_fullscreenWidth = videoMode->width;
			m_fullscreenHeight = videoMode->height;
			m_aspectRatio = static_cast<float>(videoMode->width) / static_cast<float>(videoMode->height);
		}

		glfwWindowHint(GLFW_RED_BITS, videoMode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, videoMode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, videoMode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);

		m_window = glfwCreateWindow(m_fullscreen ? m_fullscreenWidth : m_windowWidth, m_fullscreen ? m_fullscreenHeight : m_windowHeight, m_title.c_str(), m_fullscreen ? monitor : nullptr, nullptr);

		if (m_window == nullptr)
		{
			glfwTerminate();
			assert(false && "Failed to create the GLFW window!");
		}

		m_positionX = (videoMode->width - m_windowWidth) / 2;
		m_positionY = (videoMode->height - m_windowHeight) / 2;
		glfwSetWindowPos(m_window, m_positionX, m_positionY);

		glfwShowWindow(m_window);
	}
}