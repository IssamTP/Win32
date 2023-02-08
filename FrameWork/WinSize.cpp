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
		cy = height;
	}

	void WinSize::SetWidth(LONG width)
	{
		cx = width;
	}

	LONG WinSize::GetHeight() const
	{
		return cy;
	}

	LONG WinSize::GetWidth() const
	{
		return cx;
	}
#pragma endregion
};