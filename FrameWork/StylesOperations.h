#pragma once
#ifndef _STYLE_CLASS_H_
#define _STYLE_CLASS_H_
#include <type_traits>
#include <Windows.h>

namespace FW
{
    /// <summary>
    /// Stili della classe di finestre.
    /// </summary>
    enum class ClassStyles : UINT
    {
        CSHRedraw = CS_HREDRAW,
        CSVRedraw = CS_VREDRAW,
    };

    enum class WindowStyles : UINT
    {
        WSVisible = WS_VISIBLE,
    };

    /// <summary>
    /// Classe che incapsula un qualsiasi stile definito con gli enum.
    /// Usare la funzione combine per ottenere il valore dello stile richiesto.
    /// </summary>
    /// <typeparam name="S">Uno degli enum definiti qui sopra.</typeparam>
    class StylesOperations
    {
    public:
        template <class T>
        static UINT TemplateToWin32Cast(T style)
        {
            return static_cast<UINT>(style);
        }

        template <class... T>
        static UINT Combine(T... styles)
        {
            UINT combinazione = 0u;/*([](auto& stile)
            {
                return static_cast<UINT>(stile);
            }(styles), ...);*/
            for (const auto p : { styles... })
            {
                combinazione |= static_cast<UINT>(p);
            }
            return combinazione;
        }
    };
}

#endif