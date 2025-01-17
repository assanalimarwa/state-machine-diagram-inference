#include <stdexcept>
struct Event
{
};

enum class State
{
  XM,
  RA,
  MFA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::XM:
      return "XM";
    case State::RA:
      return "RA";
    case State::MFA:
      return "MFA";
  }
  return "?";
}

State handle_MFA(Event const & event)
{
  // Check the event and return one of the following states:
  // - RA
  // - XM
  return State::MFA;
}

State handle_RA(Event const & event)
{
  // Check the event and return one of the following states:
  // - MFA
  // - MFA
  // - XM
  return State::RA;
}

State handle_XM(Event const & event)
{
  // Check the event and return one of the following states:
  // - RA
  // - MFA
  // - MFA
  return State::XM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::XM:
    return handle_XM(event);
  case State::RA:
    return handle_RA(event);
  case State::MFA:
    return handle_MFA(event);
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
  State state = State::MFA;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
