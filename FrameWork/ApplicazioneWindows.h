#pragma once
#ifndef _WINDOWS_APP_H_
    #define _WINDOWS_APP_H_
    #include "HeaderCPP.h"
    #include "WinExports.h"
    #include "Window.h"
namespace FW
{
    /// <summary>
    /// Classe che gestisce la finestra principale e il ciclo dei messaggi.
    /// </summary>
    class _FRAMEWORK_CLASS_EXPORT_ ApplicazioneWindows
    {
    protected:
        /// <summary>
        /// Istanza unica dell'applicazione.
        /// </summary>
        HINSTANCE IstanzaApplicazione;
        /// <summary>
        /// Puntatore alla finestra principale del programma.
        /// </summary>
        Window* FinestraApplicazione;
    public:
        ApplicazioneWindows();
        ~ApplicazioneWindows();
#pragma region Virtuali
        virtual void AvviaApplicazione();
        /// <summary>
        /// Inizializza l'applicazione con l'istanza del programma.
        /// Questo metodo crea una classe di finestra con una serie di valori predefiniti: sovrascriverlo per personalizzare la finestra.
        /// Per mostrarla utilizzare AvviaApplicazione.
        /// </summary>
        /// <param name="instance">Istanza del programma.</param>
        /// <param name="nomeClasseFinestra">Nome da assegnare alla classe finestra.</param>
        virtual void InizializzaApplicazione(HINSTANCE instance, String nomeClasseFinestra);
#pragma endregion
    };
}
#endif