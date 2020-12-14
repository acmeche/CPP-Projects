#include <iostream>



class Matrix {
   public:

        Matrix(int r = 10, int c = 10);                     //constructor with parameters
        Matrix(const Matrix& m);                            //default empty constructor
        ~Matrix();                                          //destructor
        int getRows() const;                                //get and set functions
        int getColumns() const;
        double getElement (int r, int c) const;
        void setElement (int r, int c, double v);
        Matrix multiply (const Matrix& m) const;            //multiply function
        Matrix   operator=(const Matrix& m);                //overloaded operators, functions at the bottom
        Matrix   operator*(const Matrix& other) const;
        double*  operator[](int);

       private:
       int    rows, cols;    // matrix dimensions
       double **element;     // element array
       static int matrixCount;

};
int Matrix::matrixCount = 0;

using namespace std;

int main()
{

    Matrix f(2,2);
    Matrix g(2,2);
    Matrix h(2,2);

    int i = 0;
    int j = 0;


    f[0][0] = 1;
    f[0][1] = 4;
    f[1][0] = 7;
    f[1][1] = 2;

    g[0][0] = 4;
    g[0][1] = 3;
    g[1][0] = 1;
    g[1][1] = 5;

    h = f.multiply(g);

while (i < 2)
{
    j = 0;
    while(j < 2 )
    {
        cout << "The product of f and g at position [" << i << "][" << j << "] is: " << h[i][j] << endl;
        j++;
    }
    i++;
}


}



Matrix::Matrix(int r, int c)
{

    rows = r;
    cols = c;
    element = new double*[rows];

    int i = 0;
    while(i < r)
    {
        element[i] = new double[cols];
        i++;
    }

    matrixCount++;
}

Matrix::Matrix(const Matrix& other)
{
    rows = other.rows;
    cols = other.cols;

    element = new double*[rows];

    int i = 0;
    int j = 0;
    while(i < rows)
    {
        element[i] = new double[cols];
        i++;
    }

    i = 0;
    while(i < rows)
    {
        j = 0;
        while(j < cols)
        {
            element[i][j] = other.getElement(i, j);
            j++;
        }
        i++;
    }

}

Matrix::~Matrix()
{
    int i = 0;
    while(i < rows)
    {
        delete [] element[i];
        i++;
    }
    delete [] element;
    matrixCount--;
}

int Matrix::getRows() const
{
   return rows;
}

int Matrix::getColumns() const
{
    return cols;
}


double Matrix::getElement(int r, int c) const
{
    return element[r][c];
}

void Matrix::setElement(int r, int c, double v)
{
    element[r][c] = v;
}

Matrix Matrix::multiply(const Matrix& m) const
{
    double v;
    Matrix tmp(rows, m.cols);

    int r = 0;
    int c = 0;
    int k = 0;

    while(r < rows)
    {
        c = 0;
        while(c < m.cols)
        {
            v = 0;
            k = 0;
                while(k < cols)
                {
                    v += element[r][k] * m.element[k][c];
                    k++;
                }
            tmp.element[r][c] = v;
            c++;
        }
    r++;
    }
    return tmp;
}

double*  Matrix::operator[](int n)
{
    return element[n];
}

Matrix Matrix::operator*(const Matrix& other) const
{
    return multiply(other);
}

Matrix Matrix::operator=(const Matrix& m)
{
    int i = 0;
    int j = 0;

    while(i < rows)
    {
        delete[] element[i];
        i++;
    }
    delete[] element;

    this -> rows = m.rows;
    this -> cols = m.cols;

    element = new double*[rows];

    i = 0;
    while(i < rows)
    {
        element[i] = new double[cols];
        i++;
    }


    i = 0;
    while(i < rows)
    {
        j = 0;
        while(j < cols)
        {
            element[i][j] = m.getElement(i, j);
            j++;
        }
        i++;
    }
    return *this;
}
