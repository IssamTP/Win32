#pragma once
#ifndef _DEVICE_CONTEXT_H_
	#define _DEVICE_CONTEXT_H_
	#include "HeaderCPP.h"
	#include "Brush.h"
	#include "WinRectangle.h"
	#include "WinExports.h"
	#include "WinUndefinitions.h"
namespace FW
{
	/// <summary>Classe per la gestione del disegno della finestra...</summary>
	/// <remarks>Nella documentazione è riportata la dicitura "LOGICAL UNITS", essa ha vari significati dipendetemente dal valore di mapping:
	/// MM_TEXT: 1lu = 1pu = 1px</remarks>
	class _FRAMEWORK_CLASS_EXPORT_ DeviceContext : public PAINTSTRUCT
	{
#pragma region 
	private:
		// RISERVATI WINDOWS.
		using PAINTSTRUCT::fIncUpdate;
		using PAINTSTRUCT::fRestore;
		using PAINTSTRUCT::rgbReserved;
	protected:
		/// <summary>
		/// Se uguale da 0, indica che Windows ha già cancellato lo sfondo per il disegno di WM_PAINT (da interpretare come "TO BE ERASED"). Per personalizzare la cancellazione dello sfondo la finestra deve implementare WM_ERASEBKGROUND.
		/// </summary>
		using PAINTSTRUCT::fErase;
		using PAINTSTRUCT::hdc;
		using PAINTSTRUCT::rcPaint;
#pragma endregion
	protected:
		/// <summary>
		/// Pennello corrente.
		/// </summary>
		Brush BrushCorrente;
		/// <summary>
		/// Contiene informazioni sul disegno del testo.
		/// </summary>
		DRAWTEXTPARAMS DettagliTesto;
#pragma region Costruttori
	public:
		/// <summary>Costruttore predefinito. Privato.</summary>
		DeviceContext();
		/// <summary>Costruttore di Move.</summary>
		/// <param name="context">Contesto da spostare.</param>
		DeviceContext(DeviceContext&& context) noexcept;
		/// <summary>Costruttore di copia.</summary>
		/// <param name="context">Contesto da copiare..</param>
		DeviceContext(const DeviceContext& context);
		/// <summary>
		/// Generalmente chiamato da GetDC di Window.
		/// Non usare.
		/// </summary>
		/// <param name="handleToDeviceContext">Handle al device context.</param>
		/// <param name="clientArea">Rettangolo corrispondente a tutta la finestra.</param>
		DeviceContext(HDC handleToDeviceContext, const WinRectangle& clientArea);
#pragma endregion
#pragma region Operatori
	public:
		/// <summary>
		/// Cast diretto ad HDC.
		/// </summary>
		operator HDC();
		/// <summary>
		/// operatore di copia con HDC.
		/// </summary>
		/// <param name="deviceContext"></param>
		void operator=(HDC deviceContext);
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
		/// <remarks>Attenzione: il colore di sfondo di DrawText NON è il medesimo di quello usato per cancellare il background. Non usare caratteri speciali, DrawText non li riconosce e li disegnerà come rettangoli.</remarks>
		void DrawText(String text, const WinRectangle& drawArea, UINT textStyle);
		/// <summary>
		/// Inizializza la struttura TextMetrics.
		/// </summary>
		void GetTextMetrics();
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
		/// <summary>
		/// Imposta la formattazione del test all'interno del rettangolo di disegno.
		/// </summary>
		/// <param name="alignment">Una combinazione di flag TextAlign</param>
		void SetTextAlign(UINT alignment);
#pragma endregion
		/// <summary>
		/// Imposta il brush corrente.
		/// </summary>
		/// <param name="nuovoBrush">Nuovo brush.</param>
		void SetCurrentBrush(Brush nuovoBrush);
		/// <summary>
		/// Ottiene il brush corrente.
		/// </summary>
		/// <returns></returns>
		Brush& GetCurrentBrush();
#pragma endregion
	};
}
#endif
