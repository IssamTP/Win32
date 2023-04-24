#pragma once
#ifndef _WIN_UNDEFINITIONS_H_
	#define _WIN_UNDEFINITIONS_H_
	#ifdef RegisterClass
		#undef RegisterClass
	#endif
	#ifdef DrawText
		#undef DrawText
	#endif
	#ifdef GetTextMetrics
		#undef GetTextMetrics
	#endif
	#ifdef max
		#undef max
	#endif
#endif