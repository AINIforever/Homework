//
//  Song.h
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/NSArray.h>
@interface Song: NSObject

@property (nonatomic, copy) NSString *title, *artist, *album, *playTime;
-(void)setTitle:(NSString *)title
      andArtist:(NSString *)artist
      andAlbum:(NSString *)album
      andPlayTime:(NSString *)palyTime;
@end
