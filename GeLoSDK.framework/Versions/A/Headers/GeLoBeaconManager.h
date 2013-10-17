/** This class demonstrates AppleDoc.
 
 A second paragaph comes after an empty line.
 
 int i=0;
 i++;
 
 And some simple code can also be in a block, but indented with a TAB.
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "GeLoBeacon.h"
#import "GeLoTour.h"
#import "GeLoSite.h"



@interface GeLoBeaconManager : NSObject<CBCentralManagerDelegate> {
    __block NSMutableDictionary	  *knownBeacons;
    __block NSMutableDictionary   *knownTourBeaconsDict;
    __block NSArray               *knownTourBeacons;
    __block GeLoBeacon			  *nearestBeacon;
            dispatch_queue_t      scanningQueue;
    
	        NSNotificationCenter  *notificationCenter;
        	NSMutableDictionary	  *tours;
            NSMutableDictionary   *sites;
            NSMutableDictionary   *falloffs;
            NSInteger			  falloff;
            NSUInteger			  timeToLive;
            NSInteger             signalCeiling;
            GeLoTour			  *currentTour;
            GeLoSite              *currentSite;
            BOOL				  includeBetas;
}

+ (GeLoBeaconManager *)sharedInstance;

- (void)startScanningForBeacons;
- (void)resumeScanningForBeacons;
- (BOOL)isScanning;
- (BOOL)isPaused;
- (void)stopScanningForBeacons;
- (void)pauseScanningForBeacons;

- (void)unsetNearestBeacon;

- (NSArray *)knownBeacons;
- (NSArray *)knownTourBeacons;
- (GeLoBeacon *)nearestBeacon;

- (NSArray *)knownTours;
- (NSArray *)knownSites;
- (GeLoTour *)currentTour;
- (GeLoSite *)currentSite;

- (void)loadTourById:(NSNumber *)tourId;
- (void)loadSiteById:(NSNumber *)siteId;

- (GeLoBeaconInfo *)infoForBeaconId:(NSNumber *)beaconId;
- (NSInteger) siteForBeaconId:(NSInteger) beaconId;

- (void)setFalloff:(NSInteger)falloff forId:(NSUInteger)_id;
- (void)setDefaultFalloff:(NSInteger)falloff;
- (void)setDefaultTimeToLive:(NSUInteger)ttl;
- (void)setDefaultSignalCeiling:(NSInteger)ceiling;
- (void)setCurrentTour:(GeLoTour *)tour;
- (void)includeBetaTours;

- (NSArray*)findKnownTourBeacons;

@end
