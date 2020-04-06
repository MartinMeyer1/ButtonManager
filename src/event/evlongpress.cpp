/*
 * evlongpress.cpp
 *
 *  Created on: 6 avr. 2020
 *      Author: meyer
 */

#include <event/evlongpress.h>


evLongPress::evLongPress(int buttonIndex) :
XFCustomEvent(evButtonLongPressId) {
	this->buttonIndex = buttonIndex;
}

evLongPress::~evLongPress() {
	// TODO Auto-generated destructor stub
}
