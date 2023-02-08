#include "pch.h"
#include "WinPoint.h"

namespace FW
{

#pragma region Costruttori
	WinPoint::WinPoint()
		: POINT()
	{

	}

	WinPoint::WinPoint(LONG x, LONG y)
	{
		this->x = x;
		this->y = y;
	}
#pragma endregion

#pragma region
	WinPoint& WinPoint::operator+=(const WinPoint& traslazione)
	{
		x += traslazione.x;
		y += traslazione.y;
		return *this;
	}
#pragma endregion

#pragma region Interfaccia
	void WinPoint::SetX(LONG x)
	{
		this->x = x;
	}

	void WinPoint::SetY(LONG y)
	{
		this->y = y;
	}

	LONG WinPoint::GetX() const
	{
		return x;
	}

	LONG WinPoint::GetY() const
	{
		return y;
	}
#pragma endregion
};