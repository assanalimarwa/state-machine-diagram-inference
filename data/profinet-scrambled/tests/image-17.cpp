#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SDK,
  CMS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, CMS)
{
  // CHeck path ['CMS']
  Event event;
  auto state = State::CMS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CMS);
}

