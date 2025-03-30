# Algorithm and Problem Statement
From Macaulay, we have the following theorem which establishes the condition for a Hilbert Polynomial.
A polynomial $p(x)\in \mathbb{Q}[x]$ is a Hilbert polynomial if and only if $p(x)$ can be written
in the form $p(x)=\sum_{i\in1,2,\dots,r}\binom{x+\lambda_{i}-i}{\lambda_{i}-1}$ for some
integer sequence $\lambda_{1}\geq\lambda_{2}\geq\dots\geq\lambda_{r}\geq 1$.

That is, if you have a positive non-increasing integer sequence you can generate a Hilbert polynomial.
However, if you simply have a polynomial $p(x)\in\mathbb{Q}[x]$ how do you efficiently classify if it's
a Hilbert polynomial and if so, recover the non-increasing positive integer sequence associated with it?
The C++ library in this repository solves such problem efficiently and reliably.

# Usage
To solve the above problem, this library provides two functions.
```
std::vector<uint64_t> getLambdaFromSequence(mpz_t* const seq, const uint64_t& len, const PascalsTriangle& pt);
std::vector<uint64_t> getLambdaFromPolynomial(const Polynomial& poly, const PascalsTriangle& pt);
```
In both methods, one will notice that they expect a `PascalsTriangle` object.  This is so that if a user
intends on doing large and/or many numerical experments they only need to cache Pascals Triangle one time
by initializing the object once before the experiment or at the beginning of the program.
The depth of Pascals Triangle can be adjusted before compilation in `src/constants.hpp`.  By default, the depth
is set to 50.  If the depth of Pascals Triangle is not large enough for a particular program, then it exists with
an error message.
```
PascalsTriangle pt;
```
In the first method, the user provides the interpolated values of a polynomial in an array `mpz_t* const seq`
with number of elements `const uint64_t& len`.

In the second method, the user provides a `Polynomial` object which represents a polynomial in $\mathbb{Q}[x]$.
The `Polynomial` methods that the user should be concerned with are the following.
```
Polynomial(const uint64_t& num_terms_);
void reInit(const uint64_t& num_terms_);
void setCoefficient(const uint64_t& i, const char* str);
void setDegree(const uint64_t& i, const uint64_t& d);
uint64_t getDegree();
```
To construct a `Polynomial` object the user must provide an integer `num_terms_` which is the number of
terms in the polynomial.  The member function `reInit(const uint64_t& num_terms_)` clears the existing polynomial
and reinitializes it with a new number of terms `num_terms_`.  To set the coefficients, one can employ the
`setCoefficient(const uint64_t& i, const char* str)` member function which sets the coefficient of the `i`th term.
The second parameter `const char* str` sets the `mpq_t` object representing the coefficient by employing
`mpq_set_str(mpq_t rop, const char *str, int base)` as defined in the GMP manual but with `base` set to zero.
The member function `setDegree(const uint64_t& i, const uint64_t& d)` sets the degree of the `i`th term to `d`.
The member function `getDegree()` simply returns the degree of the polynomial.

For both methods `getLambdaFromSequence` and `getLambdaFromPolynomial` they return an empty vector if the polynomial
is not a Hilbert Polynomial and returns a positive non-increasing integer sequence of the form
$\lambda_{1}\geq\lambda_{2}\geq\dots\geq\lambda_{r}\geq 1$ if it is a Hilbert Polynomial.

# Building
To build the library, one must first provide the gmp installation and install prefix paths via the following command.
```
./configure -g <gmp installation directory> -p <install prefix>
```
From here, to install `libgetlambda.a` in `<install prefix>/lib` with header files in `<install prefix>/include` run the following.
```
make
```
Once building is done, the following command will run unit tests and put the test executable in `<install prefix>/test`.
```
make test
```
To clean the build enviornment run the following.
```
make clean
```
# Dependencies
GNU Multi-Precision library: [GMP](https://gmplib.org)
