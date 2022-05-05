#include "pch.h"
#ifdef _SOLO_STABILI_
#include "Window.h"
#endif
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
#pragma endregion

#pragma region Virtuali
	/// <summary>
	/// Inizializza l'applicazione.
	/// </summary>
	void ApplicazioneWindows::InizializzaApplicazione()
	{

	}
#pragma endregion

#pragma region Get/Set
	/// <summary>
	/// Imposta il valore dell'istanza di applicazione.
	/// </summary>
	/// <param name="istanzaApplicazione">Id dell'applicazione. Lo fornisce _tWinMain.</param>
	void ApplicazioneWindows::SetIstanzaApplicazione(HINSTANCE istanzaApplicazione)
	{
		IstanzaApplicazione = istanzaApplicazione;
	}

	/// <summary>
	/// Ottiene l'istanza dell'applicazione.
	/// </summary>
	/// <returns>L'ID dell'applicazione.</returns>
	HINSTANCE ApplicazioneWindows::GetIstanzaApplicazione() const
	{
		return IstanzaApplicazione;
	}
#pragma endregion
}
