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
		uint32_t x, y;
		Color *buf;

		/********** CTOR / DTOR ***********/
		Canvas(uint32_t x, uint32_t y);

		Color GetPixel(uint32_t x_pos, uint32_t y_pos);
		void WritePixel(uint32_t x_pos, uint32_t y_pos, Color co);
		void SavePPM(void);

};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

#endif // CANVAS_HPP
