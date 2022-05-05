#include "pch.h"
#include "SystemMessageBox.h"

namespace FW
{
#pragma region Statiche
	/// <summary>
	/// Mostra la MessageBox con il solo messaggio.
	/// </summary>
	/// <param name="messageText">Puntatore al messaggio da mostrare.</param>
	/// <returns>ID pulsante premuto.</returns>
	MessageBoxResult SystemMessageBox::Show(String messageText)
	{
		return Show(nullptr, messageText, TEXT(""), MessageBoxButtons::Ok, MessageBoxDefaultButton::DefaultButton1, MessageBoxIcons::IconAsterisk);
	}

	/// <summary>
	/// Mostra la MessageBox con messaggio e l'icona informativa.
	/// </summary>
	/// <param name="messageText">Puntatore al messaggio da mostrare.</param>
	/// <param name="messageIcon">Icona informativa circa la natura del messaggio.</param>
	/// <returns>ID pulsante premuto.</returns>
	MessageBoxResult SystemMessageBox::Show(String messageText, MessageBoxIcons messageIcon)
	{
		return Show(nullptr, messageText, TEXT(""), MessageBoxButtons::Ok, MessageBoxDefaultButton::DefaultButton1, messageIcon);
	}

	/// <summary>
	/// Mostra la MessageBox con imessaggio, titolo e la possibilità di scegliere tra i pulsanti..
	/// </summary>
	/// <param name="messageText">Puntatore al messaggio da mostrare.</param>
	/// <param name="dialogTitle">Titolo della finestra del messaggio.</param>
	/// <returns>ID pulsante premuto.</returns>
	MessageBoxResult SystemMessageBox::Show(String messageText, String dialogTitle, MessageBoxButtons buttons)
	{
		return Show(nullptr, messageText, dialogTitle, buttons, MessageBoxDefaultButton::DefaultButton1, MessageBoxIcons::IconAsterisk);
	}

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
	MessageBoxResult SystemMessageBox::Show(HWND parentHandle, String messageText, String dialogTitle, MessageBoxButtons buttons, MessageBoxDefaultButton defaultButton, MessageBoxIcons messageIcon)
	{
		UINT messageType = static_cast<UINT>(buttons);
		messageType |= static_cast<UINT>(defaultButton);
		messageType |= static_cast<UINT>(messageIcon);
		return static_cast<MessageBoxResult>(MessageBox(parentHandle, messageText, dialogTitle, messageType));
	}
#pragma endregion Statiche
}
