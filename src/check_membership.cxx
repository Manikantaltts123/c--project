/**
 * @file check_membership.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Function which validates the membership of user
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "CubeEatery.h"
/**
 * @brief Function which returns true when the user is existing memeber; false if the user is not
 * 
 * @param cus 
 * @param name 
 * @param mobile 
 * @return true if user have membership
 * @return false if user does'nt have membership
 */
bool check_membership(std::vector<Customer> &cus, const std::string& name, const std::string& mobile)
{
  for(int j_values=0;j_values<cus.size();j_values++)
  {
      if((cus[j_values].getname()==name && cus[j_values].getmobilenumber()== mobile));
      return true;
  }
  return false;
}
