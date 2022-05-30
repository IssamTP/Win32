#pragma once
#ifndef _CLASS_WIN_SCROLL_INFO_H_
	#define _CLASS_WIN_SCROLL_INFO_H_

namespace FW
{
	/// <summary>
	/// Gestisce le informazioni sullo scrolling.
	/// </summary>
	class WinScrollInfo : public SCROLLINFO
	{
#pragma region
	protected:
		using SCROLLINFO::cbSize;
		using SCROLLINFO::fMask;
		using SCROLLINFO::nMax;
		using SCROLLINFO::nMin;
		using SCROLLINFO::nPage;
		using SCROLLINFO::nPos;
		using SCROLLINFO::nTrackPos;
#pragma endregion
	public:
		/// <summary>Costruttore predefinito.</summary>
		WinScrollInfo();
	};
}
#endif
