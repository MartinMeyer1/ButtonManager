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
	// TODO Auto-generated constructor stub

}

ButtonsController::~ButtonsController() {
	// TODO Auto-generated destructor stub
}

void ButtonsController::onIrq() {
	static evButtonIrq e;
	this->pushEvent(&e);
	//GEN(evButtonIrq());
	Trace::out("Interrupt\n\r");
}

bool ButtonsController::registerCallback(
		interface::ButtonsControllerCallbackProvider* callbackProvider,
		interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) {
}

XFEventStatus ButtonsController::processEvent() {
	Trace::out("Alo process event\n\r");
	eEventStatus eventStatus = XFEventStatus::Unknown;
	eMainState _oldState;

	_oldState = _currentState;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){
			//GEN(XFNullTransition());
			Trace::out("Initial transition\n\r");
			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_CHECK_BUTTONS:

		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId()){
			_currentState = STATE_CHECK_BUTTONS;
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
	if(HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port,BUTTON_0_Pin)!=this->button_state[0]){
		Trace::out("Button 0 changed\n\r");
		button_state[0]=HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port,BUTTON_0_Pin);
	}
	if(HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,BUTTON_1_Pin)!=button_state[1]){
		Trace::out("Button 1 changed\n\r");
		button_state[1]=HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,BUTTON_1_Pin);
	}
	if(HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port,BUTTON_2_Pin)!=button_state[2]){
		Trace::out("Button 2 changed\n\r");
		button_state[2]=HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port,BUTTON_2_Pin);
	}
	if(HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port,BUTTON_3_Pin)!=button_state[3]){
		Trace::out("Button 3 changed\n\r");
		button_state[3]=HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port,BUTTON_3_Pin);
	}
}
