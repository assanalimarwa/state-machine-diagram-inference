#include <stdexcept>
struct Event
{
};

enum class State
{
  PHP,
  RAM,
  IVR,
  AIK,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::PHP:
      return "PHP";
    case State::RAM:
      return "RAM";
    case State::IVR:
      return "IVR";
    case State::AIK:
      return "AIK";
  }
  return "?";
}

State handle_PHP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PHP
  // - AIK
  return State::PHP;
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - PHP
  // - RAM
  // - AIK
  return State::RAM;
}

State handle_AIK(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  // - AIK
  // - IVR
  // - PHP
  return State::AIK;
}

State handle_IVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - PHP
  // - RAM
  return State::IVR;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::PHP:
    return handle_PHP(event);
  case State::RAM:
    return handle_RAM(event);
  case State::IVR:
    return handle_IVR(event);
  case State::AIK:
    return handle_AIK(event);
  default:
    throw std::runtime_error("Unknown state " + format_state(last_state));
  }
}

Event wait_for_event()
{
  // TODO fetch next event
  return Event();
}

int main()
{
  State state = State::PHP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
