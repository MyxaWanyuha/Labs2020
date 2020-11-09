#include <ostream>

class BaseValue
{
public:
	BaseValue(double val) : value(val) {}
	double getValue() const noexcept { return value; }
protected:
	double value;
};

class Cvalue;
class Tvalue;
class Qvalue;
class Uvalue;
class Ivalue;
class Rvalue;

class Cvalue : public BaseValue
{
public:
	explicit Cvalue(double val) : BaseValue(val) {}
	Cvalue operator+(const Cvalue& rhs) const;
	Cvalue operator%(const Cvalue& rhs) const;
	Qvalue operator*(const Uvalue& u) const;
	friend std::ostream& operator<<(std::ostream& os, const Cvalue& c);
};

class Tvalue : public BaseValue
{
public:
	explicit Tvalue(double val) : BaseValue(val) {}
	Qvalue operator*(const Ivalue& i) const;
	friend std::ostream& operator<<(std::ostream& os, const Tvalue& c);
};

class Qvalue : public BaseValue
{
public:
	explicit Qvalue(double val) : BaseValue(val) {}
	Ivalue operator/(const Tvalue& t) const;
	Tvalue operator/(const Ivalue& i) const;
	Cvalue operator/(const Uvalue& u) const;
	Uvalue operator/(const Cvalue& c) const;
	friend std::ostream& operator<<(std::ostream& os, const Qvalue& c);
};

class Uvalue : public BaseValue
{
public:
	explicit Uvalue(double val) : BaseValue(val) {}
	Ivalue operator/(const Rvalue& r) const;
	Rvalue operator/(const Ivalue& i) const;
	Qvalue operator*(const Cvalue& c) const;
	friend std::ostream& operator<<(std::ostream& os, const Uvalue& c);
};

class Rvalue : public BaseValue
{
public:
	explicit Rvalue(double val) : BaseValue(val) {}
	Rvalue operator+(const Rvalue& rhs) const;
	Rvalue operator%(const Rvalue& rhs) const;
	Uvalue operator*(const Ivalue& i) const;
	friend std::ostream& operator<<(std::ostream& os, const Rvalue& c);
};

class Ivalue : public BaseValue
{
public:
	explicit Ivalue(double val) : BaseValue(val) {}
	Uvalue operator*(const Rvalue& r) const;
	Qvalue operator*(const Tvalue& t) const;
	friend std::ostream& operator<<(std::ostream& os, const Ivalue& c);
};

