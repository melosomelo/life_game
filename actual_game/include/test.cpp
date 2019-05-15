#include "cell.h"
#include "generation.h"
#include "all_generations.h"
#include <vector>
#include <iostream>



int main()
{
    Cell cell01;
    cell01.alive = true;
    cell01.x = 3;
    cell01.y = 5;
    cell01.alive_next_state = false;
    cell01.checked = true;
    auto cell02 = cell01;
    auto result = cell01 == cell02;
    std::cout << result;
    std::vector<int> v = {1,2,3,4,5};
    std::vector<std::vector<int>>v_v;
    v_v.push_back(v);
    std::cout << v_v[0][0];


}