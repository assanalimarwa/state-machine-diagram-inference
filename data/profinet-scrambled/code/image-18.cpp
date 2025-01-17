#include <stdexcept>
struct Event
{
};

enum class State
{
  SAS,
  ASP,
  XSS,
  CPU,
  SLA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SAS:
      return "SAS";
    case State::ASP:
      return "ASP";
    case State::XSS:
      return "XSS";
    case State::CPU:
      return "CPU";
    case State::SLA:
      return "SLA";
  }
  return "?";
}

State handle_SLA(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLA
  // - CPU
  return State::SLA;
}

State handle_CPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLA
  // - CPU
  // - XSS
  // - ASP
  return State::CPU;
}

State handle_XSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - XSS
  // - SAS
  // - ASP
  return State::XSS;
}

State handle_SAS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SAS
  // - ASP
  // - SLA
  // - CPU
  return State::SAS;
}

State handle_ASP(Event const & event)
{
  // Check the event and return one of the following states:
  // - ASP
  // - SLA
  return State::ASP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SAS:
    return handle_SAS(event);
  case State::ASP:
    return handle_ASP(event);
  case State::XSS:
    return handle_XSS(event);
  case State::CPU:
    return handle_CPU(event);
  case State::SLA:
    return handle_SLA(event);
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
  State state = State::SLA;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
