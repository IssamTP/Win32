#pragma once
#ifndef _SIZE_CLASS_H_
	#define _SIZE_CLASS_H_

namespace FW
{
	/// <summary>
	/// Classe di incapsulamento della struttura SIZE.
	/// </summary>
	template <typename T>
	class Size
	{
	protected:
		SIZE WinSize;
		T Height;
		T Width;
	public:
#pragma region Costruttori
		/// <summary>
		/// Costruttore predefinito, le dimensioni sono 0.
		/// </summary>
		Size()
		{
			Height = 0;
			Width = 0;
		}
		/// <summary>
		/// Imposta le dimensioni in fase di costruzione.
		/// </summary>
		/// <param name="width">Larghezza.</param>
		/// <param name="height">Altezza.</param>
		Size(T width, T height)
		{
			Width = width;
			Height = height;
		}
#pragma endregion
	public:
#pragma region Operatori
		/// <summary>
		/// Cast automatico a SIZE.
		/// </summary>
		operator SIZE()
		{
			SIZE converted = { 0 };
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
	public:
		/// <summary>
		/// Calcola l'aspect ratio.
		/// </summary>
		/// <returns></returns>
		T AspectRatio() const
		{
			return Width / Height;
		}
	};
}
#endif
