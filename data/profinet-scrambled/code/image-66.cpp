#include <stdexcept>
struct Event
{
};

enum class State
{
  TLD,
  RDP,
  CPL,
  RAM,
  IVR,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::TLD:
      return "TLD";
    case State::RDP:
      return "RDP";
    case State::CPL:
      return "CPL";
    case State::RAM:
      return "RAM";
    case State::IVR:
      return "IVR";
  }
  return "?";
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  // - IVR
  // - TLD
  return State::RAM;
}

State handle_IVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - RAM
  // - TLD
  return State::IVR;
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  // - CPL
  // - RAM
  return State::TLD;
}

State handle_CPL(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPL
  // - RDP
  // - RAM
  return State::CPL;
}

State handle_RDP(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPL
  // - RDP
  // - RAM
  return State::RDP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::TLD:
    return handle_TLD(event);
  case State::RDP:
    return handle_RDP(event);
  case State::CPL:
    return handle_CPL(event);
  case State::RAM:
    return handle_RAM(event);
  case State::IVR:
    return handle_IVR(event);
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
  State state = State::RAM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
