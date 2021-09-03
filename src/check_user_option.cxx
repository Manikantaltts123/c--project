/**
 * @file check_user_option.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which checks the validity of user option in the restaurant
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "CubeEatery.h"

/**
 * @brief Function which checks the validity of user option in the restaurant, returns error code according to user_option
 * @version 0.1
 * 
 * @param user_option 
 * @return error_code 
 */
error_code check_user_option(int user_option)
{
    if(user_option==1||user_option==2)
    return VALID;
    else
    {
    std::cout<<"Entered option is incorrect"<<std::endl;
    return INVALID;
    }
}