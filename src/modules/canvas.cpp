/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include "../../include/utils.h"
#include "../../include/canvas.h"

using namespace std;

/*******************************************************************************
 *    PRIVATES
 ******************************************************************************/
Color data_buffer[CANVAS_MAX_SIZE_EDGE * CANVAS_MAX_SIZE_EDGE];

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

    this->buf = (Color *) data_buffer;
}


/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Color Canvas::GetPixel(uint32_t x_pos, uint32_t y_pos)
{
    return this->buf[x_pos * this->y + y_pos];
}

void Canvas::WritePixel(uint32_t x_pos, uint32_t y_pos, Color co)
{
    this->buf[x_pos * this->y + y_pos] = co;
}

void Canvas::SavePPM(void)
{
    Color c_temp;
    ofstream f_ppm;

    f_ppm.open("../../ppm_outputs/out_0x000.ppm");

    f_ppm << "P3\n";
    f_ppm << this->x << " " << this->y << endl;
    f_ppm << "255\n";


    int count = 0;

    for (uint32_t i = 0; i < this->x; i++)
    {
        for (uint32_t j = 0; j < this->y; j++)
        {
            c_temp = this->GetPixel(i, j);

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
