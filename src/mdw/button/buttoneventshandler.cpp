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

	static evButtonPressed ep;
	static evButtonReleased er;

	switch(buttonIndex){
	case BUTTON0_Pin:
		if(pressed)
			//ButtonEventsHandler::sm[0].pushEvent(&ep);
			Trace::out("Btn 0 pressed\n\r");
		else
			//ButtonEventsHandler::sm[0].pushEvent(&er);
			Trace::out("Btn 0 released\n\r");
		break;
	case BUTTON1_Pin:
		if(pressed)
			//ButtonEventsHandler::sm[1].pushEvent(&ep);
			Trace::out("Btn 1 pressed\n\r");
		else
			//ButtonEventsHandler::sm[1].pushEvent(&er);
			Trace::out("Btn 1 released\n\r");
		break;
	case BUTTON2_Pin:
		if(pressed)
			//ButtonEventsHandler::sm[2].pushEvent(&ep);
			Trace::out("Btn 2 pressed\n\r");
		else
			//ButtonEventsHandler::sm[2].pushEvent(&er);
			Trace::out("Btn 2 released\n\r");
		break;
	case BUTTON3_Pin:
		if(pressed)
			//ButtonEventsHandler::sm[3].pushEvent(&ep);
			Trace::out("Btn 3 pressed\n\r");
		else
			//ButtonEventsHandler::sm[3].pushEvent(&er);
			Trace::out("Btn 3 released\n\r");
		break;
	default:
		break;
	}
}

void ButtonEventsHandler::build() {
	ButtonsController::getInstance().registerCallback(this,(ButtonsControllerCallbackProvider::CallbackMethod)&ButtonEventsHandler::onButtonChanged);

	/*sm[0].initialize(BUTTON0_Pin);
	sm[1].initialize(BUTTON1_Pin);
	sm[2].initialize(BUTTON2_Pin);
	sm[3].initialize(BUTTON3_Pin);

	for(int i=0;i<4;i++){
		//sm[i].startBehavior();
	}*/
}

void ButtonEventsHandler::notifyButtonShortPressed(ButtonIndex buttonIndex) {
}

void ButtonEventsHandler::notifyButtonLongPressed(ButtonIndex buttonIndex) {
}
