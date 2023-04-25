#include "ImageEditor.h"
#include <fstream>

bool matchImage(string name1, string name2);

int main()
{
    int score = 0;

    ImageEditor imDouble("pikachu.png");
    ImageEditor imHoriz("pikachu.png");
    ImageEditor imVert("pikachu.png");
    ImageEditor imColor("pikachu.png");
    ImageEditor imAll("pikachu.png");

    cout << "Testing size expansion..." << endl;
    imDouble.doubleSize();
    imDouble.save("pikachu1.png");
    if (matchImage("pikachu1.png", "pikachuDouble.png"))
    {
        score += 2;
        cout << "Size expansion passed! +2 points" << endl;
    }
    else
    {
        cout << "Size expansion failed." << endl;
    }

    cout << "Testing horizontal flip..." << endl;
    imHoriz.flipHorizontal();
    imHoriz.save("pikachu2.png");
    if (matchImage("pikachu2.png", "pikachuHoriz.png"))
    {
        score += 2;
        cout << "horizontal flip passed! +2 points" << endl;
    }
    else
    {
        cout << "horizontal flip failed." << endl;
    }

    cout << "Testing vertical flip..." << endl;
    imVert.flipVertical();
    imVert.save("pikachu3.png");
    if (matchImage("pikachu3.png", "pikachuVert.png"))
    {
        score += 2;
        cout << "vertical flip passed! +2 points" << endl;
    }
    else
    {
        cout << "vertical flip failed." << endl;
    }

    cout << "Testing color filter..." << endl;
    imColor.colorFilter(226, 218, 69, 30, 255, 10, 255);
    imColor.save("pikachu4.png");
    if (matchImage("pikachu4.png", "pikachuColor.png"))
    {
        score += 2;
        cout << "color filter passed! +2 points" << endl;
    }
    else
    {
        cout << "color filter failed." << endl;
    }

    cout << "Testing all at once..." << endl;
    imAll.doubleSize();
    imAll.flipHorizontal();
    imAll.flipVertical();
    imAll.colorFilter(226, 218, 69, 30, 255, 10, 255);
    imAll.save("pikachu5.png");
    if (matchImage("pikachu5.png", "pikachuAll.png"))
    {
        score += 4;
        cout << "All at once test passed! +4 points" << endl;
    }
    else
    {
        cout << "All at once test failed." << endl;
    }

    cout << "Final score: " << score << "/12" << endl;
    ofstream ofs("score.txt");
    ofs << score << endl;
    ofs.close();

    /*
    ///Generate Test Images
    ImageEditor imDouble("pikachu.png");
    ImageEditor imHoriz("pikachu.png");
    ImageEditor imVert("pikachu.png");
    ImageEditor imColor("pikachu.png");
    ImageEditor imAll ("pikachu.png");

    imDouble.doubleSize();
    imDouble.save("pikachuDouble.png");
    imHoriz.flipHorizontal();
    imHoriz.save("pikachuHoriz.png");
    imVert.flipVertical();
    imVert.save("pikachuVert.png");
    imColor.colorFilter(226, 218, 69, 30, 255, 10, 255);
    imColor.save("pikachuColor.png");

    imAll.doubleSize();
    imAll.flipHorizontal();
    imAll.flipVertical();
    imAll.colorFilter(226, 218, 69, 30, 255, 10, 255);
    imAll.save("pikachuAll.png");
    */

   return 0;
}

bool matchImage(string name1, string name2)
{
    Picture p1(name1);
    Picture p2(name2);

    if (p1.height() != p2.height())
    {
        cout << "Image height mismatch" << endl;
        return false;
    }
    if (p1.width() != p2.width())
    {
        cout << "Image width mismatch" << endl;
        return false;
    }
    for (int x = 0; x < p1.width(); x++)
    {
        for (int y = 0; y < p1.height(); y++)
        {
            if (p1.red(x, y) != p2.red(x, y) || p1.green(x, y) != p2.green(x, y) || p1.blue(x, y) != p2.blue(x, y))
            {
                cout << "Pixel color mismatch at " << x << "," << y << endl;
                return false;
            }
        }
    }
    return true;
}