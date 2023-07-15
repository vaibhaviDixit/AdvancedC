/*
Create a base class NumberSeries with a method to generate the next term in the series.
Derive two classes FibonacciSeries and PrimeSeries from NumberSeries to generate the next Fibonacci number and the next prime number, respectively.
*/

#include <iostream>
#include <vector>

class NumberSeries {
public:
    virtual int generateNextTerm() = 0;
};

class FibonacciSeries : public NumberSeries {
private:
    int prev, curr;
public:
    FibonacciSeries() : prev(0), curr(1) {}

    int generateNextTerm() override {
        int next = prev + curr;
        prev = curr;
        curr = next;
        return next;
    }
};

class PrimeSeries : public NumberSeries {
private:
    std::vector<bool> isPrime;
    int num;
public:
    PrimeSeries() : num(2) {
        isPrime.resize(1000, true);
        isPrime[0] = isPrime[1] = false;
    }

    int generateNextTerm() override {
        while (true) {
            ++num;
            if (num >= isPrime.size())
                isPrime.resize(isPrime.size() * 2, true);

            if (isPrime[num]) {
                for (int i = num * 2; i < isPrime.size(); i += num) {
                    isPrime[i] = false;
                }
                return num;
            }
        }
    }
};

int main() {
    FibonacciSeries fibSeries;
    std::cout << "Fibonacci Series: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << fibSeries.generateNextTerm() << " ";
    }
    std::cout << std::endl;

    PrimeSeries primeSeries;
    std::cout << "Prime Series: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << primeSeries.generateNextTerm() << " ";
    }
    std::cout << std::endl;

    return 0;
}
