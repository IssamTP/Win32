#include "pch.h"
#include "String.h"

namespace FW
{
#pragma region Costruttori
	/// <summary>
	/// Costruttore predefinito.
	/// </summary>
	String::String()
	{

	}

	/// <summary>
	/// Costruttore per garantire la piena compatibilità con stringhe API di Windows.
	/// </summary>
	/// <param name="charString">Stringa API Windows.</param>
	String::String(PCTSTR charString)
	{
		*this = charString;
	}
#pragma endregion

#pragma region Interfaccia
	/// <summary>
	/// Converte la stringa memorizzata nell'oggetto in una stringa non-unicode.
	/// </summary>
	/// <returns>Una stringa convertita in versione non-unicode.</returns>
	std::string String::GetAsNonUnicode() const
	{
		return std::string(Contenuto.cbegin(), Contenuto.cend());
	}

	std::size_t String::GetLength() const noexcept
	{
		return Contenuto.length();
	}

	/// <summary>
	/// Converte la stringa memorizzata nell'oggetto in una stringa unicode.
	/// </summary>
	/// <returns>Una stringa convertita in versione unicode.</returns>
	std::wstring String::GetAsUnicode() const
	{
		return std::wstring(Contenuto.cbegin(), Contenuto.cend());
	}
#pragma endregion

#pragma region Operatori
	/// <summary>
	/// Garantisce l'interoperabilità tra i puntatori ad array di caratteri e String.
	/// </summary>
	/// <param name="charString">Puntatore alla stringa Windows da copiare.</param>
	/// <returns>Referenza al nuovo oggetto creato.</returns>
	String& String::operator=(PCTSTR charString)
	{
#ifdef _UNICODE
		this->Contenuto = std::wstring(charString);
#else
		this->Contenuto = std::string(charString);
#endif
		return *this;
	}

	/// <summary>
	/// Conversione diretta a PCTSTR.
	/// </summary>
	String::operator PCTSTR()
	{
		return Contenuto.c_str();
	}

	/// <summary>
	/// Conversione diretta a PTSTR.
	/// </summary>
	String::operator PTSTR()
	{
		return const_cast<PTSTR>(Contenuto.c_str());
	}
#pragma region
}
