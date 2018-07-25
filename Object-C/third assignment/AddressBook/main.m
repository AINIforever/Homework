//
//  main.m
//  AdressBook
//
//  Created by Woo on 18/4/19.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressBook.h"
int main(int argc, const char * argv[]) {
    NSString *aName = @"aaa";
    NSString *aEmail = @"aaa.com";
    NSString *bName = @"bbb";
    NSString *bEmail = @"bbb.com";
    NSString *cName = @"ccc";
    NSString *cEmail = @"ccc.com";
    NSString *dName = @"ddd";
    NSString *dEmail = @"ddd.com";
    AddressCards *card1 = [[AddressCards alloc] init];
    AddressCards *card2 = [[AddressCards alloc] init];
    AddressCards *card3 = [[AddressCards alloc] init];
    AddressCards *card4 = [[AddressCards alloc] init];
    AddressBook *myBook = [[AddressBook alloc]
                           initWithName: @"aaa’s Address Book"];
    
    // Now set up four address cards
    [card1 setName: aName];
    [card1 setEmail: aEmail];
    [card2 setName: bName];
    [card2 setEmail: bEmail];
    [card3 setName: cName];
    [card3 setEmail: cEmail];
    [card4 setName: dName];
    [card4 setEmail: dEmail];
    // Add some cards to the address book
    [myBook addCard: card1];
    [myBook addCard: card2];
    [myBook addCard: card3];
    [myBook addCard: card4];
    
    NSMutableArray *result = [[NSMutableArray alloc] init];
    NSString *searchKey = @"bbb";
    result = [myBook lookUp:searchKey];
    if(result != nil){
        for (AddressCards *nextCard in result) {
            NSLog(@"%-20s   %-32s",[nextCard.name UTF8String],[nextCard.email UTF8String]);
        }
    }
    else
        NSLog(@"There is no %@ in the address book", searchKey);
    
    
    
    //15.4
    //for homework 15.3 and 15.4, I use the same program. that means there exists name and firstName, lastName field at the same time. So when I test the print method in 15.4, the name and email field defined at 15.3 will be null. The program has no problem.
    
    AddressCards *card5 = [[AddressCards alloc] init];
    AddressCards *card6 = [[AddressCards alloc] init];
    [card5 setFirstName:@"ef"
            andLastName:@"el" andCountry:@"US" andAddress:@"Road1" andCity:@"NewYork" andZIP:@"43000" andPhone:@"123456" andEmail:@"eee.com"];
    [card6 setFirstName:@"ff"
            andLastName:@"fl" andCountry:@"UK" andAddress:@"Road2" andCity:@"London" andZIP:@"34000" andPhone:@"654321" andEmail:@"fff.com"];
    AddressBook *myBook2 = [[AddressBook alloc]
                           initWithName: @"eee’s Address Book"];
    [myBook2 addCard: card5];
    [myBook2 addCard: card6];
    
    [myBook2 list];
    
    [card5 print];
    [card6 print];
    
    return 0;
}
