/*
 * evshortpress.cpp
 *
 *  Created on: 6 avr. 2020
 *      Author: meyer
 */

#include <event/evshortpress.h>

evShortPress::evShortPress(int buttonIndex) :
XFCustomEvent(evButtonShortPressId) {
	// TODO Auto-generated constructor stub
	this->buttonIndex = buttonIndex;
}

evShortPress::~evShortPress() {
	// TODO Auto-generated destructor stub
}


