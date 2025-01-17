#include <stdexcept>
struct Event
{
};

enum class State
{
  IPV,
  CSV,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::IPV:
      return "IPV";
    case State::CSV:
      return "CSV";
  }
  return "?";
}

State handle_CSV(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSV
  // - IPV
  return State::CSV;
}

State handle_IPV(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSV
  // - IPV
  return State::IPV;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::IPV:
    return handle_IPV(event);
  case State::CSV:
    return handle_CSV(event);
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
  State state = State::CSV;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
