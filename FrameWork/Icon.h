#pragma once
#ifndef _ICON_CLASS_H_
	#define _ICON_CLASS_H_

namespace FW
{
	/// <summary>
	/// Classe per la gestione delle icone.
	/// </summary>
	class CLASS_EXPORT Icon
	{
	protected:
		/// <summary>
		/// Puntatore Win32 della risorsa.
		/// </summary>
		HICON HandleIcona;
	private:
		/// <summary>
		/// Costruttore predefinito.
		/// </summary>
		Icon();
	public:
		/// <summary>
		/// Costruttore per handle della risorsa.
		/// </summary>
		/// <param name="handle">L'handle della risorsa icona.</param>
		Icon(HICON handle);
	public:
		/// <summary>
		/// Cast automatico ad HICON.
		/// </summary>
		operator HICON();
	public:
		/// <summary>
		/// Carica l'icona predefinita del sistema.
		/// </summary>
		/// <returns></returns>
		static Icon GetDefaultIcon();
	};
}
#endif
