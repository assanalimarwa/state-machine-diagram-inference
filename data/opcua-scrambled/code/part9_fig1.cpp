#include <stdexcept>
struct Event
{
};

enum class State
{
  HDD,
  ACL,
  SDK,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::HDD:
      return "HDD";
    case State::ACL:
      return "ACL";
    case State::SDK:
      return "SDK";
  }
  return "?";
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - HDD
  return State::SDK;
}

State handle_HDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - ACL
  return State::HDD;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::HDD:
    return handle_HDD(event);
  case State::ACL:
    return handle_ACL(event);
  case State::SDK:
    return handle_SDK(event);
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
  State state = State::SDK;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
