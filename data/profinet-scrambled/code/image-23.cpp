#include <stdexcept>
struct Event
{
};

enum class State
{
  PDF,
  CRT,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::PDF:
      return "PDF";
    case State::CRT:
      return "CRT";
  }
  return "?";
}

State handle_CRT(Event const & event)
{
  // Check the event and return one of the following states:
  // - PDF
  return State::CRT;
}

State handle_PDF(Event const & event)
{
  // Check the event and return one of the following states:
  // - PDF
  return State::PDF;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::PDF:
    return handle_PDF(event);
  case State::CRT:
    return handle_CRT(event);
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
  State state = State::CRT;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
