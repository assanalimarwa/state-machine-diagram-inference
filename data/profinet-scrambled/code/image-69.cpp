#include <stdexcept>
struct Event
{
};

enum class State
{
  DPI,
  IOT,
  IoT,
  DNS,
  MIM,
  TLD,
  WAP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DPI:
      return "DPI";
    case State::IOT:
      return "IOT";
    case State::IoT:
      return "IoT";
    case State::DNS:
      return "DNS";
    case State::MIM:
      return "MIM";
    case State::TLD:
      return "TLD";
    case State::WAP:
      return "WAP";
  }
  return "?";
}

State handle_DPI(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOT
  return State::DPI;
}

State handle_IOT(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOT
  // - TLD
  // - DNS
  // - IoT
  return State::IOT;
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  // - DNS
  // - MIM
  return State::TLD;
}

State handle_IoT(Event const & event)
{
  // Check the event and return one of the following states:
  // - IoT
  // - WAP
  // - DNS
  // - MIM
  // - MIM
  return State::IoT;
}

State handle_WAP(Event const & event)
{
  // Check the event and return one of the following states:
  // - WAP
  // - DNS
  // - MIM
  return State::WAP;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  // - MIM
  // - DPI
  return State::DNS;
}

State handle_MIM(Event const & event)
{
  // Check the event and return one of the following states:
  // - DPI
  return State::MIM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DPI:
    return handle_DPI(event);
  case State::IOT:
    return handle_IOT(event);
  case State::IoT:
    return handle_IoT(event);
  case State::DNS:
    return handle_DNS(event);
  case State::MIM:
    return handle_MIM(event);
  case State::TLD:
    return handle_TLD(event);
  case State::WAP:
    return handle_WAP(event);
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
  State state = State::DPI;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
