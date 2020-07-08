/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../include/canvas.h"

/*******************************************************************************
 *    PRIVATES
 ******************************************************************************/
Color data_buffer[CANVAS_MAX_SIZE_EDGE * CANVAS_MAX_SIZE_EDGE];

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Canvas::Canvas(uint32_t height, uint32_t width)
{
    if (height > CANVAS_MAX_SIZE_EDGE || width > CANVAS_MAX_SIZE_EDGE)
    {
        throw "Canvas size exceed the maximum defined value!";
    }

    this->height = height;
    this->width = width;

    this->buf = (Color *) data_buffer;
}


/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Color Canvas::GetPixel(uint32_t w_pos, uint32_t h_pos)
{
    return this->buf[w_pos * this->width + h_pos];
}

void Canvas::WritePixel(uint32_t w_pos, uint32_t h_pos, Color co)
{
    this->buf[w_pos * this->width + h_pos] = co;
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/

