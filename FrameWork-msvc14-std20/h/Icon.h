#pragma once
#ifndef _ICON_CLASS_H_
	#define _ICON_CLASS_H_

namespace FW
{
	/// <summary>
	/// Classe per la gestione delle icone.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ Icon
	{
	protected:
		/// <summary>
		/// Puntatore Win32 della risorsa.
		/// </summary>
		HICON HandleIcona;
	public:
		/// <summary>
		/// Costruttore predefinito.
		/// </summary>
		Icon();
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
