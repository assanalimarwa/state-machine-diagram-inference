#include <stdexcept>
struct Event
{
};

enum class State
{
  MLB,
  ATM,
  OOP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::MLB:
      return "MLB";
    case State::ATM:
      return "ATM";
    case State::OOP:
      return "OOP";
  }
  return "?";
}

State handle_MLB(Event const & event)
{
  // Check the event and return one of the following states:
  // - OOP
  return State::MLB;
}

State handle_OOP(Event const & event)
{
  // Check the event and return one of the following states:
  // - ATM
  return State::OOP;
}

State handle_ATM(Event const & event)
{
  // Check the event and return one of the following states:
  // - OOP
  // - ATM
  return State::ATM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::MLB:
    return handle_MLB(event);
  case State::ATM:
    return handle_ATM(event);
  case State::OOP:
    return handle_OOP(event);
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
