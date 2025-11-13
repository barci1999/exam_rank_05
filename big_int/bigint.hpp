#pragma once
# include <string>
# include <stdexcept>
# include <sstream>
# include <iostream>
class bigint
{
	private:
		std::string _str;
	public:
		bigint();
		bigint(unsigned int);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);
		~bigint();

		std::string getStr() const;
		void validate();


		bigint& operator<<=(unsigned int);

		bigint operator+(const bigint& obj) const;
		bigint& operator+=(const bigint& obj);

		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(unsigned int nbr) const;
		bigint& operator>>=(const bigint& obj);

		bool operator<(const bigint& obj);
		bool operator>(const bigint& obj);
		bool operator==(const bigint& obj);
		bool operator!=(const bigint& obj);
		bool operator<=(const bigint& obj);
		bool operator>=(const bigint& obj);
};
std::ostream& operator<<(std::ostream& out,const bigint& to_print);