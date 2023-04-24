#pragma once
#ifndef _WIN_EXPORTS_H_
	#define _WIN_EXPORTS_H_
	#ifdef FRAMEWORK_EXPORTS
		#define _FRAMEWORK_CLASS_EXPORT_ __declspec(dllexport)
		#define FUNCTION_EXPORT extern "C" __declspec(dllexport)
		#define _FRAMEWORK_TEMPLATE_EXPORT_
	#else
		#define _FRAMEWORK_CLASS_EXPORT_ __declspec(dllimport)
		#define _FRAMEWORK_TEMPLATE_EXPORT_ extern
	#endif
#endif