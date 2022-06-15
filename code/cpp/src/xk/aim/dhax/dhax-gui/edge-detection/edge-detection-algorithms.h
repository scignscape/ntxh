#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "global-types.h"


void gaussian_kernel(float);
void magnitude(QImage&, const QImage&, const QImage&);

QImage convolution(const auto&, const QImage&, u1 blur_factor);

QImage canny(const QImage&, float, float, float, u1 blur_factor);

QImage sobel(const QImage&, u1 blur_factor);
QImage prewitt(const QImage&, u1 blur_factor);
QImage roberts(const QImage&, u1 blur_factor);
QImage scharr(const QImage&, u1 blur_factor);

QImage hysteresis(const QImage&, float, float);

#endif // ALGORITHMS_H
