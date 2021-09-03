#include "gtest/gtest.h"
#include "CubeEatery.h"

/**
 * Check for Valid case of user option in choosing restaurant
 **/ 
TEST(CheckUserOption,valid)
{
    ASSERT_EQ(0,check_user_option(2));
    ASSERT_EQ(0,check_user_option(1));
}

/**
 * Check for Invalid case of user option in choosing restaurant
 **/ 
TEST(CheckUserOption,Invalid)
{
    ASSERT_EQ(1,check_user_option(0));
    ASSERT_EQ(1,check_user_option(-2));
}

TEST(FileMap,CorrectEntry)
{
    std::map<int,std::string>cs_map;
    generate_file_map(cs_map);
    ASSERT_EQ("Dominos_Menu.csv",cs_map[1]);
    ASSERT_EQ("McDonalds_Menu.csv",cs_map[2]);
}

TEST(FileMap,WrongEntry)
{
    std::map<int,std::string>csv_map;
    generate_file_map(csv_map);
    ASSERT_NE("Dominos_M.csv",csv_map[1]);
    ASSERT_NE("",csv_map[2]);
}

TEST(DominosItemVector,CorrectEntry)
{
   std::map<int,std::string>csv_map;
   csv_map[1]="Dominos_Menu.csv";
   std::vector<Item> item_vector;
   display_menu(1,csv_map,item_vector);
   ASSERT_EQ("D01",item_vector[0].get_item_id());	
   ASSERT_EQ("Peppy Panner", item_vector[6].get_item_name());
   ASSERT_EQ("L",item_vector[14].get_item_size());
   ASSERT_EQ(365,item_vector[13].get_item_cost());
}

TEST(DominosItemVector,WrongEntry)
{
   std::map<int,std::string>csv_map;
   csv_map[1]="Dominos_Menu.csv";
   std::vector<Item> item_vector;
   display_menu(1,csv_map,item_vector);
   ASSERT_NE("D04",item_vector[8].get_item_id());	
   ASSERT_NE("Margherita", item_vector[4].get_item_name());
   ASSERT_NE("M",item_vector[0].get_item_size());
   ASSERT_NE(104,item_vector[12].get_item_cost());
}

TEST(McDonaldsItemVector,CorrectEntry)
{
   std::map<int,std::string>csv_map;
   csv_map[2]="McDonalds_Menu.csv";
   std::vector<Item> item_vector;
   display_menu(2,csv_map,item_vector);
   ASSERT_EQ("D05",item_vector[4].get_item_id());	
   ASSERT_EQ("Dosa Masala Brioche", item_vector[3].get_item_name());
   ASSERT_EQ("",item_vector[2].get_item_size());
   ASSERT_EQ(111,item_vector[1].get_item_cost());
}

TEST(McDonaldsItemVector,WrongEntry)
{
   std::map<int,std::string>csv_map;
   csv_map[2]="McDonalds_Menu.csv";
   std::vector<Item> item_vector;
   display_menu(2,csv_map,item_vector);
   ASSERT_NE("D02",item_vector[0].get_item_id());	
   ASSERT_NE("Veg", item_vector[1].get_item_name());
   ASSERT_NE("H",item_vector[2].get_item_size());
   ASSERT_NE(57,item_vector[3].get_item_cost());
}

TEST(PriceMap,CorrectEntry)
{
   std::vector<Item> item_vector;
   std::map<std::string,std::vector<Bill>> price_map;
   item_vector.emplace_back("D01","Margaherita","S",99);
   generate_price_map(item_vector,price_map);
   ASSERT_EQ("D01",price_map["D01"][0].get_item_id());
   ASSERT_EQ("Margaherita",price_map["D01"][0].get_item_name());
   ASSERT_EQ("S",price_map["D01"][0].get_item_size());
   ASSERT_EQ(99,price_map["D01"][0].get_item_cost());
   ASSERT_EQ(0,price_map["D01"][0].getoccurance());
   ASSERT_EQ(0.0,price_map["D01"][0].getprice());
}
   
TEST(PriceMap,WrongEntry)
{
   std::vector<Item> item_vector;
   std::map<std::string,std::vector<Bill>> price_map;
   item_vector.emplace_back("D02","Veg Burger","",177);
   generate_price_map(item_vector,price_map);
   ASSERT_NE("D05",price_map["D02"][0].get_item_id());
   ASSERT_NE("Peri Peri Fries",price_map["D02"][0].get_item_name());
   ASSERT_NE("L",price_map["D02"][0].get_item_size());
   ASSERT_NE(76,price_map["D02"][0].get_item_cost());
   ASSERT_NE(5,price_map["D02"][0].getoccurance());
   ASSERT_NE(10.0,price_map["D02"][0].getprice());
}

