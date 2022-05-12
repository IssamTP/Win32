#pragma once
#ifndef _DEVICE_CONTEXT_H_
	#define _DEVICE_CONTEXT_H_
	#include "HeaderCPP.h"
	#include "WinExports.h"
namespace FW
{
	/// <summary>
	/// Classe per la gestione del disegno della finestra..
	/// </summary>
	class _FRAMEWORK_CLASS_EXPORT_ DeviceContext
	{
	protected:
		/// <summary>
		/// Contiene 
		/// </summary>
		PAINTSTRUCT InformazioniDisegno;
	public:
#pragma region Costruttori
		/// <summary>
		/// Costruttore predefinito. Privato.
		/// </summary>
		DeviceContext();
		/// <summary>
		/// Costruttore di Move.
		/// </summary>
		/// <param name="context">Contesto da spostare.</param>
		DeviceContext(DeviceContext&& context) noexcept;
		/// <summary>
		/// Costruttore di copia.
		/// </summary>
		/// <param name="context">Contesto da copiare..</param>
		DeviceContext(const DeviceContext& context);
#pragma region Costruttori
	public:
		/// <summary>
		/// Cast diretto ad HDC.
		/// </summary>
		operator HDC();
		/// <summary>
		/// Cast diretto a PAINTSTRUCT.
		/// </summary>
		operator PAINTSTRUCT();
		/// <summary>
		/// Cast diretto a LPPAINTSTRUCT.
		/// </summary>
		operator LPPAINTSTRUCT();
		/// <summary>
		/// operatore di copia con HDC.
		/// </summary>
		/// <param name="deviceContext"></param>
		void operator=(HDC deviceContext);
		/// <summary>
		/// Inizializza l'oggetto.
		/// </summary>
		/// <param name="paintStruct"></param>
		void operator=(const PAINTSTRUCT& paintStruct);
		/// <summary>
		/// Operatore di spostamento.
		/// </summary>
		/// <param name="context">Contesto da spostare.</param>
		/// <returns>*this.</returns>
		DeviceContext& operator=(DeviceContext&& context) noexcept;
		/// <summary>
		/// Operatore di copia.
		/// </summary>
		/// <param name="context">Contesto da copiare.</param>
		/// <returns>*this.</returns>
		DeviceContext& operator=(const DeviceContext& context);
	};
}
#endif
