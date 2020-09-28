
// // license___here

#include "QColorCombo.h"

#include "ColorSet.h"

#include <QPainter>


// package facsanadu.gui.colors;


// // Combo box: List of colors
QColorCombo::QColorCombo()
 : currentColor_(new GateColor( QColor("red") ) )
{
 colorset_ = ColorSet::colorset;
   //?currentColor_ = colorset_->get(0);
 
 size_ = 12;
 
//? currentIndexChanged_ = new QSignalEmitter.Signal0();
 
 setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
 updateColorIcon();
 //fillColorCombo();
  
  //?clicked.connect(this,"actionClick()");
}
 
void QColorCombo::updateColorIcon()
{
 setIcon(QIcon(*makeColPM(*currentColor_, size_)));
}
 

QPixmap* QColorCombo::makeColPM(GateColor& col, int size)
{
 QPixmap* pm = new QPixmap(size, size);
 pm->fill(QColor(0,0,0,0));   
 QPainter p(pm);
 p.setBrush(QColor(col.r(), col.g(), col.b() ));
 p.drawEllipse(1, 1, size-2, size-2);
 p.end();
 return pm;
}
  
  
void QColorCombo::setCurrentColor(GateColor& c)
{
 currentColor_ = &c;
 updateColorIcon();
 //?currentIndexChanged.emit();
}
  
GateColor* QColorCombo::getCurrentColor()
{
 return currentColor_;
}

void QColorCombo::actionClick()
{
 //? new QColorComboPopup(this, colorset);
}



