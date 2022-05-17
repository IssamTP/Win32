#include "pch.h"
#include "WinRectangle.h"

namespace FW
{
#pragma region Costruttori
	WinRectangle::WinRectangle()
		: RECT()
	{

	}

	WinRectangle::WinRectangle(LONG x1, LONG y1, LONG x2, LONG y2)
	{
		top = y1;
		left = x1;
		right = x2;
		bottom = y2;
	}

	WinRectangle::WinRectangle(const WinPoint& upperLeftCorner, const WinPoint& lowerRightCorner)
	{
		top = upperLeftCorner.GetY();
		left = upperLeftCorner.GetX();
		right = lowerRightCorner.GetX();
		bottom = lowerRightCorner.GetY();
	}
#pragma endregion

#pragma region Operatori
	WinRectangle::operator LPRECT()
	{
		return this;
	}

	WinRectangle::operator CPRECT() const
	{
		return this;
	}
#pragma endregion

#pragma region Interfaccia
	void WinRectangle::GetOriginAndSize(WinPoint& origin, WinSize& size)
	{
		origin.SetX(left);
		origin.SetY(top);
		size.SetWidth(right - left);
		size.SetHeight(bottom - top);
	}
#pragma endregion
};