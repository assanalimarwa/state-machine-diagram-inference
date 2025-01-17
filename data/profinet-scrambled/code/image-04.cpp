#include <stdexcept>
struct Event
{
};

enum class State
{
  CSS,
  IOT,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::CSS:
      return "CSS";
    case State::IOT:
      return "IOT";
  }
  return "?";
}

State handle_CSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOT
  // - CSS
  return State::CSS;
}

State handle_IOT(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSS
  // - IOT
  return State::IOT;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::CSS:
    return handle_CSS(event);
  case State::IOT:
    return handle_IOT(event);
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
  State state = State::CSS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
