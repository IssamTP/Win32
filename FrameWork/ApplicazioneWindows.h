#pragma once
#ifndef _WINDOWS_APP_H_
    #define _WINDOWS_APP_H_
    #include "HeaderCPP.h"
    #include "WinExports.h"
    #include "Window.h"
namespace FW
{
    class CLASS_EXPORT ApplicazioneWindows
    {
    protected:
        Window* FinestraApplicazione;
        HINSTANCE IstanzaApplicazione;
    public:
        ApplicazioneWindows();
#pragma region Virtuali
        virtual void InizializzaApplicazione();
#pragma endregion
#pragma region Get/Set
        void SetIstanzaApplicazione(HINSTANCE istanzaApplicazione);
        HINSTANCE GetIstanzaApplicazione() const;
#pragma endregion
    };
}
#endif