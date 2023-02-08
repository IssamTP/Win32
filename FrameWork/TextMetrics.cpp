#include "pch.h"
#include "TextMetrics.h"

namespace FW
{
	#pragma region Singleton
	TextMetrics* TextMetrics::TextMetric = nullptr;

	TextMetrics* TextMetrics::GetTextMetricsInstance()
	{
		if (TextMetrics::TextMetric == nullptr)
		{
			TextMetrics::TextMetric = new TextMetrics();
		}
		return TextMetrics::TextMetric;
	}

	TextMetrics::TextMetrics()
		: TEXTMETRIC()
	{
		
	}
	#pragma endregion

	LONG TextMetrics::GetAverageCharacterWidth() const
	{
		return GetTextMetricsInstance()->tmAveCharWidth;
	}

	LONG TextMetrics::GetAverageMaximizedCharacterWidth() const
	{
		TextMetrics* instance = GetTextMetricsInstance();
		return (instance->tmPitchAndFamily & 1 ? 3 : 2) * instance->tmAveCharWidth / 2;
	}

	void TextMetrics::GetInformationAboutSpacing(WinSize& size) const
	{
		size.SetWidth(tmAveCharWidth);
		size.SetHeight(tmHeight + tmExternalLeading);
	}
};