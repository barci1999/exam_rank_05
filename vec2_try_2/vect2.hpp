#pragma once
#include <iostream>
#include <string>
class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int x,int y);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);

		int operator[](int index) const;
		int& operator[](int index);

		vect2& operator++();
		vect2 operator++(int);  

		vect2& operator--();
		vect2 operator--(int);

		vect2& operator+=(const vect2& to_sum);
		vect2& operator-=(const vect2& to_res);

		vect2& operator*=(int to_mult);
		vect2 operator*(int to_mult) const;

		vect2 operator+(const vect2& to_sum) const;
		vect2 operator-(const vect2& to_res) const;
		vect2& operator-();

		bool operator!=(const vect2& no);
		bool operator==(const vect2& yes);
};
vect2 operator*(int num,const vect2& to_mul);
std::ostream& operator<<(std::ostream& out, const vect2& to_print);
