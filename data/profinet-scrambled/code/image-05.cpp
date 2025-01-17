#include <stdexcept>
struct Event
{
};

enum class State
{
  JVM,
  WWW,
  CDN,
  USB,
  LTE,
  ERP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JVM:
      return "JVM";
    case State::WWW:
      return "WWW";
    case State::CDN:
      return "CDN";
    case State::USB:
      return "USB";
    case State::LTE:
      return "LTE";
    case State::ERP:
      return "ERP";
  }
  return "?";
}

State handle_JVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - ERP
  return State::JVM;
}

State handle_ERP(Event const & event)
{
  // Check the event and return one of the following states:
  // - ERP
  // - CDN
  return State::ERP;
}

State handle_CDN(Event const & event)
{
  // Check the event and return one of the following states:
  // - ERP
  // - CDN
  // - USB
  // - WWW
  return State::CDN;
}

State handle_USB(Event const & event)
{
  // Check the event and return one of the following states:
  // - USB
  // - LTE
  // - ERP
  // - WWW
  return State::USB;
}

State handle_LTE(Event const & event)
{
  // Check the event and return one of the following states:
  // - LTE
  // - WWW
  // - ERP
  // - CDN
  return State::LTE;
}

State handle_WWW(Event const & event)
{
  // Check the event and return one of the following states:
  // - WWW
  // - ERP
  // - CDN
  return State::WWW;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JVM:
    return handle_JVM(event);
  case State::WWW:
    return handle_WWW(event);
  case State::CDN:
    return handle_CDN(event);
  case State::USB:
    return handle_USB(event);
  case State::LTE:
    return handle_LTE(event);
  case State::ERP:
    return handle_ERP(event);
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
  State state = State::JVM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
