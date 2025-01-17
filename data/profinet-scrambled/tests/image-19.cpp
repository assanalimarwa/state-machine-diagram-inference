#include <gtest/gtest.h>
struct Event{};
enum class State
{
  PHP,
  IDE,
};
State handle_event(State const state, Event const & evnet);

TEST(App, PHP)
{
  // CHeck path ['PHP']
  Event event;
  auto state = State::PHP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
}

