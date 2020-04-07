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
}

ButtonStateSm::ButtonStateSm() {
	_currentState = STATE_INITIAL;
}

XFEventStatus ButtonStateSm::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;
	eMainState _oldState;

	_oldState = _currentState;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){

			//initial transition
			_currentState = STATE_WAIT_BUTTON_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_WAIT_BUTTON_PRESSED:
		//on button press
		if (getCurrentEvent()->getEventType()==XFEvent::Event
				&& getCurrentEvent()->getId() == evButtonPressedId){
			//change the current state
			_currentState = STATE_BUTTON_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}

		break;
	case STATE_BUTTON_PRESSED:
		//on button released
		if (getCurrentEvent()->getEventType()==XFEvent::Event
				&& getCurrentEvent()->getId() == evButtonReleasedId){
			//change current state
			_currentState = STATE_BUTTON_SHORT_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}
		//on timeout reached
		else if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
			getCurrentTimeout()->getId() == _evTimeout){
				//change current state
				_currentState = STATE_BUTTON_LONG_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
		break;
	case STATE_BUTTON_SHORT_PRESSED:
	case STATE_BUTTON_LONG_PRESSED:
		//return to the state
		_currentState = STATE_WAIT_BUTTON_PRESSED;
		break;
	default:
		break;
	}

	//on entry actions
	if(_currentState != _oldState){
		switch(_currentState){
		case STATE_BUTTON_PRESSED:
			//start timer
			scheduleTimeout(_evTimeout, 1000);
			break;
		case STATE_BUTTON_SHORT_PRESSED:
			//unschedule timeout to prevent some troubles
			unscheduleTimeout(_evTimeout);
			//notify the buttoneventshandler
			ButtonEventsHandler::getInstance().notifyButtonShortPressed(buttonIndex);
			_currentState=STATE_WAIT_BUTTON_PRESSED;
			break;
		case STATE_BUTTON_LONG_PRESSED:
			//notify the buttoneventshandler
			ButtonEventsHandler::getInstance().notifyButtonLongPressed(buttonIndex);
			_currentState=STATE_WAIT_BUTTON_PRESSED;
			break;
		default:
			break;
		}
	}

	return eventStatus;
}

void ButtonStateSm::initialize(
		interface::ButtonEventsHandlerSubject::ButtonIndex buttonIndex) {
	//save the button index
	this->buttonIndex=buttonIndex;
}
