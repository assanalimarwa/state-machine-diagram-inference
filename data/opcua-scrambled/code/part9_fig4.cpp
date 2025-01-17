#include <stdexcept>
struct Event
{
};

enum class State
{
  AIK,
  TLD,
  SIP,
  WAN,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::AIK:
      return "AIK";
    case State::TLD:
      return "TLD";
    case State::SIP:
      return "SIP";
    case State::WAN:
      return "WAN";
  }
  return "?";
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SIP
  // - AIK
  return State::TLD;
}

State handle_SIP(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  // - TLD
  return State::SIP;
}

State handle_WAN(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIK
  return State::WAN;
}

State handle_AIK(Event const & event)
{
  // Check the event and return one of the following states:
  // - WAN
  // - WAN
  return State::AIK;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::AIK:
    return handle_AIK(event);
  case State::TLD:
    return handle_TLD(event);
  case State::SIP:
    return handle_SIP(event);
  case State::WAN:
    return handle_WAN(event);
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
  State state = State::TLD;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
