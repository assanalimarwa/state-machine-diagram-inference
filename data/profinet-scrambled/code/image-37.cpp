#include <stdexcept>
struct Event
{
};

enum class State
{
  OSX,
  TLD,
  RDS,
  DNS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::OSX:
      return "OSX";
    case State::TLD:
      return "TLD";
    case State::RDS:
      return "RDS";
    case State::DNS:
      return "DNS";
  }
  return "?";
}

State handle_RDS(Event const & event)
{
  // Check the event and return one of the following states:
  // - RDS
  // - TLD
  return State::RDS;
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - RDS
  // - TLD
  // - DNS
  return State::TLD;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  // - OSX
  // - RDS
  return State::DNS;
}

State handle_OSX(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  // - OSX
  // - RDS
  return State::OSX;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::OSX:
    return handle_OSX(event);
  case State::TLD:
    return handle_TLD(event);
  case State::RDS:
    return handle_RDS(event);
  case State::DNS:
    return handle_DNS(event);
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
  State state = State::RDS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
