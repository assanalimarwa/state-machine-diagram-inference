#include <stdexcept>
struct Event
{
};

enum class State
{
  DPI,
  SSH,
  MLB,
  PIP,
  API,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DPI:
      return "DPI";
    case State::SSH:
      return "SSH";
    case State::MLB:
      return "MLB";
    case State::PIP:
      return "PIP";
    case State::API:
      return "API";
  }
  return "?";
}

State handle_DPI(Event const & event)
{
  // Check the event and return one of the following states:
  // - MLB
  return State::DPI;
}

State handle_MLB(Event const & event)
{
  // Check the event and return one of the following states:
  // - DPI
  // - MLB
  // - SSH
  return State::MLB;
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - PIP
  // - DPI
  // - API
  return State::SSH;
}

State handle_PIP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PIP
  // - API
  // - DPI
  return State::PIP;
}

State handle_API(Event const & event)
{
  // Check the event and return one of the following states:
  // - API
  // - DPI
  // - MLB
  return State::API;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DPI:
    return handle_DPI(event);
  case State::SSH:
    return handle_SSH(event);
  case State::MLB:
    return handle_MLB(event);
  case State::PIP:
    return handle_PIP(event);
  case State::API:
    return handle_API(event);
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
  State state = State::DPI;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
