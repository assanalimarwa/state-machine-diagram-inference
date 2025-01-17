#include <stdexcept>
struct Event
{
};

enum class State
{
  LAN,
  NOC,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::LAN:
      return "LAN";
    case State::NOC:
      return "NOC";
  }
  return "?";
}

State handle_NOC(Event const & event)
{
  // Check the event and return one of the following states:
  // - NOC
  // - LAN
  return State::NOC;
}

State handle_LAN(Event const & event)
{
  // Check the event and return one of the following states:
  // - NOC
  // - LAN
  return State::LAN;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::LAN:
    return handle_LAN(event);
  case State::NOC:
    return handle_NOC(event);
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
  State state = State::NOC;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
