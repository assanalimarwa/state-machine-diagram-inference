#include <stdexcept>
struct Event
{
};

enum class State
{
  DNS,
  EDI,
  MIM,
  SDK,
  IPX,
  AIK,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DNS:
      return "DNS";
    case State::EDI:
      return "EDI";
    case State::MIM:
      return "MIM";
    case State::SDK:
      return "SDK";
    case State::IPX:
      return "IPX";
    case State::AIK:
      return "AIK";
  }
  return "?";
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIK
  return State::SDK;
}

State handle_AIK(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIK
  // - IPX
  return State::AIK;
}

State handle_IPX(Event const & event)
{
  // Check the event and return one of the following states:
  // - IPX
  // - DNS
  // - AIK
  return State::IPX;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  // - EDI
  // - AIK
  return State::DNS;
}

State handle_EDI(Event const & event)
{
  // Check the event and return one of the following states:
  // - EDI
  // - MIM
  // - AIK
  return State::EDI;
}

State handle_MIM(Event const & event)
{
  // Check the event and return one of the following states:
  // - MIM
  // - AIK
  return State::MIM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DNS:
    return handle_DNS(event);
  case State::EDI:
    return handle_EDI(event);
  case State::MIM:
    return handle_MIM(event);
  case State::SDK:
    return handle_SDK(event);
  case State::IPX:
    return handle_IPX(event);
  case State::AIK:
    return handle_AIK(event);
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
