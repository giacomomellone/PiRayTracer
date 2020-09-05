/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "../../include/canvas.h"

using namespace std;

/*******************************************************************************
 *    PRIVATES
 ******************************************************************************/
Color data_buffer[CANVAS_MAX_SIZE_EDGE][CANVAS_MAX_SIZE_EDGE];

int GetPixelColor8bit(float co);
/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Canvas::Canvas(uint32_t x, uint32_t y)
{
    if (x > CANVAS_MAX_SIZE_EDGE || y > CANVAS_MAX_SIZE_EDGE)
    {
        throw "Canvas size exceed the maximum defined value!";
    }

    this->x = x;
    this->y = y;

    memset(data_buffer, 0, sizeof(Color) *
            (CANVAS_MAX_SIZE_EDGE * CANVAS_MAX_SIZE_EDGE));

    this->buf = data_buffer;
}


/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Color Canvas::ReadPixel(uint32_t x_pos, uint32_t y_pos)
{
    if (x_pos > this->x || y_pos > this->y)
    {
        throw "ReadPixel exceed the maximum canvas defined value!";
    }

    return this->buf[(int) y_pos][(int) x_pos];
}

void Canvas::WritePixel(uint32_t x_pos, uint32_t y_pos, Color co)
{
    if (x_pos > this->x || y_pos > this->y)
    {
        throw "WritePixel exceed the maximum canvas defined value!";
    }

    this->buf[(int) y_pos][(int) x_pos] = co;
}

void Canvas::SavePPM(string filename)
{
    Color c_temp = Color();
    ofstream f_ppm;

#ifndef CROSS_COMPILING_FLAG
    f_ppm.open("../../ppm_outputs/" + filename);
#else
    f_ppm.open(filename);
#endif

    f_ppm << "P3\n";
    f_ppm << this->x << " " << this->y << endl;
    f_ppm << "255\n";


    int count = 0;

    for (uint32_t j = 0; j < this->y; j++)
    {
        for (uint32_t i = 0; i < this->x; i++)
        {
            c_temp = this->ReadPixel(i, j);

            f_ppm << GetPixelColor8bit(c_temp.r()) << " ";
            f_ppm << GetPixelColor8bit(c_temp.g()) << " ";
            f_ppm << GetPixelColor8bit(c_temp.b());

            count += 3;
            if (count >= 69)
            {
                f_ppm << "\n";
            }
            else
            {
                f_ppm << " ";
            }
        }
    }
    f_ppm << "\n";

    f_ppm.close();

}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
int GetPixelColor8bit(float co)
{
    int co_value = (int) (co * 255);

    if (co_value < 0)
    {
        return 0;
    }
    else if (co_value > 255)
    {
        return 255;
    }
    else
    {
        return co_value;
    }
}
