#include <stdexcept>
struct Event
{
};

enum class State
{
  VMX,
  VPN,
  MIM,
  CPU,
  BIOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::VMX:
      return "VMX";
    case State::VPN:
      return "VPN";
    case State::MIM:
      return "MIM";
    case State::CPU:
      return "CPU";
    case State::BIOS:
      return "BIOS";
  }
  return "?";
}

State handle_VPN(Event const & event)
{
  // Check the event and return one of the following states:
  // - BIOS
  return State::VPN;
}

State handle_BIOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - VPN
  // - BIOS
  // - CPU
  return State::BIOS;
}

State handle_CPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPU
  // - VMX
  // - VPN
  // - MIM
  return State::CPU;
}

State handle_VMX(Event const & event)
{
  // Check the event and return one of the following states:
  // - VMX
  // - MIM
  // - VPN
  return State::VMX;
}

State handle_MIM(Event const & event)
{
  // Check the event and return one of the following states:
  // - MIM
  // - VPN
  // - BIOS
  return State::MIM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::VMX:
    return handle_VMX(event);
  case State::VPN:
    return handle_VPN(event);
  case State::MIM:
    return handle_MIM(event);
  case State::CPU:
    return handle_CPU(event);
  case State::BIOS:
    return handle_BIOS(event);
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
  State state = State::VPN;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
