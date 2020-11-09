/* axlAbstractVolumeDiscreteEditor.cpp ---
 *
 * Author: Anais Ducoffe
 */

/* Change Log:
 *
 */

#include "axlAbstractVolumeDiscreteEditor.h"


class axlAbstractVolumeDiscreteEditorPrivate{
public :
};


// ///////////////////////////////////////////////////////////////////
// axlAbstractVolumeDiscreteEditor
// ///////////////////////////////////////////////////////////////////

axlAbstractVolumeDiscreteEditor::axlAbstractVolumeDiscreteEditor(QWidget *parent) : axlInspectorObjectInterface(parent), d(new axlAbstractVolumeDiscreteEditorPrivate)
{

}

axlAbstractVolumeDiscreteEditor::~axlAbstractVolumeDiscreteEditor(void)
{
    delete d;
}

void axlAbstractVolumeDiscreteEditor::setVolume(axlAbstractVolumeDiscrete *volume)
{

}

void axlAbstractVolumeDiscreteEditor::setView(axlAbstractView *view)
{

}

//void axlAbstractVolumeDiscreteEditor::onLogChecked(bool checked)
//{

//}

//void axlAbstractVolumeDiscreteEditor::onSclChecked(bool checked)
//{

//}

//void axlAbstractVolumeDiscreteEditor::onShdChecked(bool checked)
//{

//}

//void axlAbstractVolumeDiscreteEditor::outlineNone(void)
//{

//}

//void axlAbstractVolumeDiscreteEditor::outlineCorners(void)
//{

//}

//void axlAbstractVolumeDiscreteEditor::outlineBox(void)
//{

//}

//void axlAbstractVolumeDiscreteEditor::outlineContour(void)
//{
//}


