/**
 * @file generate_price_map.cxx
 * @author Manikanta Suri (manikanta.suri%ltts.com)
 * @brief  Generate price map according to its ID
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "CubeEatery.h"

/**
 * @brief Generate price map 
 * 
 * @param item_vector 
 * @param price_map 
 */
void generate_price_map(std::vector<Item>& item_vector,std::map<std::string,std::vector<Bill>>& price_map)
{
    for(int i_values=0;i_values<item_vector.size();i_values++)
    {
        price_map[item_vector[i_values].get_item_id()].emplace_back(item_vector[i_values].get_item_id(),item_vector[i_values].get_item_name(),
                                                           item_vector[i_values].get_item_size(),item_vector[i_values].get_item_cost());                   
    }
    
}