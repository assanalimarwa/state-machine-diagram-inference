#include <stdexcept>
struct Event
{
};

enum class State
{
  XML,
  DRM,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::XML:
      return "XML";
    case State::DRM:
      return "DRM";
  }
  return "?";
}

State handle_XML(Event const & event)
{
  // Check the event and return one of the following states:
  // - XML
  // - DRM
  return State::XML;
}

State handle_DRM(Event const & event)
{
  // Check the event and return one of the following states:
  // - XML
  // - DRM
  return State::DRM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::XML:
    return handle_XML(event);
  case State::DRM:
    return handle_DRM(event);
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
