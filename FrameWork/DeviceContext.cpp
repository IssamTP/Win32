#include "pch.h"
#include "DeviceContext.h"
#include "TextMetrics.h"

namespace FW
{
#pragma region Costruttore
	DeviceContext::DeviceContext()
		: PAINTSTRUCT()
	{
		memset(&DettagliTesto, 0, sizeof(DRAWTEXTPARAMS));
		DettagliTesto.cbSize = sizeof(DRAWTEXTPARAMS);
	}

	DeviceContext::DeviceContext(DeviceContext&& context) noexcept
		: PAINTSTRUCT()
	{
		*this = context;
	}

	DeviceContext::DeviceContext(const DeviceContext& context)
		: PAINTSTRUCT()
	{
		*this = context;
	}

	DeviceContext::DeviceContext(HDC handleToDeviceContext, const WinRectangle& clientArea)
		: DeviceContext()
	{
		hdc = handleToDeviceContext;
		rcPaint = clientArea;
	}
#pragma endregion

#pragma region Operatori
	DeviceContext::operator HDC()
	{
		return hdc;
	}

	void DeviceContext::operator=(HDC deviceContext)
	{
		if (deviceContext != nullptr)
		{
			hdc = deviceContext;
		}
	}

	DeviceContext& DeviceContext::operator=(DeviceContext&& context) noexcept
	{
		if (this != &context)
		{
			fErase = context.fErase;
			fIncUpdate = context.fIncUpdate;
			fRestore = context.fRestore;
			hdc = context.hdc;
			rcPaint = context.rcPaint;
			errno_t errore = memmove_s(rgbReserved, 32u * sizeof(BYTE), context.rgbReserved, 32u * sizeof(BYTE));
			if (errore != 0)
			{
				memset(rgbReserved, 0, 32u * sizeof(BYTE));
			}
			DettagliTesto = context.DettagliTesto;
		}
		return *this;
	}

	DeviceContext& DeviceContext::operator=(const DeviceContext& context)
	{
		if (this != &context)
		{
			fErase = context.fErase;
			fIncUpdate = context.fIncUpdate;
			fRestore = context.fRestore;
			hdc = context.hdc;
			rcPaint = context.rcPaint;
			errno_t errore = memcpy_s(rgbReserved, 32u * sizeof(BYTE), context.rgbReserved, 32u * sizeof(BYTE));
			if (errore != 0)
			{
				memset(rgbReserved, 0, 32u * sizeof(BYTE));
			}
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

	void DeviceContext::DrawText(String text, const WinRectangle& drawArea, UINT textStyle)
	{
		// https://docs.microsoft.com/it-it/windows/win32/api/winuser/nf-winuser-drawtextexa
		int altezzaTesto = DrawTextEx(*this, text, static_cast<int>(text.GetLength()), *const_cast<WinRectangle *>(&drawArea), textStyle, &DettagliTesto);
		if (altezzaTesto == 0)
		{
			throw std::exception();
		}
	}

	void DeviceContext::GetTextMetrics()
	{
		BOOL esito = GetTextMetricsW(hdc, TextMetrics::GetTextMetricsInstance());
	}

	void DeviceContext::SetCurrentBrush(Brush nuovoBrush)
	{
		BrushCorrente = nuovoBrush;
		// TODO: impostare il brush corrente nel contesto di disegno?
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

	void DeviceContext::SetTextAlign(UINT alignment)
	{
		if (hdc != nullptr)
		{
			::SetTextAlign(hdc, alignment);
		}
	}

	Brush& DeviceContext::GetCurrentBrush()
	{
		return BrushCorrente;
	}
#pragma endregion
#pragma endregion
}