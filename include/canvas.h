/*******************************************************************************
 *    Tuple header
 ******************************************************************************/

#ifndef CANVAS_HPP
#define CANVAS_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "utils.h"
#include "tuple.h"
#include "color.h"
#include <stdlib.h>
#include <cmath>

using namespace std;

#define CANVAS_MAX_SIZE_EDGE 1000

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Canvas object
 *
 */
class Canvas
{
	public:
		uint32_t height, width;
		Color *buf;

		/********** CTOR / DTOR ***********/
		Canvas(uint32_t height, uint32_t width);

		Color GetPixel(uint32_t w_pos, uint32_t h_pos);
		void WritePixel(uint32_t w_pos, uint32_t h_pos, Color co);

};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

#endif // CANVAS_HPP
