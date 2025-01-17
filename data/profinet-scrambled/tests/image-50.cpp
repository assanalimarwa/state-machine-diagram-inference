#include <gtest/gtest.h>
struct Event{};
enum class State
{
  CMS,
  SSD,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SSD)
{
  // CHeck path ['SSD']
  Event event;
  auto state = State::SSD;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSD);
}

TEST(App, CMS)
{
  // CHeck path ['SSD', 'CMS', 'SSD']
  Event event;
  auto state = State::SSD;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CMS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSD);
}

