#include "ImageEditor.h"

int main()
{
    ImageEditor img("waterlily.png");
    img.unitTests();
    img.sort();
    img.save("waterlilysorted.png");

    return 0;
}