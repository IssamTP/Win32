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

	WinRectangle& WinRectangle::operator +=(const WinPoint& origin)
	{
		LONG deltaX = origin.GetX();
		LONG deltaY = origin.GetY();
		left += deltaX;
		right += deltaX;
		top += deltaY;
		bottom += deltaY;
		return *this;
	}

	WinRectangle& WinRectangle::operator +=(const WinSize& scale)
	{
		right += scale.GetWidth();
		bottom += scale.GetHeight();
		return *this;
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

	void WinRectangle::SetHeight(LONG height)
	{
		bottom = top + height;
	}

	void WinRectangle::SetOrigin(const WinPoint& origin)
	{
		LONG deltaX = origin.GetX() - left;
		LONG deltaY = origin.GetY() - top;
		
		left = origin.GetX();
		top = origin.GetY();
		right += deltaX;
		bottom += deltaY;
	}

	void WinRectangle::SetSize(const WinSize& size)
	{
		right = left + size.GetWidth();
		bottom = top + size.GetHeight();
	}

	void WinRectangle::SetWidth(LONG width)
	{
		right = left + width;
	}

	LONG WinRectangle::GetHeight() const
	{
		return bottom - top;
	}

	LONG WinRectangle::GetWidth() const
	{
		return right - left;
	}
#pragma endregion
};