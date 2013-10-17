//
//  GeLoCache.h
//  GeLoSDK
//
//  Created by Tim Bugai on 5/23/13.
//  Copyright (c) 2013 Collective Idea. All rights reserved.
//


#import <UIKit/UIKit.h>


@class GeLoTour;

@interface GeLoCache : NSObject {
	NSMutableDictionary		*imageCache;
    NSMutableDictionary		*audioCache;
	NSMutableDictionary		*tourCache;
    NSMutableDictionary     *siteCache;
    NSMutableDictionary     *beaconListCache;
    dispatch_queue_t        serialQueue;

}

@property (nonatomic) NSNotificationCenter *notificationCenter;

+ (id)sharedCache;
+ (NSString *)cacheDirectory;

- (void)clearCache;

- (NSArray *)loadTours;
- (GeLoTour *)loadTour:(NSNumber *)tourId;
- (NSArray *)loadSites;
- (GeLoSite *)loadSite:(NSNumber *)siteId;
- (UIImage *)loadImage:(NSString *)imageUrl;
- (NSData *)loadAudio:(NSString *)audioUrl;
- (NSDictionary *)loadBeaconList;
@end