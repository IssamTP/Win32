#pragma once
#ifndef _WINDOW_H_
	#define _WINDOW_H_
	#include "HeaderCPP.h"
	#include "Point.h"
	#include "Cursor.h"
	#include "Icon.h"
	#include "Size.h"
	#include "Rectangle.h"
	#include "StylesOperations.h"
	#include "DeviceContext.h"
	#include "WinExports.h"
	#include "WinUndefinitions.h"
namespace FW
{
	_FRAMEWORK_TEMPLATE_EXPORT_ template class Point2D<LONG>;
	_FRAMEWORK_TEMPLATE_EXPORT_ template class Size2D<LONG>;
	_FRAMEWORK_TEMPLATE_EXPORT_ template class Rectangle<LONG>;

	/// <summary>
	/// Finestra di base.
	/// Incapsula le funzionalità di base della finestra C.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ Window : public WNDCLASSEX
	{
#pragma region Incapsulamento membri pubblici di WNDCLASSEX.
	protected:
		using WNDCLASSEX::cbClsExtra;
		using WNDCLASSEX::cbSize;
		using WNDCLASSEX::cbWndExtra;
		using WNDCLASSEX::hbrBackground;
		using WNDCLASSEX::hCursor;
		using WNDCLASSEX::hIcon;
		using WNDCLASSEX::hIconSm;
		using WNDCLASSEX::hInstance;
		using WNDCLASSEX::lpfnWndProc;
		using WNDCLASSEX::lpszClassName;
		using WNDCLASSEX::lpszMenuName;
		using WNDCLASSEX::style;
#pragma endregion
#pragma region Membri
	protected:
		/// <summary>Identificatore unico della classe. Vale solo se != 0.</summary>
		ATOM IdUnicoClasse;
		/// <summary>Cursore della finestra.</summary>
		Cursor CursoreFinestra;
		/// <summary>Oggetto per disegnare nella finestra.</summary>
		DeviceContext ContestoDisegno;
		/// <summary>Icona della finestra.</summary>
		Icon IconaFinestra;
		/// <summary>"Puntatore" alla finestra di Windows.</summary>
		HWND HandleFinestra;
		/// <summary>Coordinata di posizione della finestra sullo schermo.</summary>
		Point2D<LONG> Posizione;
		/// <summary>Dimensioni dell'area client.</summary>
		Rectangle<LONG> RettangoloClient;
		/// <summary>Dimensioni in pixel della finestra sullo schermo.</summary>
		Size2D<LONG> Dimensione;
		/// <summary>Specifica come mostrare la finestra al comando Show.</summary>
		ShowWindowsCommands ModalitaVisualizzazione;
		/// <summary>Nome della classe di finestre.</summary>
		String NomeClasse;
		/// <summary>Imposta il nome della finestra (verrà visualizzato sulla barra del titolo).</summary>
		String NomeFinestra;
		/// <summary>Combinazione di WindowStyles.</summary>
		/// <remarks>Può essere sottoposto a revisione.</remarks>
		UINT StileFinestra;
		/// <summary>Combinazione di WindowStylesEx.</summary>
		/// <remarks>Può essere sottoposto a revisione.</remarks>
		UINT StileFinestraEsteso;
#pragma endregion
#pragma region Costruttori
	private:
		/// <summary>Costruttore predefinito. Inizializza a zero WNDCLASS.</summary>
		Window();
	public:
		/// <summary>Costruttore con l'istanza dell'applicazione.</summary>
		/// <param name="istanza">Istanza dell'applicazione.</param>
		Window(HINSTANCE istanza, String nomeClasse);
#pragma endregion
	public:
		/// <summary>Registra la classe, se non lo è già, e crea la finestra con posizione e dimensioni predefinite senza finestra proprietaria.</summary>
		void RegisterClassAndCreateWindow();
		/// <summary>Registra la classe finestra associata.</summary>
		void RegisterClass();
		/// <summary>Imposta il titolo della finestra.</summary>
		/// <param name="nomeFinestra">Nuovo titolo della finestra.</param>
		void SetTitle(String nomeFinestra);
		/// <summary>Mostra la finestra con la modalità specificata.</summary>
		/// <param name="command">Specifica come mostrare la finestra.</param>
		void ShowWindow(ShowWindowsCommands command);
		/// <summary>Ottiene l'handle dell'istanza della finestra.</summary>
		/// <returns>HWND istanza finestra.</returns>
		HWND GetWindowHandle() const;
		/// <summary>Ottiene le dimensioni del rettangolo Client.</summary>
		/// <returns>Un oggetto Rectangle<LONG></returns>
		Rectangle<LONG> GetClientRect();
	protected:
		/// <summary>Funzione di disegno di base. Ogni finestra che erediterà da quella principale deve chiamare questa funzione.</summary>
		virtual void OnPaint();
		/// <summary>Implementazione della procedura della finestra: si può cambiare, se lo si desidera...</summary>
		/// <param name="messaggio"></param>
		/// <param name="parametro1"></param>
		/// <param name="parametro2"></param>
		/// <returns></returns>
		virtual INT_PTR ProceduraFinestra(UINT messaggio, WPARAM parametro1, LPARAM parametro2);
	private:
		/// <summary>
		/// Procedura della finestra per la classe corrente.
		/// </summary>
		/// <param name="handleFinestra"></param>
		/// <param name="messaggio"></param>
		/// <param name="parametro1"></param>
		/// <param name="parametro2"></param>
		/// <returns></returns>
		static INT_PTR CALLBACK ProceduraStandard(HWND handleFinestra, UINT messaggio, WPARAM parametro1, LPARAM parametro2);
	};
}
#endif