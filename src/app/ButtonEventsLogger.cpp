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
	// TODO Auto-generated constructor stub
	_currentState = STATE_INITIAL;

}

ButtonEventsLogger::~ButtonEventsLogger() {
	// TODO Auto-generated destructor stub
}

void ButtonEventsLogger::onButtonShortPressed(ButtonIndex buttonIndex) {
	this->pushEvent(new evShortPress((int)buttonIndex));
}

void ButtonEventsLogger::onButtonLongPressed(ButtonIndex buttonIndex) {
	this->pushEvent(new evLongPress((int)buttonIndex));
}

void ButtonEventsLogger::build() {
	ButtonEventsHandler::getInstance().subscribe(this);
}

XFEventStatus ButtonEventsLogger::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){
			_currentState = STATE_WORK;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_WORK:
		if (getCurrentEvent()->getId()==evButtonLongPressId){
			const evLongPress * ev = static_cast<const evLongPress*>(getCurrentEvent());
			Trace::out("ButtonEventsLogger : Long Press on button %d\n\r", ev->buttonIndex);
			eventStatus = XFEventStatus::Consumed;
		}
		else if(getCurrentEvent()->getId()==evButtonShortPressId){
			const evShortPress * ev = static_cast<const evShortPress*>(getCurrentEvent());
			Trace::out("ButtonEventsLogger : Short Press on button %d\n\r", ev->buttonIndex);
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}
	return eventStatus;
}
