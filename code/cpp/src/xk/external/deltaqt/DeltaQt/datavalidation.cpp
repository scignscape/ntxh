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

#include <QDebug>
#include "datavalidation.h"

DataValidation::DataValidation()
{
}

/** @internal
  * Returns the number of errors encountered
  */
int DataValidation::verifyParse(const DeltaDataset* dataset, ParseLog* log)
{
    int errCount = 0;

    m_dataset = dataset;
    m_log = log;

    errCount += vfyNumberOfChars();
    errCount += vfyMaxStates();
    errCount += vfyMaxItems();
    errCount += vfyNumsOfStates();

    if (errCount != 0) {
        log->appendStdErr("Data validation",
                          QString("Failed: %1 errors encountered: ")
                            .arg(errCount));
    } else {
        log->appendStdInfo("Data validation", "Passed");
    }

    return errCount;
}

/** @internal
  * Returns the number of errors encountered
  */
int DataValidation::vfyNumberOfChars(void) const
{
    int errCount = 0;
    if (m_dataset->expectedCharCount() != -1
            && (m_dataset->charCount() != m_dataset->expectedCharCount())) {
        errCount = 1;

        m_log->appendStdErr("Data validation",
                QString("Expected %1 characters, got %2")
                    .arg(m_dataset->expectedCharCount())
                    .arg(m_dataset->charCount()) );
    }

    return errCount;
}

/** @internal
  * Returns the number of errors encountered
  */
int DataValidation::vfyMaxStates(void) const
{
    int errCount = 0;

    if (m_dataset->expectedMaxStates() != -1) {
        if (m_dataset->maxCharacterStates() > m_dataset->expectedMaxStates()) {
            errCount = 1;

            m_log->appendStdErr("Data validation",
                QString("Expected a maximum of %1 character states, got %2")
                    .arg(m_dataset->expectedMaxStates())
                    .arg(m_dataset->maxCharacterStates()) );
        }
    }
    return errCount;
}

/** @internal
  * Returns the number of errors encountered
  */
int DataValidation::vfyMaxItems(void) const
{
    int errCount = 0;

    if (m_dataset->expectedMaxItems() != -1) {
        if (m_dataset->itemCount() > m_dataset->expectedMaxItems()) {
            errCount = 1;

            m_log->appendStdErr("Data validation",
                QString("Expected a maximum of %1 items, got %2")
                    .arg(m_dataset->expectedMaxItems())
                    .arg(m_dataset->itemCount()) );

        }
    }
    return errCount;
}

/** @internal
  * Returns the number of errors encountered
  */
int DataValidation::vfyNumsOfStates(void) const
{
    int errCount = 0;
    QMap<int, int> expStatesPerChar;
    QList<int> keys;

    expStatesPerChar = m_dataset->getExpectedStatesPerChar();
    keys = expStatesPerChar.keys();

    for (int i = 0; i < keys.count(); i++) {
        const DeltaCharacter* dch;
        dch = m_dataset->getCharacter_const(keys.at(i));
        if (!dch) {
            // Could not find character

            m_log->appendStdErr("Data validation",
                QString("No character number %1")
                    .arg(keys.at(i)) );

        } else {
            if (dch->stateCount() != expStatesPerChar.value(keys.at(i))) {
                // Only checking for multistate characters, although 'number
                // of states' is specified for text characters in some datasets
                // (e.g. see Myxomycetes)
                if (dch->isMultistate()) {
                    // Wrong number of states
                    qDebug() << "";
                    errCount++;

                    m_log->appendStdErr("Data validation",
                        QString("Expected character %1 to have %2 states"
                                ". Got %3 states.")
                            .arg(expStatesPerChar.value(keys.at(i)))
                            .arg(dch->stateCount()) );
                }
            }
        }
    }
    return errCount;
}
