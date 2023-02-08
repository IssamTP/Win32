#include "pch.h"
#include "ApplicazioneWindows.h"

namespace FW
{
#pragma region Singleton
	ApplicazioneWindows* ApplicazioneWindows::WinApp = nullptr;
	ApplicazioneWindows* ApplicazioneWindows::GetWinAppInstance()
	{
		if (ApplicazioneWindows::WinApp == nullptr)
		{
			ApplicazioneWindows::WinApp = new ApplicazioneWindows();
		}
		return ApplicazioneWindows::WinApp;
	}
#pragma endregion

#pragma region Costruttori
	ApplicazioneWindows::~ApplicazioneWindows()
	{
		if (FinestraApplicazione != nullptr)
		{
			delete FinestraApplicazione;
		}
	}
#pragma endregion

#pragma region Virtuali
	WPARAM ApplicazioneWindows::AvviaApplicazione()
	{
		WPARAM valoreDiRitorno = 0u;
		if (FinestraApplicazione != nullptr)
		{
			FinestraApplicazione->RegisterClassAndCreateWindow();
			HWND handle = FinestraApplicazione->GetWindowHandle();
			MSG message;
			while (GetMessage(&message, handle, 0, 0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			valoreDiRitorno = message.wParam;
		}
		return valoreDiRitorno;
	}

	void ApplicazioneWindows::InizializzaApplicazione(Window* window)
	{
		if (FinestraApplicazione != nullptr)
		{
			delete FinestraApplicazione;
		}
		FinestraApplicazione = window;
	}

	void ApplicazioneWindows::InizializzaApplicazione(HINSTANCE istance, String nomeClasseFinestra, String nomeFinestra)
	{
		FinestraApplicazione = new Window(istance, nomeClasseFinestra);
		FinestraApplicazione->SetTitle(nomeFinestra);
	}
#pragma endregion
}
