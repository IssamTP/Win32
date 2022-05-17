#pragma once
#ifndef _RECTANGLE_CLASS_H_
	#define _RECTANGLE_CLASS_H_
	#include "Point.h"
	#include "Size.h"
namespace Math
{
	/// <summary>
	/// Classe che modella un oggetto rettangolo con origine in alto a sinistra.
	/// </summary>
	/// <typeparam name="T">Qualsiasi tipo numerico T.</typeparam>
	template <class T>
	class Rectangle
	{
	protected:
		RECT Alias;
		/// <summary>
		/// Coordinata di origine.
		/// </summary>
		Point2D<T> Origine;
		/// <summary>
		/// Dimensioni del rettangolo.
		/// </summary>
		Size2D<T> Dimensione;
#pragma region Costruttori
	public:
		/// <summary>
		/// Costruttore predefinito.
		/// </summary>
		Rectangle()
		{
		}
		/// <summary>
		/// Costruttore via singoli parametri.
		/// </summary>
		/// <param name="x">Punto a sinistra.</param>
		/// <param name="y">Punto in alto</param>
		/// <param name="larghezza">Larghezza del rettangolo.</param>
		/// <param name="altezza">Altezza del rettangolo.</param>
		Rectangle(T x, T y, T larghezza, T altezza)
		{
			Origine = Point2D<T>(x, y);
			Dimensione = Size2D<T>(larghezza, altezza);
			Alias = *this;
		}
		/// <summary>
		/// Costruttore per RECT.
		/// </summary>
		/// <param name="rettangolo"></param>
		Rectangle(const RECT& rettangolo)
		{
			Origine = Point2D<LONG>(rettangolo.left, rettangolo.top);
			Dimensione = Size2D<LONG>(rettangolo.right - Origine.GetX(), rettangolo.bottom - Origine.GetY());
			Alias = rettangolo;
		}
#pragma endregion
#pragma region Operatori
	public:
		/// <summary>
		/// Cast diretto a RECT.
		/// </summary>
		operator RECT()
		{
			POINT origine = Origine;
			SIZE dimensione = Dimensione;
			RECT alias = { 0 };
			alias.left = origine.x;
			alias.top = origine.y;
			alias.right = origine.x + dimensione.cx;
			alias.bottom = origine.y + dimensione.cy;
			return alias;
		}
		/// <summary>
		/// Cast diretto a LPRECT.
		/// </summary>
		operator LPRECT()
		{
			return &Alias;
		}
		/// <summary>
		/// Cast da RECT.
		/// </summary>
		/// <param name="rect">Referenza del rettangolo da copiare.</param>
		/// <returns>Referenza all'oggetto.</returns>
		Rectangle& operator=(const RECT& rect)
		{
			Origine.SetX(rect.left);
			Origine.SetY(rect.top);
			Dimensione.SetWidth(rect.right - rect.left);
			Dimensione.SetHeight(rect.bottom - rect.top);
			Alias = *this;
			return *this;
		}
		/// <summary>
		/// Cast da LPRECT.
		/// </summary>
		/// <param name="rect">Rettangolo da copiare.</param>
		/// <returns>Referenza all'oggetto.</returns>
		Rectangle& operator=(const LPRECT rect)
		{
			Origine.SetX(rect->left);
			Origine.SetY(rect->top);
			Dimensione.SetWidth(rect->right - rect->left);
			Dimensione.SetHeight(rect->bottom - rect->top);
			Alias = *this;
			return *this;
		}
#pragma endregion
	};
};
#endif