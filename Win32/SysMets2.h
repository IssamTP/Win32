#pragma once

#include <headers/FrameWork.h>
#include "SysMetsValue.h"

/// <summary>
/// Rappresentare la lista di parametri di SystemMetrics in una finestra di Windows e renderli visibili.
/// </summary>
class CSysMets2 : public FW::Window
{
public:
	static constexpr UINT CAPS = 0u;
	static constexpr UINT NO_CAPS = 1u;
protected:
	/// <summary>Altezza della singola riga di testo.</summary>
	LONG AltezzaRiga;
	/// <summary>Larghezza della colonna che conterrà il codice define (SM_CXSCREEN per esermpio).</summary>
	LONG LarghezzaColonnaCodice;
	/// <summary>Larghezza della colonna con la descrizione del significato della costante.</summary>
	LONG LarghezzaColonnaDescrizione;
	/// <summary>Larghezza della colonna con i valori delle costanti.</summary>
	LONG LarghezzaColonnaValore;
	/// <summary>Puntatore al font di sistema con le sue proprietà.</summary>
	FW::TextMetrics* TextMetric;
	/// <summary>Elenco dei valori con define e descrizione.</summary>
	CSysMetsValues Values;
public:
	/// <summary>Costruttore finestra.</summary>
	/// <param name="istanza">Istanza dell'applicazione.</param>
	CSysMets2(HINSTANCE istanza);
protected:
	virtual void OnCreate();
	virtual void OnPaint();
	/// <summary>Genera tutti i dati da mostrare a video.</summary>
	void CreaDati();
};
