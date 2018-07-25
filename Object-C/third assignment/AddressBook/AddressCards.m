//
//  AddressCards.m
//  AdressBook
//
//  Created by Woo on 18/4/19.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressCards.h"
@implementation AddressCards
{NSString *name;
    NSString *email;}
-(void) setName: (NSString *) theName
{
    name = [[NSString alloc] initWithString: theName];
}
-(void) setEmail: (NSString *) theEmail
{
    email = [[NSString alloc] initWithString: theEmail];
}
-(NSString *) name
{return name;}
-(NSString *) email
{return email;}

//15.4
-(void) setFirstName:(NSString *)firstName
         andLastName:(NSString *)lastName
          andCountry:(NSString *)country
          andAddress:(NSString *)address
             andCity:(NSString *)city
              andZIP:(NSString *)ZIP
            andPhone:(NSString *)phone
            andEmail:(NSString *)email2{
    _firstName = firstName;
    _lastName = lastName;
    _country = country;
    _address = address;
    _city = city;
    _ZIP = ZIP;
    _phone = phone;
    _email2 = email2;
}
-(void) print
{
    NSLog (@"====================================");
    NSLog (@"| |");
    NSLog (@"| %-31s |", [name UTF8String]);
    NSLog (@"| %-31s |", [email UTF8String]);
    NSLog (@"| |");
    NSLog (@"| |");
    NSLog (@"| |");
    NSLog (@"|in 15.4: |");
    NSLog (@"| %-31s |", [_firstName UTF8String]);
    NSLog (@"| %-31s |", [_lastName UTF8String]);
    NSLog (@"| %-31s |", [_country UTF8String]);
    NSLog (@"| %-31s |", [_address UTF8String]);
    NSLog (@"| %-31s |", [_city UTF8String]);
    NSLog (@"| %-31s |", [_ZIP UTF8String]);
    NSLog (@"| %-31s |", [_phone UTF8String]);
    NSLog (@"| %-31s |", [_email2 UTF8String]);
    NSLog (@"| O O |");
    NSLog (@"====================================");
}
@end
