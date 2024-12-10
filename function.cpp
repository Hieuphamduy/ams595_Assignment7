#include <exception>
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <iomanip>

bool ifprime(int n){
    if(n <= 1) return 0;
    int div{2};
    // we only check for odd number since
    // other than 2, all prime numbers are odd
    while(div*2 <= n){
        if(n%div == 0) return 0;
        div +=(div==2)?1:2;
    }
    return 1;
}
void test_isprime() {
    std::cout << "isprime(2) = "  << ifprime(2)  << std::endl;
    std::cout << "isprime(10) = " << ifprime(10) << std::endl;
    std::cout << "isprime(17) = " << ifprime(17) << std::endl;
}
void conditional_statements(){
    std::cout << "Enter a number: ";
    std::string numStr;
    std::cin >> numStr;
    try{
        int num = std::stoi(numStr);
        switch(num){
            case -1:
                std::cout << "negative one\n";
                break;
            case 0:
                std::cout << "zero\n";
                break;
            default:
                std::cout << "other value\n";
        }
    }
    catch (const std::exception e){
        std::cout << "Input must be in numerical form\n";
    }
}

void print_vector(std::vector<int> v) {
    for(const auto& e: v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

std::vector<int> fibonacci(int e = 1){
    std::vector<int> ret;
    int prev{1};
    while(e <= 4e+6){
        ret.push_back(e);
        e +=prev;
        prev = e - prev;
    }
    return ret;
}


std::vector<int> factorize(int n){
    if(n <= 1) return std::vector<int>(1,1);
    std::vector<int> ret;
    for(int i = 1; i <= n;i++){
        if(n%i == 0) ret.push_back(i);
    }
    return ret;
}

void test_factorize() {
    std::vector<int> nums{2,72,196};
    for(const auto& n:nums){
        std::cout << "factors of " << n << " = ";
        print_vector(factorize(n));
    }
}

std::vector<int> prime_factorize(int n){
    if(n <= 1) return std::vector<int>();
    if(ifprime(n)) return std::vector<int>(1,n);
    std::vector<int> ret;
    for(int i = 1; i <= n/2;i++){
        if(ifprime(i) && n%i == 0) ret.push_back(i);
    }
    return ret;
}

void test_prime_factorize() {
    std::vector<int> nums{2,72,196};
    for(const auto& n:nums){
        std::cout << "prime factors of " << n << " = ";
        print_vector(prime_factorize(n));
    }
}

std::vector<std::vector<int> > pascal(unsigned long n){
    std::vector<std::vector<int> > ret;

    /*
        Base cases
            return empty list if n = 0
            return [1] is n = 1
    */
    if(n <= 0) return ret;
    else if (n == 1){
        ret.push_back(std::vector<int>(1,1));
        return ret;
    }
    ret = pascal(n-1);
    std::vector<int> lastRow(ret[n-2]);
    std::vector<int> newLastRow;

    /*
        Notice the pattern
        e.g.: 2nd row ([1,1]) -> 3rd row ([1,2,1])
         [1,1,0]
        +[0,1,1]
        ---------
         [1,2,1]
        Same pattern can be applied when upgrading from nth to (n+1)th row
    */
    for(unsigned long i = 0; i < n; i++){
        if(i == 0 || i == n-1){
            newLastRow.push_back(1);
        }
        else{
            newLastRow.push_back(lastRow[i] + lastRow[i-1]);
        }
    }
    ret.push_back(newLastRow);
    return ret;
}

// Function to print a matrix
void printMatrix(const std::vector<std::vector<int> > &matrix) {
    for (const auto &row : matrix) {
        for (int  val : row)
            std::cout << val << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
