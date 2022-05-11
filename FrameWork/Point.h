#pragma once
#ifndef _CLASS_POINT_2D_H_
	#define _CLASS_POINT_2D_H_
#include "HeaderCPP.h"

template <class T>
class Point2D
{
protected:
	T X;
	T Y;
public:
	/// <summary>
	/// Costruttore predefinito.
	/// </summary>
	/// <typeparam name="T">Viene automaticamente considerato il tipo di POINT.</typeparam>
	template <class T>
	Point2D<T>()
	{
		X = 0;
		Y = 0;
	}
	/// <summary>
	/// Costruttore con le coordinate.
	/// </summary>
	/// <typeparam name="T">Qualsiasi tipo venga specificato.</typeparam>
	/// <param name="x">Coordinata X.</param>
	/// <param name="y">Coordinata Y.</param>
	template <class T>
	Point2D<T>(T x, T y)
	{
		X = x;
		Y = y;
	}
public:
	/// <summary>
	/// Conversione automatica a POINT.
	/// </summary>
	operator POINT()
	{
		POINT pixel = { 0 };
		if (typeid(T) == typeid(float) || typeid(T) == typeid(double) || typeid(T) == typeid(long double))
		{
			pixel.x = std::lround(X);
			pixel.y = std::lround(Y);
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(long) || typeid(T) == typeid(short) ||
			typeid(T) == typeid(unsigned int) || typeid(T) == typeid(unsigned long) || typeid(T) == typeid(unsigned short) ||
			typeid(T) == typeid(long long) || typeid(T) == typeid(unsigned long long))
		{
			pixel.x = static_cast<LONG>(X);
			pixel.y = static_cast<LONG>(X);
		}
		return pixel;
	}
};
#endif