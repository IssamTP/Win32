#pragma once
#ifndef _WINDOW_H_
	#define _WINDOW_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
namespace FW
{
	class Cursor;
	class Icon;
	/// <summary>
	/// Finestra di base.
	/// Incapsula le funzionalità di base della finestra C.
	/// </summary>
	class CLASS_EXPORT Window
	{
	protected:
		/// <summary>
		/// Identificatore unico della classe. Vale solo se != 0.
		/// </summary>
		ATOM IdUnicoClasse;
		/// <summary>
		/// Cursore della finestra.
		/// </summary>
		Cursor* CursoreFinestra;
		/// <summary>
		/// Icona della finestra.
		/// </summary>
		Icon* IconaFinestra;
		/// <summary>
		/// "Puntatore" alla finestra di Windows.
		/// </summary>
		HWND HandleFinestra;
		/// <summary>
		/// Coordinata di posizione della finestra sullo schermo.
		/// </summary>
		Point2D<LONG> Posizione;
		/// <summary>
		/// Dimensioni in pixel della finestra sullo schermo.
		/// </summary>
		Size<LONG> Dimensione;
		/// <summary>
		/// Nome della classe di finestre.
		/// </summary>
		String NomeClasse;
		/// <summary>
		/// Imposta il nome della finestra (verrà visualizzato sulla barra del titolo).
		/// </summary>
		String NomeFinestra;
		/// <summary>
		/// Combinazione di WindowStyles.
		/// </summary>
		/// <remarks>Può essere sottoposto a revisione.</remarks>
		UINT StileFinestra;
		/// <summary>
		/// Combinazione di WindowStylesEx.
		/// </summary>
		/// <remarks>Può essere sottoposto a revisione.</remarks>
		UINT StileFinestraEsteso;
		/// <summary>
		/// Classe di registrazione della finestra..
		/// </summary>
		WNDCLASSEX ClasseWindows;
	public:
		/// <summary>
		/// Costruttore con l'istanza dell'applicazione.
		/// </summary>
		/// <param name="istanza">Istanza dell'applicazione.</param>
		Window(HINSTANCE istanza, String nomeClasse);
		/// <summary>
		/// Registra la classe, se non lo è già, e crea la finestra.
		/// </summary>
		void RegisterClassAndCreateWindow();
		/// <summary>
		/// Registra la classe finestra associata.
		/// </summary>
		void RegisterWindowClass();
	private:
		/// <summary>
		/// Costruttore predefinito. Inizializza a zero WNDCLASS.
		/// </summary>
		Window();
	protected:
		/// <summary>
		/// Implementazione della procedura della finestra: si può cambiare, se lo si desidera...
		/// </summary>
		/// <param name="messaggio"></param>
		/// <param name="parametro1"></param>
		/// <param name="parametro2"></param>
		/// <returns></returns>
		INT_PTR ProceduraFinestra(UINT messaggio, WPARAM parametro1, LPARAM parametro2);
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