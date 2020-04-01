/*
 * buttonstatesm.h
 *
 *  Created on: 1 avr. 2020
 *      Author: meyer
 */

#ifndef BUTTON_BUTTONSTATESM_H_
#define BUTTON_BUTTONSTATESM_H_

#include "xf\include\xf\behavior.h"
#include "event/evbuttonpressed.h"
#include "event/evbuttonreleased.h"
#include "interface/buttoneventshandlersubject.h"

class ButtonStateSm : public XFBehavior{
public:
	ButtonStateSm();
	virtual ~ButtonStateSm();
	void initialize(interface::ButtonEventsHandlerSubject::ButtonIndex buttonIndex);

protected:
	virtual XFEventStatus processEvent();
	/**
	 * Timeout identifier(s) for this state machine
	 */
	typedef enum
	{
		_evTimeout = 1,	///< Timeout id for WAIT
	} eEventId;

	/**
	 * Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_UNKNOWN = 0,			///< Unknown state
		STATE_INITIAL = 1,			///< Initial state
		STATE_WAIT_BUTTON_PRESSED = 2,	///< check button state
		STATE_BUTTON_PRESSED	 = 3,
		STATE_BUTTON_SHORT_PRESSED	 = 4,
		STATE_BUTTON_LONG_PRESSED	 = 5,
	} eMainState;

	eMainState _currentState;		///< Attribute indicating currently active state

private:
	interface::ButtonEventsHandlerSubject::ButtonIndex buttonIndex;
};

#endif /* BUTTON_BUTTONSTATESM_H_ */
