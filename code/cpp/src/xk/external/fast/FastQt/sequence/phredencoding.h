/*
Copyright Copyright 2016-17 Sacha Schutz

    This file is part of FastQt.

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

    @author : Pierre Lindenbaum from FastQC <http://www.bioinformatics.babraham.ac.uk/projects/fastqc/>
    @author : Sacha Schutz <sacha@labsquare.org>
    @author : Pierre Marijon <pierre@marijon.fr>
*/
#ifndef PHREDENCODING_H
#define PHREDENCODING_H
#include <QtCore>
/*!
 * \class PhredEncoding
 * \brief Detect Quality encoding from Fastq file
 */
class PhredEncoding
{
public:
    PhredEncoding(const QString& n = QStringLiteral(), int offset = 0);

    static PhredEncoding fastqEncodingOffset(char lowestChar);
    bool isValid();

    const QString& name() const { return mName;}
    int offset() const {return mOffset;}


private:

    QString mName;
    int mOffset;
    static const int SANGER_ENCODING_OFFSET = 33;
    static const int ILLUMINA_1_3_ENCODING_OFFSET = 64;



};

#endif // PHREDENCODING_H
