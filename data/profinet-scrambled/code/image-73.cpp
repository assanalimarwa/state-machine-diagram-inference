#include <stdexcept>
struct Event
{
};

enum class State
{
  EDI,
  CPU,
  VPS,
  MFA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::EDI:
      return "EDI";
    case State::CPU:
      return "CPU";
    case State::VPS:
      return "VPS";
    case State::MFA:
      return "MFA";
  }
  return "?";
}

State handle_EDI(Event const & event)
{
  // Check the event and return one of the following states:
  // - MFA
  return State::EDI;
}

State handle_MFA(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPU
  // - VPS
  return State::MFA;
}

State handle_CPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPU
  // - VPS
  return State::CPU;
}

State handle_VPS(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPU
  return State::VPS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::EDI:
    return handle_EDI(event);
  case State::CPU:
    return handle_CPU(event);
  case State::VPS:
    return handle_VPS(event);
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
  State state = State::EDI;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
