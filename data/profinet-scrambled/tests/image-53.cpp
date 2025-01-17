#include <gtest/gtest.h>
struct Event{};
enum class State
{
  AES,
  IVR,
  DNS,
  IDE,
};
State handle_event(State const state, Event const & evnet);

TEST(App, AES)
{
  // CHeck path ['AES']
  Event event;
  auto state = State::AES;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AES);
}

