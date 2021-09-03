/**
 * @file CubeEatery.h
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief Header file for CubeEatery feature
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _CUBEEATERY_H_ 
#define _CUBEEATERY_H_
/**
 * Include necessary header files
 */
#include<map>
#include<vector>
#include<iterator>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

/**
 * @brief Customer Class Definition
 * 
 */
class Customer
{
    std::string name;
    std::string ph_no;
    public:
    Customer(std::string person_name = " ", std::string mobile_no=""): name{person_name}, ph_no{mobile_no}{}
    std::string getname() {return name;}
    std::string getmobilenumber() {return ph_no;}
};

/**
 * @brief Item class definiton
 * 
 */
class Item
{
    protected:
    std::string item_id;
    std::string item_name;
    std::string size;
    int item_cost;
    public:
    Item(std::string id = " ", std::string it_name = " ",  std::string size = " ", int cost = 0): item_id{id}, item_name{it_name},size {size}, item_cost{cost}{}
    std::string get_item_id() {return item_id;}
    std::string get_item_name() {return item_name;}
    std::string get_item_size() {return size;}
    int get_item_cost() {return item_cost;}
};

/**
 * @brief Bill class definition 
 * 
 */
class Bill : public Item
{
    protected:
    int occurance;
    float price;
    public:
    Bill(std::string id = " ", std::string it_name = " ",  std::string size = " ", int cost = 0,int occur=0,float price=0.0): Item(id,it_name,size,cost), occurance{occur},price{price}{}
    void setoccurances(int occur){occurance+=occur;}
    void increment_cost(){price=item_cost*occurance;}
    int getoccurance(){return occurance;}
    float getprice(){return price;}

};
/**
 * @brief Definition of error codes enum
 * 
 */
typedef enum
{
    VALID,
    INVALID,
}error_code;

/**
 * @brief Function Prototypes
 */
error_code check_user_option(int user_option);
void generate_file_map(std::map<int,std::string>& cs_map);
void display_menu(int user_option, std::map<int,std::string>& cs_map, std::vector<Item>& item_vector);
void generate_price_map(std::vector<Item>& item_vector,std::map<std::string,std::vector<Bill>>& price_map);
void calculate_price(std::string option,int units,std::map<std::string,std::vector<Bill>>& price_map);
float calculate_final_price(std::map<std::string,std::vector<Bill>>& price_map);
void read_log_file(std::vector<Customer> &cus);
bool check_membership(std::vector<Customer> &cus,const std::string& name, const std::string& mobile);
void displaybill(std::map<std::string,std::vector<Bill>>&price_map,float& final_price, bool is_member,char member_option);
#endif
