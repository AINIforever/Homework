//
//  Fraction.h
//  Category
//
//  Created by Woo on 18/3/27.
//  Copyright © 2018年 Woo. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface Fraction: NSObject
{
    int numerator;
    int denominator;
}
-(void) print;
-(void) setNumerator: (int) n;
-(void) setDenominator: (int) d;
-(int) numerator;
-(int) denominator;
-(double) convertToNum;
@end
