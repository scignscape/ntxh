//Author: Hung NGUYEN 9:17 AM 20/05/2014

#include "axlSurfaceRevolutionWriter.h"

#include <axlCore/axlSurfaceRevolution.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <QtGui>

axlSurfaceRevolutionWriter::axlSurfaceRevolutionWriter(void) :
    axlAbstractDataWriter() {

    this->setObjectName(this->description());
}

axlSurfaceRevolutionWriter::~axlSurfaceRevolutionWriter(void) {
}

QString axlSurfaceRevolutionWriter::identifier(void) const {
    return "axlSurfaceRevolutionWriter";
}

QString axlSurfaceRevolutionWriter::description(void) const {
    return "axlSurfaceRevolutionWriter";
}

QStringList axlSurfaceRevolutionWriter::handled(void) const {
    return QStringList() << "axlSurfaceRevolution";
}

bool axlSurfaceRevolutionWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlSurfaceRevolutionWriter", QStringList(), createaxlSurfaceRevolutionWriter);
}

bool axlSurfaceRevolutionWriter::accept(dtkAbstractData *data) {
    axlSurfaceRevolution *surfaceRevolution = dynamic_cast<axlSurfaceRevolution*>(data);
    if(surfaceRevolution)
        return true;

    return false;
}

bool axlSurfaceRevolutionWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlSurfaceRevolutionWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    axlSurfaceRevolution* surRev = dynamic_cast<axlSurfaceRevolution*>(data);

	 ///// Name
    QDomElement surElement = doc->createElement("surface_revolution");
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
	 QDomElement curvesElement = doc->createElement("curves");

	 QList<axlAbstractCurve*> curves = surRev->getCurves();

	 for(int i = 0; i<curves.size(); i++)
	 {
		 QDomElement curveElement = doc->createElement("curve");
		 QString curveWriterTag = curves.at(i)->identifier()+"Writer";
		 axlAbstractDataWriter* curveWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(curveWriterTag));
		 QDomElement subCurveElement = curveWriter->write(doc, curves.at(i));
		 curveElement.appendChild(subCurveElement);
		 curveElement.setAttribute("type",curves.at(i)->identifier());
		 curvesElement.appendChild(curveElement);
	 }
	 surElement.appendChild(curvesElement);

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

QDomElement axlSurfaceRevolutionWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlSurfaceRevolutionWriter(void) {
    return new axlSurfaceRevolutionWriter;
}
