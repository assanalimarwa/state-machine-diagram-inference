#include <stdexcept>
struct Event
{
};

enum class State
{
  XML,
  WAF,
  CSV,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::XML:
      return "XML";
    case State::WAF:
      return "WAF";
    case State::CSV:
      return "CSV";
  }
  return "?";
}

State handle_CSV(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSV
  // - XML
  return State::CSV;
}

State handle_XML(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSV
  // - XML
  // - WAF
  return State::XML;
}

State handle_WAF(Event const & event)
{
  // Check the event and return one of the following states:
  // - XML
  // - WAF
  // - CSV
  return State::WAF;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::XML:
    return handle_XML(event);
  case State::WAF:
    return handle_WAF(event);
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
  State state = State::CSV;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
