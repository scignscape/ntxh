/*  Copyright 2012 Craig Robbins

    This file is part of DeltaQt.

    DeltaQt is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DeltaQt is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DeltaQt.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H

#include "deltadataset.h"

class DataValidation
{
public:
    DataValidation();

    int verifyParse(const DeltaDataset* dataset, ParseLog* log);

protected:
    int vfyNumberOfChars(void) const;
    int vfyMaxStates(void) const;
    int vfyMaxItems(void) const;
    int vfyNumsOfStates(void) const;

private:
    const DeltaDataset* m_dataset;
    ParseLog* m_log;
};

#endif // DATAVALIDATION_H
