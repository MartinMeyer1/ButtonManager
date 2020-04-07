/*
 * ButtonEventsLogger.h
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#ifndef BUTTONEVENTSLOGGER_H_
#define BUTTONEVENTSLOGGER_H_

#include ".\interface\buttoneventshandlerobserver.h"
#include <ctime>
#include "xf\include\xf\behavior.h"

class ButtonEventsLogger : public interface::ButtonEventsHandlerObserver,public XFBehavior{
public:
	//singleton pattern
	static ButtonEventsLogger& getInstance()
	{
		static ButtonEventsLogger instance;
		return instance;
	}


	void onButtonShortPressed(ButtonIndex buttonIndex);         ///< @brief Called by the subject upon a button short pressed.
    void onButtonLongPressed(ButtonIndex buttonIndex);          ///< @brief Called by the subject upon a button long pressed.

    void build();

private:
private:
	virtual XFEventStatus processEvent();
	/**
	 * Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_UNKNOWN = 0,			///< Unknown state
		STATE_INITIAL = 1,			///< Initial state
		STATE_WORK = 2,				///< work state
	} eMainState;

	eMainState _currentState;		///< Attribute indicating currently active state
protected:
	ButtonEventsLogger();
	virtual ~ButtonEventsLogger();
	ButtonEventsLogger(const ButtonEventsLogger&){}
	void operator=(const ButtonEventsLogger&){}
};

#endif /* BUTTONEVENTSLOGGER_H_ */
