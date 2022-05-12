#include "pch.h"
#include "DeviceContext.h"

namespace FW
{
#pragma region Costruttore
	DeviceContext::DeviceContext()
	{
		memset(&InformazioniDisegno, 0, sizeof(PAINTSTRUCT));
	}

	DeviceContext::DeviceContext(DeviceContext&& context) noexcept
	{
		*this = context;
	}

	DeviceContext::DeviceContext(const DeviceContext& context)
	{
		*this = context;
	}
#pragma endregion

#pragma region Operatori
	DeviceContext::operator HDC()
	{
		return InformazioniDisegno.hdc;
	}

	DeviceContext::operator PAINTSTRUCT()
	{
		return InformazioniDisegno;
	}

	DeviceContext::operator LPPAINTSTRUCT()
	{
		return &InformazioniDisegno;
	}

	void DeviceContext::operator=(HDC deviceContext)
	{
		if (deviceContext != nullptr)
		{
			memset(&InformazioniDisegno, 0, sizeof(PAINTSTRUCT));
			InformazioniDisegno.hdc = deviceContext;
		}
	}

	void DeviceContext::operator=(const PAINTSTRUCT& paintStruct)
	{
		errno_t errore = memcpy_s(&InformazioniDisegno, sizeof(PAINTSTRUCT), &paintStruct, sizeof(PAINTSTRUCT));
		if (errore != 0)
		{
			throw std::exception();
		}
	}

	DeviceContext& DeviceContext::operator=(DeviceContext&& context) noexcept
	{
		if (this != &context)
		{
			InformazioniDisegno = context.InformazioniDisegno;

		}
		return *this;
	}

	DeviceContext& DeviceContext::operator=(const DeviceContext& context)
	{
		if (this != &context)
		{
			InformazioniDisegno = context.InformazioniDisegno;
		}
		return *this;
	}
#pragma endregion
}