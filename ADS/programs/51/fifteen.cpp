/*
Given a polynomial as a string and a value. Evaluate polynomial’s derivative for the given value.
Note: The input format is such that there is a white space between a term and the ‘+’ symbol

The derivative of p(x) = ax^n is p'(x) = a*n*x^(n-1)
Also, if p(x) = p1(x) + p2(x)
Here p1 and p2 are polynomials too
p'(x) = p1′(x) + p2′(x)

Input : 3x^3 + 4x^2 + 6x^1 + 89x^0
        2
Output :58

Explanation : Derivative of given
polynomial is : 9x^2 + 8x^1 + 6 Now put x = 2, 9*4 + 8*2 + 6 = 36 + 16 + 6 = 58

Input : 1x^3
        3
Output : 27

*/


// C++ program to find value of derivative of a polynomial.
#include <bits/stdc++.h>
using namespace std;

long long derivativeTerm(string pTerm, long long val)
{
	// Get coefficient
	string coeffStr = "";
	int i;
	for (i = 0; pTerm[i] != 'x'; i++)
		coeffStr.push_back(pTerm[i]);
	long long coeff = atol(coeffStr.c_str());

	// Get Power (Skip 2 characters for x and ^)
	string powStr = "";
	for (i = i + 2; i != pTerm.size(); i++)
		powStr.push_back(pTerm[i]);
	long long power = atol(powStr.c_str());

	// For ax^n, we return anx^(n-1)
	return coeff * power * pow(val, power - 1);
}

long long derivativeVal(string& poly, int val)
{
	long long ans = 0;

	// We use istringstream to get input in tokens
	istringstream is(poly);

	string pTerm;
	while (is >> pTerm) {

		// If the token is equal to '+' then
		// continue with the string
		if (pTerm == "+")
			continue;


		// Otherwise find the derivative of that particular term
		else
			ans = (ans + derivativeTerm(pTerm, val));
	}
	return ans;
}

int main()
{
	string str = "4x^3 + 3x^1 + 2x^2";
	int val = 2;
	cout << derivativeVal(str, val);
	return 0;
}

/*

The derivativeTerm function is defined to calculate the derivative of a single term of the polynomial. It takes two arguments: pTerm (a string representing a term) and val (the value at which the derivative is calculated).

It extracts the coefficient and power parts of the term from the string.

Then, it uses the power rule of differentiation to calculate the derivative of the term (coeff * power * val^(power-1)).

The derivativeVal function is defined to calculate the value of the derivative of the entire polynomial expression. It takes two arguments: poly (a string representing the polynomial) and val (the value at which the derivative is calculated).

It initializes ans to 0 to accumulate the derivative values.

The istringstream is is used to tokenize the polynomial expression.

The function iterates through the terms and calculates the derivative for each term using the derivativeTerm function. The derivative values are added to ans.

*/


