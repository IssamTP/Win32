#include "pch.h"
#include "Socket.h"
#include "NetworkingException.h"
#include "SocketAddressInternet.h"

namespace FW::Networking
{
	using enum AddressFamily;

	CSocketAddressInternet::CSocketAddressInternet(const std::wstring& indirizzoIp, WORD portaSocket)
		: sockaddr_in{ 0 }, m_IndirizzoIp{ indirizzoIp }
	{
		sin_family = static_cast<int>(AfInet);
		sin_port = htons(portaSocket);
		if (m_IndirizzoIp.length() > 0)
		{
			switch (InetPton(static_cast<INT>(AfInet), m_IndirizzoIp.c_str(), &sin_addr))
			{
			case 1:
				break;
			case 0:
				throw CNetworkingException(0, "Formato indirizzo IP non valido.");
				break;
			default:
				throw CNetworkingException();
				break;
			}
		}
		else
		{
			sin_addr.s_addr = htonl(INADDR_ANY);
		}
	}

	CSocketAddressInternet::operator const sockaddr* ()
	{
		return reinterpret_cast<const sockaddr *>(dynamic_cast<sockaddr_in *>(this));
	}
};