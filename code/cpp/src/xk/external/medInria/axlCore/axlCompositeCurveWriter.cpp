#include "axlCompositeCurveWriter.h"

#include <axlCore/axlCompositeCurve.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <QColor>

axlCompositeCurveWriter::axlCompositeCurveWriter(void) :
    axlAbstractDataWriter() {

    this->setObjectName(this->description());
}

axlCompositeCurveWriter::~axlCompositeCurveWriter(void) {
}

QString axlCompositeCurveWriter::identifier(void) const {
    return "axlCompositeCurveWriter";
}

QString axlCompositeCurveWriter::description(void) const {
    return "axlCompositeCurveWriter";
}

QStringList axlCompositeCurveWriter::handled(void) const {
    return QStringList() << "axlCompositeCurve";
}

bool axlCompositeCurveWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlCompositeCurveWriter", QStringList(), createaxlCompositeCurveWriter);
}

bool axlCompositeCurveWriter::accept(dtkAbstractData *data) {
    axlCompositeCurve *CompositeCurve = dynamic_cast<axlCompositeCurve*>(data);
    if(CompositeCurve)
        return true;

    return false;
}

bool axlCompositeCurveWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlCompositeCurveWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    axlCompositeCurve* comCur = dynamic_cast<axlCompositeCurve*>(data);

	 ///// Name
    QDomElement curElement = doc->createElement("composite_curve");
    curElement.setAttribute("name", comCur->name());

	///// Size
    curElement.setAttribute("size", QString::number(comCur->size()));

	//// Color
    QColor qcolor = comCur->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(comCur->opacity());
    curElement.setAttribute("color", color);

	//// Shader
    QString shader = comCur->shader();
    QFileInfo shaderFileInfo(shader);
    curElement.setAttribute("shader", shaderFileInfo.fileName());

	 //Write curves

	for(int i = 0; i<comCur->count_curve(); i++)
	 {
		 QDomElement curveElement = doc->createElement("curve");
		 QString curveWriterTag = comCur->get_pt_curve_at_id(i)->identifier()+"Writer";
		 axlAbstractDataWriter* curveWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(curveWriterTag));
		 QDomElement subCurveElement = curveWriter->write(doc, comCur->get_pt_curve_at_id(i));
		 curveElement.appendChild(subCurveElement);
		 curveElement.setAttribute("type",comCur->get_pt_curve_at_id(i)->identifier());
		 curElement.appendChild(curveElement);
	 }

	 //return
	 return curElement;

}

QDomElement axlCompositeCurveWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlCompositeCurveWriter(void) {
    return new axlCompositeCurveWriter;
}
