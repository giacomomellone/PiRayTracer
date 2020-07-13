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
                if (!equal(m1.m_data[i][j], m2.m_data[i][j]))
                    return false;
            }
        }
    }
    else
        return false;

    return true;
}

bool operator != (const Matrix &m1, const Matrix &m2)
{
    if (m1.cols == m2.cols && m1.rows == m2.rows)
    {
        for(int i = 0; i < m1.rows; i++)
        {
            for(int j = 0; j < m1.cols; j++)
            {
                if (!equal(m1.m_data[i][j], m2.m_data[i][j]))
                    return true;
            }
        }
    }
    else
        return true;

    return false;
}

Matrix operator * (const Matrix &m1, const Matrix &m2)
{
    assert (m1.cols == m2.rows);

    Matrix m_res = Matrix(m1.rows, m2.cols);

    for(int i = 0; i < m1.rows; i++)
    {
        for(int j = 0; j < m1.cols; j++)
        {
            for (int k = 0; k < m1.cols; k++)
            {
                m_res(i, j) += m1(i, k) * m2(k, j);
            }
        }
    }

    return m_res;
}

Tuple operator * (const Matrix &m1, const Tuple &t2)
{
    assert (m1.cols == 4);
    assert (m1.rows == 4);

    Tuple t_res = Tuple();

    for(int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            t_res(i) += m1(i, k) * t2(k);
        }
    }

    return t_res;
}

Matrix operator * (const Matrix &m, const float &val)
{
    Matrix res = Matrix(m.rows, m.cols);

    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.cols; j++)
        {
            res(i, j) = m(i, j) * val;
        }
    }

    return res;
}

Matrix operator / (const Matrix &m, const float &val)
{
    Matrix res = Matrix(m.rows, m.cols);

    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.cols; j++)
        {
            res(i, j) = m(i, j) / val;
        }
    }

    return res;
}

Matrix Matrix::Transpose(void)
{
    Matrix t = Matrix(4, 4);

    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            t(j, i) = this->operator()(i, j);
        }
    }

    return t;
}

float Matrix::Determinant(void)
{
    assert(this->cols == this->rows);

    if (this->cols == 2 and this->rows == 2)
    {
        return (this->m_data[0][0] * this->m_data[1][1] - this->m_data[0][1] * this->m_data[1][0]);
    }
    else
    {
        float sum = 0;
        for(int i = 0; i < this->cols; i++) {
            sum += this->m_data[0][i] * this->Cofactor(0,i);
        }

        return sum;
    }
}

Matrix Matrix::Submatrix(const uint8_t row, const uint8_t col)
{
    Matrix sub_m = Matrix(this->rows - 1, this->cols - 1);
    uint8_t sub_i, sub_j;

    for(int i = 0; i < this->rows - 1; i++)
    {
        sub_i = (i >= row) ? i + 1 : i;
        for(int j = 0; j < this->cols - 1; j++)
        {
            sub_j = (j >= col) ? j + 1: j;
            sub_m(i, j) = this->m_data[sub_i][sub_j];
        }
    }

    return sub_m;
}

float Matrix::Minor(uint8_t row, uint8_t col)
{
    return this->Submatrix(row, col).Determinant();
}

float Matrix::Cofactor(uint8_t row, uint8_t col)
{
    if((row + col) % 2 == 1)
    {
        return -this->Minor(row, col);
    }
    else
    {
        return this->Minor(row, col);
    }
}

bool Matrix::IsInvertible(void)
{
    return this->Determinant() != 0;
}

Matrix Matrix::Inverse(void)
{
    Matrix res = Matrix(this->rows, this->cols);
    float detMatrix = this->Determinant();

    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            res(i,j) = (float) this->Cofactor(j,i) / detMatrix;
        }
    }

    return res;
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
Matrix IdentityMatrix(void)
{
    Matrix m = Matrix(4, 4);

    for (int i = 0; i < m.Cols(); i++)
        m(i, i) = 1;

    return m;
}
