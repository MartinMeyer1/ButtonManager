/*
 * buttonscontroller.cpp
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#include <board/buttonscontroller.h>

#include "mdw\trace\trace.h"
#include "event\evbuttonirq.h"

ButtonsController::ButtonsController() {
	_currentState = STATE_INITIAL;
	button_state[0] = GPIO_PIN_SET;
	button_state[1] = GPIO_PIN_SET;
	button_state[2] = GPIO_PIN_SET;
	button_state[3] = GPIO_PIN_SET;
}

ButtonsController::~ButtonsController() {
	// TODO Auto-generated destructor stub
}

void ButtonsController::onIrq() {
	//Trace::out("Interrupt\n\r");
	static evButtonIrq e;
	this->pushEvent(&e);
}

bool ButtonsController::registerCallback(
		interface::ButtonsControllerCallbackProvider* callbackProvider,
		interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) {

}

XFEventStatus ButtonsController::processEvent() {
	Trace::out("Process event\n\r");
	eEventStatus eventStatus = XFEventStatus::Unknown;
	eMainState _oldState;

	_oldState = _currentState;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){
			Trace::out("Initial transition\n\r");
			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_CHECK_BUTTONS:

		if (getCurrentEvent()->getEventType()==XFEvent::Event
				&& getCurrentEvent()->getId() == evButtonIrqId){
			_currentState = STATE_DEBOUNCE;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_DEBOUNCE:

		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
		getCurrentTimeout()->getId() == _evTimeout){

			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}

	//on entry actions
	if(_currentState != _oldState){
		switch(_currentState){
			case STATE_CHECK_BUTTONS:
				Trace::out("Entry in check buttons state\n\r");
				doCheckButtons();
				break;
			case STATE_DEBOUNCE:
				Trace::out("Entry in debounce state\n\r");
				scheduleTimeout(_evTimeout, 100);
				break;

			default:
				break;
		}
	}

	return eventStatus;
}

void ButtonsController::doCheckButtons() {
	//GPIO_PIN_SET or RESET
	if(HAL_GPIO_ReadPin(BUTTON0_GPIO_Port,BUTTON0_Pin)!=this->button_state[0]){
		Trace::out("Button 0 changed\n\r");
		button_state[0]=HAL_GPIO_ReadPin(BUTTON0_GPIO_Port,BUTTON0_Pin);
	}
	if(HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin)!=button_state[1]){
		Trace::out("Button 1 changed\n\r");
		button_state[1]=HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin);
	}
	if(HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin)!=button_state[2]){
		Trace::out("Button 2 changed\n\r");
		button_state[2]=HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin);
	}
	if(HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin)!=button_state[3]){
		Trace::out("Button 3 changed\n\r");
		button_state[3]=HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin);
	}
}
