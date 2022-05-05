#pragma once
#ifndef _WIN_EXPORTS_H_
	#define _WIN_EXPORTS_H_
	#ifdef FRAMEWORK_EXPORTS
		#define CLASS_EXPORT __declspec(dllexport)
		#define FUNCTION_EXPORT extern "C" __declspec(dllexport)
		#define EXPIMP_TEMPLATE
	#else
		#define CLASS_EXPORT __declspec(dllimport)
		#define EXPIMP_TEMPLATE extern
	#endif
#endif