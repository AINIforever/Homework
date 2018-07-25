//
//  main.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
#import "GraphicObject.h"
#import "Rectangle.h"
#import "Circle.h"
#import "Triangle.h"
#import "XYPoint.h"
#import "stdio.h"











int main(int argc, const char *argv[]){
    @autoreleasepool{
        Triangle *Tri = [[Triangle alloc] init];
        [Tri setLengthA:1];
        [Tri setLengthB:1];
        [Tri setLengthC:1];
        NSLog(@"The perimeter of Triangle:%2f",[Tri perimeter]);
        NSLog(@"The area of Triangle:%2f",[Tri area]);
        
        Circle *Cir = [[Circle alloc] init];
        [Cir setRadius:1];
        
        NSLog(@"The circumference of CIrcle:%2f",[Cir circumference]);
        NSLog(@"The area of Circle:%2f",[Cir area]);
        
        
        Rectangle *RecA = [[Rectangle alloc] init];
        Rectangle *RecB = [[Rectangle alloc] init];
        XYPoint *OA = [[XYPoint alloc] init];
        XYPoint *OB = [[XYPoint alloc] init];
        [OA setX:200 andY:420];
        [OB setX:400 andY:300];
        [RecA setWidth:250 andHeight:75];
        [RecB setWidth:100 andHeight:180];
        [RecA setOrigin:OA];
        [RecB setOrigin:OB];
        NSLog(@"The origin of intersect:(%i,%i)",[RecA intersect:RecB].origin.x,[RecA intersect:RecB].origin.y);
        
        NSLog(@"The width of intersect:%i",[RecA intersect:RecB].width);
        NSLog(@"The height of intersect:%i",[RecA intersect:RecB].height);
        [RecA setWidth:10 andHeight:5];
        [RecA draw];
        
    }
    return 0;
}