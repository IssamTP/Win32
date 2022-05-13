#include "pch.h"
#include "DeviceContext.h"

namespace FW
{
#pragma region Costruttore
	DeviceContext::DeviceContext()
	{
		memset(&InformazioniDisegno, 0, sizeof(PAINTSTRUCT));
		memset(&DettagliTesto, 0, sizeof(DRAWTEXTPARAMS));
		DettagliTesto.cbSize = sizeof(DRAWTEXTPARAMS);
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
			DettagliTesto = context.DettagliTesto;
		}
		return *this;
	}

	DeviceContext& DeviceContext::operator=(const DeviceContext& context)
	{
		if (this != &context)
		{
			InformazioniDisegno = context.InformazioniDisegno;
			DettagliTesto = context.DettagliTesto;
		}
		return *this;
	}
#pragma endregion

#pragma region Interfaccia
#pragma region Text
	int DeviceContext::GetLeftMargin() const noexcept
	{
		return DettagliTesto.iLeftMargin;
	}

	int DeviceContext::GetRightMargin() const noexcept
	{
		return DettagliTesto.iRightMargin;
	}

	int DeviceContext::GetTabLength() const noexcept
	{
		return DettagliTesto.iTabLength;
	}

	void DeviceContext::DrawText(String text, Rectangle<LONG> drawArea, UINT textStyle)
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-drawtextexa
		int altezzaTesto = DrawTextEx(*this, text, text.GetLength(), drawArea, textStyle, &DettagliTesto);
		if (altezzaTesto == 0)
		{
			throw std::exception();
		}
	}

	void DeviceContext::SetLeftMargin(int leftMargin)
	{
		DettagliTesto.iLeftMargin = leftMargin;
	}

	void DeviceContext::SetRightMargin(int rightMargin)
	{
		DettagliTesto.iRightMargin = rightMargin;
	}

	void DeviceContext::SetTabLength(int tabLength)
	{
		DettagliTesto.iTabLength = tabLength;
	}
#pragma endregion
#pragma endregion
}