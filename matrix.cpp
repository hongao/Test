#include <iostream>

using namespace std;

class matrix
{
public:
  matrix(int m, int n)
  {
		row = m;
		col = n;
		row_data = new long[row];
		for(int i=0; i<col; i++)
		{
			row_data[i] = reinterpret_cast<long>(new float[col]);
		}
	}
	
	~matrix()
	{
		if(row_data != NULL)
		{
			for(int i=0; i<col; i++)
			{
				delete []reinterpret_cast<float *>(row_data[i]);
			}
			delete []row_data;
		}
	}
	
	float *operator[](int m)
	{
		return reinterpret_cast<float *>(row_data[m]);
	}
	
	matrix &operator=(const matrix &other)
	{
		row = other.get_row();
		col = other.get_col();
		other.pass_data(&row_data);
	}
	
	int get_row(){return row;}
	int get_col(){return col;}

private:
	int col;
	int row;
	long *row_data;
	
	void pass_data(long **data)
	{
		*data = row_data;
	}
};

int matrix_time(matrix A, matrix B, matrix &C)
{
	int m,n,l;
	m = A.get_row();
	n = B.get_col();
	l = A.get_col();

	if(B.get_row() != l)
	{
		cout << "This two matices cannot time" << endl;
		return -1;
	}

	matrix ret(m, n);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<l; k++)
			{
				ret[i][j] += A[i][l] * B[l][n];
			}
		}
	}

	C = ret;
	return 0;
}

int main() {
	matrix my(10,10);
	for(int i = 0 ; i < 10 ; i++)
    {
        for(int k = 0 ; k < 10 ; k++)
        {
            my[i][k] = 10;
        }
    }
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int k = 0 ; k < 10 ; k++)
        {
            cout << my[i][k] < " ";
        }
		cout << endl;
    }
	return 0;
}
