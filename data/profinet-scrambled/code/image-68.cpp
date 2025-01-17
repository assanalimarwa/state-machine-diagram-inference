#include <stdexcept>
struct Event
{
};

enum class State
{
  GPU,
  MAC,
  EDI,
  AIK,
  CPL,
  LAN,
  SIP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::GPU:
      return "GPU";
    case State::MAC:
      return "MAC";
    case State::EDI:
      return "EDI";
    case State::AIK:
      return "AIK";
    case State::CPL:
      return "CPL";
    case State::LAN:
      return "LAN";
    case State::SIP:
      return "SIP";
  }
  return "?";
}

State handle_CPL(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPL
  // - LAN
  return State::CPL;
}

State handle_LAN(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPL
  // - LAN
  // - SIP
  return State::LAN;
}

State handle_SIP(Event const & event)
{
  // Check the event and return one of the following states:
  // - SIP
  // - MAC
  // - CPL
  return State::SIP;
}

State handle_MAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  // - AIK
  // - CPL
  return State::MAC;
}

State handle_AIK(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIK
  // - EDI
  // - CPL
  return State::AIK;
}

State handle_EDI(Event const & event)
{
  // Check the event and return one of the following states:
  // - EDI
  // - GPU
  // - CPL
  return State::EDI;
}

State handle_GPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - GPU
  // - CPL
  // - LAN
  return State::GPU;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::GPU:
    return handle_GPU(event);
  case State::MAC:
    return handle_MAC(event);
  case State::EDI:
    return handle_EDI(event);
  case State::AIK:
    return handle_AIK(event);
  case State::CPL:
    return handle_CPL(event);
  case State::LAN:
    return handle_LAN(event);
  case State::SIP:
    return handle_SIP(event);
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
  State state = State::CPL;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
