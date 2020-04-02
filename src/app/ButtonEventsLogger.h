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
class ButtonEventsLogger : public interface::ButtonEventsHandlerObserver{
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
    //TODO button events handler pointer
protected:
	ButtonEventsLogger();
	virtual ~ButtonEventsLogger();
};

#endif /* BUTTONEVENTSLOGGER_H_ */
