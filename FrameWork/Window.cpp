#include "pch.h"
#include "Brush.h"
#include "Window.h"

namespace FW
{
#pragma region Costruttori
	Window::Window(HINSTANCE istanza, const String& nomeClasse)
		: WNDCLASSEX(), NomeClasse{ nomeClasse }
	{
		lpfnWndProc = &ProceduraStandard;
		lpszClassName = NomeClasse;
		style = StylesOperations::Combine(ClassStyles::CSHRedraw, ClassStyles::CSVRedraw);
		hInstance = istanza;
		// Questo colore è solitamente impostato a bianco affinché corrisponda con quello di DrawText.
		ContestoDisegno.SetCurrentBrush(Brush::GetDefaultWindowBrush());
		hbrBackground = ContestoDisegno.GetCurrentBrush();
		IconaFinestra = Icon::GetDefaultIcon();
		hIcon = IconaFinestra;
		hIconSm = IconaFinestra;
		CursoreFinestra = Cursor::GetDefaultCursor();
		hCursor = CursoreFinestra;
		lpszMenuName = nullptr;
	}
#pragma endregion

#pragma region Interfaccia
	void Window::InvalidateClientArea(bool eraseBackground)
	{
		::InvalidateRect(HandleFinestra, nullptr, eraseBackground);
	}

	void Window::InvalidateRect(const WinRectangle& invalidateArea, bool eraseBackground)
	{
		::InvalidateRect(HandleFinestra, invalidateArea, eraseBackground);
	}

	void Window::ModifyStyle(UINT stylesToAdd, UINT stylesToRemove)
	{
		StileFinestra |= stylesToAdd;
		StileFinestra &= ~stylesToRemove;
	}

	void Window::RegisterClassAndCreateWindow()
	{
		RegisterClass();
		int usaPredefinito = static_cast<int>(StylesOperations::Combine(CreateWindowOptions::CWUseDefault));
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-createwindowexw
		HandleFinestra = CreateWindowEx(StileFinestraEsteso, NomeClasse, NomeFinestra, StileFinestra, usaPredefinito, usaPredefinito, usaPredefinito, usaPredefinito, nullptr, nullptr, hInstance, this);
		if (HandleFinestra != nullptr)
		{
			ShowWindow(ShowWindowsCommands::SWShow);
			UpdateWindow(HandleFinestra);
		}
		else
		{
			throw std::exception();
		}
	}

	void Window::RegisterClass()
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-registerclassexw
		IdUnicoClasse = RegisterClassEx(this);
		if (IdUnicoClasse == 0)
		{
			throw std::exception();
		}
	}

	void Window::ReleaseDC()
	{
		if (::ReleaseDC(HandleFinestra, *ExtraContestoDisegno) == 1)
		{
			delete ExtraContestoDisegno;
			ExtraContestoDisegno = nullptr;
		}
	}

	void Window::SetTitle(String nomeFinestra)
	{
		NomeFinestra = nomeFinestra;
	}

	void Window::ShowWindow(ShowWindowsCommands command)
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-showwindow
		BOOL statoPrecedente = ::ShowWindow(HandleFinestra, static_cast<int>(command));
	}

	void Window::ValidateRect(const WinRectangle& areaToValidate)
	{
		BOOL esito = ::ValidateRect(HandleFinestra, areaToValidate);
	}

	DeviceContext* Window::GetCientDC()
	{
		if (ExtraContestoDisegno != nullptr)
		{
			ReleaseDC();
		}
		ExtraContestoDisegno = new DeviceContext(::GetDC(HandleFinestra), GetClientRect());
		return ExtraContestoDisegno;
	}

	DeviceContext* Window::GetWindowDC()
	{
		if (ExtraContestoDisegno != nullptr)
		{
			ReleaseDC();
		}
		ExtraContestoDisegno = new DeviceContext(::GetWindowDC(HandleFinestra), GetWindowRect());
		return ExtraContestoDisegno;
	}

	HWND Window::GetWindowHandle() const
	{
		return HandleFinestra;
	}

	WinRectangle Window::GetClientRect()
	{
		if (HandleFinestra != nullptr)
		{
			::GetClientRect(HandleFinestra, RettangoloClient);
		}
		return RettangoloClient;
	}

	WinRectangle Window::GetWindowRect()
	{
		if (HandleFinestra != nullptr)
		{
			::GetWindowRect(HandleFinestra, RettangoloWindow);
			RettangoloWindow.GetOriginAndSize(Posizione, Dimensione);
		}
		return RettangoloWindow;
	}
