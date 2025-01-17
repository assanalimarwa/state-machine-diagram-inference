#include <gtest/gtest.h>
struct Event{};
enum class State
{
  JVM,
  WWW,
  CDN,
  USB,
  LTE,
  ERP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, JVM)
{
  // CHeck path ['JVM']
  Event event;
  auto state = State::JVM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JVM);
}

