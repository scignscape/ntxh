//Author: Hung NGUYEN - 9:17 AM 20/05/2014.



#include "axlCompositeCurveReader.h"

#include <axlCore/axlCompositeCurve.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <axlCore/axlLine.h>
#include <axlCore/axlLineReader.h>

#include <QColor>


axlCompositeCurveReader::axlCompositeCurveReader(void) :
    axlAbstractDataReader() {

    this->setObjectName(this->description());
}

axlCompositeCurveReader::~axlCompositeCurveReader(void) {
}

QString axlCompositeCurveReader::identifier(void) const {
    return "axlCompositeCurveReader";
}

QString axlCompositeCurveReader::description(void) const {
    return "axlCompositeCurveReader";
}

QStringList axlCompositeCurveReader::handled(void) const {
    return QStringList() << "axlCompositeCurve";
}

bool axlCompositeCurveReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlCompositeCurveReader", QStringList(), createaxlCompositeCurveReader);
}

bool axlCompositeCurveReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "composite_curve")
        return false;

    return true;
}

bool axlCompositeCurveReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlCompositeCurveReader::read(const QDomNode& node) {
    // Create element from given node
    QDomElement element = node.toElement();

	axlCompositeCurve *comCur = new axlCompositeCurve;

    // Handle name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        comCur->setObjectName(name);
    }

    // Handle color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            comCur->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            comCur->setOpacity(colorList.at(3).toFloat());
    }

    // Handle shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if (!shader.isEmpty()) {
        // Try to read from axelShader.qrc
        dirShader = ":axlShader/shader/" + shader;
        if (!QFile::exists(dirShader)) {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
            dirShader.append("/" + shader);
        }
        comCur->setShader(dirShader);
    }

    // Handle size
    QString size = element.attribute("size");
    if (!size.isEmpty())
        comCur->setSize(size.toFloat());

    // Handle curves
	QList<axlAbstractCurve *> curveList;
	QDomNodeList curvelistElement = element.elementsByTagName("curve");
	for(int i = 0; i<curvelistElement.size(); i++)
	{
		QDomElement curveElement = curvelistElement.at(i).toElement();
		QString curveReaderTag = curveElement.attribute("type")+ "Reader";
		axlAbstractDataReader* curveReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(curveReaderTag));
		axlAbstractCurve *curve = dynamic_cast<axlAbstractCurve *>(curveReader->read(curveElement.firstChild()));
		curveList.append(curve);
	}

	comCur->insert_list_curves(curveList);

    return comCur;
}



dtkAbstractDataReader *createaxlCompositeCurveReader(void) {
    return new axlCompositeCurveReader;
}
