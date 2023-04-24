#pragma once
#ifndef _WIN_POINT_CLASS_H_
	#define _WIN_POINT_CLASS_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
namespace FW
{
	/// <summary>
	/// Classe wrap della struttura di base POINT.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ WinPoint : POINT
	{
	protected:
		using POINT::x;
		using POINT::y;
	public:
		/// <summary>
		/// Costruttore predefinito: azzera la struttura.
		/// </summary>
		WinPoint();
		/// <summary>
		/// Costruttore per parametri.
		/// </summary>
		/// <param name="x">Coordinata x.</param>
		/// <param name="y">Coordinata y.</param>
		WinPoint(LONG x, LONG y);
	public:
		/// <summary>
		/// Operatore di "traslazione".
		/// </summary>
		/// <param name="traslazione">Di quanto spostare il punto.</param>
		/// <returns>Nuova posizione.</returns>
		WinPoint& operator+=(const WinPoint& traslazione);
	public:
		/// <summary>
		/// Funzione setter per la coordinata x.
		/// </summary>
		/// <param name="x">Nuovo valore per la coordinata x.</param>
		void SetX(LONG x);
		/// <summary>
		/// Funzione setter per la coordinata y.
		/// </summary>
		/// <param name="x">Nuovo valore per la coordinata y.</param>
		void SetY(LONG y);
		/// <summary>
		/// Funzione getter per la coordinata x.
		/// </summary>
		/// <returns>Valore di x.</returns>
		LONG GetX() const;
		/// <summary>
		/// Funzione getter per la coordinata y.
		/// </summary>
		/// <returns>Valore di y.</returns>
		LONG GetY() const;
	};
};
#endif