#ifndef IMAGE_EDITOR_PIXEL_H
#define IMAGE_EDITOR_PIXEL_H

#include <cstdint>
#include <QColor>

//frontend for QColor

class Pixel {

private:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

public:
    Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    Pixel(); //all black
    Pixel(const Pixel &pixel);

    bool operator==(const Pixel &pixel) const;

    bool operator!=(const Pixel &pixel) const;

    uint8_t getR() const;

    uint8_t getG() const;

    uint8_t getB() const;

    uint8_t getA() const;

    uint16_t get_color_sum() const;

    void set_alpha(int a);
    void make_fully_opaque()
    {
     set_alpha(255);
    }
    void make_fully_transparent()
    {
     set_alpha(0);
    }

    void setPixel(int r, int g, int b, int a);

    static QColor toQColor(const Pixel &);

    static Pixel fromQColor(const QColor &);
};


#endif //IMAGE_EDITOR_PIXEL_H
