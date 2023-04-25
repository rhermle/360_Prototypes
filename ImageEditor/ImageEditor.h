#pragma once
#include "picture.h"
#include <iostream>
using namespace std;

class ImageEditor
{
public:
	ImageEditor(string inFileName);
	void flipVertical();
	void flipHorizontal();
	void doubleSize();
	void colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen, int newBlue);
	void save(string outFileName);

private:
	void swapPixels(int x1, int y1, int x2, int y2);
	Picture pic;
};