#include "pch.h"
#include "Socket.h"
#include "SocketAddressInternet.h"
#include "NetworkingException.h"

namespace FW::Networking
{

	using enum AddressFamily;
	using enum SocketType;

	CSocket::CSocket(SocketType type, IPPROTO protocollo, const std::wstring& indirizzoIp, WORD portaSocket)
		: m_Socket{ socket(static_cast<int>(AfInet), static_cast<int>(type), protocollo) }
	{
		if (m_Socket == INVALID_SOCKET)
		{
			throw CNetworkingException();
		}
		m_IndirizzoSocket = std::make_unique<CSocketAddressInternet>(indirizzoIp, portaSocket);
	}

	CSocket::~CSocket()
	{
		if (m_Socket != INVALID_SOCKET)
		{
			closesocket(m_Socket);
		}
	}

	void CSocket::bind()
	{
		if (m_Socket != INVALID_SOCKET)
		{
			if (::bind(m_Socket, *m_IndirizzoSocket.get(), sizeof(sockaddr_in)) == SOCKET_ERROR)
			{
				throw CNetworkingException();
			}
			else
			{
				m_BindEseguito = true;
			}
		}
	}

	void CSocket::receive()
	{
		using enum ReceivingOptions;
		if (!is_invalid())
		{
			// Questa è bloccante! ACHTUNG.
			m_ByteUltimaLettura = recv(m_Socket, m_Buffer.get(), DIMENSIONE_BUFFER, static_cast<int>(MsgNone));
			if (m_ByteUltimaLettura == SOCKET_ERROR)
			{
				throw CNetworkingException();
			}
		}
	}

	void CSocket::send()
	{
		if (!is_invalid() && m_BindEseguito && can_read())
		{
			m_ByteUltimoInvio = sendto(m_Socket, m_Buffer.get(), m_ByteUltimaLettura, 0, *m_IndirizzoSocket, sizeof(sockaddr_in));
			if (m_ByteUltimoInvio == SOCKET_ERROR)
			{
				throw CNetworkingException();
			}
		}
	}

#ifdef max
	#undef max
#endif

#ifdef min
	#undef min
#endif

	void CSocket::send(const char* dati, std::size_t numeroByte)
	{
		memcpy(m_Buffer.get(), dati, std::min(DIMENSIONE_BUFFER * sizeof(char), numeroByte));
		m_ByteUltimoInvio = numeroByte;
		send();
	}
}