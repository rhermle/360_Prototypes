#pragma once
#include "picture.h"
#include <iostream>
using namespace std;

class ImageEditor
{
public:
	ImageEditor(string inFileName);
	void save(string outFileName);
	void sort();
	void unitTests();

private:
	void swapPixels(int x1, int y1, int x2, int y2);
	int min3(int x1, int x2, int x3);
	int max3(int x1, int x2, int x3);
	int getHue(int x, int y);
	Picture pic;
};