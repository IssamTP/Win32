#pragma once
#ifndef _WIN_SIZE_CLASS_H_
	#define _WIN_SIZE_CLASS_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
namespace FW
{
	/// <summary>
	/// Classe involucro per la struttura SIZE.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ WinSize : public SIZE
	{
	protected:
		using SIZE::cx;
		using SIZE::cy;
	public:
		/// <summary>
		/// Costruttore predefinito: inizializza la struttura a 0.
		/// </summary>
		WinSize();
		/// <summary>
		/// Costruttore per parametri.
		/// </summary>
		/// <param name="width">Parametro larghezza.</param>
		/// <param name="height">Parametro altezza.</param>
		WinSize(LONG width, LONG height);
	public:
		/// <summary>
		/// Cast diretto a LPSIZE.
		/// </summary>
		operator LPSIZE();
	public:
		/// <summary>
		/// Setter per l'altezza.
		/// </summary>
		/// <param name="height">Nuovo valore per l'altezza.</param>
		void SetHeight(LONG height);
		/// <summary>
		/// Setter per la larghezza.
		/// </summary>
		/// <param name="width">Nuovo valore per la larghezza.</param>
		void SetWidth(LONG width);
		/// <summary>
		/// Getter per l'altezza.
		/// </summary>
		/// <returns>Valore di cy.</returns>
		LONG GetHeight() const;
		/// <summary>
		/// Getter per la larghezza.
		/// </summary>
		/// <returns>Valore di cx.</returns>
		LONG GetWidth() const;
	};
}
#endif