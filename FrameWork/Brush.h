#pragma once
#ifndef _BRUSH_CLASS_H_
	#define _BRUSH_CLASS_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
	#include "StylesOperations.h"
namespace FW
{
	/// <summary>
	/// Classe di base per i brush.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ Brush
	{
	#pragma region Membri
	protected:
		HBRUSH HandleBrush;
	#pragma endregion
	#pragma region Costruttori
	public:
		/// <summary>
		/// Costruttore predefinito.
		/// </summary>
		Brush();
		/// <summary>
		/// Costruisce un oggetto Brush a partire dall'handle.
		/// </summary>
		/// <param name="brushHandle"></param>
		Brush(HBRUSH brushHandle);
	#pragma endregion
	#pragma region Operatori
		/// <summary>
		/// Cast diretto a HBRUSH.
		/// </summary>
		operator HBRUSH();
		/// <summary>
		/// Operatore di assegnamento con l'handle del brush.
		/// </summary>
		/// <param name="handleBrush">Brush da copiare.</param>
		/// <returns>Referenza a *this.</returns>
		Brush& operator=(HBRUSH handleBrush);
	#pragma endregion
	#pragma region Statiche
	public:
		/// <summary>
		/// Ottiene il brush specificato predefinito dagli oggetti di sistema.
		/// </summary>
		/// <param name="object">Identificatore dell'oggetto di sistema.</param>
		/// <returns>Un oggetto con il brush predefinito.</returns>
		static Brush GetDefaultBrush(StockObjects object);
		/// <summary>
		/// Ottiene il brush predefinito per una finestra di dialogo.
		/// </summary>
		/// <returns>Un oggetto con il brush predefinito.</returns>
		static Brush GetDefaultDialogBrush();
		/// <summary>
		/// Ottiene il brush predefinito per una finestra (Bianco).
		/// </summary>
		/// <returns>Un oggetto con il brush predefinito.</returns>
		static Brush GetDefaultWindowBrush();
	};
	#pragma endregion
};
#endif
