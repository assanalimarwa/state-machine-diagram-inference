#include <stdexcept>
struct Event
{
};

enum class State
{
  TCP,
  MAC,
  SQL,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::TCP:
      return "TCP";
    case State::MAC:
      return "MAC";
    case State::SQL:
      return "SQL";
  }
  return "?";
}

State handle_SQL(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  return State::SQL;
}

State handle_MAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  // - TCP
  return State::MAC;
}

State handle_TCP(Event const & event)
{
  // Check the event and return one of the following states:
  // - SQL
  return State::TCP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::TCP:
    return handle_TCP(event);
  case State::MAC:
    return handle_MAC(event);
  case State::SQL:
    return handle_SQL(event);
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
  State state = State::SQL;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
