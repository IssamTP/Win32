#pragma once
#ifdef _DEBUG
    #include <h/FrameWork.h>
#else
    #include <Framework/Framework.h>
#endif
#include <vector>

struct SysMetsValue
{
	int Index;
    int Value;
	FW::String Label;
	FW::String Description;
public:
    SysMetsValue(int index, const FW::String& label, const FW::String& description)
    {
        Index = index;
        Label = label;
        Description = description;
        Value = GetSystemMetrics(index);
    }
};

class SysMetsWin : public FW::Window
{
    const UINT CAPS = 0u;
    const UINT NO_CAPS = 1u;
protected:
    LONG AltezzaRiga;
    LONG LarghezzaMedia;
    LONG LarghezzaMediaCaps;
    FW::TextMetrics* TextMetric;
    FW::WinSize Colonne[3];
	std::vector<SysMetsValue> SysMetsValues;
public:
	SysMetsWin(HINSTANCE istanza, FW::String nomeClasse)
		: FW::Window(istanza, nomeClasse)
	{
        
	}
protected:
    virtual void OnCreate()
    {
        FW::Window::OnCreate();
        CreaDati();
    }
    virtual void OnPaint()
    {
        LONG caratteriVisibili{ RettangoloClient.GetWidth() / LarghezzaMediaCaps };
        LONG righeVisibili{ RettangoloClient.GetHeight() / AltezzaRiga };
        FW::Window::OnPaint();
        FW::WinRectangle disegno;
        FW::WinPoint posizione;
        
        disegno.SetHeight(Colonne[0].GetHeight());
        for (auto met = SysMetsValues.begin(); met != SysMetsValues.end(); met++)
        {
            disegno.SetWidth(Colonne[0].GetWidth());
            ContestoDisegno.DrawText(met->Label, disegno, DT_VCENTER | DT_LEFT | DT_NOCLIP);
            posizione += FW::WinPoint(Colonne[0].GetWidth() + LarghezzaMedia, 0);
            disegno.SetOrigin(posizione);
            disegno.SetWidth(Colonne[1].GetWidth());
            ContestoDisegno.DrawText(met->Description, disegno, DT_VCENTER | DT_LEFT | DT_NOCLIP);
            posizione += FW::WinPoint(Colonne[1].GetWidth() + LarghezzaMedia, 0);
            disegno.SetOrigin(posizione);
            ContestoDisegno.DrawText(FW::String(std::to_wstring(met->Value).c_str()), disegno, DT_VCENTER | DT_RIGHT | DT_NOCLIP);
            posizione += FW::WinPoint(-(Colonne[0].GetWidth() + Colonne[1].GetWidth() + 2*LarghezzaMedia), Colonne[0].GetHeight());
            disegno.SetOrigin(posizione);
        }
    }
    void CreaDati()
    {
        LONG larghezzeColonne[3];
        TextMetric = FW::TextMetrics::GetTextMetricsInstance();
        FW::WinSize sizing;
        
        TextMetric->GetInformationAboutSpacing(sizing);
        AltezzaRiga = sizing.GetHeight();
        auto aggiungi = [&](auto nuovaMetrica)
        {
            SysMetsValues.push_back(nuovaMetrica);
            LONG lunghezzaStringa = SysMetsValues.rbegin()->Label.GetLength();
            larghezzeColonne[CAPS] = std::max(larghezzeColonne[0], lunghezzaStringa * LarghezzaMediaCaps);
            lunghezzaStringa = SysMetsValues.rbegin()->Description.GetLength();
            larghezzeColonne[NO_CAPS] = std::max(larghezzeColonne[1], lunghezzaStringa * LarghezzaMedia);
        };

        LarghezzaMedia = TextMetric->GetAverageCharacterWidth();
        LarghezzaMediaCaps = TextMetric->GetAverageMaximizedCharacterWidth();

        SysMetsValues.reserve(110);

        SysMetsValues.push_back(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXScreen), TEXT("SM_CXSCREEN"), TEXT("Larghezza in pixel dello schermo.")));
        larghezzeColonne[CAPS] = SysMetsValues.rbegin()->Label.GetLength() * LarghezzaMediaCaps;
        larghezzeColonne[NO_CAPS] = SysMetsValues.rbegin()->Description.GetLength() * LarghezzaMedia;

        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYScreen), TEXT("SM_CYSCREEN"), TEXT("Altezza in pixel dello schermo.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXVScroll), TEXT("SM_CXVSCROLL"), TEXT("Larghezza in pixel della barra verticale di scorrimento.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYHScroll), TEXT("SM_CYHSCROLL"), TEXT("Altezza in pixel della barra orizzontale di scorrimento.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYCaptionBar), TEXT("SM_CYCAPTION"), TEXT("Altezza in pixel della barra di caption.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXBorder), TEXT("SM_CXBORDER"), TEXT("Spessore del bordo della finestra.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYBorder), TEXT("SM_CYBORDER"), TEXT("Altezza del bordo della finestra.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXFixedFrame), TEXT("SM_CXFIXEDFRAME"), TEXT("Larghezza in pixel del frame della finestra di dialogo.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYFixedFrame), TEXT("SM_CYFIXEDFRAME"), TEXT("Altezza in pixel del frame della finestra di dialogo.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYVThumb), TEXT("SM_CYVTHUMB"), TEXT("Altezza del 'thumb' della barra di scorrimento verticale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXHThumb), TEXT("SM_CXHTHUMB"), TEXT("Larghezza del 'thumb' della barra di scorrimento verticale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXIcon), TEXT("SM_CXICON"), TEXT("Larghezza dell'icona.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYIcon), TEXT("SM_CYICON"), TEXT("Altezza dell'icona.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXCursor), TEXT("SM_CXCURSOR"), TEXT("Larghezza del cursore.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYCursor), TEXT("SM_CYCURSOR"), TEXT("Altezza del cursore.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMenu), TEXT("SM_CYMENU"), TEXT("Altezza della barra dei menu.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXFullScreen), TEXT("SM_CXFULLSCREEN"), TEXT("Larghezza a tutto schermo della client area.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYFullScreen), TEXT("SM_CYFULLSCREEN"), TEXT("Altezza a tutto schermo della client area.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYKanjiWindow), TEXT("SM_CYKANJIWINDOW"), TEXT("Altezza a tutto schermo della finestra Kanji.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMousePresent), TEXT("SM_MOUSEPRESENT"), TEXT("Spia presenza mouse.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYVScroll), TEXT("SM_CYVSCROLL"), TEXT("Altezza della freccia della barra di scorrimento verticale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXHScroll), TEXT("SM_CXHSCROLL"), TEXT("Larghezza della freccia della barra di scorrimento orizzontale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMDebug), TEXT("SM_DEBUG"), TEXT("Spia versione debug.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMSwapButton), TEXT("SM_SWAPBUTTON"), TEXT("Spia inversione bottoni del mouse.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMin), TEXT("SM_CXMIN"), TEXT("Larghezza minima finestra.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMin), TEXT("SM_CYMIN"), TEXT("Altezza minima finestra.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXSize), TEXT("SM_CXSIZE"), TEXT("Larghezza minima dei bottoni di sistema Minimizza / Massimizza / Chiudi.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYSize), TEXT("SM_CYSIZE"), TEXT("Altezza minima dei bottoni di sistema Minimizza / Massimizza / Chiudi.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXSizeFrame), TEXT("SM_CXSIZEFRAME"), TEXT("Spessore del frame di ridimensionamento in larghezza.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYSizeFrame), TEXT("SM_CYSIZEFRAME"), TEXT("Spessore del frame di ridimensionamento in altezza.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMinTrak), TEXT("SM_CXMINTRACK"), TEXT("Larghezza minima della finestra di trascinamento.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMinTrak), TEXT("SM_CYMINTRACK"), TEXT("Altezza minima della finestra di trascinamento.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXDoubleClk), TEXT("SM_CXDOUBLECLK"), TEXT("Tolleranza in X del doppio click.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYDoubleClk), TEXT("SM_CYDOUBLECLK"), TEXT("Tolleranza in Y del doppio click.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCCXIconSpacing), TEXT("SM_CXICONSPACING"), TEXT("Spaziatura in X delle icone.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYIconSpacing), TEXT("SM_CYICONSPACING"), TEXT("Spaziatura in Y delle icone.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMenuDropAlignment), TEXT("SM_MENUDROPALIGNMENT"), TEXT("Allineamento destra o sinistra del menu a discesa.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMPenWindows), TEXT("SM_PENWINDOWS"), TEXT("Spia estensione penna installata.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMDBCSEnabled), TEXT("SM_DBCSENABLED"), TEXT("Spia carattere a due byte abilitati.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCMouseButtons), TEXT("SM_CMOUSEBUTTONS"), TEXT("Numero dei bottoni del mouse.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMSecure), TEXT("SM_SECURE"), TEXT("Spia sicurezza.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXEdge), TEXT("SM_CXEDGE"), TEXT("Larghezza del bordo 3D.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYEdge), TEXT("SM_CYEDGE"), TEXT("Altezza del bordo 3D.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMinSpacing), TEXT("SM_CXMINSPACING"), TEXT("Spaziatura in X minima per le finestre minimizzate.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMinSpacing), TEXT("SM_CYMINSPACING"), TEXT("Spaziatura in Y minima per le finestre minimizzate.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXSmIcon), TEXT("SM_CXSMICON"), TEXT("Larghezza icona piccola.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYSmIcon), TEXT("SM_CYSMICON"), TEXT("Altezza icona piccola.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYSmCaption), TEXT("SM_CYSMCAPTION"), TEXT("Altezza caption piccolo.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXSmSize), TEXT("SM_CXSMSIZE"), TEXT("Larghezza bottone caption piccolo.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYSmSize), TEXT("SM_CYSMSIZE"), TEXT("Altezza bottone caption piccolo.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMenuSize), TEXT("SM_CXMENUSIZE"), TEXT("Larghezza bottone barra dei menu.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMenuSize), TEXT("SM_CYMENUSIZE"), TEXT("Altezza bottone barra dei menu.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMArrange), TEXT("SM_ARRANGE"), TEXT("Come vengono ordinate le finestre minimizzate.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMinimized), TEXT("SM_CXMINIMIZED"), TEXT("Larghezza finestra minimizzata.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMinimized), TEXT("SM_CYMINIMIZED"), TEXT("Altezza finestra minimizzata.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMaxTrack), TEXT("SM_CXMAXTRACK"), TEXT("Massima larghezza trascinabile.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMaxTrack), TEXT("SM_CYMAXTRACK"), TEXT("Massima altezza trascinabile.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMaximized), TEXT("SM_CXMAXIMIZED"), TEXT("Larghezza della finestra massimizzata.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMaximized), TEXT("SM_CYMAXIMIZED"), TEXT("Altezza della finestra massimizzata.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMNetwork), TEXT("SM_NETWORK"), TEXT("Spia presenza della rete.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCleanBoot), TEXT("SM_CLEANBOOT"), TEXT("Esito dell'ultimo avvio.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXDrag), TEXT("SM_CXDRAG"), TEXT("Tolleranza per evitare il trascinamento in X.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYDrag), TEXT("SM_CYDRAG"), TEXT("Tolleranza per evitare il trascinamento in Y.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMShowSounds), TEXT("SM_SHOWSOUNDS"), TEXT("Mostra i suoni visivamente (?)")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXMenuCheck), TEXT("SM_CXMENUCHECK"), TEXT("Larghezza della spunta di conferma nei menu.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYMenuCheck), TEXT("SM_CYMENUCHECK"), TEXT("Larghezza della spunta di conferma nei menu.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMSlowMachine), TEXT("SM_SLOWMACHINE"), TEXT("Spia macchina lenta.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMidEastEnabled), TEXT("SM_MIDEASTENABLED"), TEXT("Spia per l'abilitazione dell'ebraico e arabico.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMouseWheelPresent), TEXT("SM_MOUSEWHEELPRESENT"), TEXT("Spia presenza rotellina mouse.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMXVirtualScreen), TEXT("SM_XVIRTUALSCREEN"), TEXT("Coordinata X dell'origine dello schermo virtuale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMYVirtualScreen), TEXT("SM_YVIRTUALSCREEN"), TEXT("Coordinata Y dell'origine dello schermo virtuale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXVirtualScreen), TEXT("SM_CXVIRTUALSCREEN"), TEXT("Larghezza X dello schermo virtuale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYVirtualScreen), TEXT("SM_CYVIRTUALSCREEN"), TEXT("Larghezza Y dello schermo virtuale.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCMonitors), TEXT("SM_CMONITORS"), TEXT("Numero dei monitor.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMSameDisplayFormat), TEXT("SM_SAMEDISPLAYFORMAT"), TEXT("Spia per medesimo formato dei colori.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMImmEnabled), TEXT("SM_IMMENABLED"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXFocusBorder), TEXT("SM_CXFOCUSBORDER"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCYFocusBorder), TEXT("SM_CYFOCUSBORDER"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMTabletPC), TEXT("SM_TABLETPC"), TEXT("Windows è a bordo di un tablet.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMediaCenter), TEXT("SM_MEDIACENTER"), TEXT("Windows media center.")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMStarter), TEXT("SM_STARTER"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMServerR2), TEXT("SM_SERVERR2"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMouseHorizontalWheelPresent), TEXT("SM_MOUSEHORIZONTALWHEELPRESENT"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCXPaddedBorder), TEXT("SM_CXPADDEDBORDER"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMDigitizer), TEXT("SM_DIGITIZER"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMMaximumTouches), TEXT("SM_MAXIMUMTOUCHES"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMRemoteSession), TEXT("SM_REMOTESESSION"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMRemoteControl), TEXT("SM_REMOTECONTROL"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMCaretBlinkingEnabled), TEXT("SM_CARETBLINKINGENABLED"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMConvertIbleslateMode), TEXT("SM_CONVERTIBLESLATEMODE"), TEXT("")));
        aggiungi(SysMetsValue(static_cast<int>(FW::SystemMetrics::SMSystemDocked), TEXT("SM_SYSTEMDOCKED"), TEXT("")));

        sizing.SetWidth(larghezzeColonne[CAPS]);
        Colonne[0].SetWidth(sizing.GetWidth());
        Colonne[0].SetHeight(AltezzaRiga);
        sizing.SetWidth(larghezzeColonne[NO_CAPS]);
        Colonne[1].SetWidth(sizing.GetWidth());
        Colonne[1].SetHeight(AltezzaRiga);
        sizing.SetWidth(larghezzeColonne[2]);
        Colonne[2].SetWidth(sizing.GetWidth());
        Colonne[2].SetHeight(AltezzaRiga);
    }
};

