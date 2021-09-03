/**
 * @file calculate_price.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Calculate price of user's order
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "CubeEatery.h"

/**
 * @brief Calculate price of user according to his option 
 * 
 * @param option 
 * @param units
 * @param price_map 
 */
void calculate_price(std::string option, int units, std::map<std::string,std::vector<Bill>>& price_map)
{
    std::map<std::string,std::vector<Bill>>::iterator it =price_map.find(option);
    it->second[0].setoccurances(units);
    it->second[0].increment_cost();
}
    