#pragma endregion

#pragma region Implementazione
	void Window::InizializzaTextMetrics()
	{
		DeviceContext* wdc = GetWindowDC();
		wdc->GetTextMetrics();
		ReleaseDC();
	}
#pragma endregion

#pragma region Messaggi
	void Window::OnCreate()
	{
		InizializzaTextMetrics();
		if ((StileFinestra & WS_VSCROLL) == WS_VSCROLL)
		{
			SetScrollRange(HandleFinestra, SB_VERT, 0, 100, FALSE);
			SetScrollPos(HandleFinestra, SB_VERT, 0, TRUE);
		}
		if ((StileFinestra & WS_HSCROLL) == WS_HSCROLL)
		{
			SetScrollRange(HandleFinestra, SB_HORZ, 0, 100, FALSE);
			SetScrollPos(HandleFinestra, SB_HORZ, 0, TRUE);
		}
	}

	void Window::OnEraseBkGnd()
	{
	}

	void Window::OnPaint()
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-beginpaint
		HDC controllo = BeginPaint(HandleFinestra, &ContestoDisegno);
		if (controllo != ContestoDisegno)
		{
			throw std::exception();
		}
	}

	void Window::OnScroll(ScrollBarIdentifiers identifier, ScrollBarNotifications notification, int position)
	{
		if (notification == ScrollBarNotifications::SBThumbPosition || notification == ScrollBarNotifications::SBThumbTrack)
		{
			SetScrollPos(HandleFinestra, static_cast<int>(identifier), position, TRUE);
		}
	}

	void Window::OnSize(WORD width, WORD height)
	{
		RettangoloClient.SetSize(WinSize(width, height));
	}

	INT_PTR Window::ProceduraFinestra(UINT messaggio, WPARAM wParam, LPARAM lParam)
	{
		INT_PTR messaggioDaGestire = FALSE;

		switch (static_cast<WindowsMessages>(messaggio))
		{
		default:
			messaggioDaGestire = DefWindowProc(HandleFinestra, messaggio, wParam, lParam);
			break;
		case WindowsMessages::WMClose:
			DestroyWindow(HandleFinestra);
			messaggioDaGestire = FALSE;
			break;
		case WindowsMessages::WMCreate:
			OnCreate();
			break;
		case WindowsMessages::WMEraseBkGnd:
			OnEraseBkGnd();
			break;
		case WindowsMessages::WMDestroy:
			PostQuitMessage(EXIT_SUCCESS);
			messaggioDaGestire = FALSE;
			break;
		case WindowsMessages::WMPaint:
			OnPaint();
			// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-endpaint
			EndPaint(HandleFinestra, &ContestoDisegno);
			break;
		case WindowsMessages::WMHScroll:
		case WindowsMessages::WMVScroll:
			OnScroll(messaggio == WM_HSCROLL ? ScrollBarIdentifiers::SBHorizontal : ScrollBarIdentifiers::SBVertical, static_cast<ScrollBarNotifications>(LOWORD(wParam)), static_cast<int>(HIWORD(wParam)));
			break;
		case WindowsMessages::WMSize:
			OnSize(LOWORD(lParam), HIWORD(lParam));
			break;
		}
		if (ExtraContestoDisegno != nullptr)
		{
			ReleaseDC();
		}
		return messaggioDaGestire;
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
