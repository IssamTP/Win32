#pragma once
#ifndef _WINDOW_H_
	#define _WINDOW_H_
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
		/// Nome della classe di finestre.
		/// </summary>
		String NomeClasse;
		/// <summary>
		/// Classe di registrazione della finestra..
		/// </summary>
		WNDCLASS ClasseWindows;
	public:
		/// <summary>
		/// Costruttore con l'istanza dell'applicazione.
		/// </summary>
		/// <param name="istanza">Istanza dell'applicazione.</param>
		Window(HINSTANCE istanza, String nomeClasse);
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