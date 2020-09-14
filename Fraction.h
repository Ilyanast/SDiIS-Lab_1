class Fraction
{
public:
	Fraction(int numerator, int denominator);
	int get_numerator();
	int get_denominator();
	int get_integer_part();
	double to_double();
	Fraction operator + (Fraction& other);
	Fraction operator + (int other_int);
	void operator += (Fraction& other);
	void operator += (int other_int);

private:
	Fraction sum_of_fractions(Fraction& other);
	Fraction int_to_fraction(int number_to_translate);
	void add_to_current_fraction(Fraction& other);
	void reduce_fraction(int& numerator, int& denominator);
	void to_common_denominator(Fraction& other);
	int get_gcd(int first_number, int second_number);
	int get_lcm(int first_number, int second_number);
	bool check_for_correct_input_data(int& numerator, int& denominator);

	int numerator;
	int denominator;
};