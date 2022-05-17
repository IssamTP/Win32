#pragma once
#ifndef _STYLE_CLASS_H_
    #define _STYLE_CLASS_H_
    #include "HeaderCPP.h"

namespace FW
{
    /* HUNGARIAN NOTATION
     * c = char o wchar_t
     * by = BYTE
     * n = short
     * i = int
     * x, y = coordinate
     * cx, cy = count x/y
     * b o f = BOOL (int) o flag
     * w = word
     * l = long
     * dw = double word -> unsigned long
     * fn = function
     * s = string
     * sz = string terminated by zero
     * h = handle
     * p = pointer
     * lp / fp / np = long/far/near pointer
     */

    /* PREFISSI CODICI
     * CS = Class Style
     * CW = Create Window
     * DT = Draw Text
     * IDI = Icon Identifier
     * IDC = Cursor Identifier
     * MB = Message Box
     * SND = Sound
     * WM = Windows Message
     * WS = Windows Style
     */
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

    /// <summary>
    /// Codifica i vari stili per scrittura del testo.
    /// </summary>
    enum class DrawTextStyles : UINT
    {
        DTBottom = DT_BOTTOM,
        DTCalcRect = DT_CALCRECT,
        DTCenter = DT_CENTER,
        DTEditControl = DT_EDITCONTROL,
        DTEndEllipsis = DT_END_ELLIPSIS,
        DTExpandTabs = DT_EXPANDTABS,
        DTExternalLeading = DT_EXTERNALLEADING,
        DTHidePrefix = DT_HIDEPREFIX,
        DTInternal = DT_INTERNAL,
        DTLeft = DT_LEFT,
        DTModifyString = DT_MODIFYSTRING,
        DTNoClip = DT_NOCLIP,
        DTNoFullWidthCharBreak = DT_NOFULLWIDTHCHARBREAK,
        DTNoPrefix = DT_NOPREFIX,
        DTPathEllipsis = DT_PATH_ELLIPSIS,
        DTPrefixOnly = DT_PREFIXONLY,
        DTRight = DT_RIGHT,
        DTRTLReading = DT_RTLREADING,
        DTSingleLine = DT_SINGLELINE,
        DTTabStop = DT_TABSTOP,
        DTTop = DT_TOP,
        DTVCener = DT_VCENTER,
        DTWordBreak = DT_WORDBREAK,
        DTWordEllipsis = DT_WORD_ELLIPSIS,
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
    /// Elenco degli oggetti predefiniti.
    /// </summary>
    enum class StockObjects : UINT
    {
        SOBlackBrush = BLACK_BRUSH,
        SODKGrayBrush = DKGRAY_BRUSH,
        SODCBrush = DC_BRUSH,
        SOGrayBrush = GRAY_BRUSH,
        SONullBrush = HOLLOW_BRUSH,
        SOLTGrayBrush = LTGRAY_BRUSH,
        SOWhiteBrush = WHITE_BRUSH,
        SOBlackPen = BLACK_PEN,
        SODCPen = DC_PEN,
        SONullPen = NULL_PEN,
        SOWhitePen = WHITE_PEN,
        SOAnsiFixedFont = ANSI_FIXED_FONT,
        SOAnsiVarFont = ANSI_VAR_FONT,
        SODeviceDefaultFont = DEVICE_DEFAULT_FONT,
        SODefaultGuiFont = DEFAULT_GUI_FONT,
        SOOemFixedFont = OEM_FIXED_FONT,
        SOSystemFont = SYSTEM_FONT,
        SOSystemFixedFont = SYSTEM_FIXED_FONT,
        SODefaultPalette = DEFAULT_PALETTE,
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
    /// Enum con un elenco parziale dei messaggi che arrivano alla finestra.
    /// </summary>
    enum class WindowsMessages : UINT
    {
        WMClose = WM_CLOSE,
        WMCreate = WM_CREATE,
        WMDestroy = WM_DESTROY,
        WMEraseBkGnd = WM_ERASEBKGND,
        WMPaint = WM_PAINT,
        WMNCCreate = WM_NCCREATE,
        WMQuit = WM_QUIT,
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