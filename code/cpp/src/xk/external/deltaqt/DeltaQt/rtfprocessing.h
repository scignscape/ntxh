#ifndef DQT_RTFPROCESSING_H
#define DQT_RTFPROCESSING_H

#include <QString>
#include <QMap>

class RtfToHtmlDef
{
public:
    enum opType { BLOCK, SYMBOL, SPECIAL };

    RtfToHtmlDef();
    RtfToHtmlDef(QString rtfKeyword,
                 QString htmlKeyword,
                 opType htmlType,
                 bool bracketedHtml);

    QString rtfKeyword;
    QString htmlKeyword;
    enum opType htmlType;
    bool bracketedHtml;
};

typedef QMap<QString, const RtfToHtmlDef*> RtfToHtmlLUT;

class RtfHandler
{
public:
    RtfHandler();

    QString toHtml(const QString& rtfStr) const;
    QString toText(const QString& rtfStr) const;

    inline static RtfToHtmlLUT subs(void) { return rtfAndHtmlLUT; }
private:
    static RtfToHtmlLUT rtfAndHtmlLUT;
    static RtfToHtmlLUT initLUT(void);
};

#endif // DQT_RTFPROCESSING_H
