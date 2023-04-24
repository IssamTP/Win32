#pragma once
#ifndef _STRING_H_
	#define _STRING_H_
	#include "HeaderCPP.h"
namespace FW
{
	_FRAMEWORK_TEMPLATE_EXPORT_ template class std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>;
	/// <summary>
	/// Fornisce un accesso pratico alla versione corretta agli oggetti stl relativi alle stringhe.
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ String
	{
	protected:
#ifdef _UNICODE
		/// <summary>
		/// Stringa STL che fornisce le operazioni di base.
		/// </summary>
		std::wstring Contenuto;
#else
		/// <summary>
		/// Stringa STL che fornisce le operazioni di base.
		/// </summary>
		std::string Contenuto;
#endif
	public:
		/// <summary>
		/// Costruttore predefinito.
		/// </summary>
		String();
		/// <summary>
		/// Costruttore per garantire la piena compatibilità con stringhe API di Windows.
		/// </summary>
		/// <param name="charString">Stringa API Windows.</param>
		String(PCTSTR charString);
	public:
		/// <summary>
		/// Converte la stringa memorizzata nell'oggetto in una stringa non-unicode.
		/// </summary>
		/// <returns>Una stringa convertita in versione non-unicode.</returns>
		std::string GetAsNonUnicode() const;
		/// <summary>
		/// Ottiene la lunghezza della stringa.
		/// </summary>
		/// <returns>std::basic_string<T>.length()</returns>
		std::size_t GetLength() const noexcept;
		/// <summary>
		/// Converte la stringa memorizzata nell'oggetto in una stringa unicode.
		/// </summary>
		/// <returns>Una stringa convertita in versione unicode.</returns>
		std::wstring GetAsUnicode() const;
	public:
		/// <summary>
		/// Garantisce l'interoperabilità tra i puntatori ad array di caratteri e String.
		/// </summary>
		/// <param name="charString">Puntatore alla stringa Windows da copiare.</param>
		/// <returns>Referenza al nuovo oggetto creato.</returns>
		String& operator=(PCTSTR charString);
		/// <summary>
		/// Conversione diretta a PCTSTR.
		/// </summary>
		operator PCTSTR();
		/// <summary>
		/// Conversione diretta a PTSTR.
		/// </summary>
		operator PTSTR();
	};
}
#endif