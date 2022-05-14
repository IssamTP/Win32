#include "pch.h"
#include "Cursor.h"

namespace FW
{
	#pragma region Costruttori
	Cursor::Cursor()
	{
		HandleCursore = nullptr;
	}

	Cursor::Cursor(HCURSOR cursor)
	{
		HandleCursore = cursor;
	}
	#pragma endregion

	#pragma region Operatori
	Cursor::operator HCURSOR()
	{
		return HandleCursore;
	}
	#pragma endregion

#pragma region Statiche
	Cursor Cursor::GetDefaultCursor()
	{
		return Cursor(static_cast<HCURSOR>(LoadImage(nullptr, MAKEINTRESOURCE(OCR_NORMAL), IMAGE_CURSOR, SM_CXCURSOR, SM_CYCURSOR, LR_SHARED)));
	}
#pragma endregion
}
