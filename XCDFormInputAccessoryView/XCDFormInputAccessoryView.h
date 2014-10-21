//
//  XCDFormInputAccessoryView.h
//
//  Created by Cédric Luthi on 2012-11-10
//  Copyright (c) 2012 Cédric Luthi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, XCDFormInputAccessoryViewAction) {
	XCDFormInputAccessoryViewActionNext,
	XCDFormInputAccessoryViewActionPrevious,
	XCDFormInputAccessoryViewActionDone
};

typedef BOOL (^XCDFormInputAccessoryViewActionBlock)(XCDFormInputAccessoryViewAction action);

@interface XCDFormInputAccessoryView : UIView

/** 
 *  Objects must be UIResponder instances
 */

- (instancetype) initWithResponders:(NSArray *)responders;

- (instancetype) initWithResponders:(NSArray *)responders tintColor:(UIColor *)tintColor;

@property (nonatomic, strong) NSArray *responders;

/**
 * Defaults to YES on iPhone, NO on iPad
 */

@property (nonatomic, assign) BOOL hasDoneButton;

@property (nonatomic, strong) UIColor *tintColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *barTintColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, copy) XCDFormInputAccessoryViewActionBlock actionHandler;

- (void) selectAdjacentResponderAtIndex:(NSInteger)index;
- (void) previous;
- (void) next;
- (void) done;

- (void) setHasDoneButton:(BOOL)hasDoneButton animated:(BOOL)animated;

@end
