#import <UIKit/UIKit.h>
@class GeLoTour;

/**
`GeLoCache` stores and serves content from the GeLo CMS.
 
Example:
 
    -(void)viewDidLoad {
 
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(toursLoaded:)
                                                     name:kGeLoCacheToursLoaded
                                                   object:nil];
 
        tours = [[GeLoCache sharedCache] loadTours]; //since the tours have not loaded yet, the return will be nil
    }
 
    -(void) toursLoaded {
        tours = [[GeLoCache sharedCache] loadTours];
    }
 
While `GeLoBeaconManager` is scanning, it can emit the following notifications:
 
 - kGeLoCacheToursLoaded
 - kGeLoCacheBeaconListLoaded
 - kGeLoCacheTourLoaded
 - kGeLoCacheTourUpdated
 - kGeLoCacheSiteLoaded
 - kGeLoCacheSiteUpdated
 - kGeLoBeaconImageLoaded
 - kGeLoBeaconMediaLoaded
*/
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

///---------------------
///@name Loading Content
///---------------------
- (NSArray *)loadTours;
- (GeLoTour *)loadTour:(NSNumber *)tourId;
- (NSArray *)loadSites;
- (GeLoSite *)loadSite:(NSNumber *)siteId;
- (UIImage *)loadImage:(NSString *)imageUrl;
- (NSData *)loadAudio:(NSString *)audioUrl;
- (NSDictionary *)loadBeaconList;

@end