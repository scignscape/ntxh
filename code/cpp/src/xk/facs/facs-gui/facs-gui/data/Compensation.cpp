
// // license___here_h

#include "Compensation.h"

#include "Dataset.h"

Compensation::Compensation()
{
}


int Compensation::getSize()
{
 return matrix_.size();
}

void Compensation::updateMatrix(FacsanaduProject* p)
{
 Q_UNUSED(p)
}

void Compensation::apply(FacsanaduProject* p)
{
 Q_UNUSED(p)
}

void Compensation::apply(Dataset* ds)
{
 Q_UNUSED(ds)
}

double Compensation::get(int to, int from)
{
 return matrix_[to][from];
}

void Compensation::set(int to, int from, double v)
{
 matrix_[to][from] = v;
}


