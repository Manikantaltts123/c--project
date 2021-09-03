/**
 * @file main.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Driver file for CubeEatery feature
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "CubeEatery.h"
int main()
{
    /**
     * Parameter declaration
     **/

    int user_option,units;
    float final_price;
    std::string option,user_name,user_mobile;
    char member_option,grant_option;
    bool is_member=false;
    error_code code;
    std::vector<Item>item_vector;
    std::vector<Customer>cus;
    std::map<int,std::string> csv_map;
    std::map<std::string,std::vector<Bill>>price_map;
    std::fstream fout;
    do
    {
        /**
         * @brief Display choices of restaurants to the user 
         * 
         */
    main_menu: std::cout<<"\t\t\t\t\t Welcome to Cube Eatery"<<std::endl;
    std::cout<<"\t\t\t\t\t Enter the option to drive to the restaurant"<<std::endl;
    std::cout<<"\t\t\t\t\t Option 1: Dominos"<<std::endl;
    std::cout<<"\t\t\t\t\t Option 2: McDonalds"<<std::endl;
    std::cout<<"\t\t\t\t\t Option 3: Exit"<<std::endl;
    std::cout<<"Enter option :";
    std::cin>>user_option;
    if(user_option==3)
    exit(0);
    code=check_user_option(user_option);
    }while(code!=0);

    if(code==1)
    {
        std::cout<<"Invalid option, Enter option again"<<std::endl;
        goto main_menu;
    }

    generate_file_map(csv_map);
    /**
     * @brief Display menu
     * 
     */
    display_menu(user_option,csv_map,item_vector);
    generate_price_map(item_vector,price_map);
    std::cout<<std::endl;
    std::cout<<"Place Order, enter yes to return main menu, exit to stop"<<std::endl;
    while(1)
    {
        /**
         * @brief Get the option from user, calculate price accordingly
         * 
         */
        std::cout<<"Enter item ID: ";
        std::cin>>option;
        std::cout<<std::endl;
        if(price_map.find(option)!=price_map.end())
        {
        std::cout<<"Enter the number of units of item: ";
        std::cin>>units;
        std::cout<<std::endl;
        calculate_price(option,units,price_map);
        }
        else if(!(option.compare("yes")))
        {
            goto main_menu;
        }
        else if(!(option.compare("exit")))
        {
            goto next;
        }
        else
        {
            std::cout<<"Invalid option entered"<<std::endl;
        }
    }
    
    next:final_price=calculate_final_price(price_map);

    /**
     * Requesting for membership to user
     **/

    std::cout<<"Are you existing memeber(y/n): ";
    std::cin>>member_option;
    std::cout<<std::endl;
    std::cout<<"Do you want membership, for membership you need to pay 1500 rs(y/n): ";
    std::cin>>grant_option;
    std::cout<<std::endl;
    if(member_option=='y')
    {
        read_log_file(cus);
        std::cout<<"Enter your details to validate membership"<<std::endl;
        std::cout<<"Enter your name: ";
        std::cin>>user_name;
        std::cout<<std::endl;
        std::cout<<"Enter 10 digit mobile number: ";
        std::cin>>user_mobile;
        is_member=check_membership(cus,user_name,user_mobile);
    }
    if(grant_option=='y')
    {
    fout.open("logfile.csv", std::ios::out | std::ios::app);
    std::cout<<"Enter your details to get new membership"<<std::endl;
    std::cout<<"Enter your name: ";
    std::cin>>user_name;
    std::cout<<std::endl;
    std::cout<<"Enter 10 digit mobile number: ";
    std::cin>>user_mobile;
    fout<<user_name<<", "
        <<user_mobile<<std::endl;
    fout.close();
    }
    /**
     * Display bill to user
     **/
    displaybill(price_map,final_price,is_member,grant_option);
    return 0;
}
