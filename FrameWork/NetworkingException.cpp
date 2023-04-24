#include "pch.h"
#include "NetworkingException.h"

namespace FW::Networking
{
	CNetworkingException::CNetworkingException(int codice, const std::string& errore)
		: m_CodiceErrore{ codice }, m_Messaggio{ errore }
	{
		
	}
}
