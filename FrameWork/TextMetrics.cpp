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

	WinPoint TextMetrics::GetInformationAboutSpacing() const
	{
		return WinPoint(tmAveCharWidth, tmHeight + tmExternalLeading);
	}
};