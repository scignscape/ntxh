//Author: Hung NGUYEN - 9:17 AM 20/05/2014.



#include "axlSurfaceRevolutionParametricReader.h"

#include <axlCore/axlSurfaceRevolutionParametric.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <axlCore/axlLine.h>
#include <axlCore/axlLineReader.h>

#include <QColor>


axlSurfaceRevolutionParametricReader::axlSurfaceRevolutionParametricReader(void) :
    axlAbstractDataReader() {

    this->setObjectName(this->description());
}

axlSurfaceRevolutionParametricReader::~axlSurfaceRevolutionParametricReader(void) {
}

QString axlSurfaceRevolutionParametricReader::identifier(void) const {
    return "axlSurfaceRevolutionParametricReader";
}

QString axlSurfaceRevolutionParametricReader::description(void) const {
    return "axlSurfaceRevolutionParametricReader";
}

QStringList axlSurfaceRevolutionParametricReader::handled(void) const {
    return QStringList() << "axlSurfaceRevolutionParametric";
}

bool axlSurfaceRevolutionParametricReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlSurfaceRevolutionParametricReader", QStringList(), createaxlSurfaceRevolutionParametricReader);
}

bool axlSurfaceRevolutionParametricReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "surface_revolution_parametric")
        return false;

    return true;
}

bool axlSurfaceRevolutionParametricReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlSurfaceRevolutionParametricReader::read(const QDomNode& node) {
    // Create element from given node
    QDomElement element = node.toElement();

	axlSurfaceRevolutionParametric *surRev = new axlSurfaceRevolutionParametric;

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

    // Handle faces
	QDomElement curveElement = element.elementsByTagName("curve").at(0).toElement();
    QString curveReaderTag = curveElement.attribute("type")+ "Reader";
	axlAbstractDataReader* curveReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(curveReaderTag));
	axlAbstractCurve *curve = dynamic_cast<axlAbstractCurve *>(curveReader->read(curveElement.firstChild()));
	surRev->setCurve(curve);

	// Handle angle
	QDomElement angleElement = element.elementsByTagName("angle").at(0).toElement();
	double startAngle = angleElement.attribute("start_angle").toDouble();
	double endAngle = angleElement.attribute("end_angle").toDouble();
	surRev->setAngle(startAngle,endAngle);

    return surRev;
}



dtkAbstractDataReader *createaxlSurfaceRevolutionParametricReader(void) {
    return new axlSurfaceRevolutionParametricReader;
}
