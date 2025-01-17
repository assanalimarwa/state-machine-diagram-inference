#include <stdexcept>
struct Event
{
};

enum class State
{
  JVM,
  RAM,
  LVM,
  DVR,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JVM:
      return "JVM";
    case State::RAM:
      return "RAM";
    case State::LVM:
      return "LVM";
    case State::DVR:
      return "DVR";
  }
  return "?";
}

State handle_LVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - JVM
  return State::LVM;
}

State handle_JVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - LVM
  // - DVR
  return State::JVM;
}

State handle_DVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - JVM
  // - RAM
  // - LVM
  return State::DVR;
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - LVM
  // - JVM
  return State::RAM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JVM:
    return handle_JVM(event);
  case State::RAM:
    return handle_RAM(event);
  case State::LVM:
    return handle_LVM(event);
  case State::DVR:
    return handle_DVR(event);
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
  State state = State::LVM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
