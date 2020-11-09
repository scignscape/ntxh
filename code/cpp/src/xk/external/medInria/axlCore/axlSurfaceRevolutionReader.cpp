//Author: Hung NGUYEN - 9:17 AM 20/05/2014.

#include "axlSurfaceRevolutionReader.h"

#include <axlCore/axlSurfaceRevolution.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <axlCore/axlLine.h>
#include <axlCore/axlLineReader.h>

#include <QtGui>

axlSurfaceRevolutionReader::axlSurfaceRevolutionReader(void) :
    axlAbstractDataReader() {

    this->setObjectName(this->description());
}

axlSurfaceRevolutionReader::~axlSurfaceRevolutionReader(void) {
}

QString axlSurfaceRevolutionReader::identifier(void) const {
    return "axlSurfaceRevolutionReader";
}

QString axlSurfaceRevolutionReader::description(void) const {
    return "axlSurfaceRevolutionReader";
}

QStringList axlSurfaceRevolutionReader::handled(void) const {
    return QStringList() << "axlSurfaceRevolution";
}

bool axlSurfaceRevolutionReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlSurfaceRevolutionReader", QStringList(), createaxlSurfaceRevolutionReader);
}

bool axlSurfaceRevolutionReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "surface_revolution")
        return false;

    return true;
}

bool axlSurfaceRevolutionReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlSurfaceRevolutionReader::read(const QDomNode& node) {
    // Create element from given node
    QDomElement element = node.toElement();

	axlSurfaceRevolution *surRev = new axlSurfaceRevolution;

    // Handle name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        surRev->setObjectName(name);
    }

    // Handle color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            surRev->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            surRev->setOpacity(colorList.at(3).toFloat());
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
        surRev->setShader(dirShader);
    }

    // Handle size
    QString size = element.attribute("size");
    if (!size.isEmpty())
        surRev->setSize(size.toFloat());


    // Handle axe
    QDomElement axeElement = element.elementsByTagName("axe").at(0).toElement();
    axlLineReader *lineReader = dynamic_cast<axlLineReader*>(dtkAbstractDataFactory::instance()->reader("axlLineReader"));
    axlLine *axe = dynamic_cast<axlLine*>(lineReader->read(axeElement.firstChild()));
    surRev->setAxe(axe);

    // Handle curves
    QList<axlAbstractCurve *> curveList;
    QDomElement curvesElement = element.elementsByTagName("curves").at(0).toElement();
    QDomNodeList curvelistElement = curvesElement.elementsByTagName("curve");
    for(int i = 0; i<curvelistElement.size(); i++) {
            QDomElement curveElement = curvelistElement.at(i).toElement();
            QString curveReaderTag = curveElement.attribute("type")+ "Reader";
            axlAbstractDataReader* curveReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(curveReaderTag));
            axlAbstractCurve *curve = dynamic_cast<axlAbstractCurve *>(curveReader->read(curveElement.firstChild()));
            curveList.append(curve);
    }

    surRev->setCurves(curveList);

    // Handle angle
    QDomElement angleElement = element.elementsByTagName("angle").at(0).toElement();
    double startAngle = angleElement.attribute("start_angle").toDouble();
    double endAngle = angleElement.attribute("end_angle").toDouble();
    surRev->setAngle(startAngle,endAngle);

    return surRev;
}



dtkAbstractDataReader *createaxlSurfaceRevolutionReader(void) {
    return new axlSurfaceRevolutionReader;
}
