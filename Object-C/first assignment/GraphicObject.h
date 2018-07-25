//
//  GraphicObject.h
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
-(GraphicObject*)initWithFillColor: (int) fillColor andFilled: (BOOL) filled andLineColor: (int) lineColor;

-(void)setFillColor:(int)fillColor;
-(void)setFilled:(BOOL)filled;
-(void)setLineColor:(int)lineColor;

-(int)fillColor;
-(BOOL)filled;
-(int)lineColor;
@end