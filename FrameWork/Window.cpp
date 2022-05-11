#include "pch.h"
#include "Size.h"
#include "Point.h"
#include "Icon.h"
#include "Cursor.h"
#include "StylesOperations.h"
#include "Window.h"

namespace FW
{
#pragma region Costruttori
	Window::Window()
	{
		memset(&ClasseWindows, 0, sizeof(WNDCLASSEX));
		ClasseWindows.cbSize = sizeof(WNDCLASSEX);
		CursoreFinestra = nullptr;
		IdUnicoClasse = 0;
		StileFinestra = StileFinestraEsteso = 0ul;
		IconaFinestra = nullptr;
		HandleFinestra = nullptr;
	}

	Window::Window(HINSTANCE istanza, String nomeClasse)
		: Window()
	{
		NomeClasse = String(nomeClasse);
		ClasseWindows.style = StylesOperations::Combine(ClassStyles::CSHRedraw, ClassStyles::CSVRedraw, WindowStyles::WSVisible);
		ClasseWindows.hInstance = istanza;
		ClasseWindows.lpfnWndProc = &ProceduraStandard;
		ClasseWindows.lpszClassName = NomeClasse;
		ClasseWindows.hIcon = Icon::GetDefaultIcon();
		ClasseWindows.hIconSm = Icon::GetDefaultIcon();
		ClasseWindows.hCursor = Cursor::GetDefaultCursor();
		ClasseWindows.lpszMenuName = nullptr;
		HandleFinestra = nullptr;
	}
#pragma endregion

#pragma region Interfaccia
	void Window::RegisterClassAndCreateWindow()
	{
		CreateWindowEx(StileFinestraEsteso, NomeClasse, NomeFinestra, StileFinestra, StylesOperations::Combine(CW_USEDEFAULT))
	}

	void Window::RegisterWindowClass()
	{
		IdUnicoClasse = RegisterClassEx(&ClasseWindows);
		if (IdUnicoClasse == 0)
		{
			throw std::exception();
		}
	}
#pragma endregion

#pragma region Messaggi
	INT_PTR Window::ProceduraFinestra(UINT messaggio, WPARAM wParam, LPARAM lParam)
	{
		INT_PTR messaggioGestito = FALSE;
		switch (messaggio)
		{
		default:
			messaggioGestito = DefWindowProc(HandleFinestra, messaggio, wParam, lParam);
			break;
		case WM_CREATE:
		{
			/*
			// Inizializzazione dei parametri di TextMetric.
			HDC finestra = GetDC(HandleFinestra);
			GetTextMetrics(finestra, m_TextMetric);
			ReleaseDC(HandleFinestra, finestra);
			messaggioGestito = OnCreate(wParam, lParam);
			*/
		}
		break;
		case WM_CLOSE:
			messaggioGestito = TRUE;
			DestroyWindow(HandleFinestra);
			break;
		case WM_DESTROY:
			messaggioGestito = TRUE;
			// TODO: Pulizia risorse...
			PostQuitMessage(EXIT_SUCCESS);
			break;
		case WM_HSCROLL:
			// OnHScroll(static_cast<EventiHScroll>(LOWORD(wParam)), HIWORD(wParam));
			break;
		case WM_NOTIFY:
			// OnNotify(reinterpret_cast<LPNMHDR>(lParam));
			break;
		case WM_PAINT:
			// OnPaint();
			break;
		case WM_SIZE:
			// OnSize(LOWORD(lParam), HIWORD(lParam));
			messaggioGestito = TRUE;
			break;
		case WM_VSCROLL:
			// OnVScroll(static_cast<EventiVScroll>(LOWORD(wParam)), HIWORD(wParam));
			break;
		}
		return messaggioGestito;
	}

#pragma endregion

#pragma region Statiche
	/// <summary>
	/// Procedura come membro di classe, da rimettere in ogni classe derivata probabilmente.
	/// https://devblogs.microsoft.com/oldnewthing/20140203-00/?p=1893
	/// </summary>
	/// <param name="handleFinestra">Handle della finestra cui è destinato il messaggio.</param>
	/// <param name="messaggio">Codice del messaggio: vedere la documentazione.</param>
	/// <param name="parametro1">Parametro, il senso cambia da messaggio a messaggio.</param>
	/// <param name="parametro2">Parametro, il senso cambia da messaggio a messaggio.</param>
	/// <returns>Se 0 il messaggio è stato gestito, 1 è da gestire.</returns>
	INT_PTR CALLBACK Window::ProceduraStandard(HWND handleFinestra, UINT messaggio, WPARAM parametro1, LPARAM parametro2)
	{
		INT_PTR messaggioGestito;
		Window* finestraDiRiferimento = nullptr;
		if (messaggio == WM_NCCREATE)
		{
			/* Messaggio di creazione "NC", NonClient. È la prima volta che arriva, quindi sto mettendo in piedi l'ambaradan.
			 * Salvo il puntatore. che occorrerà in seguito per comunicare con la finestra.
			 */
			LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(parametro2);
			finestraDiRiferimento = static_cast<Window*>(lpcs->lpCreateParams);
			if (finestraDiRiferimento != nullptr)
				finestraDiRiferimento->HandleFinestra = handleFinestra;
			SetWindowLongPtr(handleFinestra, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(finestraDiRiferimento));
		}
		else
			finestraDiRiferimento = reinterpret_cast<Window*>(GetWindowLongPtr(handleFinestra, GWLP_USERDATA));
		if (finestraDiRiferimento != nullptr)
			// Sappiamo a che finestra ci stiamo riferendo: possiamo farle fare il lavoro sporco.
			messaggioGestito = finestraDiRiferimento->ProceduraFinestra(messaggio, parametro1, parametro2);
		else
			// Non sappiamo a chi fa riferimento il puntatore... ci pensa Windows.
			messaggioGestito = DefWindowProc(handleFinestra, messaggio, parametro1, parametro2);
		return messaggioGestito;
	}
#pragma endregion
}
