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
	}

	Window::Window(HINSTANCE istanza, String nomeClasse)
		: Window()
	{
		NomeClasse = String(nomeClasse);
		lpszClassName = NomeClasse;
		style = StylesOperations::Combine(ClassStyles::CSHRedraw, ClassStyles::CSVRedraw);
		hInstance = istanza;
		lpfnWndProc = &ProceduraStandard;
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
	void Window::InvalidateRect(Rectangle<LONG> invalidateArea, bool eraseBackground)
	{
		::InvalidateRect(HandleFinestra, invalidateArea, eraseBackground);
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

	void Window::SetTitle(String nomeFinestra)
	{
		NomeFinestra = nomeFinestra;
	}

	void Window::ShowWindow(ShowWindowsCommands command)
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-showwindow
		BOOL statoPrecedente = ::ShowWindow(HandleFinestra, static_cast<int>(command));
	}

	HWND Window::GetWindowHandle() const
	{
		return HandleFinestra;
	}

	Rectangle<LONG> Window::GetClientRect()
	{
		if (HandleFinestra != nullptr)
		{
			RECT rettangolo{ 0 };
			::GetClientRect(HandleFinestra, &rettangolo);
			RettangoloClient = Rectangle<LONG>(rettangolo);
		}
		return RettangoloClient;
	}
#pragma endregion

#pragma region Messaggi
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
