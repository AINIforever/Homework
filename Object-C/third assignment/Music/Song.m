//
//  Song.m
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Song.h"

@implementation Song

@synthesize title, artist, album,playTime;
-(void)setTitle:(NSString *)title
      andArtist:(NSString *)artist
       andAlbum:(NSString *)album
    andPlayTime:(NSString *)palyTime{
    self.title = title;
    self.artist = artist;
    self.album = album;
    self.playTime = playTime;
}
@end
