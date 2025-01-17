#include <stdexcept>
struct Event
{
};

enum class State
{
  CSV,
  DVR,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::CSV:
      return "CSV";
    case State::DVR:
      return "DVR";
  }
  return "?";
}

State handle_DVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - CSV
  return State::DVR;
}

State handle_CSV(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - CSV
  return State::CSV;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::CSV:
    return handle_CSV(event);
  case State::DVR:
    return handle_DVR(event);
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
  State state = State::DVR;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
