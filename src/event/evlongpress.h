/*
 * evlongpress.h
 *
 *  Created on: 6 avr. 2020
 *      Author: meyer
 */

#ifndef EVLONGPRESS_H_
#define EVLONGPRESS_H_

#include "xf/customevent.h"
#include "events.h"


class evLongPress : public XFCustomEvent {
public:
	evLongPress(int buttonIndex);
	virtual ~evLongPress();
	int buttonIndex;
};

#endif /* EVLONGPRESS_H_ */
