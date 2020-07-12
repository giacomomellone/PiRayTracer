/*******************************************************************************
 *    Tuple header
 ******************************************************************************/

#ifndef MATRIX_HPP
#define MATRIX_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include "utils.h"
#include "tuple.h"

#define MAX_MATRIX_SIZE 5

using namespace std;

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Matrix object
 *
 */
class Matrix
{
    private:
        uint8_t rows, cols;
        float m_data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    public:
        Matrix(uint8_t rows, uint8_t cols, std::vector<float> data);
        Matrix(uint8_t rows, uint8_t cols);

    float operator () (uint8_t, uint8_t) const;
    float& operator () (uint8_t, uint8_t);

    friend bool operator == (const Matrix &m1, const Matrix &m2);


    // void print();
};


/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

#endif // MATRIX_HPP
