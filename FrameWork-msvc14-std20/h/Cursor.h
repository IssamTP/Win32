#pragma once
#ifndef _CURSOR_CLASS_H_
	#define _CURSOR_CLASS_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
namespace FW
{
	/// <summary>
	/// Oggetto che modella il cursorse del mouse.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ Cursor
	{
	protected:
		/// <summary>
		/// Handle della risorsa curosore.
		/// </summary>
		HCURSOR HandleCursore;
	public:
		/// <summary>
		/// Costruttore predefinito.
		/// </summary>
		Cursor();
		/// <summary>
		/// Costruttore per handle risorsa.
		/// </summary>
		Cursor(HCURSOR cursor);
	public:
		/// <summary>
		/// Cast automatico ad HCURSOR.
		/// </summary>
		operator HCURSOR();
	public:
		/// <summary>
		/// Carica il cursore predefinito dalle risorse del S.O.
		/// </summary>
		/// <returns></returns>
		static Cursor GetDefaultCursor();
	};
}
#endif
