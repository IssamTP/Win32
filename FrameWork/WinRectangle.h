#pragma once
#ifndef _WIN_RECTANGLE_CLASS_H_
	#define _WIN_RECTANGLE_CLASS_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
	#include "WinPoint.h"
	#include "WinSize.h"
namespace FW
{
	typedef const RECT* CPRECT;
	/// <summary>
	/// Classe wrap della struttura RECT.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ WinRectangle : RECT
	{
	protected:
		using RECT::bottom;
		using RECT::left;
		using RECT::right;
		using RECT::top;
	public:
		/// <summary>
		/// Costruttore predefinito. Inizializza la struttura a 0.
		/// </summary>
		WinRectangle();
		/// <summary>
		/// Costruttore con le 4 componenti.
		/// ATTENZIONE: RECT considera origine l'angolo in alto a sinistra e non in basso.
		/// </summary>
		/// <param name="x1">Coordinata X più a sinistra.</param>
		/// <param name="y1">Coordinata Y più in alto (minore).</param>
		/// <param name="x2">Coordinata X più a destra.</param>
		/// <param name="y2">Coordinata Y più in basso (maggiore).</param>
		WinRectangle(LONG x1, LONG y1, LONG x2, LONG y2);
		/// <summary>
		/// Costruttore con due WinPoint.
		/// </summary>
		/// <param name="upperLeftCorner">Come indica il nome.</param>
		/// <param name="lowerRightCorner">Come indica il nome.</param>
		WinRectangle(const WinPoint& upperLeftCorner, const WinPoint& lowerRightCorner);
	public:
		/// <summary>
		/// Cast diretto a LPRECT.
		/// </summary>
		operator LPRECT();
		/// <summary>
		/// Cast diretto a const RECT* (Tipato in CPRECT).
		/// </summary>
		operator CPRECT() const;
	public:
		/// <summary>
		/// Valorizza due variabili con origine e dimensione.
		/// </summary>
		/// <param name="origin">Variabile che conterrà l'origine del rettangolo (ULC).</param>
		/// <param name="size">Variabile che conterrà le dimensioni del rettangolo (LRC - ULC).</param>
		void GetOriginAndSize(WinPoint& origin, WinSize& size);
	};
};
#endif