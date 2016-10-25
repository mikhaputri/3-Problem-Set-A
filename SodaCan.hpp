//
//  SodaCan.hpp
//  SodaCan
//
//  Created by Mikha Yupikha on 25/10/2016.
//  Copyright © 2016 Mikha Yupikha. All rights reserved.
//

#ifndef SodaCan_hpp
#define SodaCan_hpp

#include <iostream>
using namespace std;

class SodaCan{
    
private:
    
    string my_Brand;
    int my_Size;
    int my_Contents;
    
    //added members; expired date
    int expDay;
    int expMonth;
    int expYear;
    
public:
    
    //constructors
    SodaCan(){
        my_Brand = "";
        my_Size = 0;
        my_Contents = 0;
    };
    SodaCan(string brand, int Size, int contents){
        this->my_Brand = brand;
        this->my_Size = Size;
        this->my_Contents = contents;
    };
    
    bool isFull(); //added method; to check if the can is full (content>size)
    bool isExpired(int, int, int); //added method; to check if the drink is expired (date)
    bool isEmpty(); //to check if the can is empty
    
    void pourInSoda(int amount); //add content
    void drink(int amount); //subtract content
    
    void setSize(int Size); //re-determine container size
    void setBrand(string brand); //
    
    string getBrand(); //display brand
    int getContents(); //display content
    int getSize(); //display size
    
    //added methods
    void setExpiredDay(int);
    void setExpiredMonth(int);
    void setExpiredYear(int);
    
    //added methods
    int totalContent(SodaCan &, SodaCan &); //sum of two cans
    int diffContent(SodaCan &, SodaCan &); //difference in the two cans
};

bool SodaCan::isExpired(int currDay, int currMonth, int currYear){
    
    bool valid = false;
    
    if(currYear > expYear){
        valid = true;
    } else if(currMonth > expMonth){
        valid = true;
    } else if(currDay > expDay && currMonth==expMonth){
        valid = true;
    }
    
    return valid;
}

bool SodaCan::isFull(){
    
    bool valid = false;
    
    if(my_Contents > my_Size){
        
        valid = true;
    }
    
    return valid;
}

bool SodaCan::isEmpty(){
    
    bool valid = false;
    
    if(my_Contents == 0){
        
        valid = true;
    }
    
    return valid;
}

void SodaCan::pourInSoda(int amount){
    
    my_Contents += amount;
}

void SodaCan::drink(int amount){
    
    this->my_Contents -= amount;
}

void SodaCan::setSize(int Size){
    
    this->my_Size = Size;
}

void SodaCan::setBrand(string brand){
    
    this->my_Brand = brand;
}

int SodaCan::getContents(){
    
    return my_Contents;
}

int SodaCan::getSize(){
    
    return my_Size;
}

string SodaCan::getBrand(){
    
    return my_Brand;
}

void SodaCan::setExpiredDay(int day){
    
    this->expDay = day;
}

void SodaCan::setExpiredMonth(int month){
    
    this->expMonth = month;
}

void SodaCan::setExpiredYear(int year){
    
    this->expYear = year;
}

int SodaCan::totalContent(SodaCan &obj1, SodaCan &obj2){
    
    int newContent = obj1.getContents() + obj2.getContents();
    return newContent;
}

int SodaCan::diffContent(SodaCan &obj1, SodaCan &obj2){
    
    int newContent;
    
    if(obj1.getContents() > obj2.getContents()){
        newContent = obj1.getContents() - obj2.getContents();
    } else obj2.getContents() - obj1.getContents();
    
    return newContent;
}

#endif // SodaCan_hpp
