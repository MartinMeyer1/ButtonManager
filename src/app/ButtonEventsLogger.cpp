/*
 * ButtonEventsLogger.cpp
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#include <app/ButtonEventsLogger.h>
#include "mdw/trace/trace.h"
#include "mdw/button/buttoneventshandler.h"
#include "event/evlongpress.h"
#include "event/evshortpress.h"


ButtonEventsLogger::ButtonEventsLogger() {
	_currentState = STATE_INITIAL;

}

ButtonEventsLogger::~ButtonEventsLogger() {
}

void ButtonEventsLogger::onButtonShortPressed(ButtonIndex buttonIndex) {
	//push the received event
	this->pushEvent(new evShortPress((int)buttonIndex));
}

void ButtonEventsLogger::onButtonLongPressed(ButtonIndex buttonIndex) {
	//push the received event
	this->pushEvent(new evLongPress((int)buttonIndex));
}

void ButtonEventsLogger::build() {
	//subscribe this (observer) to the ButtonEventsHandler (subject)
	ButtonEventsHandler::getInstance().subscribe(this);
}

XFEventStatus ButtonEventsLogger::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){

			//Initial transition
			_currentState = STATE_WORK;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_WORK://just check the incoming events
		if (getCurrentEvent()->getId()==evButtonLongPressId){

			//cast the event
			const evLongPress * ev = static_cast<const evLongPress*>(getCurrentEvent());

			//display the event
			Trace::out("ButtonEventsLogger : Long Press on button %d\n\r", ev->buttonIndex);
			eventStatus = XFEventStatus::Consumed;
		}
		else if(getCurrentEvent()->getId()==evButtonShortPressId){

			//cast the event
			const evShortPress * ev = static_cast<const evShortPress*>(getCurrentEvent());

			//display the event
			Trace::out("ButtonEventsLogger : Short Press on button %d\n\r", ev->buttonIndex);
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}
	return eventStatus;
}
