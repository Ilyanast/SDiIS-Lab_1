class Fraction
{
public:
	Fraction(int numerator, int denominator);
	int get_numerator();
	int get_denominator();
	int get_integer_part();
	double to_double();
	Fraction operator + (Fraction& other_fraction);
	Fraction operator + (int other_int);
	void operator += (Fraction& other_fraction);
	void operator += (int other_int);
	Fraction operator - (Fraction& other_fraction);
	Fraction operator - (int other_int);
	void operator -= (Fraction& other_fraction);
	void operator -= (int other_int);
	Fraction operator * (Fraction& other_fraction);
	Fraction operator * (int other_int);
	void operator *= (Fraction& other_fraction);
	void operator *= (int other_int);

private:
	Fraction multiplication_of_fractions(Fraction& other_fraction);
	Fraction difference_of_fractions(Fraction& other_fraction);
	Fraction sum_of_fractions(Fraction& other_fraction);
	Fraction int_to_fraction(int number_to_translate);
	void multiply_by_current_fraction(Fraction& other_fraction);
	void add_to_current_fraction(Fraction& other_fraction);
	void remove_from_current_fraction(Fraction& other_fraction);
	void reduce_numbers(int& numerator, int& denominator);
	void to_common_denominator(Fraction& other_fraction);
	int get_gcd(int first_number, int second_number);
	int get_lcm(int first_number, int second_number);
	bool check_for_correct_input_data(int& numerator, int& denominator);

	int numerator;
	int denominator;
};