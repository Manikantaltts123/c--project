/**
 * @file calculate_final_price.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which calculates final price of customer 
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "CubeEatery.h"

/**
 * @brief Function which calculates price of the users order
 * 
 * @param price_map 
 * @return float final price of user
 */
float calculate_final_price(std::map<std::string,std::vector<Bill>>& price_map)
{
    int final_price=0;
    std::map<std::string,std::vector<Bill>>::iterator it;
    for(it=price_map.begin();it!=price_map.end();++it)
    {
        final_price+=it->second[0].getprice();
    }
    return final_price;
}
