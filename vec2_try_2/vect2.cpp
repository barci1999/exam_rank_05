#include "vect2.hpp"

vect2::vect2()
{
	this->x = 0;
	this->y = 0;
}
vect2::vect2(int x,int y )
{
	this->x = x;
	this->y = y;
}
vect2::vect2(const vect2& other)
{
	this->x = other.x;
	this->y = other.y;
}
vect2& vect2::operator=(const vect2& other)
{
	if (this == &other)
	{
		return *this;
	}
	this->x = other.x;
	this->y = other.y;
	return *this;
}
int& vect2::operator[](int index)
{
	if (index == 0)
	{
		return this->x;
	}
	else
		return this->y;
	
}
int vect2::operator[](int index) const
{
	if (index == 0)
	{
		return this->x;
	}
	else
		return this->y;
	
}
vect2& vect2::operator++()
{
	this->x++;
	this->y++;
	return *this;
}
vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	this->x++;
	this->y++;
	return temp;
}
vect2& vect2::operator--()
{
	this->x--;
	this->y--;
	return *this;
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	this->x--;
	this->y--;
	return temp;
}
std::ostream& operator<<(std::ostream& out,const vect2& to_print)
{
	out << "{" << to_print[0] << ", " << to_print[1] << "}";
	return out;
}
vect2& vect2::operator+=(const vect2& to_sum)
{
	this->x += to_sum.x;
	this->y += to_sum.y;
	return *this;
}
vect2& vect2::operator-=(const vect2& to_res)
{
	this->x -= to_res.x;
	this->y -= to_res.y;
	return *this;
}
vect2& vect2::operator*=(int to_mul)
{
	this->x *= to_mul;
	this->y *= to_mul;
	return *this;
}
vect2 vect2::operator*(int to_mult) const
{
	vect2 temp;
	temp.x = this->x * to_mult;
	temp.y = this->y * to_mult;
	return(temp);
}
vect2 operator*(int num,const vect2& to_mult)
{
	vect2 temp(to_mult);
	temp *= num;
	return temp;
}
vect2 vect2::operator+(const vect2& to_sum) const
{
	vect2 temp = *this;
	temp.x += to_sum.x;
	temp.y += to_sum.y;
	return temp;
}
vect2 vect2::operator-(const vect2& to_res) const
{
	vect2 temp = *this;
	temp.x -= to_res.x;
	temp.y -= to_res.y;
	return temp;
}
vect2& vect2::operator-()
{
	this->x = -this->x;
	this->y = -this->y;
	return *this;
}
bool vect2::operator!=(const vect2& no)
{
	if ((this->x != no.x) || (this->y != no.y))
	{
		return(true);
	}
	return false;
}
bool vect2::operator==(const vect2& yes)
{
	if (this == &yes)
	{
		return true;
	}
	return false;
}