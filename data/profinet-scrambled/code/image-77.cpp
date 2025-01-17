#include <stdexcept>
struct Event
{
};

enum class State
{
  AIX,
  MAC,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::AIX:
      return "AIX";
    case State::MAC:
      return "MAC";
  }
  return "?";
}

State handle_MAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  // - AIX
  return State::MAC;
}

State handle_AIX(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIX
  // - MAC
  return State::AIX;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::AIX:
    return handle_AIX(event);
  case State::MAC:
    return handle_MAC(event);
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
  State state = State::MAC;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
