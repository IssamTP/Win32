#include "pch.h"
#include "ApplicazioneWindows.h"

namespace FW
{
#pragma region Costruttori
	/// <summary>Costruttore predefinito.</summary>
	ApplicazioneWindows::ApplicazioneWindows()
	{
		IstanzaApplicazione = nullptr;
		FinestraApplicazione = nullptr;
	}

	ApplicazioneWindows::~ApplicazioneWindows()
	{
		if (FinestraApplicazione != nullptr)
		{
			delete FinestraApplicazione;
		}
	}
#pragma endregion

#pragma region Virtuali
	void ApplicazioneWindows::AvviaApplicazione()
	{
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
		}
	}


	void ApplicazioneWindows::InizializzaApplicazione(HINSTANCE istance, String nomeClasseFinestra)
	{
		FinestraApplicazione = new Window(istance, nomeClasseFinestra);
	}
#pragma endregion
}
