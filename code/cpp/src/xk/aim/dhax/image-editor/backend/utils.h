//
// Created by jacopo on 08/05/21.
//

#ifndef IMAGE_EDITOR_UTILS_H
#define IMAGE_EDITOR_UTILS_H

inline int truncate0_255(int value)
{
    if (value < 0)
        return 0;
    if (value > 255)
        return 255;
    else
        return value;
}

inline int truncate_m100_100(int value)
{
    if (value < -100)
        return -100;
    if (value > 100)
        return 100;
    else
        return value;
}

inline int truncate0_100(int value)
{
    if (value < 0)
        return 0;
    if (value > 100)
        return 100;
    else
        return value;
}

#endif //IMAGE_EDITOR_UTILS_H
