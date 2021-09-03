/**
 * @file generate_file_map.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which generates map for csv files 
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"CubeEatery.h"

/**
 * @brief Function which generates map for csv files with various user options
 * 
 * @param cs_map 
 */
void generate_file_map(std::map<int,std::string>& cs_map)
{
    cs_map[1]="Dominos_Menu.csv";
    cs_map[2]="McDonalds_Menu.csv";
}