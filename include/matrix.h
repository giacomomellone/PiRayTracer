/*******************************************************************************
 *    Matrix header
 ******************************************************************************/

#ifndef MATRIX_HPP
#define MATRIX_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include "support/utils.h"
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
        Matrix(uint8_t rows, uint8_t cols, vector<float> data);
        Matrix(uint8_t rows, uint8_t cols);

        uint8_t Cols(void)
        {
            return this->cols;
        }
        uint8_t Rows(void)
        {
            return this->rows;
        }

        float operator () (uint8_t, uint8_t) const;
        float& operator () (uint8_t, uint8_t);

        friend bool operator == (const Matrix &m1, const Matrix &m2);
        friend bool operator != (const Matrix &m1, const Matrix &m2);
        friend Matrix operator * (const Matrix &m1, const Matrix &m2);
        friend Tuple operator * (const Matrix &m1, const Tuple &t2);
        friend Matrix operator * (const Matrix &m, const float &val);
        friend Matrix operator / (const Matrix &m, const float &val);

        Matrix Transpose(void);
        float Determinant(void);
        Matrix Submatrix(const uint8_t row, const uint8_t col);
        float Minor(uint8_t row, uint8_t col);
        float Cofactor(uint8_t row, uint8_t col);
        bool IsInvertible(void);
        Matrix Inverse(void);

};
/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/
Matrix IdentityMatrix(uint8_t rows, uint8_t cols);

#endif // MATRIX_HPP
