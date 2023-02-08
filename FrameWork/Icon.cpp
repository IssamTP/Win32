#include "pch.h"
#include "Icon.h"

namespace FW
{
	#pragma region Costruttori
	Icon::Icon()
	{
		HandleIcona = nullptr;
	}

	Icon::Icon(HICON handle)
	{
		HandleIcona = handle;
	}
	#pragma endregion

	#pragma region Operatori
	Icon::operator HICON()
	{
		return HandleIcona;
	}
	#pragma endregion

	#pragma region Statiche
	Icon Icon::GetDefaultIcon()
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-loadimagew
		HICON handleIcona = static_cast<HICON>(LoadImage(nullptr, MAKEINTRESOURCE(OIC_WINLOGO), IMAGE_ICON, SM_CXICON, SM_CYICON, LR_SHARED));
		return Icon(handleIcona);
	}
	#pragma endregion
}