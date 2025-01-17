#include <stdexcept>
struct Event
{
};

enum class State
{
  ERP,
  KVM,
  SQL,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::ERP:
      return "ERP";
    case State::KVM:
      return "KVM";
    case State::SQL:
      return "SQL";
  }
  return "?";
}

State handle_KVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - KVM
  // - SQL
  return State::KVM;
}

State handle_SQL(Event const & event)
{
  // Check the event and return one of the following states:
  // - KVM
  // - SQL
  // - ERP
  return State::SQL;
}

State handle_ERP(Event const & event)
{
  // Check the event and return one of the following states:
  // - SQL
  // - ERP
  // - KVM
  return State::ERP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::ERP:
    return handle_ERP(event);
  case State::KVM:
    return handle_KVM(event);
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
  State state = State::KVM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
