#include "pch.h"
#include "Size.h"

namespace FW
{
	#pragma region Costruttori
	template<typename T>
	Size<T>::Size()
	{
		Height = 0;
		Width = 0;
	}

	template<typename T>
	Size<T>::Size(T width, T height)
	{
		Width = width;
		Height = height;
	}
	#pragma endregion

#pragma region Operators
	template<typename T>
	Size<T>::operator SIZE()
	{
		SIZE converted = {0};
		if (typeid(T) == typeid(float) || typeid(T) == typeid(double) || typeid(T) == typeid(long double))
		{
			converted.cx = std::lround(Width);
			converted.cy = std::lround(Height);
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(long) || typeid(T) == typeid(short) ||
			typeid(T) == typeid(unsigned int) || typeid(T) == typeid(unsigned long) || typeid(T) == typeid(unsigned short) ||
			typeid(T) == typeid(long long) || typeid(T) == typeid(unsigned long long))
		{
			converted.cx = static_cast<LONG>(Width);
			converted.cy = static_cast<LONG>(Height);
		}
		return converted;
	}
#pragma endregion

#pragma region Interfaccia
	template<typename T>
	T Size<T>::AspectRatio() const
	{
		return Width / Height;
	}
#pragma endregion
}