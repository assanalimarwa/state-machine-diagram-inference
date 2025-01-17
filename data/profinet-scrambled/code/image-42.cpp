#include <stdexcept>
struct Event
{
};

enum class State
{
  NAS,
  CAT,
  MUT,
  IFW,
  IPC,
  TDD,
  DOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::NAS:
      return "NAS";
    case State::CAT:
      return "CAT";
    case State::MUT:
      return "MUT";
    case State::IFW:
      return "IFW";
    case State::IPC:
      return "IPC";
    case State::TDD:
      return "TDD";
    case State::DOS:
      return "DOS";
  }
  return "?";
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - NAS
  return State::DOS;
}

State handle_NAS(Event const & event)
{
  // Check the event and return one of the following states:
  // - NAS
  // - IPC
  return State::NAS;
}

State handle_IPC(Event const & event)
{
  // Check the event and return one of the following states:
  // - IPC
  // - IFW
  // - NAS
  return State::IPC;
}

State handle_IFW(Event const & event)
{
  // Check the event and return one of the following states:
  // - IFW
  // - MUT
  // - NAS
  return State::IFW;
}

State handle_MUT(Event const & event)
{
  // Check the event and return one of the following states:
  // - MUT
  // - CAT
  // - NAS
  return State::MUT;
}

State handle_CAT(Event const & event)
{
  // Check the event and return one of the following states:
  // - CAT
  // - TDD
  // - NAS
  return State::CAT;
}

State handle_TDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - TDD
  // - NAS
  return State::TDD;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::NAS:
    return handle_NAS(event);
  case State::CAT:
    return handle_CAT(event);
  case State::MUT:
    return handle_MUT(event);
  case State::IFW:
    return handle_IFW(event);
  case State::IPC:
    return handle_IPC(event);
  case State::TDD:
    return handle_TDD(event);
  case State::DOS:
    return handle_DOS(event);
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
  State state = State::DOS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
