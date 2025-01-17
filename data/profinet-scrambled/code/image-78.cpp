#include <stdexcept>
struct Event
{
};

enum class State
{
  GUI,
  LVM,
  IPX,
  RSA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::GUI:
      return "GUI";
    case State::LVM:
      return "LVM";
    case State::IPX:
      return "IPX";
    case State::RSA:
      return "RSA";
  }
  return "?";
}

State handle_RSA(Event const & event)
{
  // Check the event and return one of the following states:
  // - RSA
  // - IPX
  return State::RSA;
}

State handle_IPX(Event const & event)
{
  // Check the event and return one of the following states:
  // - RSA
  // - IPX
  // - LVM
  // - GUI
  return State::IPX;
}

State handle_LVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - IPX
  // - LVM
  // - RSA
  return State::LVM;
}

State handle_GUI(Event const & event)
{
  // Check the event and return one of the following states:
  // - GUI
  // - RSA
  // - IPX
  return State::GUI;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::GUI:
    return handle_GUI(event);
  case State::LVM:
    return handle_LVM(event);
  case State::IPX:
    return handle_IPX(event);
  case State::RSA:
    return handle_RSA(event);
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
  State state = State::RSA;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
