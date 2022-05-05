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
    enum class ClassStyles
    {
        CSHRedraw = CS_HREDRAW,
        CSVRedraw = CS_VREDRAW,
    };

    template<class Head, class... Tail>
    using are_same = std::conjunction<std::is_same<Head, Tail>...>;

    /// <summary>
    /// Classe che incapsula un qualsiasi stile definito con gli enum.
    /// Usare la funzione combine per ottenere il valore dello stile richiesto.
    /// </summary>
    /// <typeparam name="S">Uno degli enum definiti qui sopra.</typeparam>
    class StylesOperation
    {
    public:
        /// <summary>
        /// Combina gli enum in maniera C++.
        /// </summary>
        /// <typeparam name="Head">Primo stile.</typeparam>
        /// <typeparam name="...Tail">Ultimo stile.</typeparam>
        /// <typeparam name="">Controllo compile-time di uguaglianza di tutti i parametri.</typeparam>
        /// <param name="head">Primo parametro.</param>
        /// <param name="...tail">Ultimo parametro.</param>
        /// <returns>La combinazione dei valori passati.</returns>
        template<class Head, class... Tail, class = std::enable_if_t<are_same<Head, Tail...>::value, void>>
        static UINT Combine(Head head, Tail... tail)
        {
            UINT combina = static_cast<UINT>(head);
            combina |= static_cast<UINT>((std::forward(tail)...));
            return combina;
        }
    };
}

#endif