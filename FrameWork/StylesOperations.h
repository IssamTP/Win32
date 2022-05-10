#pragma once
#ifndef _STYLE_CLASS_H_
    #define _STYLE_CLASS_H_
    #include "HeaderCPP.h"

namespace FW
{
    /// <summary>
    /// Incapsulamento ad enum degli stili di classe di Windows.
    /// </summary>
    enum class ClassStyles : UINT
    {
        CSHRedraw = CS_HREDRAW,
        CSVRedraw = CS_VREDRAW,
    };

    /// <summary>
    /// Incapsulamento ad enum degli stili di finestra.
    /// </summary>
    enum class WindowStyles : UINT
    {
        WSVisible = WS_VISIBLE,
    };

    /// <summary>
    /// Classe delle operazioni sugli stili.
    /// </summary>
    class StylesOperations
    {
    public:
        /// <summary>
        /// Questa operazione combina un qualsiasi numero di stili di tipo diverso in un'unica maschera.
        /// </summary>
        /// <typeparam name="...T">Tipo qualsiasi di stile come enum class.</typeparam>
        /// <param name="...styles">Un numero arbitrario di stili da combinare in un'unica maschera.</param>
        /// <returns>Una maschera di tipo UINT da fornire alle API di Windows.</returns>
        template <class... T>
        static UINT Combine(T... styles)
        {
            UINT combinazione = 0u;
            ([&](auto stile)
            {
                combinazione |= static_cast<UINT>(stile);
            }(styles), ...);
            return combinazione;
        }
    };
}

#endif