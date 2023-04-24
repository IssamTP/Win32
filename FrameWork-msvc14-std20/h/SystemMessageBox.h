#pragma once
#ifndef _MESSAGE_BOX_H_
    #define _MESSAGE_BOX_H_
    #include "HeaderCPP.h"
    #include "String.h"
namespace FW
{
    /// <summary>
    /// Specifica dei pulsanti che verranno Showti nella MessageBox.
    /// </summary>
    enum class MessageBoxButtons
    {
        Ok = MB_OK,
        OkCancel = MB_OKCANCEL,
        AbortRetryIgnore = MB_ABORTRETRYIGNORE,
        YesNoCancel = MB_YESNOCANCEL,
        YesNo = MB_YESNO,
        RetryCancel = MB_RETRYCANCEL,
    };

    /// <summary>
    /// Specifica delle icone che verranno Showte nella MessageBox.
    /// </summary>
    enum class MessageBoxIcons
    {
        IconHand = MB_ICONHAND,
        IconQuestion = MB_ICONQUESTION,
        IconExclamation = MB_ICONEXCLAMATION,
        IconAsterisk = MB_ICONASTERISK,
    };

    /// <summary>
    /// Alternativa alla MessageBoxIcons.
    /// </summary>
    enum class MessageBoxAlternativeIcons
    {
        IconWarning = MB_ICONWARNING, // MessageBoxIcons::IconExclamation
        IconError = MB_ICONERROR, // MessageBoxIcons::IconHand
        IconInformation = MB_ICONINFORMATION, // MessageBoxIcons::IconAsterisk
        IconStop = MB_ICONSTOP, // MessageBoxIcons::IconHand
    };

    /// <summary>
    /// Specifica il pulsante predefinito della message box.
    /// </summary>
    enum class MessageBoxDefaultButton
    {
        DefaultButton1 = MB_DEFBUTTON1,
        DefaultButton2 = MB_DEFBUTTON2,
        DefaultButton3 = MB_DEFBUTTON3,
        DefaultButton4 = MB_DEFBUTTON4,
    };

    /// <summary>
    /// Specifica i possibili risultati della MessageBox.
    /// </summary>
    enum class MessageBoxResult
    {
        Yes = IDYES,
        No = IDNO,
        Cancel = IDCANCEL,
        Abort = IDABORT,
        Retry = IDRETRY,
        Ignore = IDIGNORE,
    };

    /// <summary>
    /// Classe che permette di utilizzare la chiamata MessageBox delle API di Windows in un ambiente ad oggetti.
    /// L'intestazione inoltre racchiude delle enum class che raccolgono tutte (salvo mancanze) le define associate sparse nei vari .h di Windows.
    /// </summary>
    class _FRAMEWORK_CLASS_EXPORT_ SystemMessageBox
    {
    public:
        /// <summary>
        /// Mostra la MessageBox con il solo messaggio.
        /// </summary>
        /// <param name="messageText">Puntatore al messaggio da mostrare.</param>
        /// <returns>ID pulsante premuto.</returns>
        static MessageBoxResult Show(String messageText);
        /// <summary>
        /// Mostra la MessageBox con messaggio e l'icona informativa.
        /// </summary>
        /// <param name="messageText">Puntatore al messaggio da mostrare.</param>
        /// <param name="messageIcon">Icona informativa circa la natura del messaggio.</param>
        /// <returns>ID pulsante premuto.</returns>
        static MessageBoxResult Show(String messageText, MessageBoxIcons messageIcon);
        /// <summary>
        /// Mostra la MessageBox con imessaggio, titolo e la possibilità di scegliere tra i pulsanti..
        /// </summary>
        /// <param name="messageText">Puntatore al messaggio da mostrare.</param>
        /// <param name="dialogTitle">Titolo della finestra del messaggio.</param>
        /// <returns>ID pulsante premuto.</returns>
        static MessageBoxResult Show(String messageText, String dialogTitle, MessageBoxButtons buttons);
        /// <summary>
        /// Mostra la MessageBox dando la possibilità di specificare tutte le risorse opzionali.
        /// </summary>
        /// <param name="parentHandle">Puntatore della finestra proprietaria, verrà usato da Windows per centrare la finestra MessageBox.</param>
        /// <param name="messageText">Puntatore al messaggio da mostrare.</param>
        /// <param name="dialogTitle">Titolo della MessageBox, comparirà nella barra del titolo.</param>
        /// <param name="buttons">Specifica quali pulsanti mostrare nella MessageBox.</param>
        /// <param name="defaultButtons">Windows userà questo parametro per decidere quale pulsante risponderà all'Invio.</param>
        /// <param name="messageIcon">Icona informativa circa la natura del messaggio.</param>
        /// <returns>ID pulsante premuto.</returns>
        static MessageBoxResult Show(HWND parentHandle, String messageText, String dialogTitle, MessageBoxButtons buttons, MessageBoxDefaultButton defaultButton, MessageBoxIcons messageIcon);
    };
}
#endif