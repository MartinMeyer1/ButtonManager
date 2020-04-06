/*
 * evshortpress.h
 *
 *  Created on: 6 avr. 2020
 *      Author: meyer
 */

#ifndef EVSHORTPRESS_H_
#define EVSHORTPRESS_H_

#include "xf/customevent.h"
#include "events.h"

class evShortPress : public XFCustomEvent {
public:
	evShortPress(int buttonIndex);
	virtual ~evShortPress();
	int buttonIndex;
};

#endif /* EVSHORTPRESS_H_ */
