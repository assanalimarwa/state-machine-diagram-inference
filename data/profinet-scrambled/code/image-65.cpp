#include <stdexcept>
struct Event
{
};

enum class State
{
  NFS,
  EXE,
  USB,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::NFS:
      return "NFS";
    case State::EXE:
      return "EXE";
    case State::USB:
      return "USB";
  }
  return "?";
}

State handle_NFS(Event const & event)
{
  // Check the event and return one of the following states:
  // - NFS
  // - EXE
  // - USB
  return State::NFS;
}

State handle_EXE(Event const & event)
{
  // Check the event and return one of the following states:
  // - EXE
  // - USB
  return State::EXE;
}

State handle_USB(Event const & event)
{
  // Check the event and return one of the following states:
  // - USB
  // - NFS
  return State::USB;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::NFS:
    return handle_NFS(event);
  case State::EXE:
    return handle_EXE(event);
  case State::USB:
    return handle_USB(event);
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
  State state = State::NFS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
