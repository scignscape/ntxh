// Version: $Id: ba37e77ce583b2cddf9c7af6c002f7c7dd7c1bbd $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include <dtkCore/dtkCorePluginWidgetManager>
#include <dtkCore/dtkCorePluginFactory>

#include <dtkMeta/dtkMeta>

// ///////////////////////////////////////////////////////////////////
// dtkComposerNodeObject implementation
// ///////////////////////////////////////////////////////////////////

template <typename T> inline dtkComposerNodeObject<T>::dtkComposerNodeObject(void) : dtkComposerNodeLeafObject(), m_implementation(QString()), m_object(nullptr), m_factory(nullptr)
{

}

template <typename T> inline dtkComposerNodeObject<T>::~dtkComposerNodeObject(void)
{
    for (T *t : m_objects.values()) {
        QWidget *w = dtkCorePluginWidgetManager::instance().take(t);
        if (w) {
            delete w;
        }
        delete t;
    }

    m_objects.clear();
}

template <typename T> inline void dtkComposerNodeObject<T>::setFactory(const dtkCorePluginFactory<T>& factory)
{
    m_factory = &factory;
}

template <typename T> inline QVariant dtkComposerNodeObject<T>::variant(void) const
{
    if (this->object()) {
        return dtkMetaType::variantFromValue(this->object());

    } else {
        return QVariant();
    }
}

template <typename T> inline T *dtkComposerNodeObject<T>::object(void) const
{
    return m_object;
}

template <typename T> inline bool dtkComposerNodeObject<T>::createObject(const QString& implementation)
{
    if (implementation.isEmpty() || implementation == "Choose implementation") {
        return false;
    }

    if (m_objects.contains(implementation)) {
        m_object = m_objects.value(implementation);

    } else {
        m_object = m_factory->create(implementation);

        if (m_object) {
            m_objects.insert(implementation, m_object);
        }
    }

    if (m_object) {
        m_implementation = implementation;
    }

    return (m_object != nullptr);
}

template <typename T> inline QStringList dtkComposerNodeObject<T>::implementations(void) const
{
    if (m_factory) {
        return m_factory->keys();
    }

    return QStringList();
}

template <typename T> inline QString dtkComposerNodeObject<T>::currentImplementation(void) const
{
    return m_implementation;
}

template <typename T> inline bool dtkComposerNodeObject<T>::implementationHasChanged(const QString& implementation) const
{
    return (m_implementation != implementation);
}

template <typename T> inline QWidget *dtkComposerNodeObject<T>::editor(void)
{
    if (!m_factory || !m_object) {
        return nullptr;
    }

    QWidget *w = dtkCorePluginWidgetManager::instance().widget(m_object);
    if (!w) {
        w = m_factory->createWidget(m_implementation);
        if (w) {
            QVariant v = dtkMetaType::variantFromValue(m_object);
            dtkCorePluginWidgetManager::instance().add(m_object, v, w);
        }
    }
    return w;
}

//
// dtkComposerNodeObject.tpp ends here
