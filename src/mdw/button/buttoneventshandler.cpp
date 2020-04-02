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

bool ButtonEventsHandler::subscribe(
		interface::ButtonEventsHandlerObserver* observer) {
	obsList.push_front(observer);
	return true;
}

void ButtonEventsHandler::unsubscribe(
		interface::ButtonEventsHandlerObserver* observer) {

	std::list <interface::ButtonEventsHandlerObserver*> :: iterator it;
	for(it = obsList.begin(); it != obsList.end(); ++it) {
		obsList.erase(it);
	}
}

ButtonEventsHandler::~ButtonEventsHandler() {
	// TODO Auto-generated destructor stub
}


void ButtonEventsHandler::onButtonChanged(uint16_t buttonIndex, bool pressed) {

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
	ButtonsController::getInstance().registerCallback(this,(ButtonsControllerCallbackProvider::CallbackMethod)&ButtonEventsHandler::onButtonChanged);

	for(int i=0;i<4;i++){
		sm[i].initialize(i);
		sm[i].startBehavior();
	}
}

void ButtonEventsHandler::notifyButtonShortPressed(ButtonIndex buttonIndex) {
	std::list <interface::ButtonEventsHandlerObserver*> :: iterator it;
	for(it = obsList.begin(); it != obsList.end(); ++it) {
		(*it)->onButtonShortPressed(buttonIndex);
	}
}

void ButtonEventsHandler::notifyButtonLongPressed(ButtonIndex buttonIndex) {
	std::list <interface::ButtonEventsHandlerObserver*> :: iterator it;
	for(it = obsList.begin(); it != obsList.end(); ++it) {
		(*it)->onButtonLongPressed(buttonIndex);
	}
}
