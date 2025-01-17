#include <stdexcept>
struct Event
{
};

enum class State
{
  JDK,
  HDD,
  RSA,
  CMS,
  LAN,
  CSV,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JDK:
      return "JDK";
    case State::HDD:
      return "HDD";
    case State::RSA:
      return "RSA";
    case State::CMS:
      return "CMS";
    case State::LAN:
      return "LAN";
    case State::CSV:
      return "CSV";
  }
  return "?";
}

State handle_RSA(Event const & event)
{
  // Check the event and return one of the following states:
  // - RSA
  // - CSV
  return State::RSA;
}

State handle_CSV(Event const & event)
{
  // Check the event and return one of the following states:
  // - RSA
  // - CSV
  // - JDK
  return State::CSV;
}

State handle_JDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - JDK
  // - CMS
  // - RSA
  return State::JDK;
}

State handle_CMS(Event const & event)
{
  // Check the event and return one of the following states:
  // - CMS
  // - HDD
  // - RSA
  // - LAN
  return State::CMS;
}

State handle_HDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - HDD
  // - LAN
  // - RSA
  return State::HDD;
}

State handle_LAN(Event const & event)
{
  // Check the event and return one of the following states:
  // - LAN
  // - RSA
  // - CSV
  return State::LAN;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JDK:
    return handle_JDK(event);
  case State::HDD:
    return handle_HDD(event);
  case State::RSA:
    return handle_RSA(event);
  case State::CMS:
    return handle_CMS(event);
  case State::LAN:
    return handle_LAN(event);
  case State::CSV:
    return handle_CSV(event);
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
  State state = State::RSA;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
