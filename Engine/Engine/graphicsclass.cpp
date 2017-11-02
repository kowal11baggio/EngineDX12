#pragma region INCLUDES
#include "graphicsclass.h"
#pragma endregion

#pragma region CONSTRUCTORS
GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
}
GraphicsClass::GraphicsClass(const GraphicsClass& other){}

GraphicsClass::~GraphicsClass(){}
#pragma endregion

#pragma region PUBLIC
bool GraphicsClass::Initialize(int screenHeight, int screenWidth, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenHeight, screenWidth, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	return true;
}

void GraphicsClass::Shutdown()
{
	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}
	return;
}

bool GraphicsClass::Frame()
{
	bool result;
	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}
	return true;
}
#pragma endregion


#pragma region PRIVATE
bool GraphicsClass::Render()
{
	bool result;
	// Use the Direct3D object to render the scene.
	result = m_Direct3D->Render();
	if (!result)
	{
		return false;
	}
	return true;
}
#pragma endregion

