#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

void printArguments(string S, unsigned int seed, double target, unsigned int nfesLmt, unsigned int runtimeLmt, unsigned int Np) {
    cout << "Zaporedje aminokislin: " << S << endl;
    cout << "Seed: " << seed << endl;
    cout << "Target: " << target << endl;
    cout << "Nfes Limit: " << nfesLmt << endl;
    cout << "Runtime Limit: " << runtimeLmt << endl;
    cout << "Populacija (Np): " << Np << endl;
    //printArguments(S,seed,target,nfesLmt,runtimeLmt,Np);
}

struct Solution {
    vector<double> theta;  // Koti theta
    vector<double> beta;   // Koti beta
    double energy;// Energija rešitve (zaenkrat jo postaviš na 0 ali naključno)
};

double random_double(double lower_bound, double upper_bound) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    uniform_real_distribution<> dis(lower_bound, upper_bound);
    return dis(gen);
}

void initialize_population(std::vector<Solution>& population, const unsigned population_size, const unsigned L) {
    for (int i = 0; i < population_size; ++i) {
        Solution sol;
        cout<<"THETA-----------------------------------------------------------------------------------"<<endl;
        // Inicializiraj kote theta z naključnimi vrednostmi med [-PI, PI]
        for (int j = 0; j < L - 2; ++j) {
            sol.theta.push_back(random_double(-M_PI, M_PI));
            //cout<<sol.theta[j]<<endl;
        }
        cout<<"BETA+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        // Inicializiraj kote beta z naključnimi vrednostmi med [-PI, PI]
        for (int j = 0; j < L - 3; ++j) {
            sol.beta.push_back(random_double(-M_PI, M_PI));
            cout<<sol.beta[j]<<endl;
        }

        // Nastavi začetno energijo na neko vrednost (zaenkrat 0)
        sol.energy = 0.0;

        // Dodaj rešitev v populacijo
        population.push_back(sol);
    }
}

int main(int argc, char* argv[]) {
    string S;
    unsigned int seed = 0;
    double target = 0.0;
    unsigned int nfesLmt = 0;
    unsigned int runtimeLmt = 0;
    unsigned int Np = 0;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]).find("S=") == 0) {
            S = string(argv[i]).substr(2);
        } else if (string(argv[i]) == "-seed") {
            seed = stoi(argv[++i]);
        } else if (string(argv[i]) == "-target") {
            target = stod(argv[++i]);
        } else if (string(argv[i]) == "-nfesLmt") {
            nfesLmt = stoi(argv[++i]);
        } else if (string(argv[i]) == "-runtimeLmt") {
            runtimeLmt = stoi(argv[++i]);
        } else if (string(argv[i]) == "-Np") {
            Np = stoi(argv[++i]);
        }
    }
    int L = S.length();
    srand(seed);
    std::vector<Solution> population;
    initialize_population(population, Np, L);
    for(int i = 0; i < population.size(); i++){
        cout<<population[i].energy<<endl;
        for(int j = 0; j<population[i].beta.size(); j++){
            cout<<population[i].beta[j]<<endl;
        }
        for(int j = 0; j<population[i].theta.size(); j++){
            cout<<population[i].theta[j]<<endl;
        }
    }


    return 0;
}
