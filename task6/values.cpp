#include "values.h"

Cvalue Cvalue::operator+(const Cvalue& rhs) const
{
	return Cvalue(value + rhs.getValue());
}

Cvalue Cvalue::operator%(const Cvalue& rhs) const
{
	return Cvalue((value + rhs.getValue()) / (value * rhs.getValue()));
}

Qvalue Cvalue::operator*(const Uvalue& u) const
{
	return Qvalue(getValue() * u.getValue());
}

std::ostream& operator<<(std::ostream& os, const Cvalue& c)
{
	os << c.getValue() << " F";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Tvalue& c)
{
	os << c.getValue() << " sec";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Qvalue& c)
{
	os << c.getValue() << " C";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Uvalue& c)
{
	os << c.getValue() << " V";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Rvalue& c)
{
	os << c.getValue() << " Ohm";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Ivalue& c)
{
	os << c.getValue() << " A";
	return os;
}

Qvalue Tvalue::operator*(const Ivalue& i) const
{
	return i * (*this);
}

Ivalue Qvalue::operator/(const Tvalue& t) const
{
	return Ivalue(getValue() / t.getValue());
}

Tvalue Qvalue::operator/(const Ivalue& i) const
{
	return Tvalue(getValue() / i.getValue());
}

Cvalue Qvalue::operator/(const Uvalue& u) const
{
	return Cvalue(getValue() / u.getValue());
}

Uvalue Qvalue::operator/(const Cvalue& c) const
{
	return Uvalue(getValue() / c.getValue());
}

Ivalue Uvalue::operator/(const Rvalue& r) const
{
	return Ivalue(getValue() / r.getValue());
}

Rvalue Uvalue::operator/(const Ivalue& i) const
{
	return Rvalue(getValue() / i.getValue());
}

Qvalue Uvalue::operator*(const Cvalue& c) const
{
	return c * (*this);
}

Rvalue Rvalue::operator+(const Rvalue& rhs) const
{
	return Rvalue(value + rhs.getValue());
}

Rvalue Rvalue::operator%(const Rvalue& rhs) const
{
	return Rvalue((value + rhs.getValue()) / (value * rhs.getValue()));
}

Uvalue Rvalue::operator*(const Ivalue& i) const
{
	return Uvalue(getValue() * i.getValue());
}

Uvalue Ivalue::operator*(const Rvalue& r) const
{
	return r * (*this);
}

Qvalue Ivalue::operator*(const Tvalue& t) const
{
	return Qvalue(getValue() * t.getValue());
}