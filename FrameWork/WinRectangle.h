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
	class _FRAMEWORK_CLASS_EXPORT_ WinRectangle : public RECT
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
		/// <summary>
		/// Sposta l'origine del rettangolo di origine.
		/// </summary>
		/// <param name="origin"></param>
		/// <returns></returns>
		WinRectangle& operator +=(const WinPoint& spostamento);
		/// <summary>
		/// Allarga opportunamente il rettangolo.
		/// </summary>
		/// <param name="scale">Di quanto allargare il rettangolo.</param>
		/// <returns>Il nuovo rettangolo.</returns>
		WinRectangle& operator +=(const WinSize& scale);
	public:
		/// <summary>
		/// Valorizza due variabili con origine e dimensione.
		/// </summary>
		/// <param name="origin">Variabile che conterrà l'origine del rettangolo (ULC).</param>
		/// <param name="size">Variabile che conterrà le dimensioni del rettangolo (LRC - ULC).</param>
		void GetOriginAndSize(WinPoint& origin, WinSize& size);
		/// <summary>
		/// Imposta la nuova origine del rettangolo;
		/// </summary>
		/// <param name="origin">Nuova origine.</param>
		void SetOrigin(const WinPoint& origin);
		/// <summary>
		/// Imposta l'altezza del rettangolo.
		/// </summary>
		/// <param name="height">La nuova altezza del rettangolo.</param>
		void SetHeight(LONG height);
		/// <summary>
		/// Imposta le dimensioni del rettangolo.
		/// </summary>
		/// <param name="size">Nuove dimensioni del rettangolo.</param>
		void SetSize(const WinSize& size);
		/// <summary>
		/// Imposta la larghezza del rettangolo.
		/// </summary>
		/// <param name="width">Larghezza del rettangolo.</param>
		void SetWidth(LONG width);
		/// <summary>
		/// Calcola l'altezza del rettangolo.
		/// </summary>
		/// <returns>Un LONG rappresentante l'altezza del rettangolo.</returns>
		LONG GetHeight() const;
		/// <summary>
		/// Calcola la larghezza del rettangolo.
		/// </summary>
		/// <returns>Un LONG rappresentante la larghezza del rettangolo.</returns>
		LONG GetWidth() const;
	};
};
#endif