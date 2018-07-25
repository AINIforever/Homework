//
//  Fraction.m
//  Category
//
//  Created by Woo on 18/3/27.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction.h"


#import "stdio.h"
// Define the Fraction class


@implementation Fraction
-(void) print
{
    NSLog (@"%i/%i" , numerator, denominator);
}
-(void) setNumerator: (int) n
{
    numerator = n;
}
-(void) setDenominator: (int) d
{
    denominator = d;
}
-(int) numerator
{
    return numerator;
}
-(int) denominator
{
    return denominator;
}
-(double) convertToNum
{
    if (denominator != 0)
        return (double) numerator / denominator;
    else
        return 0.0;
}
@end
