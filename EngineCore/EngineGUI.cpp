#include "PreCompile.h"
#include "EngineGUI.h"
#include "EngineCore/EngineCore.h"
#include <EnginePlatform/EngineWindow.h>
#include "EngineGuiWindow.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

UEngineGUI::UEngineGUI()
{
}

UEngineGUI::~UEngineGUI()
{
}


void UEngineGUI::Init()
{

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;         io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;          io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;             io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}




	ImGui_ImplWin32_Init(UEngineCore::GetMainWindow().GetWindowHandle());
	ImGui_ImplDX11_Init(UEngineCore::GetDevice().GetDevice(), UEngineCore::GetDevice().GetContext());


	UEngineWindow::SetCustomProc(
		[=](HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
			{
				return true;
			}

			return true;
		}
	);
}

void UEngineGUI::Release()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void UEngineGUI::GUIRenderStart()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

}

void UEngineGUI::GUIRenderEnd()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}

}

void UEngineGUI::PushGUIWindow(std::shared_ptr<class UEngineGUIWindow> _Window)
{
	_Window->BeginPlay();

	Windows.insert({ _Window->GetName(), _Window });
}

void UEngineGUI::GUIRender(ULevel* _Level)
{
	UEngineGUI::GUIRenderStart();
	for (std::pair<const std::string, std::shared_ptr<UEngineGUIWindow>>& Window : Windows)
	{
		ImGui::Begin(Window.first.c_str());
		Window.second->World = _Level;
		Window.second->OnGUI();
		ImGui::End();
	}
	UEngineGUI::GUIRenderEnd();
}