#include <stdexcept>
struct Event
{
};

enum class State
{
  MLB,
  MAC,
  IIS,
  YML,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::MLB:
      return "MLB";
    case State::MAC:
      return "MAC";
    case State::IIS:
      return "IIS";
    case State::YML:
      return "YML";
  }
  return "?";
}

State handle_MLB(Event const & event)
{
  // Check the event and return one of the following states:
  // - MLB
  // - YML
  return State::MLB;
}

State handle_YML(Event const & event)
{
  // Check the event and return one of the following states:
  // - MLB
  // - YML
  // - IIS
  return State::YML;
}

State handle_IIS(Event const & event)
{
  // Check the event and return one of the following states:
  // - IIS
  // - MAC
  // - MLB
  return State::IIS;
}

State handle_MAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  // - MLB
  return State::MAC;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::MLB:
    return handle_MLB(event);
  case State::MAC:
    return handle_MAC(event);
  case State::IIS:
    return handle_IIS(event);
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
  State state = State::MLB;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
