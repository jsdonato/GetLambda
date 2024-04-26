gcc -std=c++11 -O3 \
-I/Users/a068432/Documents/gmp-6.3.0/include \
-L/Users/a068432/Documents/gmp-6.3.0/lib \
../src/Pascal.cpp \
../src/Polynomial.cpp \
../src/Utility.cpp \
../src/GetLambda.cpp \
testPascal.cpp \
testPolynomial.cpp \
main.cpp \
-o tests -lgmp -lstdc++
