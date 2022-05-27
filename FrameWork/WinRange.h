#pragma once
#ifndef _WIN_RANGE_CLASS_H_
	#define _WIN_RANGE_CLASS_H_
	#include "WinExports.h"
namespace FW
{
	/// <summary>
	/// Rappresenta un intervallo di valori con gli estremi compresi di tipo int (compatibili con SCROLLINFO).
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ WinRange
	{
	protected:
		int Minimo;
		int Massimo;
	};
};

#endif

