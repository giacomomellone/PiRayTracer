/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>

//-- module being tested
#include "../include/canvas.h"

/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE FUNCTIONS
 ******************************************************************************/

/*******************************************************************************
 *    SETUP, TEARDOWN
 ******************************************************************************/

/*******************************************************************************
 *    TESTS
 ******************************************************************************/

TEST_GROUP(CanvasTest) {};

TEST(CanvasTest, Canvas)
{
    Canvas cv = Canvas(10, 20);
    cv.WritePixel(2, 3, Color(0.2, 0.1, 0.9));

    DOUBLES_EQUAL(0.2, cv.GetPixel(2, 3).r(), EPSILON);
    DOUBLES_EQUAL(0.1, cv.GetPixel(2, 3).g(), EPSILON);
    DOUBLES_EQUAL(0.9, cv.GetPixel(2, 3).b(), EPSILON);
    DOUBLES_EQUAL(0, cv.GetPixel(2, 2).r(), EPSILON);
//    CHECK(t_point.IsPoint());
}

TEST(CanvasTest, SavePPM)
{
    Canvas cv = Canvas(5, 3);
    Color c1 = Color(1.5, 0, 0);
    Color c2 = Color(0, 0.5, 0);
    Color c3 = Color(-0.5, 0, 1);

    cv.WritePixel(0, 0, c1);
    cv.WritePixel(2, 1, c2);
    cv.WritePixel(4, 2, c3);

    cv.SavePPM();
}

TEST(CanvasTest, SavePPMSetEachPixel)
{
    Canvas cv = Canvas(10, 2);
    Color co = Color(1, 0.8, 0.6);

    for (uint32_t i = 0; i < cv.x; i++)
    {
        for (uint32_t j = 0; j < cv.y; j++)
        {
            cv.WritePixel(i, j, co);
        }
    }

    /* TODO passa path come parametro */
    cv.SavePPM();
}
