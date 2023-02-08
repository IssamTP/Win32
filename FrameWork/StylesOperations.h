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
    /// Raggruppamento dei codici per GetSystemMetrics.
    /// </summary>
    enum class SystemMetrics : UINT
    {
        /// <summary>Larghezza in pixel dello schermo.</summary>
        SMCXScreen = SM_CXSCREEN,
        /// <summary>Altezza in pixel dello schermo.</summary>
        SMCYScreen = SM_CYSCREEN,
        /// <summary>Larghezza in pixel della barra verticale di scorrimento.</summary>
        SMCXVScroll = SM_CXVSCROLL,
        /// <summary>Altezza in pixel della barra orizzontale di scorrimento.</summary>
        SMCYHScroll = SM_CYHSCROLL,
        /// <summary>Altezza in pixel della barra di caption.</summary>
        SMCYCaptionBar = SM_CYCAPTION,
        /// <summary>Spessore del bordo della finestra.</summary>
        SMCXBorder = SM_CXBORDER,
        /// <summary>Altezza del bordo della finestra.</summary>
        SMCYBorder = SM_CYBORDER,
        /// <summary>Larghezza in pixel del frame della finestra di dialogo.</summary>
        SMCXFixedFrame = SM_CXFIXEDFRAME,
        /// <summary>Altezza in pixel del frame della finestra di dialogo.</summary>
        SMCYFixedFrame = SM_CYFIXEDFRAME,
        /// <summary>Altezza del "thumb" della barra di scorrimento verticale..</summary>
        SMCYVThumb = SM_CYVTHUMB,
        /// <summary>Larghezza del "thumb" della barra di scorrimento verticale..</summary>
        SMCXHThumb = SM_CXHTHUMB,
        /// <summary>Larghezza dell'icona.</summary>
        SMCXIcon = SM_CXICON,
        /// <summary>Altezza dell'icona.</summary>
        SMCYIcon = SM_CYICON,
        /// <summary>Larghezza del cursore.</summary>
        SMCXCursor = SM_CXCURSOR,
        /// <summary>Altezza del cursore.</summary>
        SMCYCursor = SM_CYCURSOR,
        /// <summary>Altezza della barra dei menu.</summary>
        SMCYMenu = SM_CYMENU,
        /// <summary>Larghezza a tutto schermo della client area.</summary>
        SMCXFullScreen = SM_CXFULLSCREEN,
        /// <summary>Altezza a tutto schermo della client area.</summary>
        SMCYFullScreen = SM_CYFULLSCREEN,
        /// <summary>Altezza a tutto schermo della finestra Kanji.</summary>
        SMCYKanjiWindow = SM_CYKANJIWINDOW,
        /// <summary>Spia presenza mouse.</summary>
        SMMousePresent = SM_MOUSEPRESENT,
        /// <summary>Altezza della freccia della barra di scorrimento verticale.</summary>
        SMCYVScroll = SM_CYVSCROLL,
        /// <summary>Larghezza della freccia della barra di scorrimento orizzontale.</summary>
        SMCXHScroll = SM_CXHSCROLL,
        /// <summary>Spia versione debug.</summary>
        SMDebug = SM_DEBUG,
        /// <summary>Spia inversione bottoni del mouse.</summary>
        SMSwapButton = SM_SWAPBUTTON,
        /// <summary>Larghezza minima finestra.</summary>
        SMCXMin = SM_CXMIN,
        /// <summary>Altezza minima finestra.</summary>
        SMCYMin = SM_CYMIN,
        /// <summary>Larghezza minima dei bottoni di sistema Minimizza / Massimizza / Chiudi.</summary>
        SMCXSize = SM_CXSIZE,
        /// <summary>Altezza minima dei bottoni di sistema Minimizza / Massimizza / Chiudi.</summary>
        SMCYSize = SM_CYSIZE,
        /// <summary>Spessore del frame di ridimensionamento in larghezza.</summary>
        SMCXSizeFrame = SM_CXSIZEFRAME,
        /// <summary>Spessore del frame di ridimensionamento in altezza.</summary>
        SMCYSizeFrame = SM_CYSIZEFRAME,
        /// <summary>Larghezza minima della finestra di trascinamento.</summary>
        SMCXMinTrak = SM_CXMINTRACK,
        /// <summary>Altezza minima della finestra di trascinamento.</summary>
        SMCYMinTrak = SM_CYMINTRACK,
        /// <summary>Tolleranza in X del doppio click.</summary>
        SMCXDoubleClk = SM_CXDOUBLECLK,
        /// <summary>Tolleranza in Y del doppio click.</summary>
        SMCYDoubleClk = SM_CYDOUBLECLK,
        /// <summary>Spaziatura in X delle icone.</summary>
        SMCCXIconSpacing = SM_CXICONSPACING,
        /// <summary>Spaziatura in Y delle icone.</summary>
        SMCYIconSpacing = SM_CYICONSPACING,
        /// <summary>Allineamento destra o sinistra del menu a discesa.</summary>
        SMMenuDropAlignment = SM_MENUDROPALIGNMENT,
        /// <summary>Spia estensione penna installata.</summary>
        SMPenWindows = SM_PENWINDOWS,
        /// <summary>Spia carattere a due byte abilitati.</summary>
        SMDBCSEnabled = SM_DBCSENABLED,
        /// <summary>Numero dei bottoni del mouse.</summary>
        SMCMouseButtons = SM_CMOUSEBUTTONS,
        /// <summary>Spia sicurezza.</summary>
        SMSecure = SM_SECURE,
        /// <summary>Larghezza del bordo 3D.</summary>
        SMCXEdge = SM_CXEDGE,
        /// <summary>Altezza del bordo 3D.</summary>
        SMCYEdge = SM_CYEDGE,
        /// <summary>Spaziatura in X minima per le finestre minimizzate.</summary>
        SMCXMinSpacing = SM_CXMINSPACING,
        /// <summary>Spaziatura in Y minima per le finestre minimizzate.</summary>
        SMCYMinSpacing = SM_CYMINSPACING,
        /// <summary>Larghezza icona piccola.</summary>
        SMCXSmIcon = SM_CXSMICON,
        /// <summary>Altezza icona piccola.</summary>
        SMCYSmIcon = SM_CYSMICON,
        /// <summary>Altezza caption piccolo.</summary>
        SMCYSmCaption = SM_CYSMCAPTION,
        /// <summary>Larghezza bottone caption piccolo.</summary>
        SMCXSmSize = SM_CXSMSIZE,
        /// <summary>Altezza bottone caption piccolo.</summary>
        SMCYSmSize = SM_CYSMSIZE,
        /// <summary>Larghezza bottone barra dei menu.</summary>
        SMCXMenuSize = SM_CXMENUSIZE,
        /// <summary>Altezza bottone barra dei menu.</summary>
        SMCYMenuSize = SM_CYMENUSIZE,
        /// <summary>Come vengono ordinate le finestre minimizzate.</summary>
        SMArrange = SM_ARRANGE,
        /// <summary>Larghezza finestra minimizzata.</summary>
        SMCXMinimized = SM_CXMINIMIZED,
        /// <summary>Altezza finestra minimizzata.</summary>
        SMCYMinimized = SM_CYMINIMIZED,
        /// <summary>Massima larghezza trascinabile.</summary>
        SMCXMaxTrack = SM_CXMAXTRACK,
        /// <summary>Massima altezza trascinabile.</summary>
        SMCYMaxTrack = SM_CYMAXTRACK,
        /// <summary>Larghezza della finestra massimizzata.</summary>
        SMCXMaximized = SM_CXMAXIMIZED,
        /// <summary>Altezza della finestra massimizzata.</summary>
        SMCYMaximized = SM_CYMAXIMIZED,
        /// <summary>Spia presenza della rete.</summary>
        SMNetwork = SM_NETWORK,
        /// <summary>Esito dell'ultimo avvio.</summary>
        SMCleanBoot = SM_CLEANBOOT,
        /// <summary>Tolleranza per evitare il trascinamento in X.</summary>
        SMCXDrag = SM_CXDRAG,
            /// <summary>Tolleranza per evitare il trascinamento in Y.</summary>
        SMCYDrag = SM_CYDRAG,
        /// <summary>Mostra i suoni visivamente (?)</summary>
        SMShowSounds = SM_SHOWSOUNDS,
        /// <summary>Larghezza della spunta di conferma nei menu.</summary>
        SMCXMenuCheck = SM_CXMENUCHECK,
        /// <summary>Larghezza della spunta di conferma nei menu.</summary>
        SMCYMenuCheck = SM_CYMENUCHECK,
        /// <summary>Spia macchina lenta.</summary>
        SMSlowMachine = SM_SLOWMACHINE,
        /// <summary>Spia per l'abilitazione dell'ebraico e arabico.</summary>
        SMMidEastEnabled = SM_MIDEASTENABLED,
        /// <summary>Spia presenza rotellina mouse.</summary>
        SMMouseWheelPresent = SM_MOUSEWHEELPRESENT,
        /// <summary>Coordinata X dell'origine dello schermo virtuale.</summary>
        SMXVirtualScreen = SM_XVIRTUALSCREEN,
        /// <summary>Coordinata Y dell'origine dello schermo virtuale.</summary>
        SMYVirtualScreen = SM_YVIRTUALSCREEN,
        /// <summary>Larghezza X dello schermo virtuale.</summary>
        SMCXVirtualScreen = SM_CXVIRTUALSCREEN,
        /// <summary>Larghezza Y dello schermo virtuale.</summary>
        SMCYVirtualScreen = SM_CYVIRTUALSCREEN,
        /// <summary>Numero dei monitor.</summary>
        SMCMonitors = SM_CMONITORS,
        /// <summary>Spia per medesimo formato dei colori.</summary>
        SMSameDisplayFormat = SM_SAMEDISPLAYFORMAT,
        SMImmEnabled = SM_IMMENABLED,
        SMCXFocusBorder = SM_CXFOCUSBORDER,
        SMCYFocusBorder = SM_CYFOCUSBORDER,
        /// <summary>Windows è a bordo di un tablet.</summary>
        SMTabletPC = SM_TABLETPC,
        /// <summary>Windows media center.</summary>
        SMMediaCenter = SM_MEDIACENTER,
        SMStarter = SM_STARTER,
        SMServerR2 = SM_SERVERR2,
        SMMouseHorizontalWheelPresent = SM_MOUSEHORIZONTALWHEELPRESENT,
        SMCXPaddedBorder = SM_CXPADDEDBORDER,
        SMDigitizer = SM_DIGITIZER,
        SMMaximumTouches = SM_MAXIMUMTOUCHES,
        SMRemoteSession = SM_REMOTESESSION,
        SMRemoteControl = SM_REMOTECONTROL,
        SMCaretBlinkingEnabled = SM_CARETBLINKINGENABLED,
        SMConvertIbleslateMode = SM_CONVERTIBLESLATEMODE,
        SMSystemDocked = SM_SYSTEMDOCKED,
    };

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

    enum class TextAlignStyles : UINT
    {
        TALeft = TA_LEFT,
        TARight = TA_RIGHT,
        TACenter = TA_CENTER,
        TATop = TA_TOP,
        TABottom = TA_BOTTOM,
        TABaseline = TA_BASELINE,
        TARTLReading = TA_RTLREADING,
        TAMask = TA_MASK,
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
        WSHScroll = WS_HSCROLL,
        WSVScroll = WS_VSCROLL,
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
        WMSize = WM_SIZE,
        WMNCCreate = WM_NCCREATE,
        WMQuit = WM_QUIT,
        WMVScroll = WM_VSCROLL,
        WMHScroll = WM_HSCROLL,
    };

    /// <summary>
    /// Specifica che barra di scorrimento si vuole indicare come oggetto delle funzioni.
    /// </summary>
    enum class ScrollBarIdentifiers
    {
        SBVertical = SB_VERT,
        SBHorizontal = SB_HORZ,
    };

    /// <summary>
    /// Codici di notifica eventi WM_VSCROLL WM_HSCROLL.
    /// </summary>
    enum class ScrollBarNotifications
    {
        /// <summary>Equivalente a SB_LINEUP. Occorre quando si fa click sulla freccia.</summary>
        SBSingleBack = SB_LINELEFT,
        /// <summary>Equivalente a SB_LINEDOWN. Occorre quando si fa click sulla freccia.</summary>
        SBSingleForward = SB_LINERIGHT,
        /// <summary>Equivalente a SB_PAGEUP</summary>
        SBMultipleBack = SB_PAGELEFT,
        /// <summary>Equivalente a SB_PAGEDOWN</summary>
        SBMultipleForward = SB_PAGERIGHT,
        SBThumbPosition = SB_THUMBPOSITION,
        SBThumbTrack = SB_THUMBTRACK,
        /// <summary>Equivalente a SB_TOP.</summary>
        SBStart = SB_LEFT,
        /// <summary>Equivalente a SB_BOTTOM.</summary>
        SBEnd = SB_RIGHT,
        /// <summary>Fine delle operazioni di scrolling. Occorre quando si rilascia il mouse.</summary>
        SBEndScroll = SB_ENDSCROLL,
    };

    /// <summary>
    /// Classe delle operazioni sugli stili.
    /// </summary>
    class StylesOperations
    {
    public:
        int GetSystemMetric(SystemMetrics metric)
        {
            return ::GetSystemMetrics(static_cast<int>(metric));
        }
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