#pragma once
#ifndef _SIZE_CLASS_H_
	#define _SIZE_CLASS_H_

namespace FW
{
	/// <summary>
	/// 
	/// </summary>
	template <typename T>
	class CLASS_EXPORT Size
	{
	protected:
		SIZE WinSize;
		T Height;
		T Width;
	public:
		/// <summary>
		/// Costruttore predefinito, le dimensioni sono 0.
		/// </summary>
		Size();
		/// <summary>
		/// Imposta le dimensioni in fase di costruzione.
		/// </summary>
		/// <param name="width">Larghezza.</param>
		/// <param name="height">Altezza.</param>
		Size(T width, T height);
	public:
		/// <summary>
		/// Cast automatico a SIZE.
		/// </summary>
		operator SIZE();
	public:
		/// <summary>
		/// Calcola l'aspect ratio.
		/// </summary>
		/// <returns></returns>
		T AspectRatio() const;
	};
}
#endif
