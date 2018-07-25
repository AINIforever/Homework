//
//  Rectangle.h
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//
#import "GraphicObject.h"
#import "XYPoint.h"
@interface Rectangle:GraphicObject{
    int width;
    int height;
    XYPoint *origin;
    
}
@property int width,height;
-(XYPoint*)origin;
-(void)setOrigin:(XYPoint*)pt;
-(void)setWidth:(int)w andHeight: (int)h;
-(Rectangle*)intersect:(Rectangle*)rec;
-(void)draw;

@end