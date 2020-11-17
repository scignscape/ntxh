#ifndef IQMOL_COLORGRADIENTDIALOG_H
#define IQMOL_COLORGRADIENTDIALOG_H
/*******************************************************************************
         
  Copyright (C) 2011-2015 Andrew Gilbert
      
  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.
         
  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software  
  Foundation, either version 3 of the License, or (at your option) any later  
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.
      
  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.
   
********************************************************************************/

#include "ui_ColorGradientDialog.h"
#include "ColorGradient.h"


namespace IQmol {
namespace ColorGradient {

   class Dialog : public QDialog {

      Q_OBJECT

      public:
         // linked to ColorGradientDialog.ui
         Dialog(ColorList const&, QWidget* parent = 0);
         Dialog(StandardGradient const, QWidget* parent = 0);
         ColorList colors() const { return m_colors; }
         StandardGradient type() const;

      private Q_SLOTS:
         void on_gradientCombo_currentIndexChanged(int);
         void on_stopsSpin_valueChanged(int);
         void colorChanged(int const index, QColor const&);

      private:
         void setCustom();
         void updateGradient();
         void clearStops();

         Ui::ColorGradientDialog m_dialog;
         ColorList m_colors;
   };



   class StopButton : public QToolButton {

      Q_OBJECT

      public:
         StopButton(QWidget* parent, int const index, QColor const& color);
         void setColor(QColor const&);
         int index() const { return m_index; }

      Q_SIGNALS:
         void colorChanged(int const index, QColor const&);

      private Q_SLOTS:
         void getNewColor();

      private:
         QColor m_color;
         int    m_index;
   };

} // end namespace ColorGradient


ColorGradient::ColorList GetGradient(ColorGradient::ColorList const&, QWidget* parent = 0);
ColorGradient::ColorList GetGradient(ColorGradient::StandardGradient g = ColorGradient::Default,
   QWidget* parent = 0);

} // end namespace IQmol::Gradient

#endif
