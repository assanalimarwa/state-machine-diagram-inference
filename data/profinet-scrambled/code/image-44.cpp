#include <stdexcept>
struct Event
{
};

enum class State
{
  GUI,
  DNS,
  NAT,
  DAC,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::GUI:
      return "GUI";
    case State::DNS:
      return "DNS";
    case State::NAT:
      return "NAT";
    case State::DAC:
      return "DAC";
  }
  return "?";
}

State handle_NAT(Event const & event)
{
  // Check the event and return one of the following states:
  // - DAC
  return State::NAT;
}

State handle_DAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  return State::DAC;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DAC
  // - GUI
  return State::DNS;
}

State handle_GUI(Event const & event)
{
  // Check the event and return one of the following states:
  // - GUI
  // - DAC
  return State::GUI;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::GUI:
    return handle_GUI(event);
  case State::DNS:
    return handle_DNS(event);
  case State::NAT:
    return handle_NAT(event);
  case State::DAC:
    return handle_DAC(event);
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
  State state = State::NAT;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
