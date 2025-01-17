#include <stdexcept>
struct Event
{
};

enum class State
{
  CMS,
  SSD,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::CMS:
      return "CMS";
    case State::SSD:
      return "SSD";
  }
  return "?";
}

State handle_SSD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - CMS
  return State::SSD;
}

State handle_CMS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - CMS
  return State::CMS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::CMS:
    return handle_CMS(event);
  case State::SSD:
    return handle_SSD(event);
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
  State state = State::SSD;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
