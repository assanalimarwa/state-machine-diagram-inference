#include <stdexcept>
struct Event
{
};

enum class State
{
  SSH,
  DVR,
  IOS,
  ACL,
  IPV,
  API,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SSH:
      return "SSH";
    case State::DVR:
      return "DVR";
    case State::IOS:
      return "IOS";
    case State::ACL:
      return "ACL";
    case State::IPV:
      return "IPV";
    case State::API:
      return "API";
  }
  return "?";
}

State handle_IPV(Event const & event)
{
  // Check the event and return one of the following states:
  // - ACL
  return State::IPV;
}

State handle_ACL(Event const & event)
{
  // Check the event and return one of the following states:
  // - ACL
  // - SSH
  return State::ACL;
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - ACL
  // - SSH
  // - API
  return State::SSH;
}

State handle_API(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - API
  // - IOS
  // - ACL
  return State::API;
}

State handle_IOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - API
  // - IOS
  // - DVR
  // - ACL
  return State::IOS;
}

State handle_DVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - ACL
  // - SSH
  // - API
  return State::DVR;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SSH:
    return handle_SSH(event);
  case State::DVR:
    return handle_DVR(event);
  case State::IOS:
    return handle_IOS(event);
  case State::ACL:
    return handle_ACL(event);
  case State::IPV:
    return handle_IPV(event);
  case State::API:
    return handle_API(event);
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
  State state = State::IPV;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
