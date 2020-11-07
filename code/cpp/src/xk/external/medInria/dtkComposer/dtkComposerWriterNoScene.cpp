
#include "dtkComposerNode.h"
#include "dtkComposerNodeBoolean.h"
#include "dtkComposerNodeComposite.h"
#include "dtkComposerNodeControl.h"
#include "dtkComposerNodeFile.h"
#include "dtkComposerNodeGraph.h"
#include "dtkComposerNodeGraphEdge.h"
#include "dtkComposerNodeInteger.h"
#include "dtkComposerNodeLeaf.h"
#include "dtkComposerNodeReal.h"
#include "dtkComposerNodeString.h"
#include "dtkComposerNodeSpawnEmbedded.h"
#include "dtkComposerTransmitter.h"
#include "dtkComposerTransmitterProxy.h"
#include "dtkComposerTransmitterProxyLoop.h"
#include "dtkComposerWriterNoScene.h"

#include <dtkLog/dtkLogger.h>

#include <QtCore>

class dtkComposerWriterNoScenePrivate
{
public:
    QHash<int, dtkComposerNode *> node_ids;
    dtkComposerNodeGraph *graph;

public:
    int id;
};

dtkComposerWriterNoScene::dtkComposerWriterNoScene(void) : d(new dtkComposerWriterNoScenePrivate)
{
    d->id    = 0;
    d->graph = NULL;
}

dtkComposerWriterNoScene::~dtkComposerWriterNoScene(void)
{
    delete d;

    d = NULL;
}

void dtkComposerWriterNoScene::setGraph(dtkComposerNodeGraph *graph)
{
    d->graph = graph;
}


QDomDocument dtkComposerWriterNoScene::toXML(dtkComposerNode *rootNode, bool addSelf)
{

    QDomDocument document("dtk");
    QDomElement root = document.createElement("dtk");
    document.appendChild(root);

    if(!d->graph) {
        dtkError() << "no graph in writer, can't serialize composition !";
        return document;
    }

    if (addSelf) {

        dtkTrace() << "XML: adding root node";
        root.appendChild(this->writeNode(rootNode, root, document));

    } else {

        dtkTrace() << "XML: adding child nodes";
        foreach(dtkComposerNode *child, d->graph->nodes()) {
            if (d->graph->scope(child) == rootNode) {
                root.appendChild(this->writeNode(child, root, document));
            }
        }


        dtkTrace() << "XML: adding edges";
        foreach(dtkComposerNodeGraphEdge edge, d->graph->edges()) {
            if (edge.parentNode() == rootNode ) {
                this->writeEdge(edge, root, document);
            }
        }
    }

    return document;
}

bool dtkComposerWriterNoScene::write(const QString& fileName, dtkComposerWriter::Type type)
{
    if(!d->graph)
        return false;

    return this->writeNode(d->graph->rootNodes().first(), fileName, type);
}

bool dtkComposerWriterNoScene::writeNode(dtkComposerNode *node, const QString& fileName, dtkComposerWriter::Type type)
{
    if(!d->graph)
        return false;

    QDomDocument document = this->toXML(node, false);

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly))
        return false;

    if(type == dtkComposerWriter::Ascii) {
        QTextStream out(&file); out << document.toString();
    } else {
        QDataStream out(&file); out << qCompress(document.toByteArray().toHex());
    }

    file.close();
    return true;
}

