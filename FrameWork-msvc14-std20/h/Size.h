#pragma once
#ifndef _SIZE_CLASS_H_
	#define _SIZE_CLASS_H_
	#include "HeaderCPP.h"
namespace Math
{
	/// <summary>
	/// Classe di incapsulamento della struttura SIZE.
	/// </summary>
	template <typename T>
	class Size2D
	{
	protected:
		T Altezza;
		T Larghezza;
	public:
#pragma region Costruttori
		/// <summary>
		/// Costruttore predefinito, le dimensioni sono 0.
		/// </summary>
		Size2D()
		{
			Larghezza = 0;
			Altezza = 0;
		}
		/// <summary>
		/// Imposta le dimensioni in fase di costruzione.
		/// </summary>
		/// <param name="width">Larghezza.</param>
		/// <param name="height">Altezza.</param>
		Size2D(T width, T height)
		{
			Larghezza = width;
			Altezza = height;
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
				converted.cx = std::lround(Larghezza);
				converted.cy = std::lround(Altezza);
			}
			else if (typeid(T) == typeid(int) || typeid(T) == typeid(long) || typeid(T) == typeid(short) ||
				typeid(T) == typeid(unsigned int) || typeid(T) == typeid(unsigned long) || typeid(T) == typeid(unsigned short) ||
				typeid(T) == typeid(long long) || typeid(T) == typeid(unsigned long long))
			{
				converted.cx = static_cast<LONG>(Larghezza);
				converted.cy = static_cast<LONG>(Altezza);
			}
			return converted;
		}
#pragma endregion
	public:
#pragma region Interfaccia
		/// <summary>
		/// Imposta la altezza.
		/// </summary>
		/// <param name="height">Altezza della finestra.</param>
		void SetHeight(T height)
		{
			Altezza = height;
		}
		/// <summary>
		/// Imposta la larghezza.
		/// </summary>
		/// <param name="width">Larghezza della finestra.</param>
		void SetWidth(T width)
		{
			Larghezza = width;
		}
		/// <summary>
		/// Calcola l'aspect ratio.
		/// </summary>
		/// <returns>AspectRatio della dimensione.</returns>
		T AspectRatio() const
		{
			return Larghezza / Altezza;
		}
		/// <summary>
		/// Larghezza.
		/// </summary>
		/// <returns>Larghezza.</returns>
		T Width() const
		{
			return Larghezza;
		}
		/// <summary>
		/// Altezza.
		/// </summary>
		/// <returns>Altezza.</returns>
		T Height() const
		{
			return Altezza;
		}
#pragma endregion
	};
}
#endif