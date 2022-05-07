#include <csignal>
#include <iostream>
#include <random>

namespace
{
    volatile sig_atomic_t flag = 1;
}

int main(int argc, char **argv)
{
    std::random_device rnd_seed;
    std::mt19937 rnd_engine(rnd_seed());
    std::uniform_int_distribution<> rnd_dist(100, 1001);
    unsigned long long int count = 0;

    std::signal(SIGINT, [](int signum){ flag = 0; });

    while (flag)
    {
        auto colors = rnd_dist(rnd_engine);
        std::cout << "白って" << colors << "色あんねん" << std::endl;
        count++;
    }
    std::cout << count << " 人のアンミカ" << std::endl;

    return 0;
}
