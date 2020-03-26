#include "trace/trace.h"
#include "factory.h"

namespace app
{

// TODO: Implement app::Factory class

} /* namespace app */

//ButtonsController bc;

StateMachine01 app::Factory::_task01(100, "Say Hello\r");
ButtonsController app::Factory::bc;

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
    Trace::out("Starting test1...\n\r---------------------\r");

    // Start state machine
    //app::Factory::_task01.startBehavior();
    /*app::Factory::*/bc.startBehavior();
}
