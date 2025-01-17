#include <gtest/gtest.h>
struct Event{};
enum class State
{
  RAM,
  EEP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, EEP)
{
  // CHeck path ['EEP']
  Event event;
  auto state = State::EEP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EEP);
}

TEST(App, RAM)
{
  // CHeck path ['EEP', 'RAM', 'EEP']
  Event event;
  auto state = State::EEP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EEP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RAM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EEP);
}

