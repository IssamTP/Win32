#pragma once
#ifndef _DEVICE_CONTEXT_H_
	#define _DEVICE_CONTEXT_H_
	#include "HeaderCPP.h"
	#include "Rectangle.h"
	#include "WinExports.h"
	#include "WinUndefinitions.h"
namespace FW
{
	/// <summary>
	/// Classe per la gestione del disegno della finestra..
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ DeviceContext
	{
	protected:
		/// <summary>
		/// Contiene informazioni sul disegno del testo.
		/// </summary>
		DRAWTEXTPARAMS DettagliTesto;
		/// <summary>
		/// Contiene le informazioni in merito al disegno della finestra.
		/// </summary>
		PAINTSTRUCT InformazioniDisegno;
#pragma region Costruttori
	public:
		/// <summary>
		/// Costruttore predefinito. Privato.
		/// </summary>
		DeviceContext();
		/// <summary>
		/// Costruttore di Move.
		/// </summary>
		/// <param name="context">Contesto da spostare.</param>
		DeviceContext(DeviceContext&& context) noexcept;
		/// <summary>
		/// Costruttore di copia.
		/// </summary>
		/// <param name="context">Contesto da copiare..</param>
		DeviceContext(const DeviceContext& context);
#pragma endregion
#pragma region Operatori
	public:
		/// <summary>
		/// Cast diretto ad HDC.
		/// </summary>
		operator HDC();
		/// <summary>
		/// Cast diretto a PAINTSTRUCT.
		/// </summary>
		operator PAINTSTRUCT();
		/// <summary>
		/// Cast diretto a LPPAINTSTRUCT.
		/// </summary>
		operator LPPAINTSTRUCT();
		/// <summary>
		/// operatore di copia con HDC.
		/// </summary>
		/// <param name="deviceContext"></param>
		void operator=(HDC deviceContext);
		/// <summary>
		/// Inizializza l'oggetto.
		/// </summary>
		/// <param name="paintStruct"></param>
		void operator=(const PAINTSTRUCT& paintStruct);
		/// <summary>
		/// Operatore di spostamento.
		/// </summary>
		/// <param name="context">Contesto da spostare.</param>
		/// <returns>*this.</returns>
		DeviceContext& operator=(DeviceContext&& context) noexcept;
		/// <summary>
		/// Operatore di copia.
		/// </summary>
		/// <param name="context">Contesto da copiare.</param>
		/// <returns>*this.</returns>
		DeviceContext& operator=(const DeviceContext& context);
#pragma endregion
#pragma region Interfaccia
	public:
#pragma region Text
		/// <summary>
		/// Informazioni sul disegno del testo.
		/// </summary>
		/// <returns>Margine sinistro.</returns>
		int GetLeftMargin() const noexcept;
		/// <summary>
		/// Informazioni sul disegno del testo.
		/// </summary>
		/// <returns>Margine destro.</returns>
		int GetRightMargin() const noexcept;
		/// <summary>
		/// Informazioni sul disegno del testo.
		/// </summary>
		/// <returns>Lunghezza del TAB.</returns>
		int GetTabLength() const noexcept;
		/// <summary>
		/// Disegna il testo specificato nel rettangolo client. Applica lo stile specificato.
		/// Nota che è possibile specificare separatamente i valori relativi alla larghezza del TAB e dei due margini destro e sinistro.
		/// </summary>
		/// <param name="text">Stringa da scrivere.</param>
		/// <param name="drawArea">Rettangolo di scrittura.</param>
		/// <param name="textStyle">Stile di disegno del testo: usare StyleOperations::Combine con DrawTextStyles.</param>
		void DrawText(String text, Rectangle<LONG> drawArea, UINT textStyle);
		/// <summary>
		/// Imposta il margine sinistro del testo.
		/// </summary>
		/// <param name="leftMargin">L'unità di misura è la media della larghezza del carattere.</param>
		void SetLeftMargin(int leftMargin);
		/// <summary>
		/// Imposta il margine destro del testo.
		/// </summary>
		/// <param name="rightMargin">L'unità di misura è la media della larghezza del carattere.</param>
		void SetRightMargin(int rightMargin);
		/// <summary>
		/// Imposta la dimensione del tab.
		/// </summary>
		/// <param name="tabLength">L'unità di misura è la media della larghezza del carattere.</param>
		void SetTabLength(int tabLength);
#pragma endregion
#pragma endregion
	};
}
#endif
