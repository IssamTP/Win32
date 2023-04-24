#pragma once
#ifndef _WINDOWS_APP_H_
    #define _WINDOWS_APP_H_
    #include "HeaderCPP.h"
    #include "WinExports.h"
    #include "Window.h"
    #include "TextMetrics.h"
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
#pragma region Singleton
    private:
        static ApplicazioneWindows* WinApp;
        ApplicazioneWindows() = default;
        ApplicazioneWindows(const ApplicazioneWindows& winApp) = delete;
        ApplicazioneWindows& operator=(const ApplicazioneWindows& winApp) = delete;
    public:
        static ApplicazioneWindows* GetWinAppInstance();
#pragma endregion
    public:
        ~ApplicazioneWindows();
#pragma region Virtuali
        /// <summary>
        /// Inizializza l'applicazione con l'istanza del programma.
        /// Questo metodo crea una classe di finestra con una serie di valori predefiniti: sovrascriverlo per personalizzare la finestra.
        /// Per mostrarla utilizzare AvviaApplicazione.
        /// </summary>
        /// <param name="instance">Istanza del programma.</param>
        /// <param name="nomeClasseFinestra">Nome da assegnare alla classe finestra.</param>
        /// <param name="titoloFinestra">Titolo che comparirà nella barra del titolo.</param>
        virtual void InizializzaApplicazione(HINSTANCE instance, String nomeClasseFinestra, String titoloFinestra);
        /// <summary>
        /// Inizializza l'applicazione con l'istanza del programma.
        /// Questo metodo crea una classe di finestra con una serie di valori predefiniti: sovrascriverlo per personalizzare la finestra.
        /// Per mostrarla utilizzare AvviaApplicazione.
        /// </summary>
        /// <param name="window">Finestra di avvio.</param>
        virtual void InizializzaApplicazione(Window* window);
        /// <summary>
        /// Avvia l'applicazione corrente.
        /// </summary>
        /// <return>Valore dell'ultimo messaggio ricevuto.</param>
        virtual WPARAM AvviaApplicazione();
#pragma endregion
    };
}
#endif