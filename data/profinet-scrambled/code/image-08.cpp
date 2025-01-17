#include <stdexcept>
struct Event
{
};

enum class State
{
  TLD,
  NAT,
  SSD,
  LTE,
  NTP,
  ICQ,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::TLD:
      return "TLD";
    case State::NAT:
      return "NAT";
    case State::SSD:
      return "SSD";
    case State::LTE:
      return "LTE";
    case State::NTP:
      return "NTP";
    case State::ICQ:
      return "ICQ";
  }
  return "?";
}

State handle_NTP(Event const & event)
{
  // Check the event and return one of the following states:
  // - LTE
  return State::NTP;
}

State handle_LTE(Event const & event)
{
  // Check the event and return one of the following states:
  // - LTE
  // - ICQ
  return State::LTE;
}

State handle_ICQ(Event const & event)
{
  // Check the event and return one of the following states:
  // - LTE
  // - ICQ
  // - SSD
  // - TLD
  return State::ICQ;
}

State handle_SSD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - TLD
  // - LTE
  return State::SSD;
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - TLD
  // - NAT
  // - LTE
  return State::TLD;
}

State handle_NAT(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  // - NAT
  // - LTE
  // - SSD
  return State::NAT;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::TLD:
    return handle_TLD(event);
  case State::NAT:
    return handle_NAT(event);
  case State::SSD:
    return handle_SSD(event);
  case State::LTE:
    return handle_LTE(event);
  case State::NTP:
    return handle_NTP(event);
  case State::ICQ:
    return handle_ICQ(event);
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
  State state = State::NTP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
