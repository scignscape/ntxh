
#include "rtfprocessing.h"


// Notes from the 'specification'

// "Control Words" is the phrase the RTF doc specifies. The RTF documentation
// also mentions "Control Symbols", however here we will lump them all
// together

// A control word cannot be longer than 32 characters
// RTF is case sensitive.

// Format:  \ControlWord<Delimiter>

// RTF supports character escapes; e.g. \\, \{, \}


const static RtfToHtmlDef subsToHtml[] = {
    RtfToHtmlDef( "i",          "i",        RtfToHtmlDef::BLOCK,   true  ),
    RtfToHtmlDef( "u",          "u",        RtfToHtmlDef::BLOCK,   true  ),
    RtfToHtmlDef( "b",          "b",        RtfToHtmlDef::BLOCK,   true  ),
    RtfToHtmlDef( "sub",        "sub",      RtfToHtmlDef::BLOCK,   true  ),
    RtfToHtmlDef( "super",      "sup",      RtfToHtmlDef::BLOCK,   true  ),
    RtfToHtmlDef( "nosupersub", "",         RtfToHtmlDef::SPECIAL, true  ),
    RtfToHtmlDef( "par",        "p",        RtfToHtmlDef::BLOCK,   true  ),
    RtfToHtmlDef( "emdash",     "&mdash",   RtfToHtmlDef::SYMBOL,  false ),
    RtfToHtmlDef( "endash",     "&ndash",   RtfToHtmlDef::SYMBOL,  false ),
    RtfToHtmlDef( "line",       "br",       RtfToHtmlDef::SYMBOL,  true  ),
    RtfToHtmlDef( "lquote",     "&lsquo",   RtfToHtmlDef::SYMBOL,  false ),
    RtfToHtmlDef( "rquote",     "&rsquo",   RtfToHtmlDef::SYMBOL,  false ),
    RtfToHtmlDef( "ldblquote",  "&ldquo",   RtfToHtmlDef::SYMBOL,  false ),
    RtfToHtmlDef( "rdbquote",   "&rdquo",   RtfToHtmlDef::SYMBOL,  false ),
    // non-breaking hyphen
    RtfToHtmlDef( "_",          "-",        RtfToHtmlDef::SYMBOL,  false ),
    // non-breaking space
    RtfToHtmlDef( "~",          "&nbsp",    RtfToHtmlDef::SYMBOL,  false ),
    // optional hyphen
    RtfToHtmlDef( "-",          "",         RtfToHtmlDef::SPECIAL, false ),
    // hex value: \'hh
    RtfToHtmlDef( "'",          "",         RtfToHtmlDef::SPECIAL, false )
};


/****************************************************************************
  class RtfToHtmlDef
 ***************************************************************************/

RtfToHtmlDef::RtfToHtmlDef()
{
}

RtfToHtmlDef::RtfToHtmlDef(QString rtfKeyword,
                           QString htmlKeyword,
                           opType htmlType,
                           bool bracketedHtml)
{
    this->rtfKeyword = rtfKeyword;
    this->htmlKeyword = htmlKeyword;
    this->htmlType = htmlType;
    this->bracketedHtml = bracketedHtml;
}

/****************************************************************************
  class RtfToHtml
 ***************************************************************************/

RtfToHtmlLUT RtfHandler::rtfAndHtmlLUT = RtfHandler::initLUT();

RtfHandler::RtfHandler()
{
}

RtfToHtmlLUT RtfHandler::initLUT(void)
{
    RtfToHtmlLUT lut;

    for (int i = 0; i < (int)(sizeof subsToHtml / sizeof (subsToHtml[0])); i++)
    {
        lut.insert(subsToHtml[i].rtfKeyword, &subsToHtml[i]);
    }
    return lut;
}
