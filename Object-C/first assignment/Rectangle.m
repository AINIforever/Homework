//
//  Rectangle.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
#import "Rectangle.h"
#import "stdio.h"
@implementation Rectangle
@synthesize width,height;
-(void)setWidth:(int)w andHeight:(int)h{
    width = w;
    height = h;
}
-(void)setOrigin:(XYPoint*)pt{
    origin = pt;
}
-(XYPoint*)origin{
    return origin;
}
-(void)draw{
    char a = '-';
    for (int i=0; i<width; i++) {
        printf("-");
    }
    printf("\n");
    for (int i=0; i<height; i++) {
        printf("|");
        for (int j=0; j<width-2; j++) {
            printf(" ");
        }
        printf("|");
        printf("\n");
    }
    for (int i=0; i<width; i++) {
        printf("-");
    }
}
-(Rectangle*)intersect:(Rectangle*)rect{
    Rectangle* inter = [[Rectangle alloc] init];
    inter.origin = [[XYPoint alloc] init];
    inter.origin.x = 0;
    inter.origin.y = 0;
    inter.width = 0;
    inter.height = 0;
    
    
    if (rect.origin.x>origin.x+width || rect.origin.y>origin.y+height) {
        return inter;
    }
    if (rect.origin.x>origin.x && rect.origin.x<origin.x+width) {
        if (origin.y>rect.origin.y) {
            if (rect.origin.y+rect.height<origin.y) {
                return inter;
            }
            else{
                inter.origin.x = rect.origin.x;
                inter.origin.y = origin.y;
                if (rect.origin.y+rect.height>origin.y && rect.origin.y+rect.height<origin.y+height) {
                    
                    inter.height = rect.origin.y+rect.height-origin.y;
                    inter.width = rect.origin.x+rect.width>origin.x+width?origin.x+width-rect.origin.x:rect.width;
                    return inter;
                }
                else{
                    inter.height = height;
                    inter.width = rect.origin.x+rect.width>origin.x+width?origin.x+width-rect.origin.x:rect.width;
                    return inter;
                }
            }
        }
        else{
            inter.origin.x = rect.origin.x;
            inter.origin.y = rect.origin.y;
            inter.width = rect.origin.x+rect.width>origin.x+width?origin.x+width-rect.origin.x:rect.width;
            inter.height = rect.origin.y+rect.height>origin.y+height?origin.y+height-rect.origin.y:rect.height;
            return inter;
        }
        
    }
    if (rect.origin.x<origin.x) {
        if (rect.origin.x+rect.width<origin.x || rect.origin.y+rect.height<origin.y) {
            return inter;
        }
        else{
            inter.origin.x = origin.x;
            inter.origin.y = rect.origin.y>origin.y?rect.origin.y:origin.y;
            inter.width = rect.origin.x+rect.width>origin.x+width?origin.x+width-rect.origin.x:rect.width;
            inter.height = rect.origin.y+rect.height>origin.y+height?origin.y+height-rect.origin.y:rect.height;
            return inter;
        }
        
    }
    return inter;
}
@end
