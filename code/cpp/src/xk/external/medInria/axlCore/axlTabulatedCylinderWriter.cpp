#include "axlTabulatedCylinderWriter.h"

#include <axlCore/axlTabulatedCylinder.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <QColor>

axlTabulatedCylinderWriter::axlTabulatedCylinderWriter(void) :
    axlAbstractDataWriter() {

    this->setObjectName(this->description());
}

axlTabulatedCylinderWriter::~axlTabulatedCylinderWriter(void) {
}

QString axlTabulatedCylinderWriter::identifier(void) const {
    return "axlTabulatedCylinderWriter";
}

QString axlTabulatedCylinderWriter::description(void) const {
    return "axlTabulatedCylinderWriter";
}

QStringList axlTabulatedCylinderWriter::handled(void) const {
    return QStringList() << "axlTabulatedCylinder";
}

bool axlTabulatedCylinderWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlTabulatedCylinderWriter", QStringList(), createaxlTabulatedCylinderWriter);
}

bool axlTabulatedCylinderWriter::accept(dtkAbstractData *data) {
    axlTabulatedCylinder *TabulatedCylinder = dynamic_cast<axlTabulatedCylinder*>(data);
    if(TabulatedCylinder)
        return true;

    return false;
}

bool axlTabulatedCylinderWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlTabulatedCylinderWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    axlTabulatedCylinder* tabCyl = dynamic_cast<axlTabulatedCylinder*>(data);

	 ///// Name
    QDomElement surElement = doc->createElement("tabulated_cylinder");
    surElement.setAttribute("name", tabCyl->name());

	///// Size
    surElement.setAttribute("size", QString::number(tabCyl->size()));

	//// Color
    QColor qcolor = tabCyl->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(tabCyl->opacity());
    surElement.setAttribute("color", color);

	//// Shader
    QString shader = tabCyl->shader();
    QFileInfo shaderFileInfo(shader);
    surElement.setAttribute("shader", shaderFileInfo.fileName());

	 //Write generatrix
		 QDomElement generatrixElement = doc->createElement("generatrix");
		 QString genWriterTag = tabCyl->get_pt_generatrix()->identifier()+"Writer";
		 axlAbstractDataWriter* genWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(genWriterTag));
		 QDomElement subGenElement = genWriter->write(doc, tabCyl->get_pt_generatrix());
		 generatrixElement.appendChild(subGenElement);
		 surElement.appendChild(generatrixElement);
	//Write
		 QDomElement directrixElement = doc->createElement("directrix");
		 QString dirWriterTag = tabCyl->get_pt_directrix()->identifier()+"Writer";
		 axlAbstractDataWriter* dirWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(dirWriterTag));
		 QDomElement subDirElement = dirWriter->write(doc, tabCyl->get_pt_directrix());
		 directrixElement.appendChild(subDirElement);
		 directrixElement.setAttribute("type",tabCyl->get_pt_directrix()->identifier());
		 surElement.appendChild(directrixElement);
	 //return
	 return surElement;

}

QDomElement axlTabulatedCylinderWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlTabulatedCylinderWriter(void) {
    return new axlTabulatedCylinderWriter;
}
