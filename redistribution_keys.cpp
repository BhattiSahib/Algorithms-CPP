#include <iostream>
#include <unordered_map>


int main()
{

    int num_of_keys, num_of_pwds;
    double tolerance;

    std::cout << "Enter the number of keys: ";
    std::cin >> num_of_keys;
    std::cout << "Enter the total number of passwords: ";
    std::cin >> num_of_pwds;
    std::cout << "Enter the tolerance value: ";
    std::cin >> tolerance;

    int input_table[num_of_keys][num_of_pwds];

    int temp_pwd;

    std::unordered_map<int, int> keyCounts;

    for(int i = 0; i < num_of_keys; i++)
    {
        std::cout << "Enter the initial number of passwords for key ==> "<< i << " :: ";
        std::cin >> temp_pwd;
        keyCounts[i] = temp_pwd;
    }

    int target = num_of_pwds / num_of_keys;

    // Initialize keyCounts with the current counts of passwords per key
    // and determine the number of moves needed to rebalance the load
    int moves = 0;
    for (int i = 0; i < num_of_keys; i++) {
        int count = keyCounts[i];
        if (count > target * (1 + tolerance)) {
            moves += count - target*(1 + tolerance);
        }
        else if(count < target * (1 - tolerance))
        {
            moves += target*(1 - tolerance) - count;
        }
    }

    std::cout << "Initial counts: ";
    for (auto &itr : keyCounts)
    {
        std::cout << itr.first << "::" << itr.second << " ";
    }
    std::cout << std::endl;

    // Perform moves to rebalance the load
    for (int i = 0; i < num_of_keys && moves > 0; i++)
    {
        int count = keyCounts[i];
        if (count > target * (1 + tolerance))
        {
            for (int j = 0; j < num_of_keys && moves > 0; j++)
            {
                int otherCount = keyCounts[j];
                if (otherCount < target * (1 - tolerance))
                {
                    int moveCount = std::min(count - target, target - otherCount);
                    keyCounts[i] -= moveCount;
                    keyCounts[j] += moveCount;
                    moves -= moveCount;
                    std::cout << "Moves " << moveCount << " from key" << i << " to key" << j << std::endl;
                }
            }
        }
    }


    std::cout << "Final counts: ";
    for (auto &itr : keyCounts)
    {
        std::cout << itr.first << "::" << itr.second << " ";
    }
    return 0;
}

