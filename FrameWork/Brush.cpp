#include "pch.h"
#include "Brush.h"

namespace FW
{
	#pragma region Costruttori
	Brush::Brush()
	{
		HandleBrush = nullptr;
	}

	Brush::Brush(HBRUSH brushHandle)
	{
		HandleBrush = brushHandle;
	}
	#pragma endregion

#pragma region Operatori
	Brush::operator HBRUSH()
	{
		return HandleBrush;
	}

	Brush& Brush::operator=(HBRUSH handleBrush)
	{
		HandleBrush = handleBrush;
		return *this;
	}
#pragma endregion

	#pragma region Statiche
	Brush Brush::GetDefaultBrush(StockObjects object)
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/wingdi/nf-wingdi-getstockobject
		return Brush(static_cast<HBRUSH>(GetStockObject(static_cast<int>(object))));
	}

	Brush Brush::GetDefaultDialogBrush()
	{
		return GetDefaultBrush(StockObjects::SOLTGrayBrush);
	}

	Brush Brush::GetDefaultWindowBrush()
	{
		return GetDefaultBrush(StockObjects::SOWhiteBrush);
	}
	#pragma endregion
};