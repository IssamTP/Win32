#include "pch.h"
#include "WinScrollInfo.h"

namespace FW
{
#pragma region Costruttori
	WinScrollInfo::WinScrollInfo()
		: SCROLLINFO()
	{
		cbSize = sizeof(SCROLLINFO);
	}
#pragma endregion

};