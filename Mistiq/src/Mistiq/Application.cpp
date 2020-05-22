#include "Mstqpch.h"
#include "Application.h"
#include <imgui.h>
#include "include/glad/glad.h"
#include "Graphics/ModelLoading/GLTF/GLTFParser.h"
#include "Graphics/Shaders/Shader.h"
#include "Graphics/Shaders/ShaderProgram.h"
#include "Graphics/Textures/Texture.h";
#include "ECS/Components/Transform.h"


Mistiq::Application::Application()
{
    ///Setting up upper hierarchy engine classes
	m_Window = std::make_unique<GLFWWindow>();
	m_GuiManager = std::make_unique<GUIManager>();
	m_ECSManager = std::make_unique<EntityManager>();
	m_Input = std::make_unique<Input>();
}

Mistiq::Application::~Application()
{
    
}

void Mistiq::Application::Setup() {
	///Setting up window
	WindowProperties windowProps;
	windowProps.m_Name = "Mistiq";
	windowProps.m_Width = 1920;
	windowProps.m_Height = 1080;
	m_Window->Create(windowProps);

    //Setting up input
	m_Input->SetWindow(m_Window->m_Window);
}

void Mistiq::Application::Update() {
    OPTICK_FRAME("ApplicationUpdate")
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_ECSManager->Update(0.2f);
	m_GuiManager->Update(0.2f);
	m_Window->Update(0.2f);

	m_Count += m_Window->GetDeltaTime();
}

void Mistiq::Application::Clean() {
	m_Window->Destroy();
}

bool Mistiq::Application::IsOpen() {
	return m_Window->IsOpen();
}
