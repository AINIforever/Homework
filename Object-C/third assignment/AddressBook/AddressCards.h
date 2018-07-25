//
//  AddressCards.h
//  AdressBook
//
//  Created by Woo on 18/4/19.
//  Copyright © 2018年 Woo. All rights reserved.
//
#import <Foundation/Foundation.h>
@interface AddressCards: NSObject
-(void) setName: (NSString *) theName;
-(void) setEmail: (NSString *) theEmail;
-(NSString *) name;
-(NSString *) email;
-(void) print;

//15.4
@property(copy, nonatomic) NSString *firstName, *lastName, *country, *address, *city, *ZIP, *phone, *email2;
-(void) setFirstName:(NSString *)firstName
        andLastName:(NSString *)lastName
        andCountry:(NSString *)country
        andAddress:(NSString *)address
        andCity:(NSString *)city
        andZIP:(NSString *)ZIP
        andPhone:(NSString *)phone
        andEmail:(NSString *)email;
@end
