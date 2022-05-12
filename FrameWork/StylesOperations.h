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
    /// Tag di riferimento.
    /// </summary>
    enum class CreateWindowOptions
    {
        CWUseDefault = CW_USEDEFAULT,
    };

    enum class ShowWindowsCommands : int
    {
        SWHide = SW_HIDE,
        SWShowNormal = SW_NORMAL,
        SWShowMinimized = SW_SHOWMINIMIZED,
        SWShowMaximized = SW_SHOWMAXIMIZED,
        SWShowNoActivate = SW_SHOWNOACTIVATE,
        SWShow = SW_SHOW,
        SWMinimize = SW_MINIMIZE,
        SWShowMinNoActive = SW_SHOWMINNOACTIVE,
        SWShowNA = SW_SHOWNA,
        SWRestore = SW_RESTORE,
        SWDefault = SW_SHOWDEFAULT,
        SWForceMinimize = SW_FORCEMINIMIZE,
    };

    /// <summary>
    /// Incapsulamento ad enum degli stili di finestra.
    /// </summary>
    enum class WindowStyles : UINT
    {
        WSOverlappedWindow = WS_OVERLAPPEDWINDOW,
        WSVisible = WS_VISIBLE,
    };

    /// <summary>
    /// Codifica dei codici di errore di alcune funzioni Windows.
    /// </summary>
    enum class ErrNoCodes : int
    {
        EInval = EINVAL,
        ERange = ERANGE,
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