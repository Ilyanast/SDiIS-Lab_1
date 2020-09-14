class Fraction
{
public:
	Fraction(int numerator, int denominator);
	int get_numerator();
	int get_denominator();
	int get_integer_part();
	Fraction operator + (Fraction& other);

private:
	void reduce_fraction(int& numerator, int& denominator);
	int get_gcd(int first_number, int second_number);
	int get_lcm(int first_number, int second_number);

	int numerator;
	int denominator;
};