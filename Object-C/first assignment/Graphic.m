//
//  Graphic.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
// GraphicObject
@interface GraphicObject : NSObject
{
    int fillColor;
    BOOL filled;
    int lineColor;
}
-(id)init;

-(void)setFillColor:(int)fillColor;
-(void)setFilled:(BOOL)filled;
-(void)setLineColor:(int)lineColor;

-(int)getFillColor;
-(BOOL)getFIlled;
-(int)getLineColor;
@end