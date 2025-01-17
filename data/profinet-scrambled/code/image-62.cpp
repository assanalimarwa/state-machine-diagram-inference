#include <stdexcept>
struct Event
{
};

enum class State
{
  CSV,
  DRM,
  YML,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::CSV:
      return "CSV";
    case State::DRM:
      return "DRM";
    case State::YML:
      return "YML";
  }
  return "?";
}

State handle_YML(Event const & event)
{
  // Check the event and return one of the following states:
  // - YML
  // - CSV
  return State::YML;
}

State handle_CSV(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSV
  // - YML
  // - DRM
  return State::CSV;
}

State handle_DRM(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSV
  // - DRM
  // - YML
  return State::DRM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::CSV:
    return handle_CSV(event);
  case State::DRM:
    return handle_DRM(event);
  case State::YML:
    return handle_YML(event);
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
  State state = State::YML;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
