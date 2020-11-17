#ifndef IQMOL_CONFIGURATOR_CONSTRAINT_H
#define IQMOL_CONFIGURATOR_CONSTRAINT_H
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

#include "Configurator.h"
#include "ui_ScalarConstraintConfigurator.h"
#include "ui_VectorConstraintConfigurator.h"


namespace IQmol {

namespace Layer {
   class Constraint;
}

namespace Configurator {

   /// Base class for the Constraint configurators
    class Constraint : public Base {

      Q_OBJECT

      public:
         Constraint(Layer::Constraint& constraint) : m_constraint(constraint) { }

      protected:
         Layer::Constraint& m_constraint;
   };


   /// Configurator dialog that allows the user to set the value of a
   /// vector constraint such as the position.
   class VectorConstraint : public Constraint {

      Q_OBJECT

      public:
         VectorConstraint(Layer::Constraint& constraint);

      public Q_SLOTS:
         void init();
         void sync();
         void on_deleteButton_clicked(bool);

      private Q_SLOTS:
         void accept();

      private:
         Ui::VectorConstraintConfigurator m_constraintConfigurator;
   };


   /// Basic Configurator dialog that allows the user to set the value of a
   /// scalar constraint such as a bond angle.
   class ScalarConstraint : public Constraint {

      Q_OBJECT

      public:
         ScalarConstraint(Layer::Constraint& constraint);

      public Q_SLOTS:
         void init();
         void sync();
         void on_deleteButton_clicked(bool);

      private Q_SLOTS:
         void accept();
         void on_scanButton_clicked(bool) { updateRange(); }
         void on_setButton_clicked(bool) { updateRange(); }
         void on_constrainButton_clicked(bool) { updateRange(); }

      private:
         void initDistance();
         void initAngle();
         void initTorsion();
         void syncDistance();
         void syncAngle();
         void syncTorsion();
         void updateRange();
         Ui::ScalarConstraintConfigurator m_constraintConfigurator;
   };

} } // end namespace IQmol::Configurator

#endif
