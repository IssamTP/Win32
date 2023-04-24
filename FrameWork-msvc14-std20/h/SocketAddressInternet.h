#pragma once
#include "WinExports.h"

namespace FW::Networking
{
	/// <summary>Wrap dell'indirizzo socket nello stile internet.Dovrebbe avere la medesima dimensione.</summary>
	class CSocketAddressInternet : public sockaddr_in
	{
	public:
		/// <summary></summary>
		/// <param name="indirizzoIp">Specificare stringa vuota per ascolto e invio da tutti gli IP.</param>
		/// <param name="portaSocket"></param>
		CSocketAddressInternet(const std::wstring& indirizzoIp, WORD portaSocket);
		/// <summary>
		/// Converte l'oggetto corrente in sockaddr.
		/// </summary>
		operator const sockaddr* ();
	private:
		/// <summary>Indirizzo ip.</summary>
		std::wstring m_IndirizzoIp;
#pragma region Incapsulamento
		using sockaddr_in::sin_addr;
		using sockaddr_in::sin_family;
		using sockaddr_in::sin_port;
		using sockaddr_in::sin_zero;
#pragma endregion
	};
};
