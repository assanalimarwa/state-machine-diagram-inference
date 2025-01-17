#include <stdexcept>
struct Event
{
};

enum class State
{
  PDF,
  DNS,
  DAC,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::PDF:
      return "PDF";
    case State::DNS:
      return "DNS";
    case State::DAC:
      return "DAC";
  }
  return "?";
}

State handle_PDF(Event const & event)
{
  // Check the event and return one of the following states:
  // - PDF
  return State::PDF;
}

State handle_DAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - DAC
  // - DNS
  return State::DAC;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DAC
  // - DNS
  return State::DNS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::PDF:
    return handle_PDF(event);
  case State::DNS:
    return handle_DNS(event);
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
  State state = State::PDF;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
