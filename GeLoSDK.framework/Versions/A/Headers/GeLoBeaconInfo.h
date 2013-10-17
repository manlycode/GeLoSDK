/** This class demonstrates AppleDoc.
 
 A second paragaph comes after an empty line.
 
    int i=0;
    i++;
 
 And some simple code can also be in a block, but indented with a TAB.
*/


#import <Foundation/Foundation.h>

@interface GeLoBeaconInfo : NSObject

@property (nonatomic) NSNumber *remoteId;
@property (nonatomic) NSDate   *updatedAt;
@property (nonatomic) NSNumber *beaconId;
@property (nonatomic) NSString *name;
@property (nonatomic) NSString *description;
@property (nonatomic) NSNumber *signalFalloff;
@property (nonatomic) NSArray  *images;
@property (nonatomic) NSArray *audios;

@property (nonatomic) NSString *mapUrl;

+ (id)beaconInfoFromJson:(NSDictionary *)dictionary;
- (id)initWithJson:(NSDictionary *)dictionary;

@end