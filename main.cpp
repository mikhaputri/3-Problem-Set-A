//
//  main.cpp
//  SodaCan
//
//  Created by Mikha Yupikha on 25/10/2016.
//  Copyright © 2016 Mikha Yupikha. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "SodaCan.hpp"

using namespace std;
//ttd: total&diff content, check expired or not and display it, display all members of the cans
int main(){
    
    string brand;
    int Size;
    int contents;
    
    int currDay = 25;
    int currMonth = 10;
    int currYear = 2016;
    
    int exDay,exMonth,exYear;
    
    cout<<"\tWelcome to Miyabi's Vending Machine!"<<endl;
    cout<<"Please Place Your Order! Your WIsh Is My Command!"<<endl;
    cout<<"Oh yeah.... don't put any spaces in the brand name, ok!"<<endl;
    cout<<"gimme a brand size contents"<<endl;
    cin>>brand>>Size>>contents;
    
    cout<<"Enter the expired date in the order of dd/mm/yyyy: ";
    cin>>exDay>>exMonth>>exYear;
    
    SodaCan can1;
    can1.setBrand(brand);
    can1.setSize(Size);
    can1.pourInSoda(contents);
    can1.setExpiredDay(exDay);
    can1.setExpiredMonth(exMonth);
    can1.setExpiredYear(exYear);
    
    if(can1.isFull() == true){
        cout<<"Invalid Size to Content Input";
        exit(0);
    } else if(exDay<1 || exDay>30 || exMonth<1 || exMonth>12 || exYear<1){
        cout<<"Invalid date input";
        exit(0);
    } else if(can1.isExpired(currDay, currMonth, currYear) == true){
        cout<<"Drink is expired, please get another drink";
        exit(0);
    }
    
    cout<<"\nHere You Go!: ";
    cout<<can1.getContents()<< " ounces of " << can1.getBrand() << " that will expire on "
    << exDay << "/" << exMonth << "/" << exYear << endl;
    
    SodaCan can2 = SodaCan("sprite", 100, 50);
    can2.setExpiredDay(28);
    can2.setExpiredMonth(10);
    can2.setExpiredYear(2016);
    
    cout<<"Here You Go!: ";
    cout<<can2.getContents()<< " ounces of " << can2.getBrand() << " that will expire on 28/10/2016" << endl;
    
    if(can1.getBrand() == can2.getBrand()){
        
        int action = 0;
        
        cout<<"\nWhat do you want to do with the two cans?\n\n"
        <<"1. Combine the content\n"
        <<"2. Know the difference in content\n";
        cin>>action;
        
        if(action == 1){
            cout<<"The total content of the two cans is: "<<can1.totalContent(can1,can2)<<endl;
        } else if(action == 2){
            cout<<"The difference in content of the two cans is: "<<can1.diffContent(can1,can2)<<endl;
        }
    }
    
    return 0;
}
