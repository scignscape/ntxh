//Author: Hung NGUYEN 9:17 AM 20/05/2014

#include "axlSurfaceRevolutionParametricWriter.h"

#include <axlCore/axlSurfaceRevolutionParametric.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <QColor>

axlSurfaceRevolutionParametricWriter::axlSurfaceRevolutionParametricWriter(void) :
    axlAbstractDataWriter() {

    this->setObjectName(this->description());
}

axlSurfaceRevolutionParametricWriter::~axlSurfaceRevolutionParametricWriter(void) {
}

QString axlSurfaceRevolutionParametricWriter::identifier(void) const {
    return "axlSurfaceRevolutionParametricWriter";
}

QString axlSurfaceRevolutionParametricWriter::description(void) const {
    return "axlSurfaceRevolutionParametricWriter";
}

QStringList axlSurfaceRevolutionParametricWriter::handled(void) const {
    return QStringList() << "axlSurfaceRevolutionParametric";
}

bool axlSurfaceRevolutionParametricWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlSurfaceRevolutionParametricWriter", QStringList(), createaxlSurfaceRevolutionParametricWriter);
}

bool axlSurfaceRevolutionParametricWriter::accept(dtkAbstractData *data) {
    axlSurfaceRevolutionParametric *surfaceRevolution = dynamic_cast<axlSurfaceRevolutionParametric*>(data);
    if(surfaceRevolution)
        return true;

    return false;
}

bool axlSurfaceRevolutionParametricWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlSurfaceRevolutionParametricWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    axlSurfaceRevolutionParametric* surRev = dynamic_cast<axlSurfaceRevolutionParametric*>(data);

	 ///// Name
    QDomElement surElement = doc->createElement("surface_revolution_parametric");
    surElement.setAttribute("name", surRev->name());

	///// Size
    surElement.setAttribute("size", QString::number(surRev->size()));

	//// Color
    QColor qcolor = surRev->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(surRev->opacity());
    surElement.setAttribute("color", color);

	//// Shader
    QString shader = surRev->shader();
    QFileInfo shaderFileInfo(shader);
    surElement.setAttribute("shader", shaderFileInfo.fileName());

	// Write axe
	 QDomElement axeElement = doc->createElement("axe");
	 axlLine* axe = surRev->getAxe();
     axlAbstractDataWriter* axeWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer("axlLineWriter"));
     QDomElement lineElement = axeWriter->write(doc, axe);
     axeElement.appendChild(lineElement);
	 surElement.appendChild(axeElement);

	 //Write curve
	 QDomElement curveElement = doc->createElement("curve");
	 axlAbstractCurve* curve = surRev->getCurve();
	 QString curveWriterTag = curve->identifier()+"Writer";
     axlAbstractDataWriter* curveWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(curveWriterTag));
     QDomElement subCurveElement = curveWriter->write(doc, curve);
     curveElement.appendChild(subCurveElement);
	 curveElement.setAttribute("type",curve->identifier());
	 surElement.appendChild(curveElement);

	 //Write Angle
	 QDomElement angleElement = doc->createElement("angle");
	 double startAngle = surRev->getStartAngle();
	 double endAngle = surRev->getEndAngle();
	 angleElement.setAttribute("start_angle",startAngle);
	 angleElement.setAttribute("end_angle",endAngle);
	 surElement.appendChild(angleElement);

	 //return

	 return surElement;

}

QDomElement axlSurfaceRevolutionParametricWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlSurfaceRevolutionParametricWriter(void) {
    return new axlSurfaceRevolutionParametricWriter;
}
