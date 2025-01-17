#include <stdexcept>
struct Event
{
};

enum class State
{
  DPI,
  JDK,
  PPT,
  XSS,
  BIOS,
  MFA,
  DOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DPI:
      return "DPI";
    case State::JDK:
      return "JDK";
    case State::PPT:
      return "PPT";
    case State::XSS:
      return "XSS";
    case State::BIOS:
      return "BIOS";
    case State::MFA:
      return "MFA";
    case State::DOS:
      return "DOS";
  }
  return "?";
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DOS
  // - PPT
  return State::DOS;
}

State handle_PPT(Event const & event)
{
  // Check the event and return one of the following states:
  // - DOS
  // - PPT
  // - DPI
  return State::PPT;
}

State handle_DPI(Event const & event)
{
  // Check the event and return one of the following states:
  // - BIOS
  // - DOS
  return State::DPI;
}

State handle_BIOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - BIOS
  // - JDK
  // - DOS
  return State::BIOS;
}

State handle_JDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - XSS
  // - DOS
  return State::JDK;
}

State handle_XSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - MFA
  // - DOS
  return State::XSS;
}

State handle_MFA(Event const & event)
{
  // Check the event and return one of the following states:
  // - MFA
  // - DOS
  // - PPT
  return State::MFA;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DPI:
    return handle_DPI(event);
  case State::JDK:
    return handle_JDK(event);
  case State::PPT:
    return handle_PPT(event);
  case State::XSS:
    return handle_XSS(event);
  case State::BIOS:
    return handle_BIOS(event);
  case State::MFA:
    return handle_MFA(event);
  case State::DOS:
    return handle_DOS(event);
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
  State state = State::DOS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
