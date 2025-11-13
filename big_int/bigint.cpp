#include "bigint.hpp"
#include "stdlib.h"
bigint::bigint()
{
	this->_str = "0";
}
bigint::bigint(unsigned int  nbr)
{
	std::ostringstream os;
	os << nbr;
	this->_str = os.str();
	validate();
}
void bigint::validate()
{
	if (this->_str.empty())
	{
		exit(1);
	}
	int i = 0;
	while (this->_str[i] && this->_str[i] == '0')
	{
		i++;
	}
	this->_str.erase(0,i);
}
bigint::bigint(const bigint& other)
{
	this->_str = other._str;
}
bigint& bigint::operator=(const bigint& other)
{
	if (this == &other)
	{
		return *this;
	}
	this->_str = other._str;
	return *this;
}
bigint::~bigint(){}
bigint& bigint::operator<<=(unsigned int n)
{
	if (this->_str == "0")
	{
		return *this;
	}
	
	this->_str.append(n,'0');
	return *this;
}
bigint bigint::operator+(const bigint& obj) const
{
	std::string a = this->_str;
	std::string b = obj._str;
	std::string res = "";

	int i = a.size() - 1;
	int j = b.size() - 1;
	int me_llevo = 0;

	while (i >= 0 || j >= 0 || me_llevo)
	{
		int da = (i >= 0) ? a[i] - '0' : 0 ;
		int db = (j >= 0) ? b[j] - '0' : 0 ;

		int sum = da + db + me_llevo;
		me_llevo = sum /10;
		res.insert(res.begin(),char(sum % 10) + '0');
		j--;
		i--;
	}
	bigint temp;
	temp._str = res;
	return temp;
}
bigint& bigint::operator+=(const bigint& obj)
{
	*this = *this + obj;
	return *this;
}
bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}
bigint bigint::operator++(int)
{
	bigint temp(*this);
	*this += bigint(1);
	return temp;
}
bigint bigint::operator<<(unsigned int nbr) const
{
	bigint temp(*this);
	temp._str.append(nbr,'0');
	return temp;
}
static unsigned long long str_to_ull(std::string to_chage)
{
	unsigned long long res = 0;
	if (to_chage.empty())
	{
		return 0;
	}
	for (size_t i = 0; i < to_chage.size(); i++)
	{
		res = res * 10 + to_chage[i] -'0';
	}
	return res;
	
}
bigint& bigint::operator>>=(const bigint& obj)
{
	unsigned long long res = str_to_ull(obj._str);
	unsigned long long i = this->_str.size() -1;
	if (res >= i)
	{
		this->_str ="0";
		return *this;
	}
	this->_str.erase(this->_str.size() - res, this->_str.size());
	return *this;

}
bool bigint::operator<(const bigint& obj)
{
	if ((this->_str.size() < obj._str.size()) && (this->_str < obj._str))
	{
		return true;
	}
	return false;
	
}
bool bigint::operator>(const bigint& obj)
{
	return !(*this < obj);
}
bool bigint::operator==(const bigint& obj)
{
	if (this == &obj)
	{
		return true;
	}
	return false;
}
bool bigint::operator!=(const bigint& obj)
{
	if (this == &obj)
	{
		return false;
	}
	return true;
}
bool bigint::operator<=(const bigint& obj)
{
	if ((this < &obj) || this == &obj)
	{
		return true;
	}
	return false;
	
}
bool bigint::operator>=(const bigint& obj)
{
	if ((this >&obj) || this == &obj)
	{
		return true;
	}
	return false;
}
std::string bigint::getStr() const
{
	return this->_str;
}
std::ostream& operator<<(std::ostream& out, const bigint& to_print)
{
	out << to_print.getStr();
	return out;
}