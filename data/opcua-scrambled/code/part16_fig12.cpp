#include <stdexcept>
struct Event
{
};

enum class State
{
  XML,
  GIF,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::XML:
      return "XML";
    case State::GIF:
      return "GIF";
  }
  return "?";
}

State handle_XML(Event const & event)
{
  // Check the event and return one of the following states:
  // - GIF
  return State::XML;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::XML:
    return handle_XML(event);
  case State::GIF:
    return handle_GIF(event);
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
  State state = State::XML;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
