#include "ImageEditor.h"

ImageEditor::ImageEditor(string inFileName)
{
	pic = Picture(inFileName);
}

void ImageEditor::swapPixels(int x1, int y1, int x2, int y2)
{
    int redTemp = pic.red(x1, y1);
    int greenTemp = pic.green(x1, y1);
    int blueTemp = pic.blue(x1, y1);

    pic.set(x1, y1, pic.red(x2, y2), pic.green(x2, y2), pic.blue(x2, y2));
    pic.set(x2, y2, redTemp, greenTemp, blueTemp);
}

void ImageEditor::flipVertical()
{
    for (int x = 0; x < pic.width(); x++)
    {
        for (int y = 0; y < pic.height() / 2; y++)
        {
            swapPixels(x, y, x, pic.height() - y - 1);
        }
    }
}
void ImageEditor::flipHorizontal()
{
    for (int x = 0; x < pic.width() / 2; x++)
    {
        for (int y = 0; y < pic.height(); y++)
        {
            swapPixels(x, y, pic.width() - x - 1, y);
        }
    }
}
void ImageEditor::doubleSize()
{
	Picture picOut(pic.width() * 2, pic.height() * 2);
    for (int x = 0, xOut = 0; x < pic.width(); x++, xOut += 2)
    {
        for (int y = 0, yOut = 0; y < pic.height(); y++, yOut += 2)
        {
            int red = pic.red(x, y);
            int green = pic.green(x, y);
            int blue = pic.blue(x, y);
            picOut.set(xOut, yOut, red, green, blue);
            picOut.set(xOut + 1, yOut + 1, red, green, blue);
            picOut.set(xOut, yOut + 1, red, green, blue);
            picOut.set(xOut + 1, yOut, red, green, blue);
        }
    }
    pic = picOut;
}
void ImageEditor::colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen, int newBlue)
{
    for (int x = 0; x < pic.width(); x++)
    {
        for (int y = 0; y < pic.height(); y++)
        {
            int red = pic.red(x, y);
            int green = pic.green(x, y);
            int blue = pic.blue(x, y);
            if (abs(red - redTarget) <= tolerance && abs(green - greenTarget) <= tolerance && abs(blue - blueTarget) <= tolerance)
            {
                pic.set(x, y, newRed, newGreen, newBlue);
            }
        }
    }
}
void ImageEditor::save(string outFileName)
{
	pic.save(outFileName);
}