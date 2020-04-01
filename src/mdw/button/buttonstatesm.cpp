/*
 * buttonstatesm.cpp
 *
 *  Created on: 1 avr. 2020
 *      Author: meyer
 */
#include "buttoneventshandler.h"
#include <button/buttonstatesm.h>
#include "mdw\trace\trace.h"



ButtonStateSm::~ButtonStateSm() {
	// TODO Auto-generated destructor stub
}

XFEventStatus ButtonStateSm::processEvent() {
	//Trace::out("Process event\n\r");
	eEventStatus eventStatus = XFEventStatus::Unknown;
	eMainState _oldState;

	_oldState = _currentState;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){
			_currentState = STATE_WAIT_BUTTON_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_WAIT_BUTTON_PRESSED:
		if (getCurrentEvent()->getEventType()==XFEvent::Event
				&& getCurrentEvent()->getId() == evButtonPressedId){
			_currentState = STATE_BUTTON_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}

		break;
	case STATE_BUTTON_PRESSED:
		if (getCurrentEvent()->getEventType()==XFEvent::Event
				&& getCurrentEvent()->getId() == evButtonReleasedId){
			_currentState = STATE_BUTTON_SHORT_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}
		else if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
			getCurrentTimeout()->getId() == _evTimeout){

				_currentState = STATE_BUTTON_LONG_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
		break;
	case STATE_BUTTON_SHORT_PRESSED:
	case STATE_BUTTON_LONG_PRESSED:
		_currentState = STATE_WAIT_BUTTON_PRESSED;
		break;
	default:
		break;
	}

	//on entry actions
	if(_currentState != _oldState){
		switch(_currentState){
		case STATE_BUTTON_PRESSED:
			scheduleTimeout(_evTimeout, 1000);
			break;
		case STATE_BUTTON_SHORT_PRESSED:
			Trace::out("Short press\n\r");
			unscheduleTimeout(_evTimeout);
			ButtonEventsHandler::getInstance().notifyButtonShortPressed(buttonIndex);
			break;
		case STATE_BUTTON_LONG_PRESSED:
			Trace::out("Long press\n\r");
			ButtonEventsHandler::getInstance().notifyButtonLongPressed(buttonIndex);
			break;
		default:
			break;
		}
	}

	return eventStatus;
}

void ButtonStateSm::initialize(
		interface::ButtonEventsHandlerSubject::ButtonIndex buttonIndex) {
	this->buttonIndex=buttonIndex;
}
