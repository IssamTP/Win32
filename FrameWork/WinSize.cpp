#include "pch.h"
#include "WinSize.h"

namespace FW
{
#pragma region Costruttori
	WinSize::WinSize()
		: SIZE()
	{
	}

	WinSize::WinSize(LONG width, LONG height)
	{
	}
#pragma endregion

#pragma region Operatori
	WinSize::operator LPSIZE()
	{
		return this;
	}
#pragma endregion

#pragma region Interfaccia
	void WinSize::SetHeight(LONG height)
	{
		cx = height;
	}

	void WinSize::SetWidth(LONG width)
	{
		cy = width;
	}

	LONG WinSize::GetHeight() const
	{
		return cx;
	}

	LONG WinSize::GetWidth() const
	{
		return cy;
	}
#pragma endregion
};