#pragma once

// 
#include <d3d11.h>
#include <dxgi.h>

namespace Craft
{
	// CPU에서 GPU로 명령을 전달
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

	private:
		// 장치 생성
		void CreateDevice();

	private:
		// 장치 (그래픽 카드)

		// 디바이스 -> 데이터 생성
		ID3D11Device* device = nullptr;

		// 그래픽카드에 데이터 설정(연결 / 바인딩)
		ID3D11DeviceContext* context = nullptr;

		// 기능 변경이 거의 없는 장치
		IDXGISwapChain* swapChain = nullptr;
	};
}
