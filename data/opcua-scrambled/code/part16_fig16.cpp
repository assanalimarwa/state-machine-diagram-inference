#include <stdexcept>
struct Event
{
};

enum class State
{
  EXE,
  DAC,
  CS,
  CDN,
  RAM,
  DOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::EXE:
      return "EXE";
    case State::DAC:
      return "DAC";
    case State::CS:
      return "CS";
    case State::CDN:
      return "CDN";
    case State::RAM:
      return "RAM";
    case State::DOS:
      return "DOS";
  }
  return "?";
}

State handle_EXE(Event const & event)
{
  // Check the event and return one of the following states:
  // - CS
  return State::EXE;
}

State handle_CS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DOS
  // - CDN
  return State::CS;
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  // - CDN
  return State::DOS;
}

State handle_CDN(Event const & event)
{
  // Check the event and return one of the following states:
  // - EXE
  // - DAC
  return State::CDN;
}

State handle_DAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - CDN
  // - CS
  return State::DAC;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::EXE:
    return handle_EXE(event);
  case State::DAC:
    return handle_DAC(event);
  case State::CS:
    return handle_CS(event);
  case State::CDN:
    return handle_CDN(event);
  case State::RAM:
    return handle_RAM(event);
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
  State state = State::EXE;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
