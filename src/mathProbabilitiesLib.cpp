#include <iostream>
#include <vector>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

#include "mathProbabilitiesLib.hpp"

// -------- Math utilities -------------

long factorial(const int n)
{
    long f = 1;
    for (int i = 1; i <= n; ++i)
        f *= i;
    return f;
}

int binomialCoefficient(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

// ---------- Probability distributions -----------

// Basic random number generator, between 0 and 1 (prerequisite)
double sampleRandomBetweenZeroAndOne()
{
    static std::random_device rd;                   // obtain a random number from hardware
    static std::mt19937 gen(rd());                  // seed the generator ; use rand() if mingw doesnt work well with rd
    std::uniform_real_distribution<> distr(0., 1.); // define the range
    return distr(gen);                              // generate numbers
}

// Uniform CONTINUOUS generator
float sampleUniformContinuous(float min, float max)
{
    return sampleRandomBetweenZeroAndOne() * (max - min) + min;
}

// Bernoulli
int sampleBernoulli(float p)
{
    double randNb = sampleRandomBetweenZeroAndOne();
    if (randNb <= p)
    {
        return 1;
    }
    return 0;
}

// Poisson
float poisson(float lambda, float k)
{ // probability P(X=k)
    return exp(-lambda) * pow(lambda, k) / factorial(k);
}

float samplePoisson(float lambda)
{ // sample generator
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    double k = 0;

    while (i <= randNb)
    {
        i += poisson(lambda, k);
        k += 1;
    }

    return k;
}

// Geometric
float geometric(float p, float k)
{ // probability P(X=k)
    return p * (pow(1 - p, k - 1));
}

float sampleGeometric(float p)
{ // sample generator
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    double k = 1;

    while (i <= randNb)
    {
        i += geometric(p, k);
        k += 1;
    }

    return k;
}

// Binomial
float binomial(int n, float p, int k)
{ // probability P(X=k)
    return binomialCoefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
}

int sampleBinomial(int n, float p)
{ // sample generator
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    int k = 0;

    while (i <= randNb && k < n)
    {
        i += binomial(n, p, k);
        k += 1;
    }

    return k;
}

// Probabilty (%)

bool probabilityPercent(float q) { return sampleUniformContinuous(0, 100) < q; }
