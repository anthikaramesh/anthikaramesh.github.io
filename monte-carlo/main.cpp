#include <iostream>
#include <random>
#include <cmath>
#include <vector>

int main() {
    // Parameters
    double S0 = 100.0;      // Initial stock price
    double mu = 0.05;       // Expected return (5%)
    double sigma = 0.2;     // Volatility (20%)
    double T = 1.0;         // Time horizon (1 year)
    int steps = 252;        // Trading days in a year
    int paths = 5;          // Number of simulations (keep small for now)
    
    double dt = T / steps;  // Time step
    
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    
    // Simulate paths
    for (int p = 0; p < paths; p++) {
        double S = S0;
        std::cout << "Path " << p + 1 << ": " << S;
        
        for (int i = 0; i < steps; i++) {
            double Z = d(gen);
            S = S * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
        }
        
        std::cout << " -> " << S << std::endl;
    }
    
    return 0;
}