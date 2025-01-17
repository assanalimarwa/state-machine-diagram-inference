#include <stdexcept>
struct Event
{
};

enum class State
{
  SDK,
  CMS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SDK:
      return "SDK";
    case State::CMS:
      return "CMS";
  }
  return "?";
}

State handle_CMS(Event const & event)
{
  // Check the event and return one of the following states:
  // - CMS
  // - SDK
  return State::CMS;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  return State::SDK;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SDK:
    return handle_SDK(event);
  case State::CMS:
    return handle_CMS(event);
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
  State state = State::CMS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
