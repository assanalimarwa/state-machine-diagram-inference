#include <stdexcept>
struct Event
{
};

enum class State
{
  RDP,
  JSON,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::RDP:
      return "RDP";
    case State::JSON:
      return "JSON";
  }
  return "?";
}

State handle_RDP(Event const & event)
{
  // Check the event and return one of the following states:
  // - RDP
  // - JSON
  return State::RDP;
}

State handle_JSON(Event const & event)
{
  // Check the event and return one of the following states:
  // - RDP
  // - JSON
  return State::JSON;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::RDP:
    return handle_RDP(event);
  case State::JSON:
    return handle_JSON(event);
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
  State state = State::RDP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
