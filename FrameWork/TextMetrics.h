#pragma once
#ifndef _TEXT_METRICS_CLASS_H_
    #define _TEXT_METRICS_CLASS_H_
    #include "HeaderCPP.h"
    #include "WinSize.h"
namespace FW
{
    /// <summary>
    /// Classe involucro per TEXTMETRIC.
    /// Questa struttura è inizializzabile una tantum: SINGLETON (o unique_ptr).
    /// </summary>
    /// <remarks>
    /// 1) Le linee del testo sono spaziate con l'altezza del carattere.
    /// 2) Le lettere singole del testo sono spaziate con la larghezza media del carattere.
    /// 3) Anche in questo caso le unità di misura dei campi sono unità logiche che, nel caso di mapping MM_TEXT, corrispondono a 1px.
    /// 4) Leading nella stampa è lo spessore delle linee.
    /// </remarks>
    class _FRAMEWORK_CLASS_EXPORT_ TextMetrics : public TEXTMETRIC
    {
    protected:
        using TEXTMETRIC::tmAscent; // Distanza Y baseline-punta superiore del carattere.
        using TEXTMETRIC::tmAveCharWidth;   // Larghezza media del carattere minuscolo. Il valore per la maiuscola è circa 3/2 questo.
        using TEXTMETRIC::tmBreakChar;
        using TEXTMETRIC::tmCharSet;
        using TEXTMETRIC::tmDefaultChar;
        using TEXTMETRIC::tmDescent; // Distanza Y baseline-punta inferiore del carattere.
        using TEXTMETRIC::tmDigitizedAspectX;
        using TEXTMETRIC::tmDigitizedAspectY;
        using TEXTMETRIC::tmExternalLeading; // Spazio tra una riga e l'altra.
        using TEXTMETRIC::tmFirstChar;
        using TEXTMETRIC::tmHeight; // Distanza Y tmDescent tmAscent compresi.
        using TEXTMETRIC::tmInternalLeading;    // Distanza Y punta carattere fine segni diacrilici.
        using TEXTMETRIC::tmItalic;
        using TEXTMETRIC::tmLastChar;
        using TEXTMETRIC::tmMaxCharWidth;   // Larghezza del carattere più grande
        using TEXTMETRIC::tmOverhang;
        using TEXTMETRIC::tmPitchAndFamily;
        using TEXTMETRIC::tmStruckOut;
        using TEXTMETRIC::tmUnderlined;
        using TEXTMETRIC::tmWeight;
#pragma region Singleton
    private:
        /// <summary>
        /// Unica istanza di TextMetric.
        /// </summary>
        static TextMetrics* TextMetric;
        /// <summary>
        /// Costruttore predefinito che azzera anche TEXTMETRIC.
        /// </summary>
        TextMetrics();
        /// <summary>
        /// Costruttore di copia annullato.
        /// </summary>
        /// <param name="textMetrics"></param>
        TextMetrics(const TextMetrics& textMetrics) = delete;
        /// <summary>
        /// Operatore di copia annullato.
        /// </summary>
        /// <param name="textMetrics"></param>
        /// <returns></returns>
        TextMetrics& operator=(const TextMetrics& textMetrics) = delete;
    public:
        /// <summary>
        /// Ottiene la larghezza media del carattere minuscolo.
        /// </summary>
        /// <returns></returns>
        LONG GetAverageCharacterWidth() const;
        /// <summary>
        /// Ottiene la larghezza media del carattere minuscolo.
        /// </summary>
        /// <returns></returns>
        LONG GetAverageMaximizedCharacterWidth() const;
        /// <summary>
        /// Ottiene l'istanza di textMetrics.
        /// </summary>
        static TextMetrics* GetTextMetricsInstance();
#pragma endregion
    public:
        /// <summary>
        /// Indica se il font è a larghezza variabile.
        /// </summary>
        /// <returns>True se il bit meno significativo di tmPitchAndFamily è 1.</returns>
        bool IsVariableWidthChar() const;
        /// <summary>
        /// Calcola l'ingombro in altezza e larghezza, quindi WinSize, del font attualmente caricato in TextMetrics.
        /// </summary>
        /// <param name="size">Riferimento ad una variabile WinSize da valorizzare.</param>
        void GetInformationAboutSpacing(WinSize& size) const;
    };
};
#endif