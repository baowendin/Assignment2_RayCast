#ifndef _IFS_H_
#define _IFS_H_
#include "matrix.h"
#include<vector>
#include <assert.h>
#include <time.h>
class ifs{
	int n; // number of transformation
	int size;
	vector<Matrix> matrixs; // n transformations
	vector<float> possibiliy; // n possibility
public:
	ifs(int n, int size)
	{
		this->n = n;
		this->size = size;	
	}

	void read(Matrix matrix, float rate)
	{
		matrixs.push_back(matrix);
		possibiliy.push_back(rate);
	}
	
	void render(Vec2f& v)
	{
		for (int i = 0; i < n; i++)
		{
			float num = rand() % 100 * 1.0 / 100;
			float count = 0;
			for (int j = 0; j < possibiliy.size(); j++)
			{
				count += possibiliy[j];
				if (count > num)
				{
					Vec4f tmp(v.x(), v.y(), size, size);
					matrixs[j].Transform(tmp);
					v.Set(tmp.x(), tmp.y());
					break;
				}
			}
		}
	}


};


#endif