#include <stdexcept>
struct Event
{
};

enum class State
{
  SSH,
  GPU,
  PPT,
  EHR,
  IOS,
  CLI,
  CPU,
  CSS,
  NAT,
  WAP,
  IVR,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SSH:
      return "SSH";
    case State::GPU:
      return "GPU";
    case State::PPT:
      return "PPT";
    case State::EHR:
      return "EHR";
    case State::IOS:
      return "IOS";
    case State::CLI:
      return "CLI";
    case State::CPU:
      return "CPU";
    case State::CSS:
      return "CSS";
    case State::NAT:
      return "NAT";
    case State::WAP:
      return "WAP";
    case State::IVR:
      return "IVR";
  }
  return "?";
}

State handle_IOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - NAT
  return State::IOS;
}

State handle_NAT(Event const & event)
{
  // Check the event and return one of the following states:
  // - CSS
  return State::NAT;
}

State handle_CSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - NAT
  // - CSS
  // - PPT
  return State::CSS;
}

State handle_PPT(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPT
  // - CPU
  // - WAP
  return State::PPT;
}

State handle_CPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - WAP
  return State::CPU;
}

State handle_IVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - EHR
  // - WAP
  return State::IVR;
}

State handle_EHR(Event const & event)
{
  // Check the event and return one of the following states:
  // - EHR
  // - CLI
  // - WAP
  return State::EHR;
}

State handle_CLI(Event const & event)
{
  // Check the event and return one of the following states:
  // - CLI
  // - SSH
  // - WAP
  // - GPU
  return State::CLI;
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - GPU
  // - WAP
  return State::SSH;
}

State handle_GPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - WAP
  return State::GPU;
}

State handle_WAP(Event const & event)
{
  // Check the event and return one of the following states:
  // - NAT
  return State::WAP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SSH:
    return handle_SSH(event);
  case State::GPU:
    return handle_GPU(event);
  case State::PPT:
    return handle_PPT(event);
  case State::EHR:
    return handle_EHR(event);
  case State::IOS:
    return handle_IOS(event);
  case State::CLI:
    return handle_CLI(event);
  case State::CPU:
    return handle_CPU(event);
  case State::CSS:
    return handle_CSS(event);
  case State::NAT:
    return handle_NAT(event);
  case State::WAP:
    return handle_WAP(event);
  case State::IVR:
    return handle_IVR(event);
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
  State state = State::IOS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
