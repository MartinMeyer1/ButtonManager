/*
 * ButtonEventsLogger.cpp
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#include <app/ButtonEventsLogger.h>
#include "mdw/trace/trace.h"

ButtonEventsLogger::ButtonEventsLogger() {
	// TODO Auto-generated constructor stub

}

ButtonEventsLogger::~ButtonEventsLogger() {
	// TODO Auto-generated destructor stub
}

void ButtonEventsLogger::onButtonShortPressed(ButtonIndex buttonIndex) {
	Trace::out("ButtonEventsLogger : Short Press on button %d\n\r", buttonIndex);
}

void ButtonEventsLogger::onButtonLongPressed(ButtonIndex buttonIndex) {
	Trace::out("ButtonEventsLogger : Long Press on button %d\n\r", buttonIndex);
}
