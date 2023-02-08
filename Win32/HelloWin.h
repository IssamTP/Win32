#pragma once
#ifdef _DEBUG
    #include <h/FrameWork.h>
#else
    #include <FrameWork/FrameWork.h>
#endif

class HelloWin : public FW::Window
{
public:
    HelloWin(HINSTANCE istanza, FW::String nomeClasse)
        : Window(istanza, nomeClasse)
    {
    }
protected:
    virtual void OnPaint()
    {
        FW::Window::OnPaint();
        UINT stileTesto = FW::StylesOperations::Combine(FW::DrawTextStyles::DTSingleLine, FW::DrawTextStyles::DTCenter, FW::DrawTextStyles::DTVCener);
        ContestoDisegno.DrawText(TEXT("Hello, Windows 10!"), GetClientRect(), stileTesto);
    }
};

