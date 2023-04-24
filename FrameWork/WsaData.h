#pragma once
#include "framework.h"

namespace FW::Networking
{
	class CWsaData : public WSAData
	{
    public:
        static constexpr unsigned short WsaDescriptionLen{ WSADESCRIPTION_LEN + 1 };
        static constexpr unsigned short WsaSysStatusLen{ WSASYS_STATUS_LEN + 1 };
        CWsaData(WORD versione, WORD versioneAlta, unsigned short socketMassimi, unsigned short udpDgMassimi);
    private:
        using WSAData::wVersion;
        using WSAData::wHighVersion;
        using WSAData::iMaxSockets;
        using WSAData::iMaxUdpDg;
        using WSAData::lpVendorInfo;
        using WSAData::szDescription;
        using WSAData::szSystemStatus;
	};
};