QDomElement dtkComposerWriterNoScene::writeNode(dtkComposerNode *node, QDomElement& element, QDomDocument& document)
{
    int current_id = d->id++; d->node_ids.insert(current_id, node);

    QDomElement tag = document.createElement("node");
    tag.setAttribute("id", QString::number(current_id));

    if(dtkComposerNodeControl *control = dynamic_cast<dtkComposerNodeControl *>(node)) {

        tag.setAttribute("type", control->type());
        tag.setAttribute("title", node->titleHint());

        QDomElement child = this->writeNode(control->header(), tag, document);
        tag.appendChild(child);

        int max = control->blockCount();
        for(int i = 0; i< max; ++i) {
            dtkComposerNodeComposite *block = control->block(i);
            child = this->writeNode(block, tag, document);
            child.setAttribute("blockid", i);
            tag.appendChild(child);
        }

        child = this->writeNode(control->footer(), tag, document);
        tag.appendChild(child);
    }

    if(dtkComposerNodeComposite *composite = dynamic_cast<dtkComposerNodeComposite *>(node)) {

        if(dynamic_cast<dtkComposerNodeControl *>(d->graph->scope(node)) &&  d->id !=1 ) {

            tag.setTagName("block");
        }
        tag.setAttribute("type", composite->type());
        tag.setAttribute("title", composite->titleHint());

        QMap<dtkComposerTransmitterProxyLoop *, int> twin_ids_map;

        for(int i = 0; i < composite->receivers().count(); ++i) {
            dtkComposerTransmitter *t = composite->receivers().at(i);
            if (!t->required()) {
                QDomElement property = document.createElement("port");
                property.setAttribute("id", i);
                property.setAttribute("type", "input");
                if (t->kind() == dtkComposerTransmitter::Proxy) {
                    property.setAttribute("kind", "proxy");
                } else if (t->kind() == dtkComposerTransmitter::ProxyLoop) {
                    property.setAttribute("kind", "proxyloop");
                } else if (t->kind() == dtkComposerTransmitter::ProxyVariant) {
                    property.setAttribute("kind", "proxyvariant");
                }

                if(dtkComposerTransmitterProxyLoop *tpl = dynamic_cast<dtkComposerTransmitterProxyLoop *>(t)) {
                    twin_ids_map[tpl] = i;
                }

                tag.appendChild(property);

            }
        }

        for(int i = 0; i < composite->emitters().count(); ++i) {
            dtkComposerTransmitter *t = composite->emitters().at(i);
            if (!t->required()) {
                QDomElement property = document.createElement("port");
                property.setAttribute("id", i);
                property.setAttribute("type", "output");
                if (t->kind() == dtkComposerTransmitter::Proxy) {
                    property.setAttribute("kind", "proxy");
                } else if (t->kind() == dtkComposerTransmitter::ProxyLoop) {
                    property.setAttribute("kind", "proxyloop");
                } else if (t->kind() == dtkComposerTransmitter::ProxyVariant) {
                    property.setAttribute("kind", "proxyvariant");
                }


                if(dtkComposerTransmitterProxyLoop *tpl = dynamic_cast<dtkComposerTransmitterProxyLoop *>(t)) {
                    if (dtkComposerTransmitterProxyLoop *twin = tpl->twin()) {
                        property.setAttribute("twin", twin_ids_map.value(twin));
                    }
                }

                tag.appendChild(property);

            }
        }

        foreach(dtkComposerNode *child, d->graph->nodes()) {
            if (d->graph->scope(child) == node) {
                tag.appendChild(this->writeNode(child, tag, document));
            }
        }

        foreach(dtkComposerNodeGraphEdge edge, d->graph->edges()) {
            if (edge.parentNode() == node ) {
                this->writeEdge(edge, tag, document);
            }
        }

    }

    if(dtkComposerNodeLeaf *leaf = dynamic_cast<dtkComposerNodeLeaf *>(node)) {
        if (leaf->isHeader())
            tag.setTagName("header");

        if (leaf->isFooter())
            tag.setTagName("footer");

        tag.setAttribute("type", leaf->type());
        tag.setAttribute("title", leaf->titleHint());

        if (dtkComposerNodeBoolean *boolean = dynamic_cast<dtkComposerNodeBoolean *>(node)) {

            QDomText text = document.createTextNode(boolean->value() ? "true" : "false");

            QDomElement value = document.createElement("value");
            value.appendChild(text);

            tag.appendChild(value);
        }

        if (dtkComposerNodeInteger *integer = dynamic_cast<dtkComposerNodeInteger *>(node)) {

            QDomText text = document.createTextNode(QString::number(integer->value()));

            QDomElement value = document.createElement("value");
            value.appendChild(text);

            tag.appendChild(value);
        }

        if (dtkComposerNodeReal *real = dynamic_cast<dtkComposerNodeReal *>(node)) {

            QDomText text = document.createTextNode(QString::number(real->value()));

            QDomElement value = document.createElement("value");
            value.appendChild(text);

            tag.appendChild(value);
        }

        if (dtkComposerNodeString *s = dynamic_cast<dtkComposerNodeString *>(node)) {

            QDomText text = document.createTextNode(s->value());

            QDomElement value = document.createElement("value");
            value.appendChild(text);

            tag.appendChild(value);
        }

        if (dtkComposerNodeFile *f = dynamic_cast<dtkComposerNodeFile *>(node)) {

            QDomText text = document.createTextNode(f->value());

            QDomElement value = document.createElement("value");
            value.appendChild(text);

            tag.appendChild(value);
        }

        if (dtkComposerNodeDirectory *f = dynamic_cast<dtkComposerNodeDirectory *>(node)) {

            QDomText text = document.createTextNode(f->value());

            QDomElement value = document.createElement("value");
            value.appendChild(text);

            tag.appendChild(value);
        }

        if (dtkComposerNodeLeafObject *object_node = dynamic_cast<dtkComposerNodeLeafObject *>(node)) {

            QDomText text = document.createTextNode(object_node->currentImplementation());
            QDomElement implementation = document.createElement("implementation");
            implementation.appendChild(text);
            tag.appendChild(implementation);
        }

        this->extend(node, tag, document);

    }

    return tag;
}


QDomElement dtkComposerWriterNoScene::writeEdge(dtkComposerNodeGraphEdge edge, QDomElement& element, QDomDocument& document)
{

    typedef QPair<int, int> Connexion;
    foreach( Connexion connexion, edge.connexions()) {

        QDomElement source = document.createElement("source");
        int id = d->node_ids.key(edge.source(),-1);
        if (id < 0)
            continue;
        source.setAttribute("node", id);
        source.setAttribute("id", connexion.first);
        source.setAttribute("type", edge.srcType());

        id = d->node_ids.key(edge.destination(),-1);
        if (id < 0)
            continue;
        QDomElement destin = document.createElement("destination");
        destin.setAttribute("node", id);
        destin.setAttribute("id", connexion.second);
        destin.setAttribute("type", edge.dstType());

        QDomElement tag = document.createElement("edge");
        tag.appendChild(source);
        tag.appendChild(destin);
        element.appendChild(tag);
    }
    return element;
}

void dtkComposerWriterNoScene::extend(dtkComposerNode *node, QDomElement& element, QDomDocument& document)
{
    Q_UNUSED(node);
    Q_UNUSED(element);
    Q_UNUSED(document);
}
