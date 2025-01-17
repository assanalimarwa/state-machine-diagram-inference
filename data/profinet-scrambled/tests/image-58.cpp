#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DNS,
  EDI,
  MIM,
  SDK,
  IPX,
  AIK,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SDK)
{
  // CHeck path ['SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

