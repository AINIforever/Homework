//
//  AddressBook.h
//  AdressBook
//
//  Created by Woo on 18/4/19.
//  Copyright © 2018年 Woo. All rights reserved.
//
#import <Foundation/NSArray.h>
#import "AddressCards.h"
@interface AddressBook: NSObject
{
    NSString *bookName;
    NSMutableArray *book;
}
@property (nonatomic, copy) NSString *bookName;
@property (nonatomic, strong) NSMutableArray *book;
-(instancetype) initWithName: (NSString *) name;
-(void) addCard: (AddressCards *) theCard;
-(int) entries;
-(void) list;
-(void) dealloc;
-(NSMutableArray *) lookUp:(NSString *) someName;
@end

