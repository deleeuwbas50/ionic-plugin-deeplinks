#import <Cordova/CDVPlugin.h>

@interface IonicDeeplinkPlugin : CDVPlugin {
  // Handlers for URL events
	NSMutableArray *_handlers;
	CDVPluginResult *_lastEvent;
}

//These are for the OpenIn
@property (nonatomic, strong) NSURL* launchedURL;
@property (strong) NSString* callbackId;
@property (strong) NSString* unhandleURL;

// User-plugin command handler
- (void)canOpenApp:(CDVInvokedUrlCommand *)command;
- (void)onDeepLink:(CDVInvokedUrlCommand *)command;
- (void)getHardwareInfo:(CDVInvokedUrlCommand *)command;

// Internal deeplink and CUA handlers
- (BOOL)handleLink:(NSURL *)url;
- (BOOL)handleContinueUserActivity:(NSUserActivity *)userActivity;

- (void)sendToJs;

- (CDVPluginResult*)createResult:(NSURL *)url;



//These are for OpenIn
- (BOOL)handleFileUrl:(NSURL *)url;
- (void)onOpenFile:(CDVInvokedUrlCommand *)command;

@end