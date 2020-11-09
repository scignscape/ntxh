#include "axlShapeBSplineReader.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlShapeBSpline.h>

#include <QtXml>
#include <QtCore>
#include <QtGui>

axlShapeBSplineReader::axlShapeBSplineReader()
{
    this->setObjectName(this->identifier());
}


axlShapeBSplineReader::~axlShapeBSplineReader(){
}

QString axlShapeBSplineReader::identifier(void) const{
    return "axlShapeBSplineReader";
}

QString axlShapeBSplineReader::description(void) const{
    return "axlShapeBSplineReader";
}

QStringList axlShapeBSplineReader::handled(void) const{
    return QStringList();
}

bool axlShapeBSplineReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlShapeBSplineReader", QStringList(), createaxlShapeBSplineReader);
}


bool axlShapeBSplineReader::accept(const QDomNode& node){
    QDomElement element = node.toElement();

    if(element.tagName() == "surface"){
        if(element.attribute("type") == "patch")
            return true;
    }

    return false;
}

bool axlShapeBSplineReader::reject(const QDomNode& node){
    return !this->accept(node);
}

axlAbstractData *axlShapeBSplineReader::read(const QDomNode& node){
    // Create element from given node
    QDomElement element = node.toElement();

    // Create surf from points, edges and faces counters
    int pointCount = element.attribute("nb_points").toInt();
    int edgeCount = element.attribute("nb_edges").toInt();
    int faceCount = element.attribute("nb_faces").toInt();
    int orderu = element.attribute("orderu").toInt();
    int orderv = element.attribute("orderv").toInt();

    double *points = new double[3*pointCount];
    QVector< QVector<int> >pe;
    QVector< QVector<int> >pf;
    QVector< QPair<int,int> >npf;
    QList<QString> tags;
    axlShapeBSpline* surf = new axlShapeBSpline();

    // Handle name
    QString name = element.attribute("name");
    if (!name.isEmpty()){
        surf->setObjectName(name);
    }

    // Handle color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            surf->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            surf->setOpacity(colorList.at(3).toFloat());
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
        surf->setShader(dirShader);
    }

    // Handle size
    QString size = element.attribute("size");
    if (!size.isEmpty())
        surf->setSize(size.toFloat());

    // Handle points
    QDomElement pointsElement = element.elementsByTagName("points").at(0).toElement();
    QStringList pointsList = pointsElement.text().simplified().split(QRegExp("\\s+"));

    for (int k = 0; k < pointsList.size(); k+=3){
        points[k] = pointsList.at(k).toDouble();
        points[k+1] =pointsList.at(k+1).toDouble();
        points[k+2] =pointsList.at(k+2).toDouble();
    }



    // Handle edges
    QDomElement edgesElement = element.elementsByTagName("edges").at(0).toElement();
    QDomNodeList edgesList = edgesElement.elementsByTagName("edge");

    for (int k = 0; k < edgesList.size(); k++) {
        QDomElement edgeElement = edgesList.at(k).toElement();

        QDomElement controlPointsElement = edgeElement.elementsByTagName("controlPoints").at(0).toElement();
        QStringList controlpointsList = controlPointsElement.text().simplified().split(QRegExp("\\s+"));
        QVector<int> controlPointIndices;

        for (int k = 0; k < controlpointsList.size(); k++){
            controlPointIndices.append(controlpointsList.at(k).toInt());
        }

        pe.append(controlPointIndices);

        tags.append(edgeElement.attribute("tag"));

    }

    // Handle faces
    QDomElement facesElement = element.elementsByTagName("faces").at(0).toElement();
    QDomNodeList facesList = facesElement.elementsByTagName("face");

    for (int k = 0; k < facesList.size(); k++) {
        QDomElement faceElement = facesList.at(k).toElement();

        QDomElement controlPointsElement = faceElement.elementsByTagName("controlPoints").at(0).toElement();
        QStringList controlpointsList = controlPointsElement.text().simplified().split(QRegExp("\\s+"));
        QVector<int> controlPointIndices;

        for (int k = 0; k < controlpointsList.size(); k++){
            controlPointIndices.append(controlpointsList.at(k).toInt());
        }

        pf.append(controlPointIndices);

        QDomElement edgeIndicesElement = faceElement.elementsByTagName("nbpts").at(0).toElement();
        QStringList edgeIndicesList = edgeIndicesElement.text().simplified().split(QRegExp("\\s+"));
        QPair<int,int> np = QPair<int,int>(edgeIndicesList.at(0).toInt(),edgeIndicesList.at(1).toInt());

        npf.append(np);

    }
    surf->setSurface(orderu,orderv,pointCount,edgeCount,faceCount, points,pe,pf,npf);

    //tags for boundary edges.
    for(int i = 0; i < tags.size(); i++){
        surf->getEdge(i)->tag = tags.at(i);
    }
    return surf;
}


dtkAbstractDataReader *createaxlShapeBSplineReader(void) {
    return new axlShapeBSplineReader;
}
