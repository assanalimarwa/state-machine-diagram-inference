#include <stdexcept>
struct Event
{
};

enum class State
{
  SDK,
  NAT,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SDK:
      return "SDK";
    case State::NAT:
      return "NAT";
  }
  return "?";
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  // - NAT
  return State::SDK;
}

State handle_NAT(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  // - NAT
  return State::NAT;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SDK:
    return handle_SDK(event);
  case State::NAT:
    return handle_NAT(event);
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
  State state = State::SDK;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
