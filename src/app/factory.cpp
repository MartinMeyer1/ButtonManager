#include "trace/trace.h"
#include "factory.h"
#include "mdw/button/buttoneventshandler.h"
#include "platform\f7-disco-gcc\board\buttonscontroller.h"
//#include "ButtonEventsLogger.h"

namespace app
{

// TODO: Implement app::Factory class

} /* namespace app */

//ButtonsController bc;

//StateMachine01 app::Factory::_task01(100, "Say Hello\r");
//ButtonsController app::Factory::bc;

void Factory_initialize()
{

    app::Factory::initialize();

}

void Factory_build()
{
    app::Factory::build();
}



// static
void app::Factory::initialize()
{
}

// static
void app::Factory::build()
{
    Trace::out("Starting program...\n\r---------------------\r");

    ButtonEventsLogger::getInstance().build();
    ButtonsController::getInstance().startBehavior();
    ButtonEventsHandler::getInstance().build();
    ButtonEventsLogger::getInstance().startBehavior();
}
