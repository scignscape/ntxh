//Author: Hung NGUYEN - 9:17 AM 20/05/2014.



#include "axlTabulatedCylinderReader.h"

#include <axlCore/axlTabulatedCylinder.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <QColor>


axlTabulatedCylinderReader::axlTabulatedCylinderReader(void) :
    axlAbstractDataReader() {

    this->setObjectName(this->description());
}

axlTabulatedCylinderReader::~axlTabulatedCylinderReader(void) {
}

QString axlTabulatedCylinderReader::identifier(void) const {
    return "axlTabulatedCylinderReader";
}

QString axlTabulatedCylinderReader::description(void) const {
    return "axlTabulatedCylinderReader";
}

QStringList axlTabulatedCylinderReader::handled(void) const {
    return QStringList() << "axlTabulatedCylinder";
}

bool axlTabulatedCylinderReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlTabulatedCylinderReader", QStringList(), createaxlTabulatedCylinderReader);
}

bool axlTabulatedCylinderReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "tabulated_cylinder")
        return false;

    return true;
}

bool axlTabulatedCylinderReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlTabulatedCylinderReader::read(const QDomNode& node) {
    // Create element from given node
    QDomElement element = node.toElement();

	axlTabulatedCylinder *tabCyl = new axlTabulatedCylinder;

    // Handle name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        tabCyl->setObjectName(name);
    }

    // Handle color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            tabCyl->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            tabCyl->setOpacity(colorList.at(3).toFloat());
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
        tabCyl->setShader(dirShader);
    }

    // Handle size
    QString size = element.attribute("size");
    if (!size.isEmpty())
        tabCyl->setSize(size.toFloat());

    // Handle curves
    // axlPoint *gen = new axlPoint();
    QDomNode genElement = element.elementsByTagName("generatrix").at(0);

    QDomElement ptElement = genElement.toElement();
    QString ptReaderTag = "axlPointReader";
    axlAbstractDataReader* ptReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(ptReaderTag));
    axlPoint *pt = dynamic_cast<axlPoint *>(ptReader->read(ptElement.firstChild()));

    tabCyl->set_generatrix(pt);

    QDomElement dirElement = element.elementsByTagName("directrix").at(0).toElement();
    QString curveReaderTag = dirElement.attribute("type")+ "Reader";
    axlAbstractDataReader* curveReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(curveReaderTag));
    axlAbstractCurve *curve = dynamic_cast<axlAbstractCurve *>(curveReader->read(dirElement.firstChild()));
    tabCyl->set_directrix(curve);

    return tabCyl;
}



dtkAbstractDataReader *createaxlTabulatedCylinderReader(void) {
    return new axlTabulatedCylinderReader;
}
