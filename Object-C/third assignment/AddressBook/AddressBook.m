//
//  AdressBook.m
//  AdressBook
//
//  Created by Woo on 18/4/19.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressBook.h"
@implementation AddressBook;
@synthesize bookName, book;
// set up the AddressBook’s name and an empty book
-(instancetype) initWithName: (NSString *) name
{
    self = [super init];
    if (self) {
        bookName = [[ NSString alloc] initWithString: name];
        book = [[NSMutableArray alloc] init];
    }
    return self;
}
-(instancetype) init
{
    return [self initWithName: @"NoName"];
}
-(void) addCard: (AddressCards *) theCard
{
    [book addObject: theCard];
}
-(int) entries
{
    return [book count];
}
-(void) list
{
    NSLog (@"======== Contents of: %@ =========", bookName);
    for ( AddressCards *theCard in book )
        NSLog (@"%-20s %-32s", [theCard.name UTF8String],
               [theCard.email UTF8String]);
    NSLog (@"===============================================");
    //15.4
    NSLog(@"In 15.4:");
    NSLog (@"======== Contents of: %@ =========", bookName);
    for ( AddressCards *theCard in book )
        NSLog (@"%-20s %-32s", [theCard.firstName UTF8String],
               [theCard.lastName UTF8String]);
    NSLog (@"===============================================");}
//-(void) dealloc
//{
//    [bookName release];
//    [book release];
//    [super dealloc];
//}

-(NSMutableArray *) lookUp:(NSString *) someName{
    NSMutableArray *nameFound = [[NSMutableArray alloc] init];
    for(AddressCards *addressCard in book){
        if([addressCard.name rangeOfString:someName options:NSCaseInsensitiveSearch].location != NSNotFound)
            [nameFound addObject:addressCard];
    }
    return [nameFound count]?nameFound:nil;
}

@end
