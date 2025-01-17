#include <stdexcept>
struct Event
{
};

enum class State
{
  HDD,
  API,
  SIP,
  CSV,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::HDD:
      return "HDD";
    case State::API:
      return "API";
    case State::SIP:
      return "SIP";
    case State::CSV:
      return "CSV";
  }
  return "?";
}

State handle_API(Event const & event)
{
  // Check the event and return one of the following states:
  // - SIP
  // - HDD
  return State::API;
}

State handle_SIP(Event const & event)
{
  // Check the event and return one of the following states:
  // - SIP
  // - HDD
  return State::SIP;
}

State handle_HDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SIP
  // - HDD
  // - CSV
  return State::HDD;
}

State handle_CSV(Event const & event)
{
  // Check the event and return one of the following states:
  // - HDD
  // - CSV
  // - SIP
  return State::CSV;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::HDD:
    return handle_HDD(event);
  case State::API:
    return handle_API(event);
  case State::SIP:
    return handle_SIP(event);
  case State::CSV:
    return handle_CSV(event);
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
  State state = State::API;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
