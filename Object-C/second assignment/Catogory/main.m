//
//  main.m
//  Category
//
//  Created by Woo on 18/3/27.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction+Method.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        Fraction *f1 = [[Fraction alloc] init];
        [f1 setNumerator:3];
        [f1 setDenominator:4];
        Fraction *f2= [[Fraction alloc] init];
        [f2 setNumerator:6];
        [f2 setDenominator:8];
        NSLog(@"f1 is equal to f2?%@",[f1 isEqualTo:f2]?@"YES":@"NO");
        NSLog(@"f1 compare to f2?%i",[f1 compare:f2]);
    }
    return 0;
}
