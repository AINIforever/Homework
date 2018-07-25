//
//  Fraction+Method.m
//  Category
//
//  Created by Woo on 18/3/27.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import "Fraction+Method.h"

@implementation Fraction (Method)
-(BOOL) isEqualTo: (Fraction *) f{
    return numerator / denominator == f.numerator / f.denominator ? YES:NO;
}
-(int) compare: (Fraction *) f{
    if (numerator / denominator > f.numerator / f.denominator) {
        return 1;
    }
    else if(numerator / denominator < f.numerator / f.denominator){
        return -1;
    }
    return 0;
}
@end
