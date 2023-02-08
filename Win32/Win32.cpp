#ifdef _DEBUG
    #include <h/FrameWork.h>
#else
    #include <FrameWork/FrameWork.h>
#endif
#include "AG_Framework.h"
#include "Win32.h"
#include "HelloWin.h"
#include "SysMetsWin.h"

#define MAX_LOADSTRING 100

// Variabili globali:
HINSTANCE hInst;                                // istanza corrente
WCHAR szTitle[MAX_LOADSTRING];                  // Testo della barra del titolo
WCHAR szWindowClass[MAX_LOADSTRING];            // nome della classe della finestra principale

// Dichiarazioni con prototipo di funzioni incluse in questo modulo di codice:
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    // Inizializzare le stringhe globali
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32, szWindowClass, MAX_LOADSTRING);
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32));
    FW::ApplicazioneWindows* applicazioneWindows = FW::ApplicazioneWindows::GetWinAppInstance();
    //HelloWin* finestra = new HelloWin(hInstance, szWindowClass);
    SysMetsWin* finestra = new SysMetsWin(hInstance, szWindowClass);
    finestra->ModifyStyle(FW::StylesOperations::Combine(FW::WindowStyles::WSHScroll, FW::WindowStyles::WSVScroll), 0ul);
    finestra->SetTitle(szTitle);
    applicazioneWindows->InizializzaApplicazione(finestra);
    WPARAM exitValue = applicazioneWindows->AvviaApplicazione();
    delete applicazioneWindows;
    return exitValue;
}

// Gestore di messaggi per la finestra Informazioni su.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
