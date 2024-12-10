#include <iostream>
#include "function.cpp"

#define LINE 50
int main(int argc, char** argv){
    int question{0};
    if(argc > 1) question = std::stoi(argv[1]);

    switch(question){
        case 0:
        case 1:
            std::cout << std::endl << "1 Conditional Statements (10 Points)"
                    << std::endl << std::string(LINE,'-') << std::endl;
            conditional_statements();
            if(question) break;
        case 2:
        case 3:
            std::cout << std::endl << "2 + 3 Printing a Vector and While Loop (10 + 15 points)"
                        << std::endl << std::string(LINE,'-') << std::endl;
            std::cout << "all elements of the Fibonacci sequence whose values do not exceed 4,000,000:\n";
            print_vector(fibonacci());
            if(question) break;
        case 4:
            std::cout << std::endl << "4.1 If Prime (10 Points)"
                        << std::endl << std::string(LINE,'-') << std::endl;
            test_isprime();

            std::cout << std::endl << "4.2 Factorize (10 Points)"
                        << std::endl << std::string(LINE,'-') << std::endl;
            test_factorize();

            std::cout << std::endl << "4.3 Prime Factorization (10 Points)"
                        << std::endl << std::string(LINE,'-') << std::endl;
            test_prime_factorize();
            if(question) break;
        case 5:
            std::cout << std::endl << "5 Recursive Functions and Loops (25 Points)"
                        << std::endl << std::string(LINE,'-') << std::endl;
            unsigned long n{5};
            std::cout << "Pascal’s Triangle of " << n << " rows\n";
            printMatrix(pascal(n));
            if(question) break;
    }
}
