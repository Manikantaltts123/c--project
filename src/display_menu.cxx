/**
 * @file display_menu.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which displays menu
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "CubeEatery.h"

/**
 * @brief Function which displays the menu according to the user choice of restaurant
 * 
 * @param user_option 
 * @param cs_map 
 * @param item_vector 
 */
void display_menu(int user_option, std::map<int,std::string>& cs_map, std::vector<Item>& item_vector)
{
    std::fstream fin;
    std::string line,strings[4];
    fin.open(cs_map[user_option], std::ios::in);
    while(getline(fin, line))
    {
        int curr_index = 0, i = 0;  
        int start_index = 0, end_index = 0;
        while (i <= line.size())  
        {
            /**
             * @brief Split the csv line into various elements
             * 
             */
            if (line[i] == ','|| i== line.size())  
            {  
                end_index = i;  
                std::string subStr = "";  
                subStr.append(line, start_index, end_index - start_index);  
                strings[curr_index] = subStr;  
                curr_index += 1;  
                start_index = end_index + 1;  
            }  
        i++;  
        }
        /**
         * @brief Store the seperated elements in a vector
         * 
         */
        item_vector.emplace_back(strings[0],strings[1],strings[2],stoi(strings[3]));
    }

    /**
     * @brief Display menu
     * 
     */
    std::cout<<std::left
            <<std::setw(30)<<"Item ID"
            <<std::setw(30)<<"Item Name"
            <<std::setw(30)<<"Item Size"
            <<std::setw(30)<<"Item Cost(in Rs)"<<std::endl;
    for(int i_values=0;i_values<item_vector.size();i_values++)
    {
         std::cout<<std::left
         <<std::setw(30)<<item_vector[i_values].get_item_id()
         <<std::setw(30)<<item_vector[i_values].get_item_name()
         <<std::setw(30)<<item_vector[i_values].get_item_size()
         <<std::setw(30)<<item_vector[i_values].get_item_cost()<<std::endl;
    }
}
