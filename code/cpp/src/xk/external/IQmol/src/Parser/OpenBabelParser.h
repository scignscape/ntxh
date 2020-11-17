#ifndef IQMOL_PARSER_OPENBABEL_H
#define IQMOL_PARSER_OPENBABEL_H
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

#include "Parser.h"


namespace OpenBabel {
   class OBMol;
   class OBGridData;
   class OBVibrationData;
}

namespace IQmol {
namespace Parser {

   class OpenBabel : public Base {

      public:
         bool parseFile(QString const& filePath);
         bool parse(TextStream&);
         bool parse(::OpenBabel::OBMol& mol);
         bool parse(QString const& string, QString const& extension);

		 /// Returns true if extension is in the list of supported file formats
         static bool formatSupported(QString const& extension);

      private:
         static QStringList s_obFormats;
         static bool s_formatsLoaded;

         void buildFrom2D(::OpenBabel::OBMol& mol);
         void appendGridData(::OpenBabel::OBGridData const&);
         void appendVibrationData(::OpenBabel::OBVibrationData const&);
   };

} } // end namespace IQmol::Parser

#endif
