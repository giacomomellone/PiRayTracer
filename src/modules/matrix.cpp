/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <assert.h>
#include <initializer_list>
#include "../../include/matrix.h"

using namespace std;

/*******************************************************************************
 *    PRIVATES
 ******************************************************************************/

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/
Matrix::Matrix(uint8_t rows, uint8_t cols, std::vector<float> data)
{
    assert (rows <= MAX_MATRIX_SIZE);
    assert (cols <= MAX_MATRIX_SIZE);

    this->rows = rows;
    this->cols = cols;

    int count = 0;
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            m_data[i][j] = data[count++];
        }
    }
}

Matrix::Matrix(uint8_t rows, uint8_t cols)
{
    assert (rows <= MAX_MATRIX_SIZE);
    assert (cols <= MAX_MATRIX_SIZE);

    this->rows = rows;
    this->cols = cols;

    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            m_data[i][j] = 0;
        }
    }
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
float Matrix::operator() (uint8_t row, uint8_t col) const
{
    assert (row < this->rows);
    assert (col < this->cols);

    return this->m_data[row][col];
}

float& Matrix::operator() (uint8_t row, uint8_t col)
{
    assert (row < this->rows);
    assert (col < this->cols);

    return this->m_data[row][col];
}

bool operator == (const Matrix &m1, const Matrix &m2)
{
    if (m1.cols == m2.cols && m1.rows == m2.rows)
    {
        for(int i = 0; i < m1.rows; i++)
        {
            for(int j = 0; j < m1.cols; j++)
            {
                if (m1.m_data[i][j] != m2.m_data[i][j])
                    return false;
            }
        }
    }
    else
        return false;

    return true;
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/