TEST(CalculatePrice, correctentry)
{
   std::map<std::string,std::vector<Bill>> price_map;
   price_map["D01"].emplace_back("D01","Margaherita","S",99,0,0);
   calculate_price("D01",3,price_map);
   ASSERT_EQ(3,price_map["D01"][0].getoccurance());
   ASSERT_EQ(297,price_map["D01"][0].getprice());
   calculate_price("D01",3,price_map);
   ASSERT_EQ(6,price_map["D01"][0].getoccurance());
   ASSERT_EQ(594,price_map["D01"][0].getprice());
}

TEST(CalculatePrice, wrongentry)
{
   std::map<std::string,std::vector<Bill>> price_map;
   price_map["D01"].emplace_back("D01","Margaherita","S",99,0,0);
   calculate_price("D01",3,price_map);
   ASSERT_NE(2,price_map["D01"][0].getoccurance());
   ASSERT_NE(197,price_map["D01"][0].getprice());
}

TEST(CalculateFInalPrice, correctentry)
{
   std::map<std::string,std::vector<Bill>> price_map;
   price_map["D03"].emplace_back("D03","Veg Burger","",177,3,531);
   ASSERT_EQ(531,calculate_final_price(price_map));
   price_map["D05"].emplace_back("D05","Masala Wedges","",101,1,101);
   ASSERT_EQ(632,calculate_final_price(price_map));
}
TEST(CalculateFInalPrice, wrongentry)
{
   std::map<std::string,std::vector<Bill>> price_map;
   price_map["D08"].emplace_back("D08","Peppy Panner","",365,2,730);
   ASSERT_NE(700,calculate_final_price(price_map));
   price_map["D15"].emplace_back("D15","Mexican Green Wave","",545,2,1090);
   ASSERT_NE(1000,calculate_final_price(price_map));
}

TEST(ReadLogFile, correctentry)
{
   std::vector<Customer>cus;
   read_log_file(cus);
   ASSERT_EQ("Manikanta",cus[0].getname());
   ASSERT_EQ("7893065100", cus[1].getmobilenumber());
}

TEST(ReadLogFile, wrongentry)
{
   std::vector<Customer>cus;
   read_log_file(cus);
   ASSERT_NE("Raja",cus[0].getname());
   ASSERT_NE("9535897518", cus[1].getmobilenumber());
}

TEST(CheckMembership, isamemeber)
{
   std::vector<Customer>cus;
   cus.emplace_back("Manikanta","9535897518");
   ASSERT_EQ(true,check_membership(cus,"Manikanta","9535897518"));
}

TEST(CheckMembership, isnotamemeber)
{
   std::vector<Customer>cus;
   ASSERT_EQ(false,check_membership(cus,"Manikanta","9535897516"));
   ASSERT_EQ(false,check_membership(cus,"Raja","9535897518"));
   ASSERT_EQ(false,check_membership(cus,"Manikanta","7893065100"));
}

TEST(CheckGrandTotal, correctentry)
{
   std::map<std::string,std::vector<Bill>> price_map;
   float final_price=730;
   price_map["D08"].emplace_back("D08","Peppy Panner","",365,2,730);
   displaybill(price_map,final_price,true,'y');
   ASSERT_EQ(2139,int(final_price));
   final_price=730;
   displaybill(price_map,final_price,false,'y');
   ASSERT_EQ(2251,int(final_price));
   final_price=730;
   displaybill(price_map,final_price,false,'n');
   ASSERT_EQ(751,int(final_price));
   final_price=730;
   displaybill(price_map,final_price,true,'n');
   ASSERT_EQ(714,int(final_price));
}

TEST(CheckGrandTotal, wrongentry)
{
   std::map<std::string,std::vector<Bill>> price_map;
   float final_price=1770;
   price_map["D08"].emplace_back("D03","Veg Burger","",177,10,1770);
   displaybill(price_map,final_price,true,'y');
   ASSERT_NE(2500,int(final_price));
   final_price=1770;
   displaybill(price_map,final_price,false,'y');
   ASSERT_NE(2000,int(final_price));
   final_price=1770;
   displaybill(price_map,final_price,false,'n');
   ASSERT_NE(750,int(final_price));
   final_price=1770;
   displaybill(price_map,final_price,true,'n');
   ASSERT_NE(1770,int(final_price));
}				

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
