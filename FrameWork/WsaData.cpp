#include "pch.h"
#include "WsaData.h"

namespace FW::Networking
{
	CWsaData::CWsaData(WORD versione, WORD versioneAlta, unsigned short socketMassimi, unsigned short udpDgMassimi)
		: WSAData{ 0 }
	{
		wVersion = MAKEWORD(versione, 0);
		wHighVersion = versioneAlta;
		iMaxSockets = socketMassimi;
		iMaxUdpDg = udpDgMassimi;
		lpVendorInfo = nullptr;
		memset(szDescription, 0, sizeof(szDescription));
		memset(szSystemStatus, 0, sizeof(szSystemStatus));
	}
};