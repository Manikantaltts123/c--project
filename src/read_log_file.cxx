/**
 * @file read_log_file.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which reads the log file
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "CubeEatery.h"

/**
 * @brief Function which reads log file and stores the data in cus vector
 * 
 * @param cus 
 */
void read_log_file(std::vector<Customer> &cus)
{
    std::fstream fin;
    std::string line,strings[2];
    fin.open("logfile.csv", std::ios::in);
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
            if (line[i] == ','||i==line.size())  
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
        cus.emplace_back(strings[0],strings[1].substr(1,strings[1].size()));
    }
}
