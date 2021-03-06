#include "pch.h"
#include "Brush.h"
#include "Window.h"

namespace FW
{
#pragma region Costruttori
	Window::Window()
		: WNDCLASSEX()
	{
		ModalitaVisualizzazione = ShowWindowsCommands::SWDefault;
		IdUnicoClasse = 0;
		StileFinestra = StileFinestraEsteso = 0ul;
		cbSize = sizeof(WNDCLASSEX);
		CursoreFinestra = nullptr;
		HandleFinestra = nullptr;
		IconaFinestra = nullptr;
		ExtraContestoDisegno = nullptr;
	}

	Window::Window(HINSTANCE istanza, String nomeClasse)
		: Window()
	{
		NomeClasse = String(nomeClasse);
		lpszClassName = NomeClasse;
		style = StylesOperations::Combine(ClassStyles::CSHRedraw, ClassStyles::CSVRedraw);
		hInstance = istanza;
		lpfnWndProc = &ProceduraStandard;
		// Questo colore ? solitamente impostato a bianco affinch? corrisponda con quello di DrawText.
		ContestoDisegno.SetCurrentBrush(Brush::GetDefaultWindowBrush());
		hbrBackground = ContestoDisegno.GetCurrentBrush();
		IconaFinestra = Icon::GetDefaultIcon();
		hIcon = IconaFinestra;
		hIconSm = IconaFinestra;
		CursoreFinestra = Cursor::GetDefaultCursor();
		hCursor = CursoreFinestra;
		lpszMenuName = nullptr;
		StileFinestra = StylesOperations::Combine(WindowStyles::WSOverlappedWindow);
		HandleFinestra = nullptr;
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

	void Window::SetContentSize(LONG width, LONG height)
	{
		DimensioneContenuto.SetHeight(height);
		DimensioneContenuto.SetWidth(width);
		SetScrollRange(ScrollBarIdentifiers::SBVertical, 0, height, false);
		SetScrollPos(ScrollBarIdentifiers::SBVertical, 0, true);
		SetScrollRange(ScrollBarIdentifiers::SBHorizontal, 0, height, false);
		SetScrollPos(ScrollBarIdentifiers::SBHorizontal, 0, true);
	}

	void Window::SetHorizontalScrollPos(int position, bool redraw)
	{
		SetScrollPos(ScrollBarIdentifiers::SBHorizontal, position, redraw);
	}

	void Window::SetHorizontalScrollRange(int minimum, int maximum, bool redraw)
	{
		SetScrollRange(ScrollBarIdentifiers::SBHorizontal, minimum, maximum, redraw);
	}

	void Window::SetTitle(String nomeFinestra)
	{
		NomeFinestra = nomeFinestra;
	}

	void Window::SetVerticalScrollPos(int position, bool redraw)
	{
		SetScrollPos(ScrollBarIdentifiers::SBVertical, position, redraw);
	}

	void Window::SetVerticalScrollRange(int minimum, int maximum, bool redraw)
	{
		SetScrollRange(ScrollBarIdentifiers::SBVertical, minimum, maximum, redraw);
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
		ExtraContestoDisegno = new DeviceContext(::GetDC(HandleFinestra), GetClientRect(false));
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

	WinRectangle Window::GetClientRect(bool considerScrollBars)
	{
		if (HandleFinestra != nullptr)
		{
			::GetClientRect(HandleFinestra, RettangoloClient);
			if (considerScrollBars)
			{
				int larghezzaSV = GetSystemMetrics(static_cast<int>(SystemMetrics::SMCXVScroll));
				int altezzaSO = GetSystemMetrics(static_cast<int>(SystemMetrics::SMCYHScroll));
				RettangoloClient += WinSize(-larghezzaSV, -altezzaSO);

			}
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

	void Window::SetScrollPos(ScrollBarIdentifiers scrollBar, int position, bool redraw)
	{
		int esito = ::SetScrollPos(HandleFinestra, static_cast<int>(scrollBar), position, redraw);
	}

	void Window::SetScrollRange(ScrollBarIdentifiers scrollBar, int minimum, int maximum, bool redraw)
	{
		BOOL esito = ::SetScrollRange(HandleFinestra, static_cast<int>(scrollBar), minimum, maximum, redraw ? TRUE : FALSE);
	}
#pragma endregion

#pragma region Messaggi
	void Window::OnCreate()
	{
		InizializzaTextMetrics();
		if ((StileFinestra & WS_VSCROLL) == WS_VSCROLL)
		{
			MinimoBarraDiScorrimentoVerticale = 0;
			MassimoBarraDiScorrimentoVerticale = 100;
			SetScrollRange(ScrollBarIdentifiers::SBVertical, MinimoBarraDiScorrimentoVerticale, MassimoBarraDiScorrimentoVerticale, false);
			SetScrollPos(ScrollBarIdentifiers::SBVertical, 0, true);
		}
		if ((StileFinestra & WS_HSCROLL) == WS_HSCROLL)
		{
			MinimoBarraDiScorrimentoOrizzontale = 0;
			MassimoBarraDiScorrimentoOrizzontale = 100;
			SetScrollRange(ScrollBarIdentifiers::SBHorizontal, MinimoBarraDiScorrimentoOrizzontale, MassimoBarraDiScorrimentoOrizzontale, false);
			SetScrollPos(ScrollBarIdentifiers::SBHorizontal, 0, true);
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

		switch (notification)
		{
		case ScrollBarNotifications::SBSingleForward:

			break;
		}

		// Versione obsoleta.
		if (identifier == ScrollBarIdentifiers::SBVertical)
		{
			if (position < MinimoBarraDiScorrimentoVerticale)
			{
				position = MinimoBarraDiScorrimentoVerticale;
			}
			if (position > MassimoBarraDiScorrimentoVerticale)
			{
				position = MassimoBarraDiScorrimentoVerticale;
			}
		}
		if (identifier == ScrollBarIdentifiers::SBHorizontal)
		{
			if (position < MinimoBarraDiScorrimentoOrizzontale)
			{
				position = MinimoBarraDiScorrimentoOrizzontale;
			}
			if (position > MassimoBarraDiScorrimentoOrizzontale)
			{
				position = MassimoBarraDiScorrimentoOrizzontale;
			}
		}
		SetScrollPos(identifier, position, true);
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
	/// <param name="handleFinestra">Handle della finestra cui ? destinato il messaggio.</param>
	/// <param name="messaggio">Codice del messaggio: vedere la documentazione.</param>
	/// <param name="parametro1">Parametro, il senso cambia da messaggio a messaggio.</param>
	/// <param name="parametro2">Parametro, il senso cambia da messaggio a messaggio.</param>
	/// <returns>Se 0 il messaggio ? stato gestito, 1 ? da gestire.</returns>
	INT_PTR CALLBACK Window::ProceduraStandard(HWND handleFinestra, UINT messaggio, WPARAM parametro1, LPARAM parametro2)
	{
		INT_PTR messaggioGestito;
		Window* finestraDiRiferimento = nullptr;
		if (messaggio == WM_NCCREATE)
		{
			/* Messaggio di creazione "NC", NonClient. ? la prima volta che arriva, quindi sto mettendo in piedi l'ambaradan.
			 * Salvo il puntatore. che occorrer? in seguito per comunicare con la finestra.
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
