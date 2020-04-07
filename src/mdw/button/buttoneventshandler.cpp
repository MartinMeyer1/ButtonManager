/*
 * buttoneventshandler.cpp
 *
 *  Created on: 1 avr. 2020
 *      Author: meyer
 */

#include <button/buttoneventshandler.h>
#include "mdw\trace\trace.h"
#include "buttonstatesm.h"
#include "platform/f7-disco-gcc/board/buttonscontroller.h"

ButtonEventsHandler::ButtonEventsHandler() {

}

//Called by an observer to subscribe
bool ButtonEventsHandler::subscribe(
		interface::ButtonEventsHandlerObserver* observer) {

	//add an observer to the list
	obsList.push_front(observer);
	return true;
}

//Called by an observer to unsubscribe
void ButtonEventsHandler::unsubscribe(
		interface::ButtonEventsHandlerObserver* observer) {

	//erase the observer form the list
	std::list <interface::ButtonEventsHandlerObserver*> :: iterator it;
	for(it = obsList.begin(); it != obsList.end(); ++it) {
		obsList.erase(it);
	}
}

ButtonEventsHandler::~ButtonEventsHandler() {

}


void ButtonEventsHandler::onButtonChanged(uint16_t buttonIndex, bool pressed) {

	//push event to the concerned state machine
	switch(buttonIndex){
	case BUTTON0_Pin:
		if(pressed){
			ButtonEventsHandler::sm[0].pushEvent(new evButtonPressed);
		}
		else{
			ButtonEventsHandler::sm[0].pushEvent(new evButtonReleased);
		}
		break;
	case BUTTON1_Pin:
		if(pressed){
			ButtonEventsHandler::sm[1].pushEvent(new evButtonPressed);
		}
		else{
			ButtonEventsHandler::sm[1].pushEvent(new evButtonReleased);
		}
		break;
	case BUTTON2_Pin:
		if(pressed){
			ButtonEventsHandler::sm[2].pushEvent(new evButtonPressed);
		}
		else{
			ButtonEventsHandler::sm[2].pushEvent(new evButtonReleased);
		}
		break;
	case BUTTON3_Pin:
		if(pressed){
			ButtonEventsHandler::sm[3].pushEvent(new evButtonPressed);
		}
		else{
			ButtonEventsHandler::sm[3].pushEvent(new evButtonReleased);
		}
		break;
	default:
		break;
	}
}
void ButtonEventsHandler::build() {

	//register the function onButtonChanged to the ButtonsController Callback
	ButtonsController::getInstance().registerCallback(this,(ButtonsControllerCallbackProvider::CallbackMethod)&ButtonEventsHandler::onButtonChanged);

	//initialize and start the 4 state machines
	for(int i=0;i<4;i++){
		sm[i].initialize(i);
		sm[i].startBehavior();
	}
}

//called on short press by the 4 state machines
void ButtonEventsHandler::notifyButtonShortPressed(ButtonIndex buttonIndex) {

	//call onButtonShortPressed on all subscribed observers
	std::list <interface::ButtonEventsHandlerObserver*> :: iterator it;
	for(it = obsList.begin(); it != obsList.end(); ++it) {
		(*it)->onButtonShortPressed(buttonIndex);
	}
}

//called on long press by the 4 state machines
void ButtonEventsHandler::notifyButtonLongPressed(ButtonIndex buttonIndex) {

	//call onButtonLongPressed on all subscribed observers
	std::list <interface::ButtonEventsHandlerObserver*> :: iterator it;
	for(it = obsList.begin(); it != obsList.end(); ++it) {
		(*it)->onButtonLongPressed(buttonIndex);
	}
}
