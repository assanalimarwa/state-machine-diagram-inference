#include <stdexcept>
struct Event
{
};

enum class State
{
  RDP,
  USB,
  CMS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::RDP:
      return "RDP";
    case State::USB:
      return "USB";
    case State::CMS:
      return "CMS";
  }
  return "?";
}

State handle_RDP(Event const & event)
{
  // Check the event and return one of the following states:
  // - RDP
  return State::RDP;
}

State handle_USB(Event const & event)
{
  // Check the event and return one of the following states:
  // - USB
  // - CMS
  return State::USB;
}

State handle_CMS(Event const & event)
{
  // Check the event and return one of the following states:
  // - USB
  // - CMS
  return State::CMS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::RDP:
    return handle_RDP(event);
  case State::USB:
    return handle_USB(event);
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
  State state = State::RDP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
