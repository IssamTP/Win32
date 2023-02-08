#pragma once
#ifndef _WINDOW_H_
	#define _WINDOW_H_
	#include "HeaderCPP.h"
	#include "WinPoint.h"
	#include "WinSize.h"
	#include "Cursor.h"
	#include "Icon.h"
	#include "WinRectangle.h"
	#include "StylesOperations.h"
	#include "DeviceContext.h"
	#include "WinExports.h"
	#include "WinUndefinitions.h"
namespace FW
{
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
		/// <summary>Riferimento all'extra context da deallocare nel caso in cui l'utente se ne dimentichi.</summary>
		/// <summary>Riferimento all'extra context da deallocare nel caso in cui l'utente se ne dimentichi.</summary>
		DeviceContext* ExtraContestoDisegno;
		/// <summary>Icona della finestra.</summary>
		Icon IconaFinestra;
		/// <summary>"Puntatore" alla finestra di Windows.</summary>
		HWND HandleFinestra;
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
		/// <summary>Coordinata di posizione della finestra sullo schermo.</summary>
		WinPoint Posizione;
		/// <summary>Dimensioni dell'area client.</summary>
		WinRectangle RettangoloClient;
		/// <summary>Dimensioni dell'area client.</summary>
		WinRectangle RettangoloWindow;
		/// <summary>Dimensioni in pixel della finestra sullo schermo.</summary>
		WinSize Dimensione;
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
		/// <summary>
		/// Invalida tutta l'area client della finestra.
		/// </summary>
		/// <param name="eraseBackground">Se sì, invita Windows a cancellare lo sfondo (fErase di PAINTSTRUCT sarà == 0).</param>
		void InvalidateClientArea(bool eraseBackground);
		/// <summary>
		/// Specifica a Windows che si vuole invalidare una porzione dell'area di client E se si vuole cancellare lo sfondo.
		/// </summary>
		/// <param name="invalidateArea">Rettangolo da invalidare.</param>
		/// <param name="eraseBackground">Se sì, invita Windows a cancellare lo sfondo (fErase di PAINTSTRUCT sarà == 0).</param>
		void InvalidateRect(const WinRectangle& invalidateArea, bool eraseBackground);
		/// <summary>
		/// Modifica lo stile corrente della finestra.
		/// </summary>
		/// <param name="stylesToAdd">Aggiunge questa combinazione di stili a quella già presente.</param>
		/// <param name="stylesToRemove">Rimuove questa combinazione di stili a quella già presente.</param>
		/// <remarks>Funzione ancora in lavorazione.</remarks>
		void ModifyStyle(UINT stylesToAdd, UINT stylesToRemove);
		/// <summary>Registra la classe, se non lo è già, e crea la finestra con posizione e dimensioni predefinite senza finestra proprietaria.</summary>
		void RegisterClassAndCreateWindow();
		/// <summary>Registra la classe finestra associata.</summary>
		void RegisterClass();
		/// <summary>
		/// Dealloca il DeviceContext ottenuto con GetDC.
		/// </summary>
		/// <remarks>Questa funzione deve essere chiamata nello stesso messaggio in cui si è chiamato GetDC.</remarks>
		void ReleaseDC();
		/// <summary>Imposta il titolo della finestra.</summary>
		/// <param name="nomeFinestra">Nuovo titolo della finestra.</param>
		void SetTitle(String nomeFinestra);
		/// <summary>Mostra la finestra con la modalità specificata.</summary>
		/// <param name="command">Specifica come mostrare la finestra.</param>
		void ShowWindow(ShowWindowsCommands command);
		/// <summary>
		/// Valida manualmente una porzione dello schermo.
		/// </summary>
		/// <param name="areaToValidate">Porzione dello schermo da validare.</param>
		/// <remarks>Questa funzione va eventualmente utilizzata di concerto con GetClient/WindowDC.</remarks>
		void ValidateRect(const WinRectangle& areaToValidate);
		/// <summary>
		/// Crea e restituisce un Device Context.
		/// Richiede una chiamata a ReleaseDC().
		/// </summary>
		/// <returns>Un oggetto DeviceContext da usare per disegnare fuori dal messaggio WM_PAINT.</returns>
		/// <remarks>GetDC non valida porzioni di finestra eventualmente invaldiate, chiamare ValidateRect(). Questa funzione dovrebbe essere usata per disegnare qualcosa in risposta agli eventi generati dall'utente.</remarks>
		DeviceContext* GetCientDC();
		/// <summary>
		/// Crea e restituisce un Device Context per tutta la finestra.
		/// Richiede una chiamata a ReleaseDC().
		/// </summary>
		/// <returns>Come per GetClientDC, ma valido su tutta la finestra.</returns>
		DeviceContext* GetWindowDC();
		/// <summary>Ottiene l'handle dell'istanza della finestra.</summary>
		/// <returns>HWND istanza finestra.</returns>
		HWND GetWindowHandle() const;
		/// <summary>Ottiene le dimensioni del rettangolo Client.</summary>
		/// <returns>Un oggetto WinRectangle.</returns>
		WinRectangle GetClientRect();
		/// <summary>
		/// Ottiene le dimensioni del rettangolo finestra.
		/// </summary>
		/// <returns>Un oggetto WinRectangle.</returns>
		WinRectangle GetWindowRect();
	protected:
		/// <summary>
		/// Crea le funzionalità di base della finestra.
		/// Se si sovrascrive va chiamato sempre.
		/// </summary>
		virtual void OnCreate();
		/// <summary>
		/// Funzione di cancellazione personalizzata dello sfondo dell'area client.
		/// </summary>
		virtual void OnEraseBkGnd();
		/// <summary>Funzione di disegno di base. Ogni finestra che erediterà da quella principale deve chiamare questa funzione.</summary>
		/// <remarks>Si suggerisce di fare caso al rettangolo di ridisegno in fase di implementazione della OnPaint.</remarks>
		virtual void OnPaint();
		/// <summary>
		/// Gestisce lo scorrimento dell'area visibile sia in orizzontale che in verticale.
		/// </summary>
		/// <param name="identifier">Identificatore della barra di scorrimento.</param>
		/// <param name="notification">Operazione occorsa.</param>
		/// <param name="position">Ha senso solo se operazione occorsa è uguale a SB_THUMBTRACK/SB_THUMBPOSITION.</param>
		/// <remarks>ACHTUNG: Windows non cambierà la posizione dello scroll alla ricezione di questo messaggio, bisogna farlo con SetScrollInfo. Se non lo si farà, Windows porterà indietro la posizione dello scroll. Solitamente si elabora solamente uno tra i due messaggi di trascinamento: se si elabora THUMBTRACK la vista viene spostata mentre il cursore è trascinato, altrimenti alla fine.</remarks>
		virtual void OnScroll(ScrollBarIdentifiers identifier, ScrollBarNotifications notification, int position);
		/// <summary>
		/// Registra le nuove dimensioni della finestra a seguito di WM_SIZE.
		/// </summary>
		/// <param name="width">Larghezza della finestra.</param>
		/// <param name="height">Altezza della finestra.</param>
		virtual void OnSize(WORD width, WORD height);
		/// <summary>Implementazione della procedura della finestra: si può cambiare, se lo si desidera...</summary>
		/// <param name="messaggio"></param>
		/// <param name="parametro1"></param>
		/// <param name="parametro2"></param>
		/// <returns></returns>
		virtual INT_PTR ProceduraFinestra(UINT messaggio, WPARAM parametro1, LPARAM parametro2);
	private:
		void InizializzaTextMetrics();
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