#include <automobile>

#include <iostream>

void test_bs() {
    using namespace std;

    double x{1.96}, spot{273},  rate_base{0.01}, rate_term{0.03},  maturity{0.5},  strike{275};

    cout << bs::std_normal_density(x) << endl;
    cout << bs::cumulative_normal_distribution(x) << endl;
    cout << bs::forward(spot, rate_base, rate_term, maturity) << endl;
    cout << bs::blackscholes(spot, rate_base, rate_term, maturity, strike) << endl;
}

int main() {

    vehicles::Motorcycle c("Yamaha");
    std::cout << "Made a car called: " << c.get_name() << std::endl;
    c.ride("mullholland");

    double x = 5.5;
    std::cout << bs::std_normal_density(x) << std::endl;
    test_bs();
    return 0;
}
